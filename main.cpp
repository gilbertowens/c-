/******************************************************************************

BIKIN PROGRAM CRUD (Create, Read, Update, Delete) TOKO:
1. Deklarasi variabel dalam struct
- nama_barang
- kuantitas
- harga
- total (kuantitas*harga)
2. Bikin program CRUD
3. Total akan otomatis tampil ketika telah menginputkan kuantitas dan harga

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Toko{
    string nama_barang;
    int kuantitas;
    int harga;
    int total;
};

void TampilanData(const vector<Toko> &data){
    cout << "\nTampilan Data:\n";
    
    if (data.empty()){
        cout << "\nBelum ada data\n";
        return;
    }
    
    
    
    // for(size_t i = 0; i < data.size(); i++){
    //     cout << "Data ke- " << i + 1 << endl;
    //     cout << "Nama Barang:       " << data[i].nama_barang << endl;
    //     cout << "Kuantitas:         " << data[i].kuantitas << endl;
    //     cout << "Harga barang (pcs):" << data[i].harga << endl;
    //     cout << "Harga Total:       " << data[i].total << endl;
    //     cout << "---------------------------------\n";
    // }
    
    //cout << "\nDaftar Barang:\n";
    cout << left << setw(5) << "ID"
         << setw(20) << "Nama Barang"
         << setw(10) << "Stok"
         << setw(15) << "Harga (Rp)"
         << setw(20) << "Total" << endl;
    cout << string(60, '-') << endl;

    for (const auto &Toko : data) {
        for(size_t i = 0; i < data.size(); i++){
            cout << left << setw(5) << i+1 
                 << setw(20) << data[i].nama_barang
                 << setw(10) << data[i].kuantitas
                 << setw(15) << data[i].harga
                 << setw(20) << data[i].total << endl;
        }
    }

}

void TambahData(vector<Toko>& data){
    cout << "\nMasukkan data: \n" << endl;
    Toko obj;
    
    cin.ignore();
    cout << "Masukkan nama barang       :   ";
    getline(cin, obj.nama_barang);
    //cin.ignore();
    cout << "Masukkan kuantitas barang  :   ";
    cin >> obj.kuantitas;
    cin.ignore();
    cout << "Masukkan harga barang(pcs) :   ";
    cin >> obj.harga;
    //cin.ignore();
    cout << "\n-------------------------------\n";
    
    obj.total = obj.kuantitas * obj.harga;
    
    data.push_back(obj);
    cout << "Data berhasil ditambahkan!\n\n";
}

void EditData(vector<Toko>& data){
    if(data.empty()){
        cout << "\nTidak ada data yang diedit!\n";
        return;
    }
    
    TampilanData(data);
    
    size_t nomor;
    
    cout << "\nMasukkan nomor data yang mau diganti   :   ";
    cin >> nomor;
    
    if (nomor < 1 || nomor > data.size()){
        cout << "Nomor yang anda masukkan tidak valid!";
        return;
    }
    
    Toko& stok = data [nomor - 1];
    
    cin.ignore();
    cout << "\nMasukkan kuantitas barang (sebelumnya  :   " << stok.kuantitas << ")   :   ";
    cin >> stok.kuantitas;
    cout << "Masukkan harga barang (sebelumnya      :   " << stok.harga << ")       :   ";
    cin >> stok.harga;
    //stok.total = stok.kuantitas*stok.harga;
    cout << "---------------------------------------------------------------------------\n";
    
    stok.total = stok.kuantitas * stok.harga;
    
    cout << "\nData berhasil diedit!\n";
}

void HapusData(vector <Toko>& data){
    if(data.empty()){
        cout << "\nTidak ada data yang bisa dihapus!\n";
        return;
    }
    
    size_t nomor;
    
    TampilanData(data);
    
    cout << "\nMasukkan nomor data yang mau dihapus: ";
    cin >> nomor;
    
    if(nomor < 1 || nomor > data.size()){
        cout << "\nNomor yang anda pilih tidak valid!\n";
        return;
    }
    
    data.erase(data.begin() + nomor - 1);
    cout << "\nData berhasil dihapus!\n";
}


int main()
{
    int pilihan;
    
    vector<Toko> myData;
    
    do{
        cout << "\nDaftar Menu Toko:\n";
        cout << "=================\n";
        cout << "1. Tampilan Data\n";
        cout << "2. Tambahkan Data\n";
        cout << "3. Edit Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "=================\n";
        cout << "\nMasukkan pilihan anda: ";
        cin >> pilihan;
        
        switch(pilihan){
            
            case 1:
            TampilanData(myData);
            break;
            
            case 2:
            TambahData(myData);
            break;
            
            case 3:
            EditData(myData);
            break;
            
            case 4:
            HapusData(myData);
            break;
            
            case 5:
            cout << "\nAnda telah keluar dari program\n";
            break;
            
            default:
            cout << "Pilihan anda tidak valid.\n";
        }
    }while (pilihan != 5);
    

    return 0;
}