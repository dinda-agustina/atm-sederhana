#include <iostream>
using namespace std;

// ================================
// Fungsi LOGIN (PUNYA DINDA)
// ================================
bool loginPIN(int pinBenar) {
    int pinInput;
    int kesempatan = 3;

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


// ================================
// FUNGSI TRANSFER (PUNYA GINA)
// ================================
void transferUang(int &saldo, int daftarRekening[], int jumlahRek) {
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
    cout << "Transfer berhasil! Anda mentransfer Rp" << jumlah 
         << " ke rekening " << rekTujuan << endl;
}


// ================================
// PROGRAM UTAMA
// ================================
int main(){
    int pinATM = 2025;
    int saldo = 200000; // contoh saldo
    int rekeningLain[] = {111, 222, 333, 444}; // array rekening untuk transfer
    int jumlahRekening = 4;

    // login
    if (!loginPIN(pinATM)) {
        return 0; // keluar bila gagal login
    }

    int pilihan;
    do {
        cout << "\n===== MENU ATM =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Transfer\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:
                cout << "Saldo Anda: Rp" << saldo << endl;
                break;
            case 2:
                transferUang(saldo, rekeningLain, jumlahRekening);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan ATM.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 3);

    return 0;
}
