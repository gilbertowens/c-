#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Biodata{
    string nik;
    string nama;
    string alamat;
};

void TampilanData(const vector <Biodata>& data){
    cout << "\nTampilan Data: " << endl;
    
    if (data.empty()){
        cout << "Belum ada data." << "\n\n";
        return;
    }
    
    for (size_t i = 0; i < data.size(); i++){
    cout << "Data ke- " << i + 1 << endl;
    cout << "NIK:            " << data[i].nik << endl;
    cout << "Nama:           " << data[i].nama << endl;
    cout << "Alamat:         " << data[i].alamat << endl;
    cout << "----------------\n\n";
    }
}

void TambahData(vector <Biodata>& data){
    cout << "\nTambah data:\n\n";
    Biodata bio;
    cout << "Masukkan NIK   :   ";
    cin >> bio.nik;
    //cin.ignore();
    cout << "Masukkan Nama  :   ";
    getline(cin, bio.nama);
    cout << "Masukkan Alamat:   ";
    getline(cin, bio.alamat);
    
    data.push_back(bio);
    cout << "Data Berhasil Ditambahkan.\n\n";
}

void EditData(vector <Biodata>& data){
    cout << "Edit data:\n\n";
    
    if(data.empty()){
        cout << "\nTidak ada data yang diedit.\n";
        return;
    }
    
    TampilanData(data);
    
    size_t x;
    
    cout << "Masukkan nomor data yang mau diedit: ";
    cin >> x;
    
    if (x < 1 || x > data.size()){
        cout << "Nomor data tidak valid.\n";
    }
    
    Biodata& ktp = data[x - 1];
    cin.ignore();
    cout << "Masukkan Nama Baru     (sebelumnya: " << ktp.nama << "): ";
    getline(cin, ktp.nama);
    cout << "Masukkan Alamat Baru   (sebelumnya: " << ktp.alamat << "): ";
    getline(cin, ktp.alamat);
    
    cout << "Data berhasil di edit.\n\n";
}

void HapusData(vector <Biodata>& data){
    cout << "Hapus data:\n";
    if(data.empty()){
        cout << "Tidak ada data yang dihapus.\n";
        return;
    }
    
    TampilanData(data);
    
    size_t index;
    
    cout << "Masukkan nomor data yang mau dihapus: ";
    cin >> index;
    
    if (index < 1 || index > data.size()){
        cout << "Nomor data tidak valid.\n";
        return;
    }
    
    data.erase(data.begin() + index - 1);
    cout << "Data Berhasil Dihapus.\n\n";
}

int main()
{
    
    vector<Biodata> myData;
    int pilihan;
    do{
        cout << "==================" << endl;
        cout << "1. Tampilan Data" << endl;
        cout << "2. Insert Data" << endl;
        cout << "3. Edit Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "==================" << endl;
        cout << "Masukkan pilihan anda: ";
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
        cout << "\nAnda telah keluar dari program\n" << endl;
        break;
        
        default:
        cout << "Pilihan tidak valid.\n";
    }
    
    } while(pilihan != 5);
    
    return 0;
}

