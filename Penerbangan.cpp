#include "penerbangan.h"

//create list maskapai,penumpang dan tujuan
void createlistmaskapai(listmaskapai &lm){
    first(lm)= NULL;
}

void createlistpenumpang(listpenumpang &lp){
    first(lp)=NULL;
}

void createlisttujuan(listtujuan &lt){
    first(lt)=NULL;
}


//create element maskapai, penumpang dan tujuan
adr_maskapai createElementMaskapai(maskapaiPR2 m){
    adr_maskapai p = new elementmaskapai;
    info(p) = m;
    next(p) = NULL;
    nextt(p)= NULL;
    prev(p) = NULL;
    return p;
}

adr_penumpang createElementPenumpang(penumpangCH x){
    adr_penumpang p=new elementpenumpang;
    info(p) =x;
    next(p)=NULL;
    return p;
}

adr_tujuan createElementTujuan(){
    adr_tujuan p= new elementtujuan;
    nextpenumpang(p) = NULL;
    next(p) = NULL;
    return p;
}


//insert maskapai DLL
void insertFirstMaskapai(listmaskapai &lm, adr_maskapai m){
    if(first(lm)==NULL){    //Element kosong
        first(lm)=m;
        last(lm)=m;
    }else{                  //Element tidak kosong
        next(m)=first(lm);
        prev(first(lm))=m;
        first(lm)=m;
    }
}

//show maskapai
void showListMaskapai(listmaskapai lm){
    adr_maskapai p=first(lm);
    while(p!=NULL){
        cout<<"Maskapai : "<<info(p).jmaskapai<<endl;
        cout<<"Tanggal : "<< info(p).tanggal<<endl;
        cout<<"Tujuan : "<<info(p).tujuan<<endl;
        cout<<"No Maskapai : "<<info(p).nomaskapai<<endl;
        cout<<endl;
        p=next(p);
    }
}

//Hapus data maskapai beserta penumpang (12)
void delMaskapaiPenumpang(listmaskapai &lm, listpenumpang &lp, adr_maskapai m){
    if(first(lm)==NULL){                                                        //List kosong
        cout<<"Maskapai tidak ditemukan"<<endl;
    }else{
        adr_tujuan x = nextt(m);
        string nama;
        while(x!=NULL){
            nama = info(nextpenumpang(x)).nama;
            deletepenumpang(lp,nama);
            adr_maskapai y = first(lm);
            while(y!=NULL){
                disconnect(lm,info(y).jmaskapai,nama);
                y = next(y);
            }
            x = nextt(m);
        }
        nextt(m) = NULL;
        if(m==first(lm)){
            first(lm) = next(first(lm));
            next(m) = NULL;

        }else if(m==last(lm)){
            last(lm) = prev(last(lm));
            next(m) = NULL;
            next(last(lm)) = NULL;
        }else{
            adr_maskapai r = prev(m);
            next(r) = next(m);
            next(m) = NULL;
        }

    }

}

//search maskapai
adr_maskapai searchMaskapai(listmaskapai lm,string name){
    adr_maskapai p = first(lm);
    while(p != NULL){
        if(info(p).jmaskapai == name)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;

}

//search penumpang
adr_penumpang searchPenumpang(listpenumpang lp,string nama){
    adr_penumpang p = first(lp);
    while(p != NULL){
        if(info(p).nama == nama)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}


//insert penumpang
void insertFirstPenumpang(listpenumpang &lp, adr_penumpang p){
    if(first(lp) == NULL){
        first(lp) = p;
    }else{
        next(p) = first(lp);
        first(lp) = p;
    }
}


//connect
void connect(listmaskapai &lm, listpenumpang &lp, string maskapai, string nama){
    adr_tujuan r = createElementTujuan();
    adr_maskapai s = searchMaskapai(lm,maskapai);
    checkMaskapai(lm,s);
    adr_penumpang p = searchPenumpang(lp,nama);
    checkPenumpang(lp,p);
    if (nextt(s) == NULL )       //Belum mempunyai sambungan
    {
        nextt(s) = r;
        next(r) = nextt(s);
        nextpenumpang(r) = p;

        cout<<"Berhasil Menghubungkan Penumpang "<<nama<<" Dengan Maskapai "<< maskapai;
    }else{                       //Sudah mempunyai sambungan
        adr_tujuan q = nextt(s);
        while(next(q) != nextt(s)){
            q = next(q);
        }
        next(q) = r;
        next(r) = nextt(s);

        nextpenumpang(r) = p;
        cout<<"Berhasil Menghubungkan Penumpang "<<nama<<" Dengan Maskapai "<<maskapai;
    }
}

//print maskapai + penumpang
void printMaskapaiDanPenumpang(listmaskapai lm){
    adr_maskapai p = first(lm);
    adr_tujuan q;
    while (p != NULL){
        cout<<"===================== Maskapai ====================="<<endl;
        cout<<"Nama : "<<info(p).jmaskapai<<endl;
        cout<<"Tanggal Penerbangan : "<<info(p).tanggal<<endl;
        cout<<"Tujuan : "<<info(p).tujuan<<endl;
        cout<<"No Maskapai : "<<info(p).nomaskapai<<endl;
        cout<<"===================== Penumpang ======================"<<endl;
        if(nextt(p)!=NULL){
            q = nextt(p);
            while(next(q) != nextt(p)){
                cout<<"Nama: "<<info(nextpenumpang(q)).nama<<endl;
                cout<<"Tanggal Lahir : "<<info(nextpenumpang(q)).ttl<<endl;
                cout<<"Umur : "<<info(nextpenumpang(q)).umur<<endl;
                cout<<"Jenis Kelamin : "<<info(nextpenumpang(q)).jk<<endl;
                cout<<endl;
                q = next(q);
            }
            cout<<"Nama: "<<info(nextpenumpang(q)).nama<<endl;
            cout<<"Tanggal Lahir : "<<info(nextpenumpang(q)).ttl<<endl;
            cout<<"Umur : "<<info(nextpenumpang(q)).umur<<endl;
            cout<<"Jenis Kelamin : "<<info(nextpenumpang(q)).jk<<endl;
            cout<<endl;
        }else{
            cout<<"-"<<endl;
        }
        cout<<"==============================================="<<endl;
        cout<<endl;
        cout<<endl;
        p = next(p);
    }
}

//print data penumpang dalam maskapai
void printPenumpangDariMaskapai(listmaskapai lm, string nama){
    adr_maskapai p = searchMaskapai(lm,nama);
    checkMaskapai(lm,p);
    if(p == NULL){
        cout<<"Nama Maskapai tidak ditemukan"<<endl;
    }else{
        adr_tujuan q = nextt(p);
        if(q==NULL){
            cout<<"Maskapai Tidak Memiliki Penumpang"<<endl;
        }else{
            int x = 1;
            while(next(q)!=nextt(p)){
                cout<<"====================Penumpang "<<x<<"====================="<<endl;
                cout<<"Nama : "<<info(nextpenumpang(q)).nama<<endl;
                cout<<"Tanggal Lahir : "<<info(nextpenumpang(q)).ttl<<endl;
                cout<<"Umur : "<<info(nextpenumpang(q)).umur<<endl;
                cout<<"Jenis Kelamin : "<<info(nextpenumpang(q)).jk<<endl;
                q = next(q);
                x++;
                cout<<endl;
            }
            cout<<"====================Penumpang "<<x<<"====================="<<endl;
            cout<<"Nama : "<<info(nextpenumpang(q)).nama<<endl;
            cout<<"Tanggal Lahir : "<<info(nextpenumpang(q)).ttl<<endl;
            cout<<"Umur : "<<info(nextpenumpang(q)).umur<<endl;
            cout<<"Jenis Kelamin : "<<info(nextpenumpang(q)).jk<<endl;

            cout<<"==============================================="<<endl;
        }
    }
}

void disconnect(listmaskapai &lm, string maskapai, string nama){
    adr_maskapai p = searchMaskapai(lm,maskapai);
    checkMaskapai(lm,p);
    adr_tujuan q = searchTujuan(p,nama);
    if(q!=NULL){
        nextpenumpang(q)=NULL;
        if(nextt(p)==q){
            if(next(nextt(p))==NULL){
                nextt(p)=NULL;
            }else{
                adr_tujuan r = nextt(p);
                while(next(r) != nextt(p))
                {
                    r = next(r);
                }
                q = nextt(p);
                nextt(p)= next(nextt(p));
                next(r) = nextt(p);
                next(q) = NULL;
            }
        }else if(next(q)==nextt(p)){
            adr_tujuan r = nextt(p);
            while(next(next(r)) != nextt(p)){
                r = next(r);
            }
            q = next(r);
            next(r) = nextt(p);
            next(q) = NULL;
        }else{
            adr_tujuan r = nextt(p);
            while(next(r) != q){
                r = next(r);
            }
            next(r) = next(q);
        }
    }
}

//disconnect+delete penumpang
void disconnectdel(listmaskapai &lm,listpenumpang &lp,string maskapai, string nama){
    adr_maskapai p = searchMaskapai(lm,maskapai);
    checkMaskapai(lm,p);
    deletepenumpang(lp,nama);
    adr_tujuan q = searchTujuan(p,nama);
    adr_maskapai y = first(lm);
    while(y!=NULL){
        disconnect(lm,info(y).jmaskapai,nama);
        y = next(y);
    }
    nextpenumpang(q)=NULL;
}


//tampilkan jumlah penumpang dari maskapai
void jumlahPenumpang(listmaskapai lm,string nama){
    adr_maskapai p = searchMaskapai(lm,nama);
    checkMaskapai(lm,p);
    adr_tujuan q = nextt(p);
    int i = 0;
    if(nextt(p)!=NULL)
    {
        while(next(q)!=nextt(p)){
        i++;
        q = next(q);
        }
    }i=i+1;
    cout<<"Maskapai "<<nama<<" terdiri dari "<<i<<" Penumpang"<<endl;
}

//select menu
int selectMenu(){
    cout<<"================================MENU=================================="<<endl;
    cout<<"| 1. Menambah data Maskapai baru ke list                             |"<<endl;
    cout<<"| 2. Menambah data Penumpang baru ke list                            |"<<endl;
    cout<<"| 3. Menampilkan semua data Maskapai                                 |"<<endl;
    cout<<"| 4. Menampilkan semua data Penumpang                                |"<<endl;
    cout<<"| 5. Menampilkan semua data Maskapai beserta Penumpang               |"<<endl;
    cout<<"| 6. Menghubungkan Maskapai dan Penumpang                            |"<<endl;
    cout<<"| 7. Memutuskan Maskapai dan seorang Penumpang                       |"<<endl;
    cout<<"| 8. Mencari Data Maskapai                                           |"<<endl;
    cout<<"| 9. Mencari Data Penumpang                                          |"<<endl;
    cout<<"| 10. Menampilkan Data semua Penumpang yang dalam suatu Maskapai     |"<<endl;
    cout<<"| 11. Menampilkan jumlah penumpang dalam suatu Maskapai              |"<<endl;
    cout<<"| 12. Menghapus data Maskapai beserta Penumpang                      |"<<endl;
    cout<<"| 13. Menghapus Penumpang dalam suatu Maskapai                       |"<<endl;
    cout<<"| 0. Exit                                                            |"<<endl;
    cout<<"======================================================================"<<endl;
    cout<<"Masukkan menu : ";
    int input = 0;
    cin >> input;
    return input;
}



//================================== extra =============================================================================
void deletepenumpang(listpenumpang &lp, string nama){
adr_penumpang q = searchPenumpang(lp,nama);
    checkPenumpang(lp,q);
    if(q==first(lp)){
        first(lp) = next(q);
        next(q) = NULL;
    }else{
        adr_penumpang y = first(lp);
        while(next(y)!=q){
            y = next(y);
        }
        if(next(q)==NULL){
            next(y) = NULL;
        }else{
            next(y) = next(q);
            next(q) = NULL;
        }
    }
}

adr_tujuan searchTujuan(adr_maskapai t, string nama){
    adr_tujuan p = nextt(t);
    do{
        if(info(nextpenumpang(p)).nama == nama)
        {
            return p;
        }
        p = next(p);
    } while(next(p)!=nextt(t));
    if(info(nextpenumpang(p)).nama == nama)
    {
        return p;
    }
    return NULL;
}

void deleteTujuan(adr_maskapai m, string nama){
    adr_tujuan p = searchTujuan(m,nama);
    if(p==NULL){
        cout<<"Maskapai tidak memiliki Penumpang"<<endl;
    }else{
        nextpenumpang(p) = NULL;
        adr_tujuan s = nextt(m);
        while(next(s)!=p){
            s = next(s);
        }
        next(s) = nextt(m);
    }
}

void checkMaskapai(listmaskapai lm ,adr_maskapai &m){
    string nama;
    while(m==NULL){
        cout<<"Maskapai Tidak Ditemukan Masukkan kembali"<<endl;
        cout<<"Nama Maskapai : ";
        cin.ignore();
        getline(cin, nama);
        m = searchMaskapai(lm,nama);
    }
}

void checkPenumpang(listpenumpang lp, adr_penumpang &p){
    string nama;
    while(p==NULL){
        cout<<"Nama Penumpang Tidak Ditemukan Masukkan kembali"<<endl;
        cout<<"Nama Penumpang : ";
        cin.ignore();
        getline(cin, nama);
        p = searchPenumpang(lp,nama);
    }
}

//=========================================================================================================
void printMaskapaiSaja(listmaskapai lm){
    adr_maskapai p = first(lm);
    while(p != NULL){
        cout<<"===================== Maskapai ====================="<<endl;
        cout<<"Nama : "<<info(p).jmaskapai<<endl;
        cout<<"Tanggal Penerbangan : "<<info(p).tanggal<<endl;
        cout<<"Tujuan : "<<info(p).tujuan<<endl;
        cout<<"No Maskapai : "<<info(p).nomaskapai<<endl;
        p=next(p);
    }
}

void printPenumpangSaja(listpenumpang lp){
    if(first(lp)!=NULL)
    {
        adr_penumpang q = first(lp);
        while(q != NULL){
            cout<<"==================== Penumpang ====================="<<endl;
            cout<<"Nama : "<<info(q).nama<<endl;
            cout<<"Tanggal Lahir : "<<info(q).ttl<<endl;
            cout<<"Umur : "<<info(q).umur<<endl;
            cout<<"Jenis Kelamin : "<<info(q).jk<<endl;
            q = next(q);
        }
    }
    else
    {
        cout<<"Tidak Ada Penumpang"<<endl;
    }
}
