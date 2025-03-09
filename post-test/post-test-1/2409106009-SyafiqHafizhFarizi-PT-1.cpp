#include <iostream>

using namespace std;

void ubah() {
    int pilihan;
    double nilai;

    cout << "\nPilih jenis konversi:\n";
    cout << "1. Konversi Meter ke (Centimeter, Mile, Foot)" << endl;
    cout << "2. Konversi Centimeter ke (Meter, Mile, Foot)" << endl;
    cout << "3. Konversi Mile ke (Meter, Centimeter, Foot)" << endl;
    cout << "4. Konversi Foot ke (Meter, Centimeter, Mile)" << endl;
    cout << "Masukkan pilihan Anda: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Masukkan nilai dalam Meter: ";
            cin >> nilai;
            cout << nilai << " Meter = " << nilai * 100 << " Centimeter" << endl;
            cout << nilai << " Meter = " << nilai * 0.000621371 << " Mile" << endl;
            cout << nilai << " Meter = " << nilai * 3.28084 << " Foot" << endl;
            break;
        case 2:
            cout << "Masukkan nilai dalam Centimeter: ";
            cin >> nilai;
            cout << nilai << " Centimeter = " << nilai / 100 << " Meter" << endl;
            cout << nilai << " Centimeter = " << nilai * 0.000621371 << " Mile" << endl;
            cout << nilai << " Centimeter = " << nilai * 0.0328084 << " Foot" << endl;
            break;
        case 3:
            cout << "Masukkan nilai dalam Mile: ";
            cin >> nilai;
            cout << nilai << " Mile = " << nilai * 1609.34 << " Meter" << endl;
            cout << nilai << " Mile = " << nilai * 160934 << " Centimeter" << endl;
            cout << nilai << " Mile = " << nilai * 5280 << " Foot" << endl;
            break;
        case 4:
            cout << "Masukkan nilai dalam Foot: ";
            cin >> nilai;
            cout << nilai << " Foot = " << nilai / 3.28084 << " Meter" << endl;
            cout << nilai << " Foot = " << nilai * 30.48 << " Centimeter" << endl;
            cout << nilai << " Foot = " << nilai / 5280  << " Mile" << endl;
            break;
            return;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
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