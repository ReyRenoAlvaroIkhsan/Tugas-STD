#ifndef PENERBANGAN_H_INCLUDED
#define PENERBANGAN_H_INCLUDED
#include<iostream>
using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define nextt(p) (p)->nextt
#define nextpenumpang(p) (p)->nextpenumpang
#define prev(p) (p)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

struct penumpangCH{
    string nama,ttl,jk;
    int umur;
};

struct maskapaiPR2{
    string jmaskapai,tanggal,tujuan;
    int nomaskapai;
};

typedef struct elementpenumpang *adr_penumpang; //Parent 2 SLL
typedef struct elementtujuan *adr_tujuan;       //Child CSLL
typedef struct elementmaskapai *adr_maskapai;   //Parent 1 DLL

typedef struct penumpangCH infotypeCH; // Child CSLL
typedef struct maskapaiPR2 infotypePR2; // Parent 2

struct elementmaskapai{ //Parent 1
    maskapaiPR2 info;
    adr_maskapai next;
    adr_tujuan nextt;
    adr_maskapai prev;
};

struct elementtujuan{ //Child
    adr_tujuan next;
    adr_penumpang nextpenumpang;
};

struct elementpenumpang{ //Parent 2
    penumpangCH info;
    adr_penumpang next;
};

struct listtujuan{
    adr_tujuan first;
};

struct listpenumpang{
    adr_penumpang first;
};

struct listmaskapai{
    adr_maskapai first;
    adr_maskapai last;
};
    //create element
void createlistpenumpang(listpenumpang &lp);
void createlistmaskapai(listmaskapai &lm);
void createlisttujuan(listtujuan &lt);
adr_maskapai createElementMaskapai(maskapaiPR2 m);
adr_penumpang createElementPenumpang(penumpangCH x);
adr_tujuan createElementTujuan();

    //Search
adr_maskapai searchMaskapai(listmaskapai lm,string name);
adr_penumpang searchPenumpang(listpenumpang lp,string nama);
adr_tujuan searchTujuan(adr_maskapai t, string nama);

    //insert
void insertFirstMaskapai(listmaskapai &lm,adr_maskapai m);
void insertFirstPenumpang(listpenumpang &lp, adr_penumpang x);

    //Show Maskapai & Penumpang
void printMaskapaiSaja(listmaskapai lm);
void printPenumpangSaja(listpenumpang lp);
void printMaskapaiDanPenumpang(listmaskapai m);
void printPenumpangDariMaskapai(listmaskapai lm, string nama);
void showListMaskapai(listmaskapai lm);

    //Connect & Disconnect
void connect(listmaskapai &m, listpenumpang &p, string maskapai, string nama);
void disconnectdel(listmaskapai &lm,listpenumpang &lp,string maskapai, string nama);
void disconnect(listmaskapai &lm, string maskapai, string nama);

    //Delete
void deletepenumpang(listpenumpang &lp, string nama);
void deleteTujuan(adr_maskapai m, string nama);
void delMaskapaiPenumpang(listmaskapai &lm, listpenumpang &lp, adr_maskapai m);

    //Check & Jumlah
void jumlahPenumpang(listmaskapai lm,string nama);
void checkMaskapai(listmaskapai lm ,adr_maskapai &m);
void checkPenumpang(listpenumpang lp, adr_penumpang &p);
int selectMenu();
int menu();

#endif // PENERBANGAN_H_INCLUDED
