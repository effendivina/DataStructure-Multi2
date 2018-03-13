#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>

using namespace std;

#define nil NULL

struct mahasiswa{
    string NIM;
    string nama;
    string kelas;
    string doswal;
    string angkatan;
    float ipk;
};

struct jurusan{
    string namajurusan;
    string kodejurusan;
    string akreditasi;
    string kaprodi;
    string lokasi;
    string kodeinventaris;
};

typedef mahasiswa infotypeanak;
typedef jurusan infotypeinduk;
typedef struct elmlist_induk* adr_induk; //induk gunakan double linked list
typedef struct elmlist_anak* adr_anak; //anak gunakan single linked list

struct elmlist_anak{
    infotypeanak info_anak;
    adr_anak next_anak;
};

struct list_anak{
    adr_anak first_anak;
};

struct elmlist_induk{
    infotypeinduk info_induk;
    list_anak listanak;
    adr_induk next_induk;
    adr_induk prev_induk;
};

struct list_induk{
    adr_induk first_induk;
    adr_induk last_induk;
};

bool listempty_induk(list_induk l);
bool listempty_anak(list_anak l);

void createlist_induk(list_induk &l);
void createlist_anak(list_anak &listanak);

adr_induk alokasi_induk(infotypeinduk x);
adr_induk alokasi_induk_sort(adr_induk x);
adr_anak alokasi_anak(infotypeanak x);

void dealokasi_induk (adr_induk p);
void dealokasi_anak(adr_anak p);

adr_induk findelm_induk(list_induk l, infotypeinduk x);
bool fFindelm_induk(list_induk L, adr_induk p);
adr_induk findbefore_induk(list_induk l,adr_induk prec);

adr_anak findelm_anak(list_anak listanak,infotypeanak x);
bool fFindelm_anak(list_anak listanak,adr_anak p);
adr_anak findbefore_anak(list_anak listanak, infotypeanak x, adr_anak pec);

void insertfirst_induk(list_induk &l,adr_induk p);
void insertafter_induk(list_induk &l,adr_induk p, adr_induk prec);
void insertlast_induk(list_induk &l, adr_induk p);

void insertfirst_anak(list_anak &listanak,adr_anak p);
void insertafter_anak(list_anak &listanak,adr_anak p, adr_anak prec);
void insertlast_anak(list_anak &listanak, adr_anak p);

void deletefirst_induk(list_induk &l,adr_induk &p);
void deleteafter_induk(list_induk &l, adr_induk &p, adr_induk prec);
void deletelast_induk(list_induk &l, adr_induk &p);

void deletefirst_anak(list_anak &listanak,adr_anak &p);
void deleteafter_anak(list_anak &listanak, adr_anak &p, adr_anak prec);
void deletelast_anak(list_anak &listanak, adr_anak &p);

void printinfo_induk(list_induk l);
void printinfo_anak(list_anak listanak, list_induk l);

void SearchtoDeleteInduk(list_induk &l);
void SearchtoDeleteAnak(list_anak &listanak, list_induk &listinduk);
void SearchToEditInduk(list_induk &l);
void SearchToEditAnak(list_anak &listanak, list_induk &listinduk);
void SearchtoViewInduk (list_induk &jur);
void SearchtoViewAnak(list_anak &mhs, list_induk &jur);

void sorting_nama_induk(list_induk &l);
void sorting_kodeinventaris_induk(list_induk &l);
void sorting_lokasi_induk(list_induk &l);
void sorting_akreditasi_induk(list_induk &l);
void sorting_kaprodi_induk(list_induk &l);

void sorting_nama_anak(list_induk &l);
void sorting_ipk_anak(list_induk &l);
void sorting_kelas_anak(list_induk &l);
void sorting_doswal_anak(list_induk &l);
void sorting_angkatan_anak(list_induk &l);

void viewAll(list_induk &l, list_anak &listanak);

void menuinsert(list_induk &jur, list_anak &mhs);
void menudelete(list_induk &jur, list_anak &mhs);
void menuupdate(list_induk &jur, list_anak &mhs);
void menuview(list_induk &jur, list_anak &mhs);
void menusort(list_induk &jur, list_anak &mhs);
void menusearch (list_induk &jur, list_anak &mhs);

adr_induk cekinduk (list_induk &jur, infotypeinduk ii);
adr_anak cekanak (list_anak &mhs, infotypeanak ia);
adr_anak cekanak1 (list_anak &mhs, infotypeanak ia);

#endif // LINKEDLIST_H_INCLUDED
