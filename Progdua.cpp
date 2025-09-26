#include <iostream> //untuk input-output
#include <string> //untuk dapat menggunakan tipe data string
#include <algorithm> //untuk fungsi algoritma
#include <cctype> //untuk fungsi karakter

using namespace std; //untuk mempermudah menulis std::

void KS(string a){ //fungsi KS untuk memproses Kata Asli menjadi Kata Sandi
    if (a.empty()){ //mengecek apabila inputnya kosong
        cout << "Input Kosong" << endl;
        return;
    }
    string paw; //wadah untuk menyimpan Kata Sandi
    int ascii = int(a[0]); //nilai kode ASCII dari huruf pertama Kata Asli
    for(int i = a.length()-1; i >= 0; i--){ //loop untuk membalik urutan Kata Asli
        char huruf = tolower(a[i]); //diubah jadi huruf kecil untuk pengecekan
        if(huruf != 'a' && huruf != 'i' && huruf != 'u' && huruf != 'e' && huruf != 'o'){ //menyeleksi atau menghilangkan huruf vokal
            paw += a[i]; //huruf konsonan  dengan urutan yang sudah dibalik ditambahkan ke string paw  
        }
    }
    paw.insert(paw.length() - paw.length()/2, to_string(ascii)); //menyisipkan kode ASCII yang sudah didapat ke tengah string paw
    cout << "Kata sandi : " << paw << endl; //menampilkan hasil Kata Sandi
}

void KA(string a){ //fungsi KA untuk memproses Kata Sandi menjadi Kata Asli
    string rill; //wadah untuk menyimpan Kata Asli
    string ascii; //wadah buat konversi kode ASCII
    for(int i = 0; i < a.length(); i++){ //loop buat memisahkan huruf dan angka
        if(isdigit(a[i])){ //seleksi pemisahaan
            ascii += (a[i]); //jika angka masuk sini
        } else {
            rill += a[i]; //jika huruf masuk sini
        }
    }
    string rillbalik = "";//membalik urutan huruf
    for(int i = rill.length() - 1; i >= 0; i--){
        rillbalik += rill[i];
    }

    if(ascii.empty() != true){ //mengecek apakah string ascii kosong
        char huruf = char(stoi(ascii)); //jika tidak kosong maka angka diubah menjadi huruf konversinya
        if (huruf != rillbalik[0]){ //mengecek apakah huruf koversi kode ASCII sama dengan huruf pertama pada string rill
            rillbalik.insert(0, 1, huruf); //menyisipkan huruf ke urutan awal string rill
        }
    }
    cout << "Kerangka kata asli : " << rillbalik << endl; //menampilkan kerangka Kata Asli yang hanya berupa huruf konsonan dan huruf ke-1
}

int main(){ //fungsi utama
    cout << "Ingin mencari Kata Sandi (1) atau Kata Asli (2) ?" << endl; //menampilkan instruksi untuk memilih konversi 
    int opsi; //menyatakan inputan harus interger
    cin >> opsi; //tempat meng-input
    if(opsi == 1){ //jika inputnya angka 1
        cout << "Apa Kata Aslinya?";
        string kata_asli; //wadah kata inputan
        cin >> kata_asli; //input kata yang ingin diubah
        KS(kata_asli); //menjalankan fungsi KS
    } else if(opsi == 2){ //jika inputnya angka 2
        cout << "Apa Kata Sandinya?";
        string kata_sandi; //wadah kata inputan
        cin >> kata_sandi; //input kata yang ingin diubah
        KA(kata_sandi); //menjalankan fungsi KA
    } else {
        cout << "Pilihan tidak tersedia. \nSilakan pilih 1 atau 2";
    }
}
