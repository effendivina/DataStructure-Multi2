#include <iostream>
#include "LinkedList.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

void SearchToEditInduk(list_induk &l)
{
    char input [100];
    adr_induk ai;
    infotypeinduk cari;
    infotypeinduk ii;
    int pilih;

    cout<<"Masukkan kode jurusan yang akan diedit: ";
    cin>>cari.kodejurusan;
    ai = findelm_induk(l,cari);
    if(ai != NULL )
    {
        cout<<"Apakah ingin menghapus data ini? "<<endl;
        cout<< "Kode Jurusan: " << ai->info_induk.kodejurusan<<endl;
        cout<<"Nama Jurusan: " << ai->info_induk.namajurusan<<endl;
        cout<<"Akreditasi Jurusan: "<<ai->info_induk.akreditasi<<endl;
        cout<<"Nama Kepala Program Studi: "<<ai->info_induk.kaprodi<<endl;
        cout<<"Lokasi Gedung: "<<ai->info_induk.lokasi<<endl;
        cout<<"Kode Inventaris: "<<ai->info_induk.kodeinventaris<<endl;
        cout<<"1. Ya"<<endl;
        cout<<"2. Tidak"<<endl;
        cin>>pilih;
        if(pilih == 1)
        {
                cout<<"MASUKKAN DATA TERBARU"<<endl;
                cout<<" Kode Jurusan : ";
                cin>>ii.kodejurusan;
                ai->info_induk.kodejurusan = ii.kodejurusan;
                cout<<" Nama Jurusan : ";
                cin.ignore();
                cin.getline(input,100);
                ii.namajurusan = input;
                ai->info_induk.namajurusan = ii.namajurusan;
                cout<<" Akreditasi Jurusan : ";
                cin>>ii.akreditasi;
                ai->info_induk.akreditasi = ii.akreditasi;
                cout<<" Nama Kaprodi : ";
                cin.ignore();
                cin.getline(input,100);
                ii.kaprodi = input;
                ai->info_induk.kaprodi = ii.kaprodi;
                cout<<" Lokasi Gedung : ";
                //cin.ignore();
                cin.getline(input,100);
                ii.lokasi = input;
                ai->info_induk.lokasi = ii.lokasi;
                cout<<" Kode Inventaris : ";
                cin>>ii.kodeinventaris;
                ai->info_induk.kodeinventaris = ii.kodeinventaris;
                cout<<"============ data jurusan telah diedit ============"<<endl;
                cout<<"============   tekan 0 untuk kembali    ============"<<endl;
        }
        else{
        cout<<"============ data jurusan batal dihapus ============"<<endl;
        cout<<"============   tekan 0 untuk kembali    ============"<<endl;
        }
    }else{
    cout<<"=========== data jurusan tidak ditemukan ============"<<endl;
    cout<<"===========    tekan 0 untuk kembali     ==========="<<endl;
    }
}

void SearchToEditAnak(list_anak &mhs, list_induk &jur)
{
    char input[100];
    adr_anak aa;
    adr_induk ai;
    infotypeinduk ii;
    infotypeanak ia;
    int pilih;

cout<<" Masukkan Kode Jurusan : ";
    cin>>ii.kodejurusan;
    ai = findelm_induk(jur,ii);
    if (ai == NULL){
        cout<<"=== kode jurusan tidak ditemukan ==="<<endl;
        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
    }
    else {
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#         Edit  Mahasiswa        #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"Masukkan NIM yang akan diedit: ";
        cin>>ia.NIM;
        aa = findelm_anak(ai->listanak,ia);
        if(aa != NULL )
        {
            cout<<"Apakah ingin menghapus data ini? "<<endl;
            cout<<"NIM: " << aa->info_anak.NIM<<endl;
            cout<<"Nama Mahasiswa: " << aa->info_anak.nama<<endl;
            cout<<"Kelas: "<<aa->info_anak.kelas<<endl;
            cout<<"IPK Mahasiswa: "<<aa->info_anak.ipk<<endl;
            cout<<"Dosen Wali: "<<aa->info_anak.doswal<<endl;
            cout<<"Angkatan: "<<aa->info_anak.angkatan<<endl;
            cout<<"1. Ya"<<endl;
            cout<<"2. Tidak"<<endl;
            cin>>pilih;
            if(pilih == 1)
            {
                cout<<" NIM Mahasiswa  : ";
                cin>>ia.NIM;
                aa->info_anak.NIM = ia.NIM;
                cout<<" Nama Mahasiswa : ";
                cin.ignore();
                cin.getline(input,100);
                ia.nama = input;
                aa->info_anak.nama = ia.nama;
                cout<<" Kelas Mahasiswa : ";
                //cin.ignore();
                cin.getline(input,100);
                ia.kelas = input;
                aa->info_anak.kelas = ia.kelas;
                cout<<" IPK Mahasiswa : ";
                cin>>ia.ipk;
                aa->info_anak.ipk = ia.ipk;
                cout<<" Nama Dosen Wali : ";
                cin.ignore();
                cin.getline(input,100);
                ia.doswal = input;
                aa->info_anak.doswal = ia.doswal;
                cout<<" Angkatan : ";
                cin>>ia.angkatan;
                aa->info_anak.doswal = ia.doswal;
                cout<<"============ data mahasiswa telah dihapus ============"<<endl;
                cout<<"============     tekan 0 untuk kembali    =========="<<endl;
            }
            else{
            cout<<"============ data mahasiswa batal dihapus ============"<<endl;
            cout<<"============     tekan 0 untuk kembali    =========="<<endl;
            }
        }else{
            cout<<"=========== data mahasiswa tidak ditemukan ============"<<endl;
            cout<<"===========      tekan 0 untuk kembali     ========="<<endl;
        }
    }
}

void SearchtoDeleteInduk(list_induk &l)
{
    adr_induk temp;
    infotypeinduk cari;
    int pilih;
    cout<<"Masukkan kode jurusan yang akan dihapus: ";
    cin>>cari.kodejurusan;
    temp = findelm_induk(l,cari);
    if(temp != NULL )
    {
        cout<<"Apakah ingin menghapus data ini? "<<endl;
        cout<< "Kode Jurusan: " << temp->info_induk.kodejurusan<<endl;
        cout<<"Nama Jurusan: " << temp->info_induk.namajurusan<<endl;
        cout<<"Akreditasi Jurusan: "<<temp->info_induk.akreditasi<<endl;
        cout<<"Nama Kepala Program Studi: "<<temp->info_induk.kaprodi<<endl;
        cout<<"Lokasi Gedung: "<<temp->info_induk.lokasi<<endl;
        cout<<"Kode Inventaris: "<<temp->info_induk.kodeinventaris<<endl;
        cout<<"1. Ya"<<endl;
        cout<<"2. Tidak"<<endl;
        cin>>pilih;
        if(pilih == 1)
        {
                if(temp == l.first_induk)
                    deletefirst_induk(l,temp);
                else if(temp == l.last_induk)
                    deletelast_induk(l,temp);
                else if(temp != l.first_induk && temp != l.last_induk)
                    deleteafter_induk(l,temp,temp-1);
                cout<<"============ data jurusan telah dihapus ============"<<endl;
                cout<<"============   tekan 0 untuk kembali    ============"<<endl;
        }
        else{
        cout<<"============ data jurusan batal dihapus ============"<<endl;
        cout<<"============   tekan 0 untuk kembali    ============"<<endl;
        }
    }else{
    cout<<"=========== data jurusan tidak ditemukan ============"<<endl;
    cout<<"===========    tekan 0 untuk kembali     ==========="<<endl;
    }
}

void SearchtoDeleteAnak(list_anak &mhs, list_induk &jur)
{
    adr_anak aa;
    adr_induk ai;
    infotypeinduk ii;
    infotypeanak ia;
    int pilih;

    cout<<" Masukkan Kode Jurusan : ";
    cin>>ii.kodejurusan;
    ai = findelm_induk(jur,ii);
    if (ai == NULL){
        cout<<"=== kode jurusan tidak ditemukan ==="<<endl;
        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
    }
    else {
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#         Hapus Mahasiswa        #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"Masukkan NIM yang akan dihapus: ";
        cin>>ia.NIM;
        aa = findelm_anak(ai->listanak,ia);
        if(aa != NULL )
        {
            cout<<"Apakah ingin menghapus data ini? "<<endl;
            cout<<"NIM: " << aa->info_anak.NIM<<endl;
            cout<<"Nama Mahasiswa: " << aa->info_anak.nama<<endl;
            cout<<"Kelas: "<<aa->info_anak.kelas<<endl;
            cout<<"IPK Mahasiswa: "<<aa->info_anak.ipk<<endl;
            cout<<"Dosen Wali: "<<aa->info_anak.doswal<<endl;
            cout<<"Angkatan: "<<aa->info_anak.angkatan<<endl;
            cout<<"1. Ya"<<endl;
            cout<<"2. Tidak"<<endl;
            cin>>pilih;
            if(pilih == 1)
            {
                if(aa == mhs.first_anak)
                    deletefirst_anak(mhs,aa);
                else if(aa->next_anak == nil)
                    deletelast_anak(mhs,aa);
                else if(aa != mhs.first_anak && aa->next_anak != nil)
                    deleteafter_anak(mhs,aa,aa-1);
                cout<<"============ data mahasiswa telah dihapus ============"<<endl;
                cout<<"============     tekan 0 untuk kembali    =========="<<endl;
            }
            else{
            cout<<"============ data mahasiswa batal dihapus ============"<<endl;
            cout<<"============     tekan 0 untuk kembali    =========="<<endl;
            }
        }else{
            cout<<"=========== data mahasiswa tidak ditemukan ============"<<endl;
            cout<<"===========      tekan 0 untuk kembali     ========="<<endl;
        }
    }
}

void viewAll(list_induk &l, list_anak &listanak)
{
    adr_induk p = l.first_induk;
    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#           SEMUA DATA           #"<<endl;
    cout<<"#================================#"<<endl;
    while (p!=NULL)
    {
        cout<<"----------INFORMASI JURUSAN------------"<<endl;
        cout<<"Kode Jurusan: "<<p->info_induk.kodejurusan<<endl;
        cout<<"Nama Jurusan: "<<p->info_induk.namajurusan<<endl;
        adr_anak q = (p)->listanak.first_anak;
        while (q!=NULL)
        {
            cout<<"-------------------INFORMASI MAHASISWA---------------"<<endl;
            cout<<"NIM: "<<(q)->info_anak.NIM<<endl;
            cout<<"Nama Mahasiswa: "<<(q)->info_anak.nama<<endl;
            cout<<"Kelas: "<<(q)->info_anak.kelas<<endl;
            q = (q)->next_anak;
        }
        p = (p)->next_induk;
    }
}

void sorting_nama_induk(list_induk &l)
{
    adr_induk p,q,m;
    list_induk l2;
    createlist_induk(l2);
    p = l.first_induk;
    while(p!=NULL){
        q=alokasi_induk_sort(p);
        if(l2.first_induk == NULL)
            insertfirst_induk(l2,q);
        else
        {
            m = l2.first_induk;
            while (m->info_induk.namajurusan< p->info_induk.namajurusan && m->next_induk != NULL)
            {
                m = m->next_induk;
            }
            if(l2.first_induk->next_induk == NULL)
            {
                if(l2.first_induk->info_induk.namajurusan>q->info_induk.namajurusan)
                {
                    insertfirst_induk(l2,q);
                }
                else
                    insertlast_induk(l2,q);
            }
            else
            {
                if (m==l2.first_induk)
                {
                    insertfirst_induk(l2,q);
                }
                else if(m==l2.last_induk && m->info_induk.namajurusan < q->info_induk.namajurusan)
                {
                    insertlast_induk(l2,q);
                }
                else
                    insertafter_induk(l2,q,m->prev_induk);
            }
        }
        p=p->next_induk;
    }
    printinfo_induk(l2);
}

void sorting_akreditasi_induk(list_induk &l)
{
    adr_induk p,q,m;
    list_induk l2;
    createlist_induk(l2);
    p = l.first_induk;
    while(p!=NULL){
        q=alokasi_induk_sort(p);
        if(l2.first_induk == NULL)
            insertfirst_induk(l2,q);
        else
        {
            m = l2.first_induk;
            while (m->info_induk.akreditasi< p->info_induk.akreditasi && m->next_induk != NULL)
            {
                m = m->next_induk;
            }
            if(l2.first_induk->next_induk == NULL)
            {
                if(l2.first_induk->info_induk.akreditasi>q->info_induk.akreditasi)
                {
                    insertfirst_induk(l2,q);
                }
                else
                    insertlast_induk(l2,q);
            }
            else
            {
                if (m==l2.first_induk)
                {
                    insertfirst_induk(l2,q);
                }
                else if(m==l2.last_induk && m->info_induk.akreditasi < q->info_induk.akreditasi)
                {
                    insertlast_induk(l2,q);
                }
                else
                    insertafter_induk(l2,q,m->prev_induk);
            }
        }
        p=p->next_induk;
    }
    printinfo_induk(l2);
}

void sorting_kaprodi_induk(list_induk &l)
{
    adr_induk p,q,m;
    list_induk l2;
    createlist_induk(l2);
    p = l.first_induk;
    while(p!=NULL){
        q=alokasi_induk_sort(p);
        if(l2.first_induk == NULL)
            insertfirst_induk(l2,q);
        else
        {
            m = l2.first_induk;
            while (m->info_induk.kaprodi< p->info_induk.kaprodi && m->next_induk != NULL)
            {
                m = m->next_induk;
            }
            if(l2.first_induk->next_induk == NULL)
            {
                if(l2.first_induk->info_induk.kaprodi>q->info_induk.kaprodi)
                {
                    insertfirst_induk(l2,q);
                }
                else
                    insertlast_induk(l2,q);
            }
            else
            {
                if (m==l2.first_induk)
                {
                    insertfirst_induk(l2,q);
                }
                else if(m==l2.last_induk && m->info_induk.kaprodi< q->info_induk.kaprodi)
                {
                    insertlast_induk(l2,q);
                }
                else
                    insertafter_induk(l2,q,m->prev_induk);
            }
        }
        p=p->next_induk;
    }
    printinfo_induk(l2);
}

void sorting_lokasi_induk(list_induk &l)
{
    adr_induk p,q,m;
    list_induk l2;
    createlist_induk(l2);
    p = l.first_induk;
    while(p!=NULL){
        q=alokasi_induk_sort(p);
        if(l2.first_induk == NULL)
            insertfirst_induk(l2,q);
        else
        {
            m = l2.first_induk;
            while (m->info_induk.lokasi< p->info_induk.lokasi && m->next_induk != NULL)
            {
                m = m->next_induk;
            }
            if(l2.first_induk->next_induk == NULL)
            {
                if(l2.first_induk->info_induk.lokasi>q->info_induk.lokasi)
                {
                    insertfirst_induk(l2,q);
                }
                else
                    insertlast_induk(l2,q);
            }
            else
            {
                if (m==l2.first_induk)
                {
                    insertfirst_induk(l2,q);
                }
                else if(m==l2.last_induk && m->info_induk.lokasi < q->info_induk.lokasi)
                {
                    insertlast_induk(l2,q);
                }
                else
                    insertafter_induk(l2,q,m->prev_induk);
            }
        }
        p=p->next_induk;
    }
    printinfo_induk(l2);
}

void sorting_kodeinventaris_induk(list_induk &l)
{
    adr_induk p,q,m;
    list_induk l2;
    createlist_induk(l2);
    p = l.first_induk;
    while(p!=NULL){
        q=alokasi_induk_sort(p);
        if(l2.first_induk == NULL)
            insertfirst_induk(l2,q);
        else
        {
            m = l2.first_induk;
            while (m->info_induk.kodeinventaris< p->info_induk.kodeinventaris && m->next_induk != NULL)
            {
                m = m->next_induk;
            }
            if(l2.first_induk->next_induk == NULL)
            {
                if(l2.first_induk->info_induk.kodeinventaris>q->info_induk.kodeinventaris)
                {
                    insertfirst_induk(l2,q);
                }
                else
                    insertlast_induk(l2,q);
            }
            else
            {
                if (m==l2.first_induk)
                {
                    insertfirst_induk(l2,q);
                }
                else if(m==l2.last_induk && m->info_induk.kodeinventaris < q->info_induk.kodeinventaris)
                {
                    insertlast_induk(l2,q);
                }
                else
                    insertafter_induk(l2,q,m->prev_induk);
            }
        }
        p=p->next_induk;
    }
    printinfo_induk(l2);
}

void sorting_nama_anak(list_induk &l)
{
    adr_induk ai = l.first_induk;
    list_anak list2;

    if (l.first_induk == NULL)
        cout<<"KOSONG";
    else{
        while (ai != NULL){

            createlist_anak(list2);
            adr_anak aa = ai->listanak.first_anak;
            while (aa != NULL){
                adr_anak temp = alokasi_anak(aa->info_anak);
                if(list2.first_anak == NULL)
                    insertfirst_anak(list2,temp);
                else if(list2.first_anak->next_anak == NULL)
                {
                    if(list2.first_anak->info_anak.nama < aa->info_anak.nama)
                        insertlast_anak(list2,temp);
                    else
                        insertfirst_anak(list2,temp);
                }
                else
                {
                    adr_anak prev = list2.first_anak;
                    adr_anak prev1;
                    while (prev != NULL)
                    {
                        if(prev->info_anak.nama> temp->info_anak.nama)
                            break;
                        prev1=prev;
                        prev = prev->next_anak;
                    }
                    if(prev==list2.first_anak){
                        insertfirst_anak(list2,temp);
                    }
                    else if(prev==NULL){
                        insertlast_anak(list2,temp);
                    }else
                    insertafter_anak(list2,temp,prev1);
                }
                aa = aa->next_anak;
            }
            ai->listanak=list2;
            ai = ai->next_induk;
        }

    }
    printinfo_anak(list2,l);
}

void sorting_kelas_anak(list_induk &l)
{
    adr_induk ai = l.first_induk;
    list_anak list2;

    if (l.first_induk == NULL)
        cout<<"KOSONG";
    else{
        while (ai != NULL){

            createlist_anak(list2);
            adr_anak aa = ai->listanak.first_anak;
            while (aa != NULL){
                adr_anak temp = alokasi_anak(aa->info_anak);
                if(list2.first_anak == NULL)
                    insertfirst_anak(list2,temp);
                else if(list2.first_anak->next_anak == NULL)
                {
                    if(list2.first_anak->info_anak.kelas < aa->info_anak.kelas)
                        insertlast_anak(list2,temp);
                    else
                        insertfirst_anak(list2,temp);
                }
                else
                {
                    adr_anak prev = list2.first_anak;
                    adr_anak prev1;
                    while (prev != NULL)
                    {
                        if(prev->info_anak.kelas> temp->info_anak.kelas)
                            break;
                        prev1=prev;
                        prev = prev->next_anak;
                    }
                    if(prev==list2.first_anak){
                        insertfirst_anak(list2,temp);
                    }
                    else if(prev==NULL){
                        insertlast_anak(list2,temp);
                    }else
                    insertafter_anak(list2,temp,prev1);
                }
                aa = aa->next_anak;
            }
            ai->listanak=list2;
            ai = ai->next_induk;
        }

    }
    printinfo_anak(list2,l);
}

void sorting_doswal_anak(list_induk &l)
{
    adr_induk ai = l.first_induk;
    list_anak list2;

    if (l.first_induk == NULL)
        cout<<"KOSONG";
    else{
        while (ai != NULL){

            createlist_anak(list2);
            adr_anak aa = ai->listanak.first_anak;
            while (aa != NULL){
                adr_anak temp = alokasi_anak(aa->info_anak);
                if(list2.first_anak == NULL)
                    insertfirst_anak(list2,temp);
                else if(list2.first_anak->next_anak == NULL)
                {
                    if(list2.first_anak->info_anak.doswal < aa->info_anak.doswal)
                        insertlast_anak(list2,temp);
                    else
                        insertfirst_anak(list2,temp);
                }
                else
                {
                    adr_anak prev = list2.first_anak;
                    adr_anak prev1;
                    while (prev != NULL)
                    {
                        if(prev->info_anak.doswal> temp->info_anak.doswal)
                            break;
                        prev1=prev;
                        prev = prev->next_anak;
                    }
                    if(prev==list2.first_anak){
                        insertfirst_anak(list2,temp);
                    }
                    else if(prev==NULL){
                        insertlast_anak(list2,temp);
                    }else
                    insertafter_anak(list2,temp,prev1);
                }
                aa = aa->next_anak;
            }
            ai->listanak=list2;
            ai = ai->next_induk;
        }

    }
    printinfo_anak(list2,l);
}

void sorting_angkatan_anak(list_induk &l)
{
    adr_induk ai = l.first_induk;
    list_anak list2;

    if (l.first_induk == NULL)
        cout<<"KOSONG";
    else{
        while (ai != NULL){

            createlist_anak(list2);
            adr_anak aa = ai->listanak.first_anak;
            while (aa != NULL){
                adr_anak temp = alokasi_anak(aa->info_anak);
                if(list2.first_anak == NULL)
                    insertfirst_anak(list2,temp);
                else if(list2.first_anak->next_anak == NULL)
                {
                    if(list2.first_anak->info_anak.angkatan < aa->info_anak.angkatan)
                        insertlast_anak(list2,temp);
                    else
                        insertfirst_anak(list2,temp);
                }
                else
                {
                    adr_anak prev = list2.first_anak;
                    adr_anak prev1;
                    while (prev != NULL)
                    {
                        if(prev->info_anak.angkatan> temp->info_anak.angkatan)
                            break;
                        prev1=prev;
                        prev = prev->next_anak;
                    }
                    if(prev==list2.first_anak){
                        insertfirst_anak(list2,temp);
                    }
                    else if(prev==NULL){
                        insertlast_anak(list2,temp);
                    }else
                    insertafter_anak(list2,temp,prev1);
                }
                aa = aa->next_anak;
            }
            ai->listanak=list2;
            ai = ai->next_induk;
        }

    }
    printinfo_anak(list2,l);
}

void sorting_ipk_anak(list_induk &l)
{
    adr_induk ai = l.first_induk;
    list_anak list2;

    if (l.first_induk == NULL)
        cout<<"KOSONG";
    else{
        while (ai != NULL){

            createlist_anak(list2);
            adr_anak aa = ai->listanak.first_anak;
            while (aa != NULL){
                adr_anak temp = alokasi_anak(aa->info_anak);
                if(list2.first_anak == NULL)
                    insertfirst_anak(list2,temp);
                else if(list2.first_anak->next_anak == NULL)
                {
                    if(list2.first_anak->info_anak.ipk < aa->info_anak.ipk)
                        insertlast_anak(list2,temp);
                    else
                        insertfirst_anak(list2,temp);
                }
                else
                {
                    adr_anak prev = list2.first_anak;
                    adr_anak prev1;
                    while (prev != NULL)
                    {
                        if(prev->info_anak.ipk> temp->info_anak.ipk)
                            break;
                        prev1=prev;
                        prev = prev->next_anak;
                    }
                    if(prev==list2.first_anak){
                        insertfirst_anak(list2,temp);
                    }
                    else if(prev==NULL){
                        insertlast_anak(list2,temp);
                    }else
                    insertafter_anak(list2,temp,prev1);
                }
                aa = aa->next_anak;
            }
            ai->listanak=list2;
            ai = ai->next_induk;
        }

    }
    printinfo_anak(list2,l);
}

adr_induk cekinduk (list_induk &jur, infotypeinduk ii){
    adr_induk prec = jur.first_induk;
    //cout<<"test";
    while (prec != NULL){
        if (prec->info_induk.kodejurusan > ii.kodejurusan){
            return prec ;
        }
            prec = prec->next_induk;
    }
    return NULL;
}

adr_anak cekanak (list_anak &mhs, infotypeanak ia){
    adr_anak prec = mhs.first_anak;
    while (prec != NULL){
        if (prec->info_anak.NIM > ia.NIM){
            adr_anak p = mhs.first_anak;
            while (p->next_anak != prec){
                p = p->next_anak;
            }
            return p;
        }
        else prec = prec->next_anak;
    }
    if(prec == NULL){
        prec = mhs.first_anak;
        while(prec->next_anak != NULL) prec = prec->next_anak;
        return prec;
    }
    /*adr_anak prec = mhs.first_anak;
    adr_anak sebelumnya=mhs.first_anak;

    while (prec != NULL){

        if (prec->info_anak.NIM > ia.NIM){
            if(prec==mhs.first_anak){
                return prec;
            }else
            return sebelumnya;
        }
        sebelumnya=prec;
        prec=prec->next_anak;
    }
    return NULL;*/

}

adr_anak cekanak1 (list_anak &mhs, infotypeanak ia){
    /*adr_anak prec = mhs.first_anak;
    while (prec != NULL){
        if (prec->info_anak.NIM > ia.NIM){
            adr_anak p = mhs.first_anak;
            while (p->next_anak != prec){
                p = p->next_anak;
            }
            return p;
        }
        else prec = prec->next_anak;
    }
    if(prec == NULL){
        prec = mhs.first_anak;
        while(prec->next_anak != NULL) prec = prec->next_anak;
        return prec;
    }*/
    adr_anak prec = mhs.first_anak;
    adr_anak sebelumnya=mhs.first_anak;

    while (prec != NULL){

        if (prec->info_anak.nama > ia.nama){
            if(prec==mhs.first_anak){
                return prec;
            }
            return sebelumnya;
        }
        sebelumnya=prec;
        prec=prec->next_anak;
    }
    return NULL;

}

void SearchtoViewInduk (list_induk &jur){
    char input [100];
    adr_induk ai;
    infotypeinduk cari;
    int pilih;

    cout<<"Masukkan kode jurusan yang akan dicari: ";
    cin>>cari.kodejurusan;
    ai = findelm_induk(jur,cari);
    if(ai == NULL ){
        cout<<"=========== data jurusan tidak ditemukan ============"<<endl;
        cout<<"===========    tekan 0 untuk kembali     ==========="<<endl;
    }
    else{
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#   0.  Kembali                  #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#          Data Jurusan          #"<<endl;
        cout<<"#================================#"<<endl;
        cout<< "Kode Jurusan: " << ai->info_induk.kodejurusan<<endl;
        cout<<"Nama Jurusan: " << ai->info_induk.namajurusan<<endl;
        cout<<"Akreditasi Jurusan: "<<ai->info_induk.akreditasi<<endl;
        cout<<"Nama Kepala Program Studi: "<<ai->info_induk.kaprodi<<endl;
        cout<<"Lokasi Gedung: "<<ai->info_induk.lokasi<<endl;
        cout<<"Kode Inventaris: "<<ai->info_induk.kodeinventaris<<endl;
    }
}

void SearchtoViewAnak(list_anak &mhs, list_induk &jur)
{
    char input[100];
    adr_anak aa;
    adr_induk ai;
    infotypeinduk ii;
    infotypeanak ia;
    int pilih;

    cout<<" Masukkan Kode Jurusan : ";
    cin>>ii.kodejurusan;
    ai = findelm_induk(jur,ii);
    if (ai == NULL){
        cout<<"=== kode jurusan tidak ditemukan ==="<<endl;
        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
    }
    else {
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#         Cari  Mahasiswa        #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"Masukkan NIM yang akan dicari: ";
        cin>>ia.NIM;
        aa = findelm_anak(ai->listanak,ia);
        if(aa != NULL )
        {
            system("cls");
            cout<<"#================================#"<<endl;
            cout<<"#   0.  Kembali                  #"<<endl;
            cout<<"#================================#"<<endl;
            cout<<"#         Cari  Mahasiswa        #"<<endl;
            cout<<"#================================#"<<endl;
            cout<<"NIM: " << aa->info_anak.NIM<<endl;
            cout<<"Nama Mahasiswa: " << aa->info_anak.nama<<endl;
            cout<<"Kelas: "<<aa->info_anak.kelas<<endl;
            cout<<"IPK Mahasiswa: "<<aa->info_anak.ipk<<endl;
            cout<<"Dosen Wali: "<<aa->info_anak.doswal<<endl;
            cout<<"Angkatan: "<<aa->info_anak.angkatan<<endl;
        }
        else{
            cout<<"=========== data mahasiswa tidak ditemukan ============"<<endl;
            cout<<"===========      tekan 0 untuk kembali     ========="<<endl;
        }
    }
}

