#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct User {
    string nama;
    string nim;
};

struct Membership {
    User anggota;
    int durasi;
    bool status;
};

const string ADMIN_NAMA = "Syafiq Hafizh Farizi";
const string ADMIN_NIM = "2409106009";
const int MAX_USERS = 100;
const int MAX_MEMBERS = 100;

User users[MAX_USERS];
int totalUsers = 0;
Membership members[MAX_MEMBERS];
int totalMembers = 0;

int main() {
    int batas_login = 0;
    string username_id, nim_id;
    int menu_pilihan;
    bool masuk = false;
    int loggedInIndex = -1;

    while (true) {
        cout << "===== Menu =====" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "Pilihan: ";
        cin >> menu_pilihan;
        cin.ignore();

        if (menu_pilihan == 1) {
            if (totalUsers < MAX_USERS) {
                cout << "===== Registrasi =====" << endl;
                cout << "Masukkan Nama: ";
                getline(cin, users[totalUsers].nama);
                cout << "Masukkan Password: ";
                getline(cin, users[totalUsers].nim);
                totalUsers++;
                cout << "Registrasi berhasil! Silakan login." << endl;
            } else {
                cout << "Jumlah pengguna penuh!" << endl;
            }
        } else if (menu_pilihan == 2) {
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    while (batas_login < 3) {
        cout << "===== Login =====" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, username_id);
        cout << "Masukkan NIM: ";
        getline(cin, nim_id);

        if (username_id == ADMIN_NAMA && nim_id == ADMIN_NIM) {
            masuk = true;
            break;
        }
        
        for (int i = 0; i < totalUsers; i++) {
            if (users[i].nama == username_id && users[i].nim == nim_id) {
                masuk = true;
                loggedInIndex = i;
                break;
            }
        }

        if (masuk) {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Login gagal! Coba lagi." << endl;
            batas_login++;
        }
    }

    if (batas_login == 3) {
        cout << "Terlalu banyak percobaan gagal.";
        return 0;
    }

    if (username_id == ADMIN_NAMA && nim_id == ADMIN_NIM) {
        Membership members[MAX_MEMBERS];
        int totalMembers = 0;
        int pilihan;
        bool masuk = true;

        while (masuk) {
            cout << "===== Membership Gym =====" << endl;
            cout << "1. Tambah Anggota" << endl;
            cout << "2. Lihat Anggota" << endl;
            cout << "3. Perbarui Keaktifan" << endl;
            cout << "4. Hapus Anggota" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan) {
                case 1:
                    if (totalMembers < MAX_MEMBERS) {
                        cout << "Masukkan Nama Anggota: ";
                        getline(cin, members[totalMembers].anggota.nama);
                        cout << "Masukkan NIM Anggota: ";
                        getline(cin, members[totalMembers].anggota.nim);
                        cout << "Masukkan Angka Durasi Membership (1/2/3 bulan): ";
                        cin >> members[totalMembers].durasi;
                        members[totalMembers].status = true;
                        cin.ignore();
                        totalMembers++;
                        cout << "Anggota berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Jumlah anggota penuh!" << endl;
                    }
                    break;
                case 2:
                    cout << "===============================================================" << endl;
                    cout << "| No |         Nama        |      NIM      | Durasi |  Status  |" << endl;
                    cout << "===============================================================" << endl;
                    for (int i = 0; i < totalMembers; i++) {
                        cout << "| " << setw(2) << i + 1 << " | " << setw(18) << left << members[i].anggota.nama << " | "
                            << setw(12) << members[i].anggota.nim << " | "
                            << setw(6) << members[i].durasi << " | "
                            << setw(8) << (members[i].status ? "Aktif" : "Tidak Aktif") << " |" << endl;
                    }
                    cout << "===============================================================" << endl;
                    break;
                case 3:
                cout << "===============================================================" << endl;
                cout << "| No |         Nama        |      NIM      | Durasi |  Status  |" << endl;
                cout << "===============================================================" << endl;
                for (int i = 0; i < totalMembers; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(18) << left << members[i].anggota.nama << " | "
                        << setw(12) << members[i].anggota.nim << " | "
                        << setw(6) << members[i].durasi << " | "
                        << setw(8) << (members[i].status ? "Aktif" : "Tidak Aktif") << " |" << endl;
                }
                cout << "===============================================================" << endl;
                    int index;
                    cout << "Masukkan nomor anggota yang ingin diperbarui: ";
                    cin >> index;
                    cin.ignore();
                    if (index > 0 && index <= totalMembers) {
                        cout << "Perbarui Durasi Membership (0 jika tidak lanjut): ";
                        cin >> members[index - 1].durasi;
                        members[index - 1].status = (members[index - 1].durasi > 0);
                        cin.ignore();
                        cout << "Membership diperbarui!" << endl;
                    } else {
                        cout << "Nomor anggota tidak valid!" << endl;
                    }
                    break;
                case 4:
                cout << "===============================================================" << endl;
                cout << "| No |         Nama        |      NIM      | Durasi |  Status  |" << endl;
                cout << "===============================================================" << endl;
                for (int i = 0; i < totalMembers; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(18) << left << members[i].anggota.nama << " | "
                        << setw(12) << members[i].anggota.nim << " | "
                        << setw(6) << members[i].durasi << " | "
                        << setw(8) << (members[i].status ? "Aktif" : "Tidak Aktif") << " |" << endl;
                }
                cout << "===============================================================" << endl;
                    cout << "Masukkan nomor anggota yang ingin dihapus: ";
                    cin >> index;
                    cin.ignore();
                    if (index > 0 && index <= totalMembers) {
                        for (int i = index - 1; i < totalMembers - 1; i++) {
                            members[i] = members[i + 1];
                        }
                        totalMembers--;
                        cout << "Anggota berhasil dihapus" << endl;
                    } else {
                        cout << "Nomor anggota tidak valid!" << endl;
                    }
                    break;
                case 5:
                    masuk = false;
                    cout << "Keluar dari program." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        }
    } else {
        cout << "===== Menu Pengguna =====" << endl;
        cout << "1. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> menu_pilihan;
        cin.ignore();
        cout << "Terima kasih!" << endl;
    }

    return 0;
}
