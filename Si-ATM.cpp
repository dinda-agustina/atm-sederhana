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

// Fungsi Tarik Tunai
void tarikTunai(int &saldo, string riwayat[], int &index) {
    int jumlah;
    cout << "Masukkan Jumlah Tarik: ";
    cin >> jumlah;

    if (jumlah <= 0) {
        cout << "Jumlah Tidak Boleh 0 atau Negatif!\n\n";
        return;
    }
    if (jumlah > saldo) {
        cout << "Saldo Tidak Mencukupi!\n\n";
        return;
    }
    if (jumlah < 20000) {
        cout << "Minimal Tarik Rp 20.000!\n\n";
        return;
    }

    saldo -= jumlah;
    riwayat[index++] = "Tarik " + to_string(jumlah);
    cout << "Tarik tunai Berhasil!\n\n";
}

// =========================
// Fungsi Transfer Gina
// =========================
void transferUang(int &saldo, int daftarRekening[], int jumlahRek, string riwayat[], int &index) 
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

    cout << "Transfer berhasil! Anda mentransfer Rp" << jumlah << " ke rekening " << rekTujuan << endl << endl;
}

// Fungsi Riwayat Transaksi
void tampilRiwayat(string riwayat[], int index) {
    cout << "\n=== RIWAYAT TRANSAKSI ===\n";
    if (index == 0) {
        cout << "Belum Ada Transaksi.\n\n";
        return;
    }

    for (int i = 0; i < index; i++) {
        cout << i + 1 << ". " << riwayat[i] << endl;
    }
    cout << endl;
}

int main(){
    int pinATM = 2025;
    int saldo[5] = {500000, 300000, 700000, 250000, 900000};
    int rekeningUser = 0;

    string riwayat[100];
    int indexRiwayat = 0;

    // Login
    if (!loginPIN(pinATM))
        return 0;

    int pilihan;
    
    do {
        cout << "===== MENU ATM Nusantara =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Tunai\n";
        cout << "3. Setor Tunai\n";
        cout << "4. Transfer Antar Rekening\n";
        cout << "5. Riwayat Transaksi\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                cekSaldo(saldo[rekeningUser]);
                break;

            case 2:
                tarikTunai(saldo[rekeningUser], riwayat, indexRiwayat);
                break;

            case 3:
                setorTunai(saldo[rekeningUser], riwayat, indexRiwayat);
                break;

            case 4:
                // 
                break;

            case 5:
                tampilRiwayat(riwayat, indexRiwayat);
                break;

            case 6:
                cout << "Terima Kasih Telah Menggunakan ATM Nusantara!\n";
                break;

            default:
                cout << "Menu Tidak Tersedia!\n\n";
        }

    } while (pilihan != 6);

    return 0;

}