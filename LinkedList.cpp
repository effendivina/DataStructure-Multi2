#include <iostream>
#include "LinkedList.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

void createlist_induk(list_induk &l)
{
    l.first_induk = nil;
    l.last_induk = nil;
}

void createlist_anak(list_anak &listanak)
{
    listanak.first_anak = nil;

}

adr_induk alokasi_induk(infotypeinduk x)
{
    adr_induk p = new elmlist_induk;
    p->info_induk = x;
    p->next_induk = nil;
    p->prev_induk = nil;
    createlist_anak(p->listanak);
    return p;
}

adr_induk alokasi_induk_sort(adr_induk x)
{
    adr_induk p = new elmlist_induk;
    p->info_induk = x->info_induk;
    p->next_induk = nil;
    p->prev_induk = nil;
    p->listanak=x->listanak;
    return p;
}

adr_anak alokasi_anak(infotypeanak x)
{
    adr_anak p = new elmlist_anak;
    p->info_anak = x;
    p->next_anak = nil;
    return p;
}

void dealokasi_induk (adr_induk p)
{
    delete p;
}

void dealokasi_anak(adr_anak p)

{
    delete p;
}

adr_induk findelm_induk(list_induk l, infotypeinduk x)
{
    adr_induk p;
    if(l.first_induk == NULL){
        p = NULL;
    }
    else{
        p=l.first_induk;
        while(p!=NULL && p->info_induk.kodejurusan!=x.kodejurusan){
            p=p->next_induk;
        }
    }
    return p;
}

adr_anak findelm_anak(list_anak listanak,infotypeanak x)
{
    adr_anak p;
    if(listanak.first_anak == NULL){
        p = NULL;
    }else{
        p = listanak.first_anak;
        while(p != NULL  && p->info_anak.NIM!= x.NIM){
            p=p->next_anak;
        }
    }
    return p;
}

void insertfirst_induk(list_induk &l,adr_induk p)
{
    if (l.first_induk == NULL)
    {
        l.first_induk = p;
        l.last_induk = p;
    }

    else
    {
        p->next_induk = l.first_induk;
        l.first_induk->prev_induk = p;
        l.first_induk = p;
    }
}

void insertafter_induk(list_induk &l,adr_induk p, adr_induk prec)
{
    p->next_induk = prec->next_induk;
    p->prev_induk = prec;
    prec->next_induk->prev_induk=p->prev_induk;
    prec->next_induk = p;
}

void insertlast_induk(list_induk &l, adr_induk p)
{
    if (l.first_induk == NULL)
    {
        l.first_induk = p;
        l.last_induk = p;
    }
    else
    {
        p->prev_induk = l.last_induk;
        l.last_induk->next_induk = p;
        l.last_induk = p;
        p->next_induk = NULL;
    }
}

void insertfirst_anak(list_anak &listanak,adr_anak p)
{
    if (listanak.first_anak == NULL)
    {
		listanak.first_anak = p;
	}
	else
	{
		p->next_anak = listanak.first_anak;
		listanak.first_anak = p;
	}
}

void insertafter_anak(list_anak &listanak,adr_anak p, adr_anak prec)
{
    if (listanak.first_anak != NULL)
    {
        p->next_anak = prec->next_anak;
        prec->next_anak = p;
    }
}

void insertlast_anak(list_anak &listanak, adr_anak p)
{
    if (listanak.first_anak == NULL){
        listanak.first_anak = p;
    }
    else{
        adr_anak q = listanak.first_anak;
        while(q->next_anak != NULL){
            q=q->next_anak;
        }
        q->next_anak = p;
    }
}

void deletefirst_induk(list_induk &l,adr_induk &p)
{
    if(l.first_induk == NULL)
    {
        cout<<"list kosong ";
    }
    else if (l.first_induk == l.last_induk)
    {
        adr_induk p = l.first_induk;
        l.first_induk = NULL;
        l.last_induk = NULL;
        delete p;
    }
    else
    {
        adr_induk p = l.first_induk;
        l.first_induk = p->next_induk;
        p->next_induk = NULL;
        p->prev_induk = NULL;
        delete p;
    }
}

void deleteafter_induk(list_induk &l, adr_induk &p, adr_induk prec)
{
    p=prec->next_induk;
    p->next_induk->prev_induk = p->prev_induk;
    p->next_induk = nil;
    p->prev_induk = nil;
    delete p;
}

void deletelast_induk(list_induk &l, adr_induk &p)
{
    if ( l.first_induk == l.last_induk)
    {

        l.first_induk = NULL;
        l.last_induk = NULL;
    }
    else
    {
        adr_induk p = l.last_induk;
        l.last_induk = p->prev_induk;
        p->next_induk = NULL;
        p->prev_induk = NULL;
    }
    delete p;
}

void deletefirst_anak(list_anak &listanak,adr_anak &p)
{
    if (listanak.first_anak != NULL)
    {
		p = listanak.first_anak;
		if ( p->next_anak == NULL)
		{
			listanak.first_anak = NULL;
		}
		else
		{
			listanak.first_anak = p->next_anak;
			p->next_anak = NULL;
		}
	}
}

void deleteafter_anak(list_anak &listanak, adr_anak &p, adr_anak prec)
{

    if (listanak.first_anak != NULL){
        if (listanak.first_anak->next_anak == listanak.first_anak){
            p = listanak.first_anak;
            listanak.first_anak = NULL;
        }
    }
    else{
        p = prec->next_anak;
        if (prec->next_anak == listanak.first_anak){
            listanak.first_anak = listanak.first_anak->next_anak;
        }
        prec->next_anak = p->next_anak;
    }
}

void deletelast_anak(list_anak &listanak, adr_anak &p)
{
    if (listanak.first_anak != NULL)
    {
		adr_anak q = listanak.first_anak;
		if(q->next_anak == NULL)
		{
			listanak.first_anak = NULL;
		}
		else
		{
			while((q->next_anak)->next_anak != NULL)
			{
				q=q->next_anak = NULL;
			}
			p= q->next_anak;
			q->next_anak = NULL;
		}
	}
}

void printinfo_induk(list_induk l)
{

    if(l.first_induk == NULL)
    {
        cout<<"kosong";
    }
    else
    {
        adr_induk q = l.first_induk;
        int i = 1;
        do
        {
            cout<<"---------DATA JURUSAN KE-"<<i<<"------------"<<endl;
            cout<< "Kode Jurusan: " << q->info_induk.kodejurusan<<endl;
            cout<<"Nama Jurusan: " << q->info_induk.namajurusan<<endl;
            cout<<"Akreditasi Jurusan: "<<q->info_induk.akreditasi<<endl;
            cout<<"Nama Kepala Program Studi: "<<q->info_induk.kaprodi<<endl;
            cout<<"Lokasi Gedung: "<<q->info_induk.lokasi<<endl;
            cout<<"Kode Inventaris: "<<q->info_induk.kodeinventaris<<endl;
            cout<<endl;
            q = q->next_induk;
            i = i+1;
        }
        while (q != NULL);
    }
}

void printinfo_anak(list_anak listanak, list_induk l )
{
    adr_induk p = l.first_induk;
    while (p!=NULL)
    {
        adr_anak q = (p)->listanak.first_anak;
        while (q!=NULL)
        {
            cout<<"-------------------INFORMASI MAHASISWA---------------"<<endl;
            cout<<"NIM: "<<(q)->info_anak.NIM<<endl;
            cout<<"Nama Mahasiswa: "<<(q)->info_anak.nama<<endl;
            cout<<"Kelas: "<<(q)->info_anak.kelas<<endl;
            cout<<"IPK: "<<(q)->info_anak.ipk<<endl;
            cout<<"Angkatan: "<<(q)->info_anak.angkatan<<endl;
            cout<<"Dosen Wali:  "<<(q)->info_anak.doswal<<endl;
            q = (q)->next_anak;
        }
        p = (p)->next_induk;
    }
}





void SearchandViewInduk (list_induk &l){

}
