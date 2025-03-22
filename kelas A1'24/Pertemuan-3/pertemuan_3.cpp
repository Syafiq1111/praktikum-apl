#include <iostream>
using namespace std;

#define MAX_MAHASISWA 100

struct Alamat {
    string jalan;
    int nomor;
    string kota;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    Alamat alamat;
};

Mahasiswa mhs[MAX_MAHASISWA];
int panjang = 0;

int main() {
    int pilihan, index;
    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Mahasiswa" << endl;
        cout << "2. Tambah Mahasiswa" << endl;
        cout << "3. Ubah Mahasiswa" << endl;
        cout << "4. Hapus Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (panjang == 0) {
                    cout << "Belum ada mahasiswa" << endl;
                } else {
                    cout << "Daftar Mahasiswa" << endl;
                    cout << "==================" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Mahasiswa ke-" << i + 1 << endl;
                        cout << "Nama: " << mhs[i].nama << endl;
                        cout << "Umur: " << mhs[i].umur << endl;
                        cout << "Jurusan: " << mhs[i].jurusan << endl;
                        cout << "Alamat: " << mhs[i].alamat.jalan << " No. "
                            << mhs[i].alamat.nomor << ", " << mhs[i].alamat.kota << endl;
                        cout << endl;
                    }
                }
                break;

            case 2:
                if (panjang < MAX_MAHASISWA) {
                    cout << "Masukkan nama mahasiswa: ";
                    cin.ignore();
                    getline(cin, mhs[panjang].nama);
                    cout << "Masukkan umur mahasiswa: ";
                    cin >> mhs[panjang].umur;
                    cin.ignore();
                    cout << "Masukkan jurusan mahasiswa: ";
                    getline(cin, mhs[panjang].jurusan);
                    cout << "Masukkan alamat mahasiswa: " << endl;
                    cout << "Jalan: ";
                    getline(cin, mhs[panjang].alamat.jalan);
                    cout << "Nomor: ";
                    cin >> mhs[panjang].alamat.nomor;
                    cin.ignore();
                    cout << "Kota: ";
                    getline(cin, mhs[panjang].alamat.kota);
                    panjang++;
                    cout << "Mahasiswa berhasil ditambahkan" << endl;
                } else {
                    cout << "Kapasitas penuh! Tidak bisa menambah mahasiswa lagi." << endl;
                }
                break;

            case 3:
                if (panjang == 0) {
                    cout << "Belum ada mahasiswa untuk diubah." << endl;
                } else {
                    cout << "Daftar Mahasiswa" << endl;
                    cout << "==================" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Mahasiswa ke-" << i + 1 << endl;
                        cout << "Nama: " << mhs[i].nama << endl;
                        cout << endl;
                    }
                    cout << "Masukkan nomor mahasiswa yang akan diubah: ";
                    cin >> index;

                    if (index > 0 && index <= panjang) {
                        cout << "Masukkan nama mahasiswa baru: ";
                        cin.ignore();
                        getline(cin, mhs[index - 1].nama);
                        cout << "Masukkan umur mahasiswa baru: ";
                        cin >> mhs[index - 1].umur;
                        cin.ignore();
                        cout << "Masukkan jurusan mahasiswa baru: ";
                        getline(cin, mhs[index - 1].jurusan);
                        cout << "Masukkan alamat mahasiswa baru: " << endl;
                        cout << "Jalan: ";
                        getline(cin, mhs[index - 1].alamat.jalan);
                        cout << "Nomor: ";
                        cin >> mhs[index - 1].alamat.nomor;
                        cin.ignore();
                        cout << "Kota: ";
                        getline(cin, mhs[index - 1].alamat.kota);
                        cout << "Mahasiswa berhasil diubah" << endl;
                    } else {
                        cout << "Nomor mahasiswa tidak valid" << endl;
                    }
                }
                break;

            case 4:
                if (panjang == 0) {
                    cout << "Belum ada mahasiswa untuk dihapus." << endl;
                } else {
                    cout << "Daftar Mahasiswa" << endl;
                    cout << "==================" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Mahasiswa ke-" << i + 1 << endl;
                        cout << "Nama: " << mhs[i].nama << endl;
                        cout << endl;
                    }
                    cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
                    cin >> index;

                    if (index > 0 && index <= panjang) {
                        for (int i = index - 1; i < panjang - 1; i++) {
                            mhs[i] = mhs[i + 1];
                        }
                        panjang--;
                        cout << "Mahasiswa berhasil dihapus" << endl;
                    } else {
                        cout << "Nomor mahasiswa tidak valid" << endl;
                    }
                }
                break;

            case 5:
                cout << "Program selesai" << endl;
                break;

            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}
