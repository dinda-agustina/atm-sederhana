#include <iostream>
using namespace std;

// Fungsi Login 
bool loginPIN(int pinBenar) {
    int pinInput;
    int kesempatan = 3;

    cout << "======== SELAMAT DATANG DI ATM NUSANTARA ========\n" << endl;
    while (kesempatan > 0) {
        cout << "Masukkan PIN: ";
        cin >> pinInput;

        if (pinInput == pinBenar) {
            cout << "Login Berhasil!\n" << endl;
            return true;
        } else {
            kesempatan--;
            cout << "PIN Salah! Coba Lagi, Sisa Kesempatan: " << kesempatan << endl;
        }
    }

    cout << "Akun Terblokir!" << endl;
    return false;
}

int main(){
    int pinATM = 2025;
}

// Ghina
// Update: Penambahan dokumentasi dan perbaikan format

// Fungsi untuk menampilkan saldo pengguna
void cekSaldo(int saldo) {
    cout << "Saldo Anda: Rp " << saldo << "\n" << endl;
}

// Fungsi untuk melakukan setor tunai ke saldo ATM
void setorTunai(int &saldo, string riwayat[], int &index) {
    int jumlah;
    cout << "Masukkan Jumlah Setor Tunai : ";
    cin >> jumlah;

    // Validasi input nominal
    if (jumlah <= 0) {
        cout << "Jumlah Tidak Boleh 0 atau Negatif!\n" << endl;
        return;
    }

    // Input harus kelipatan 10.000
    if (jumlah % 10000 != 0) {
        cout << "Setoran Harus Kelipatan Rp 10.000!\n" << endl;
        return;
    }

    // Proses menambahkan saldo dan menyimpan riwayat transaksi
    saldo += jumlah;
    riwayat[index++] = "Setor " + to_string(jumlah);

    cout << "Setor Tunai Berhasil!\n\n";
}

// =========================
// Fungsi Transfer Gina
// =========================
void transferUang(int &saldo, int daftarRekening[], int jumlahRek, 
                  string riwayat[], int &index) 
{
    int rekTujuan;
    int jumlah;

    cout << "Masukkan nomor rekening tujuan: ";
    cin >> rekTujuan;

    bool ditemukan = false;
    for (int i = 0; i < jumlahRek; i++) {
        if (rekTujuan == daftarRekening[i]) {
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Rekening tidak ditemukan!\n";
        return;
    }

    cout << "Masukkan jumlah transfer: ";
    cin >> jumlah;

    if (jumlah <= 0) {
        cout << "Jumlah tidak valid!\n";
        return;
    }

    if (jumlah > saldo) {
        cout << "Saldo tidak cukup!\n";
        return;
    }

    saldo -= jumlah;

    // Simpan ke riwayat transaksi
    riwayat[index++] = "Transfer " + to_string(jumlah) + " ke " + to_string(rekTujuan);

    cout << "Transfer berhasil! Anda mentransfer Rp" 
         << jumlah << " ke rekening " << rekTujuan << endl << endl;
}
