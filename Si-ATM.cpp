#include <iostream>
using namespace std;

// Fungsi Login 
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

int main(){
    int pinATM = 2025;
    return 0;
}

