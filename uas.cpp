#include <iostream>
#include <vector>
#include <string>

using namespace std;

// peminjam
    string nama_mahasiswa;
    int NIM;
    string prodi;

struct Peralatan {
    string nama;
    string kode;
    int jumlah;
    bool tersedia;
    string peminjam;
    string jenis; //(misal elektronik, kimia, fisika, biologi)
};

vector<Peralatan> peralatan;

void inisialisasiData() {
    Peralatan alat1 = {"Kabel UTP", "UTP001", 30, true, "", "elektronik"};
    Peralatan alat2 = {"Proyektor", "PROJ001", 20, false, "Ulil", "elektronik"};
    Peralatan alat3 = {"Keyboard", "KEYB001", 10, true, "", "elektronik"};
    Peralatan alat4 = {"Mouse", "MOU001", 15, true, "", "elektronik"};
    Peralatan alat5 = {"Arduino", "ARD001", 10, false, "Kafi", "elektronik"};
    Peralatan alat6 = {"3D Printer", "3DP001", 5, false, "Nizhar", "elektronik"};
    Peralatan alat7 = {"Pipet Tetes", "PT001", 25, true, "", "kimia"};
    Peralatan alat8 = {"Gelas Ukur", "GU001", 25, true, "", "kimia"};
    Peralatan alat9 = {"Stopwatch", "SW001", 15, true, "", "fisika"};
    Peralatan alat10 = {"Mikroskop", "MKP001", 20, true, "", "biologi"};

    peralatan.push_back(alat1);
    peralatan.push_back(alat2);
    peralatan.push_back(alat3);
    peralatan.push_back(alat4);
    peralatan.push_back(alat5);
    peralatan.push_back(alat6);
    peralatan.push_back(alat7);
    peralatan.push_back(alat8);
    peralatan.push_back(alat9);
    peralatan.push_back(alat10);
}

void lihatPeralatan() {
    cout << "Daftar Peralatan:\n";
    cout << "--------------------\n";
    for (const Peralatan & alat : peralatan) {
        cout << "Nama: " << alat.nama << endl;
        cout << "Kode: " << alat.kode << endl;
        cout << "Jumlah: " << alat.jumlah << endl;
        cout << "Jenis: " << alat.jenis << endl;
        cout << "Status: " << (alat.tersedia ? "Tersedia" : "Dipinjam oleh " + alat.peminjam) << endl;
        cout << "--------------------\n";
    }
}

void cariPeralatan() 
{
    string kataKunci;
    cout << "Masukkan kata kunci pencarian (nama atau jenis): ";
    cin >> kataKunci;
    bool ditemukan = false;
    for (const Peralatan &alat : peralatan) {
        if (alat.nama.find(kataKunci) != string::npos || alat.jenis.find(kataKunci) != string::npos) {
            cout << "Ditemukan:\n";
            cout << "Nama: " << alat.nama << endl;
            cout << "Kode: " << alat.kode << endl;
            cout << "Jumlah: " << alat.jumlah << endl;
            cout << "Jenis: " << alat.jenis << endl;
            cout << "Status: " << (alat.tersedia ? "Tersedia" : "Dipinjam oleh " + alat.peminjam) << endl;
            cout << "--------------------\n";
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Peralatan dengan kata kunci '" << kataKunci << "' tidak ditemukan.\n";
    }
}

int main() {
    // Inisialisasi data awal
    inisialisasiData();

    // Input data mahasiswa
    cout << "Masukkan nama mahasiswa: ";
    getline(cin, nama_mahasiswa);
    cout << "Masukkan NIM: ";
    cin >> NIM;
    cin.ignore(); // Mengabaikan newline setelah input angka
    cout << "Masukkan program studi: ";
    getline(cin, prodi);

    // Menampilkan menu
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Lihat daftar peralatan\n";
        cout << "2. Cari peralatan\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Mengabaikan newline setelah input angka

        switch (pilihan) {
            case 1:
                lihatPeralatan();
                break;
            case 2:
                cariPeralatan();
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}  