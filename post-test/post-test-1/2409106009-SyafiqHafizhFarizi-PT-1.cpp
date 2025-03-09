#include <iostream>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;

void ubah() {
    int pilihan;
    double nilai;

    cout << endl;
    cout << ANSI_COLOR_BLUE "==========================================" ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE "        PILIH JENIS KONVERSI          " ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE "==========================================" ANSI_COLOR_RESET << endl;

    cout << ANSI_COLOR_RED   "1. Konversi Meter ke (Centimeter, Mile, Foot)" ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_GREEN "2. Konversi Centimeter ke (Meter, Mile, Foot)" ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE  "3. Konversi Mile ke (Meter, Centimeter, Foot)" ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_YELLOW "4. Konversi Foot ke (Meter, Centimeter, Mile)" ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE "==========================================" ANSI_COLOR_RESET << endl;

    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Masukkan nilai dalam Meter: ";
            cin >> nilai;
            cout << ANSI_COLOR_YELLOW "------------------------------------------" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_BLUE " Meter = " << nilai * 100 << " Centimeter" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_RED " Meter = " << nilai * 0.000621371 << " Mile" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_GREEN " Meter = " << nilai * 3.28084 << " Foot" ANSI_COLOR_RESET << endl;
            cout << ANSI_COLOR_YELLOW "------------------------------------------" ANSI_COLOR_RESET << endl;
            break;
        case 2:
            cout << "Masukkan nilai dalam Centimeter: ";
            cin >> nilai;
            cout << ANSI_COLOR_RED "------------------------------------------" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_YELLOW " Centimeter = " << nilai / 100 << " Meter" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_RED " Centimeter = " << nilai * 0.000621371 << " Mile" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_GREEN " Centimeter = " << nilai * 0.0328084 << " Foot" ANSI_COLOR_RESET << endl;
            cout << ANSI_COLOR_RED "------------------------------------------" ANSI_COLOR_RESET << endl;
            break;
        case 3:
            cout << "Masukkan nilai dalam Mile: ";
            cin >> nilai;
            cout << ANSI_COLOR_BLUE "------------------------------------------" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_YELLOW " Mile = " << nilai * 1609.34 << " Meter" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_BLUE " Mile = " << nilai * 160934 << " Centimeter" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_GREEN " Mile = " << nilai * 5280 << " Foot" ANSI_COLOR_RESET << endl;
            cout << ANSI_COLOR_BLUE "------------------------------------------" ANSI_COLOR_RESET << endl;
            break;
        case 4:
            cout << "Masukkan nilai dalam Foot: ";
            cin >> nilai;
            cout << ANSI_COLOR_GREEN "------------------------------------------" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_YELLOW " Foot = " << nilai / 3.28084 << " Meter" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_BLUE " Foot = " << nilai * 30.48 << " Centimeter" ANSI_COLOR_RESET << endl;
            cout << nilai << ANSI_COLOR_RED " Foot = " << nilai / 5280  << " Mile" ANSI_COLOR_RESET << endl;
            cout << ANSI_COLOR_GREEN "------------------------------------------" ANSI_COLOR_RESET << endl;
            break;
        default:
            cout << ANSI_COLOR_RED "Pilihan tidak valid. Silakan coba lagi." ANSI_COLOR_RESET << endl;
            cout << ANSI_COLOR_BLUE "------------------------------------------" ANSI_COLOR_RESET << endl;
    }
}

int main() {  
    string username = "Syafiq Hafizh Farizi";
    string nim = "2409106009";
    string username_id;
    string nim_id;
    int batas_login = 0;

    while (batas_login < 3) {
        cout << "Masukkan nama lengkap anda: ";
        getline(cin, username_id);

        cout << "Masukkan nim lengkap anda: ";
        getline(cin, nim_id);

        if (username_id == username && nim_id == nim) {
            cout << "Login berhasil!\n";
            break;
        } else {
            batas_login++;
            cout << "Nama lengkap/NIM tidak terdaftar" << endl;
        }
    }

    if (batas_login == 3) {
        cout << "Terlalu banyak percobaan. Program selesai." << endl;
        return 0;
    }

    char ulangprogram;
    do {
        ubah();
        cout << "\nApakah Anda ingin melakukan konversi lagi? (y/n): ";
        cin >> ulangprogram;
        cin.ignore();
    } while (ulangprogram == 'y' || ulangprogram == 'Y');

    cout << "Terima kasih telah menggunakan program ini!" << endl;
    return 0;
}