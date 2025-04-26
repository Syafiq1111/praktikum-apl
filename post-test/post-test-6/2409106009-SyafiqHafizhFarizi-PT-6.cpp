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

void registrasi(User users[], int &totalUsers) {
    if (totalUsers >= MAX_USERS) {
        cout << "Jumlah pengguna penuh!" << endl;
        return;
    }

    cout << "===== Registrasi =====" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, users[totalUsers].nama);
    cout << "Masukkan Password (NIM): ";
    getline(cin, users[totalUsers].nim);

    // Address-of
    totalUsers++;
    cout << "Registrasi berhasil!" << endl;
}

bool login(User users[], int totalUsers, string &namaLogin, string &nimLogin, int batas = 0) {
    if (batas >= 3) {
        cout << "Terlalu banyak percobaan gagal.\n";
        return false;
    }

    cout << "===== Login =====" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, namaLogin);
    cout << "Masukkan NIM: ";
    getline(cin, nimLogin);

    if (namaLogin == ADMIN_NAMA && nimLogin == ADMIN_NIM)
        return true;

    for (int i = 0; i < totalUsers; i++) {
        if (users[i].nama == namaLogin && users[i].nim == nimLogin)
            return true;
    }

    cout << "Login gagal! Coba lagi." << endl;
    return login(users, totalUsers, namaLogin, nimLogin, batas + 1);
}

void tambahAnggota(Membership* members, int* totalMembers) {
    if (*totalMembers >= MAX_MEMBERS) {
        cout << "Jumlah anggota penuh!" << endl;
        return;
    }

    cout << "Masukkan Nama Anggota: ";
    getline(cin, members[*totalMembers].anggota.nama);
    cout << "Masukkan NIM Anggota: ";
    getline(cin, members[*totalMembers].anggota.nim);
    cout << "Masukkan Durasi Membership (1/2/3): ";
    cin >> members[*totalMembers].durasi;
    members[*totalMembers].status = true;
    cin.ignore();

    (*totalMembers)++; // dereference pointer untuk menambah jumlah
    cout << "Anggota berhasil ditambahkan!" << endl;
}

void tampilkanAnggota(const Membership members[], int totalMembers) {
    cout << "===============================================================" << endl;
    cout << "| No |         Nama        |      NIM      | Durasi |  Status  |" << endl;
    cout << "===============================================================" << endl;
    for (int i = 0; i < totalMembers; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(19) << left << members[i].anggota.nama << " | "
             << setw(13) << members[i].anggota.nim << " | "
             << setw(6) << members[i].durasi << " | "
             << setw(8) << (members[i].status ? "Aktif" : "Tidak Aktif") << " |" << endl;
    }
    cout << "===============================================================" << endl;
}

void perbaruiDurasi(Membership* members, int totalMembers) {
    tampilkanAnggota(members, totalMembers);
    int index;
    cout << "Masukkan nomor anggota yang ingin diperbarui: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= totalMembers) {
        Membership* anggotaPtr = &members[index - 1]; // pointer ke struct
        cout << "Perbarui Durasi (0 untuk nonaktif): ";
        cin >> anggotaPtr->durasi; // dereference struct
        anggotaPtr->status = (anggotaPtr->durasi > 0);
        cin.ignore();
        cout << "Durasi diperbarui!" << endl;
    } else {
        cout << "Nomor tidak valid!" << endl;
    }
}

void hapusAnggota(Membership members[], int &totalMembers) {
    tampilkanAnggota(members, totalMembers);
    int index;
    cout << "Masukkan nomor anggota yang ingin dihapus: ";
    cin >> index;
    cin.ignore();
    if (index > 0 && index <= totalMembers) {
        for (int i = index - 1; i < totalMembers - 1; i++) {
            members[i] = members[i + 1];
        }
        totalMembers--;
        cout << "Anggota dihapus." << endl;
    } else {
        cout << "Nomor tidak valid!" << endl;
    }
}

void insertSortNama(Membership members[], int totalMembers) {  // Sort Ascending Huruf
    for (int i = 1; i < totalMembers; i++) {
        Membership simpan = members[i];
        int j = i - 1;
        while (j >= 0 && members[j].anggota.nama > simpan.anggota.nama) {
            members[j + 1] = members[j];
            j--;
        }
        members[j + 1] = simpan;
    }
    cout << "Data berhasil diurutkan berdasarkan nama (Ascending)!" << endl;
}

void bubbleSortDurasi(Membership members[], int totalMembers) {  // Sort Descending Angka
    for (int i = 0; i < totalMembers - 1; i++) {
        for (int j = 0; j < totalMembers - i - 1; j++) {
            if (members[j].durasi < members[j + 1].durasi) {
                swap(members[j], members[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan durasi (Descending)!" << endl;
}

int partition(Membership members[], int low, int high) {
    int pivot = members[high].durasi;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (members[j].durasi < pivot) {
            i++;
            swap(members[i], members[j]);
        }
    }
    swap(members[i + 1], members[high]);
    return i + 1;
}

void quickSortDurasi(Membership members[], int low, int high, bool firstCall = true) { // Sort Ascending Angka
    if (low < high) {
        int pi = partition(members, low, high);
        quickSortDurasi(members, low, pi - 1, false);
        quickSortDurasi(members, pi + 1, high, false);
    }

    if (firstCall) {
        cout << "Data berhasil diurutkan berdasarkan durasi (Ascending)!" << endl;
    }
}

void menuAdmin(Membership members[], int &totalMembers) {
    int pilihan;
    bool aktif = true;
    while (aktif) {
        cout << "===== Membership Gym =====" << endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Lihat Anggota" << endl;
        cout << "3. Perbarui Keaktifan" << endl;
        cout << "4. Hapus Anggota" << endl;
        cout << "5. Urutkan Nama (Insert Sort Ascending)" << endl;
        cout << "6. Urutkan Durasi (Bubble Sort Descending)" << endl;
        cout << "7. Urutkan Durasi (Quick Sort Ascending)" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tambahAnggota(members, &totalMembers); break;
            case 2: tampilkanAnggota(members, totalMembers); break;
            case 3: perbaruiDurasi(members, totalMembers); break;
            case 4: hapusAnggota(members, totalMembers); break;
            case 5: insertSortNama(members, totalMembers); break;
            case 6: bubbleSortDurasi(members, totalMembers); break;
            case 7: quickSortDurasi(members, 0, totalMembers - 1); break;
            case 8: aktif = false; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    }
}

void menuUser(const Membership members[], int totalMembers) {
    int pilihan;
    bool aktif = true;

    while (aktif) {
        cout << "===== Menu Pengguna =====" << endl;
        cout << "1. Lihat Anggota" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tampilkanAnggota(members, totalMembers); 
                break;
            case 2:
                cout << "Terima kasih!" << endl;
                aktif = false;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

int main() {
    int pilihan;
    string namaLogin, nimLogin;

    while (true) {
        cout << "===== MENU =====" << endl;
        cout << "1. Registrasi\n2. Login\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1)
            registrasi(users, totalUsers);
        else if (pilihan == 2)
            break;
        else
            cout << "Pilihan tidak valid!" << endl;
    }

    bool suksesLogin = login(users, totalUsers, namaLogin, nimLogin);
    if (!suksesLogin) return 0;

    if (namaLogin == ADMIN_NAMA && nimLogin == ADMIN_NIM)
        menuAdmin(members, totalMembers);
    else
        menuUser(members, totalMembers);


    return 0;
}
