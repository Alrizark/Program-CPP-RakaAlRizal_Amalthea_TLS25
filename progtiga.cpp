#include <iostream> //masukkan library
using namespace std; //agar tidak perlu mengetik std lagi tiap baris

int main(){ //aksi
    
    cout << "Detik ke Berapa ? " << endl; //intruksi untuk inputan
    int t; //menyatakan bahwa inputan bentuknya interger
    cin >> t; //tempat meng-input
    int x = (t-24)%103; //menghitung warna siklus
    if (1 <= x && x <= 20){
        cout << "Lampu Hijau" << endl; //output hijau
    } else if (21 <= x && x <= 23){
        cout << "Lampu Kuning" << endl; //output kuning
    } else {
        cout << "Lampu Merah" << endl; //output merah
    }
    return 0; //selesai
}
