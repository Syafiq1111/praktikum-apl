#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int batas_login = 0;
    string username = "Syafiq Hafizh Farizi";
    string nim = "2409106009";
    string username_id;
    string nim_id;
    const int MAX_MEMBERS = 1;
    
    string members[MAX_MEMBERS]; 
    int durasi[MAX_MEMBERS];     
    int status[MAX_MEMBERS];     
    int data[MAX_MEMBERS][2];    
    int totalMembers = 0;
    
    while (batas_login < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, username_id);
        cout << "Masukkan NIM: ";
        getline(cin, nim_id);
        
        if (username_id == username && nim_id == nim) {
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
    
    int pilihan;
    bool masuk = true;
    
    while (masuk) {
        cout << "\n===== Membership Gym =====" << endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Lihat Anggota" << endl;
        cout << "3. Perbarui Keaktifan" << endl;
        cout << "4. Hapus Anggota" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: {
                if (totalMembers < MAX_MEMBERS) {
                    cout << "Masukkan Nama Anggota: ";
                    getline(cin, members[totalMembers]);
                    cout << "Masukkan Angka Durasi Membership (1/2/3 bulan): ";
                    cin >> durasi[totalMembers];
                    data[totalMembers][0] = durasi[totalMembers];
                    status[totalMembers] = 1;  
                    data[totalMembers][1] = status[totalMembers]; 
                    cin.ignore();
                    totalMembers++;
                    cout << "Anggota berhasil ditambahkan!" << endl;
                } else {
                    cout << "Jumlah anggota penuh!" << endl;
                }
                break;
            }
            case 2: {
                cout << "\n==================================================" << endl;
                cout << "| No |          Nama         | Durasi |  Status     |" << endl;
                cout << "====================================================" << endl;
                for (int i = 0; i < totalMembers; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << members[i] << " | "
                        << setw(6) << durasi[i] << " | " << setw(10) << (status[i] ? "Aktif" : "Tidak Aktif") << " |" << endl;
                }
                cout << "===================================================" << endl;
                break;
            }
            case 3: {
                int index;
                cout << "Masukkan nomor anggota yang ingin diperbarui: ";
                cin >> index;
                cin.ignore();
                if (index > 0 && index <= totalMembers) {
                    cout << "Perbarui Durasi Membership (0 jika tidak lanjut): ";
                    cin >> durasi[index - 1];
                    data[index - 1][0] = durasi[index - 1];
                    status[index - 1] = (durasi[index - 1] > 0);
                    data[index - 1][1] = status[index - 1]; 
                    cin.ignore();
                    cout << "Membership diperbarui!" << endl;
                } else {
                    cout << "Nomor anggota tidak valid!" << endl;
                }
                break;
            }
            case 4: {
                int index;
                cout << "Masukkan nomor anggota yang ingin dihapus: ";
                cin >> index;
                cin.ignore();
                if (index > 0 && index <= totalMembers) {
                    for (int i = index - 1; i < totalMembers - 1; i++) {
                        members[i] = members[i + 1];
                        durasi[i] = durasi[i + 1];
                        status[i] = status[i + 1];
                        data[i][0] = data[i + 1][0];
                        data[i][1] = data[i + 1][1];
                    }
                    totalMembers--;
                    cout << "Anggota berhasil dihapus" << endl;
                } else {
                    cout << "Nomor anggota tidak valid!" << endl;
                }
                break;
            }
            case 5:
                masuk = false;
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
    
    return 0;
}
