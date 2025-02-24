#include <iostream>
#include <string>
using namespace std;

string rakBuku[3][10];

string kategoriBuku[3] = {
    "Fiksi",
    "Non-Fiksi",
    "Referensi"
};

struct Anggota {
    string 
        nama, 
        idAnggota, 
        alamat;
};

struct Buku {
    string 
        kategoriBuku, 
        judulBuku, 
        penulis, 
        metodePeminjaman;
};

Buku buku;
Anggota anggota;


void lihatStatusBuku();
void inputDataBuku();
void inputDataAnggota();
void tampilkanKategoriBuku();
void resetData();
void pinjamBuku();

int main() {
    int pilihan;
    do {
        cout << "\n=== Menu Utama Perpustakaan ===" << endl;
        cout << "1. Pinjam Buku" << endl;
        cout << "2. Lihat Status Buku" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1 :
                pinjamBuku();
                break;
            
            case 2 :
                lihatStatusBuku();
                break;
            
            case 3 :
                cout << "Terima kasih telah menggunakan layanan perpustakaan kami!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
                break;
        }

    } while (pilihan != 3);

    return 0;
}

void pinjamBuku() {
    inputDataBuku();
    inputDataAnggota();
}

void lihatStatusBuku() {
    cout << "\n=== Status Buku ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Rak Buku " << i + 1 << ":" << endl;
        for (int j = 0; j < 10; j++) {
            cout << " Buku " << j + 1 << ": ";
            if (rakBuku[i][j].empty()) {
                cout << "Tersedia" << endl;
            } else {
                cout << "Dipinjam oleh " << rakBuku[i][j] << endl;
            }
        }

        cout << endl;
    }
    cout << "====================" << endl;
}

void inputDataBuku() {
    int pilih;
    
    cout << "\nPilih kategori buku: " << endl;
    tampilkanKategoriBuku();
    cout << "Pilihan    : ";
    cin >> pilih;
    cin.ignore();
    cout << endl;

    switch (pilih) {
        case 1:
            buku.kategoriBuku = kategoriBuku[0];
            break;
        case 2:
            buku.kategoriBuku = kategoriBuku[1];
            break;
        case 3:
            buku.kategoriBuku = kategoriBuku[2];
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return;
    }

    cout << "\nMasukkan judul buku: ";
    getline(cin, buku.judulBuku);

    cout << "Masukkan penulis buku: ";
    getline(cin, buku.penulis);
}

void inputDataAnggota() {
    resetData();   

    cout << "\nInputkan data diri Anda: " << endl;
    cout << "Nama   : ";
    getline(cin, anggota.nama);
    cout << "ID Anggota : ";
    getline(cin, anggota.idAnggota);
    cout << "Alamat : ";
    getline(cin, anggota.alamat);

    int pilihan;
    bool bukuDitemukan = false;

    cout << "\nPilih metode peminjaman : "<<endl;
    cout << "1. Pilih buku sendiri"<<endl;
    cout << "2. Biarkan sistem memilihkan buku"<<endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1 :
            int rak, nomorBuku;

            do {
                cout << "\nPilih rak buku (1-3): ";
                cin >> rak;
                cout << "Pilih nomor buku (1-10): ";
                cin >> nomorBuku;
                cin.ignore();

                if (rak < 1 || rak > 3 || nomorBuku < 1 || nomorBuku > 10) {
                    cout << "Pilihan rak atau buku tidak valid!" << endl;
                    
                }
            } while (rak < 1  || rak > 3 || nomorBuku < 1 || nomorBuku > 10);

            
            if (rakBuku[rak - 1][nomorBuku - 1].empty()) {
                rakBuku[rak - 1][nomorBuku - 1] = anggota.nama;
                cout << "Buku berhasil dipinjam!" << endl;
            } else {
                cout << "Maaf, buku sudah dipinjam." << endl;
            }

            break;

        
        case 2 :
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 10; j++) {
                    if (rakBuku[i][j].empty()) {
                        rakBuku[i][j] = anggota.nama;
                        cout    << "Buku dipilihkan oleh sistem: Rak " << i + 1 
                                << ", Buku " << j +1 <<endl;
                        
                        bukuDitemukan = true;
                        break;
                    }
                }

                if (bukuDitemukan) { break;}            
            }

            if (!bukuDitemukan) { 
                cout << "Maaf, tidak ada buku tersedia. Apakah Anda ingin mencoba lagi (Y/y)" << endl; 
                
                char cobaLagi;

                cin >> cobaLagi;
                cin.ignore();

                if (cobaLagi == 'Y' || cobaLagi == 'y') {
                    pinjamBuku(); // Coba lagi
                } else {
                    cout << "Peminjaman dibatalkan. " << endl;
                }
            }
            
            break;

        default :
            cout << "Pilihan tidak valid!"<< endl;
            break;
    }
}

 
void resetData(){
    anggota = Anggota();    
    buku = Buku();          
}

void tampilkanKategoriBuku() {
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << kategoriBuku[i] << endl;
    }
}
