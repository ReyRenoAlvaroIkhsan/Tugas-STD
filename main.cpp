#include "penerbangan.h"

using namespace std;

int main(){
    listpenumpang lp;
    listmaskapai lm;
    createlistpenumpang(lp);
    createlistmaskapai(lm);
    int Pilihan = 0, N;
    Pilihan = selectMenu();
    char answer;

    while (Pilihan != 0){
        switch(Pilihan){
        case 1:
            {
                maskapaiPR2 data;
                adr_maskapai p;
                cout<<"Jumlah Maskapai yang akan ditambahkan : ";
                cin>>N;
                cout<<endl;
                for(int i=1;i<=N;i++){
                    cout<<"Data Ke : "<< i <<endl;
                    cout<<"Masukkan data baru "<<endl;
                    cout<<"Masukkan Nama Maskapai : ";
                    cin.ignore();
                    getline(cin, data.jmaskapai);
                    cout<<"Masukkan Tanggal Penerbangan : ";
                    cin>>data.tanggal;
                    cout<<"Masukkan Tujuan Penerbangan : ";
                    cin>>data.tujuan;
                    data.nomaskapai = i;
                    p = createElementMaskapai(data);
                    insertFirstMaskapai(lm,p);
                    cout<<endl;
                }
            }
            break;
        case 2:
            {
                penumpangCH data2;
                adr_penumpang q;
                cout<<"Jumlah Penumpang yang akan ditambahkan : ";
                cin>>N;
                cout<<endl;
                for(int i=1;i<=N;i++){
                    cout<<"Data Ke : "<< i <<endl;
                    cout<<"Masukkan data baru "<<endl;
                    cout<<"Masukkan Nama : ";
                    cin.sync();
                    getline(cin, data2.nama);
                    cout<<"Masukkan Tempat,Tanggal Lahir : ";
                    cin.sync();
                    getline(cin, data2.ttl);
                    cout<<"Masukkan Jenis Kelamin : ";
                    cin>>data2.jk;
                    cout<<"Masukkan Umur : ";
                    cin.ignore();
                    cin>>data2.umur;
                    q = createElementPenumpang(data2);
                    insertFirstPenumpang(lp,q);
                    cout<<endl;
                }
            }
            break;
        case 3:
            printMaskapaiSaja(lm);
            break;
        case 4:
            printPenumpangSaja(lp);
            break;
        case 5:
            printMaskapaiDanPenumpang(lm);
            break;
        case 6:
            {
                string maskapai,nama;
                cout<<"Nama Maskapai : ";
                cin.ignore();
                getline(cin,maskapai);
                cout<<"Nama Penumpang : ";
                cin.sync();
                getline(cin, nama);
                connect(lm,lp,maskapai,nama);
                break;
            }
        case 7:
            {
                string maskapai,nama;
                cout<<"Nama Maskapai : ";
                cin.ignore();
                getline(cin,maskapai);
                cout<<"Nama Penumpang : ";
                cin.sync();
                getline(cin, nama);
                disconnect(lm,maskapai,nama);
                break;
            }
        case 8:
            {
                string maskapai;
                cout<<"Nama Maskapai: ";
                cin.ignore();
                getline(cin, maskapai);
                adr_maskapai p = searchMaskapai(lm,maskapai);
                if(p!=NULL)
                {
                    cout<<"Nama Maskapai : "<<info(p).jmaskapai<<endl;
                    cout<<"Tanggal Penerbangan : "<<info(p).tanggal<<endl;
                    cout<<"Tujuan Penerbangan : "<<info(p).tujuan<<endl;
                    cout<<"No Penerbangan : "<<info(p).nomaskapai<<endl;
                }else
                {
                    cout<<"Maskapai Tidak Ditemukan"<<endl;
                }


                break;
            }
        case 9:
            {
                string nama;
                cout<<"Nama Penumpang : ";
                cin.ignore();
                getline(cin, nama);
                adr_penumpang p = searchPenumpang(lp,nama);
                if(p!=NULL)
                {
                    cout<<"Nama : "<<info(p).nama<<endl;
                    cout<<"Tanggal Lahir : "<<info(p).ttl<<endl;
                    cout<<"Jenis Kelamin : "<<info(p).jk<<endl;
                    cout<<"Umur : "<<info(p).umur<<endl;
                }else
                {
                    cout<<"Penumpang Tidak Ditemukan"<<endl;
                }

                break;
            }
        case 10:
            {
                string maskapai;
                cout<<"Nama Maksapai : ";
                cin.ignore();
                getline(cin, maskapai);
                printPenumpangDariMaskapai(lm,maskapai);
                break;
            }
        case 11:
            {
                string maskapai;
                cout<<"Nama Maksapai : ";
                cin.ignore();
                getline(cin, maskapai);
                jumlahPenumpang(lm,maskapai);
                break;
            }
        case 12:
            {
                string maskapai;
                cout<<"Nama Maksapai : ";
                cin.ignore();
                getline(cin, maskapai);
                adr_maskapai p = searchMaskapai(lm,maskapai);
                delMaskapaiPenumpang(lm,lp,p);
                break;
            }
        case 13:
            {
                string maskapai,nama;
                cout<<"Nama Maskapai : ";
                cin.ignore();
                getline(cin, maskapai);
                cout<<"Nama Penumpang : ";
                cin.sync();
                getline(cin, nama);
                disconnectdel(lm,lp,maskapai,nama);
                break;
            }
        }
        cout<<endl;
        cout<<"Kembali ke menu utama? (Y/N) : ";
        cin>>answer;
        cout<<endl;
        system("CLS");
        if (answer == 'Y' || answer == 'y'){
            Pilihan = selectMenu();
        }else{
            break;
        }
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
