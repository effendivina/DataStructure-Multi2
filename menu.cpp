#include <iostream>
#include "LinkedList.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

void menuinsert(list_induk &jur, list_anak &mhs){
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int a,b=1,c=1,d,ch;
    while (c==1){
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#    0.  Kembali                 #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           INPUT DATA           #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#    1.  Input Jurusan           #"<<endl;
                cout<<"#    2.  Input Mahasiswa         #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d){
                case 1:
                    system("cls");
					cout<<"#================================#"<<endl;
                    cout<<"#          Input Jurusan         #"<<endl;
                    cout<<"#================================#"<<endl;

                    cout<<" Kode Jurusan : ";
                    cin>>ii.kodejurusan;
                    cout<<" Nama Jurusan : ";
                    cin.ignore();
                    cin.getline(input,100);
                    ii.namajurusan = input;
                    cout<<" Akreditasi Jurusan : ";
                    cin>>ii.akreditasi;
                    cout<<" Nama Kaprodi : ";
                    cin.ignore();
                    cin.getline(input,100);
                    ii.kaprodi = input;
                    cout<<" Lokasi Gedung : ";
                    //cin.ignore();
                    cin.getline(input,100);
                    ii.lokasi = input;
                    cout<<" Kode Inventaris : ";
                    cin>>ii.kodeinventaris;
                    ai = alokasi_induk(ii);
					if ( findelm_induk(jur,ii) == NULL){
                        adr_induk p = jur.first_induk;
                        if (p == NULL){
                            insertfirst_induk(jur, ai);
                            cout<<endl;
                            cout<<"=== input jurusan baru sukses ==="<<endl;
                            cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                        }
                        else if (p == jur.last_induk){
                            if (p->info_induk.kodejurusan < ai->info_induk.kodejurusan)
                                insertlast_induk(jur, ai);
                            else
                                insertfirst_induk(jur, ai);
                            cout<<endl;
                            cout<<"=== input jurusan baru sukses ==="<<endl;
                            cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                        }
                      else {
                            adr_induk prec = cekinduk(jur, ai->info_induk);
                            if(prec==jur.first_induk){
                                insertfirst_induk(jur,ai);
                            }
                            else if(prec==jur.last_induk){
                                insertafter_induk(jur,ai,prec->prev_induk);
                            }else{
                                insertlast_induk(jur,ai);
                            }

                            //insertafter_induk(jur, ai, prec);
                            cout<<endl;
                            cout<<"=== input jurusan baru sukses ==="<<endl;
                            cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                        }
					}
					else{
                        cout<<endl;
                        cout<<"=== nama jurusan sudah ada ==="<<endl;
                        cout<<"===   tekan 0 untuk kembali   ==="<<endl;
					}
					while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Input Mahasiswa       #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Kode Jurusan : ";
                    cin>>ii.kodejurusan;
                    ai = findelm_induk(jur,ii);
                    if (ai == NULL){
                        cout<<"=== kode jurusan tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else{
                        system("cls");
                        cout<<"#================================#"<<endl;
                        cout<<"#          Input Mahasiswa       #"<<endl;
                        cout<<"#================================#"<<endl;
                        cout<<" NIM Mahasiswa  : ";
                        cin>>ia.NIM;
                        cout<<" Nama Mahasiswa : ";
                        cin.ignore();
                        cin.getline(input,100);
                        ia.nama = input;
                        cout<<" Kelas Mahasiswa : ";
                        //cin.ignore();
                        cin.getline(input,100);
                        ia.kelas = input;
                        cout<<" IPK Mahasiswa : ";
                        cin>>ia.ipk;
                        cout<<" Nama Dosen Wali : ";
                        cin.ignore();
                        cin.getline(input,100);
                        ia.doswal = input;
                        cout<<" Angkatan : ";
                        cin>>ia.angkatan;
                        aa=alokasi_anak(ia);
                        if ( findelm_anak(mhs,ia) == NULL){
                            mhs = ai->listanak;
                            if (mhs.first_anak == NULL){
                                insertfirst_anak(ai->listanak, aa);
                                cout<<endl;
                                cout<<"=== input mahasiswa baru sukses ==="<<endl;
                                cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                            }
                            else if (mhs.first_anak->next_anak == NULL){
                                if (mhs.first_anak->info_anak.NIM < aa->info_anak.NIM)
                                    insertlast_anak(ai->listanak,aa);
                                else
                                    insertfirst_anak(ai->listanak,aa);
                                cout<<endl;
                                cout<<"=== input mahasiswa baru sukses ==="<<endl;
                                cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                            }
                            else{
                                adr_anak prec = cekanak(mhs, aa->info_anak);
                                /*if(prec==mhs.first_anak){
                                    insertfirst_anak(mhs,aa);
                                }
                                else if(prec==NULL){
                                    insertlast_anak(ai->listanak,aa);
                                }else{
                                    insertafter_anak(ai->listanak,aa,prec);
                                }*/
                                insertafter_anak(ai->listanak, aa, prec);
                                cout<<endl;
                                cout<<"=== input mahasiswa baru sukses ==="<<endl;
                                cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                            }
                        }
                        else{
                            cout<<endl;
                            cout<<"=== nama mahasiswa sudah ada ==="<<endl;
                            cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                        }
                    }
                    while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                case 0:
                     c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"=======   tekan 0 untuk kembali   ======="<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;

        }
    }
}

void menudelete(list_induk &jur, list_anak &mhs){
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int a,b=1,c=1,d,ch;
            while (c==1){
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#    0.  Kembali                 #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           HAPUS DATA           #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#    1.  Hapus Jurusan           #"<<endl;
                cout<<"#    2.  Hapus Mahasiswa         #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d){
                case 1:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Hapus Jurusan          #"<<endl;
                    cout<<"#================================#"<<endl;
                    SearchtoDeleteInduk(jur);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Hapus Mahasiswa        #"<<endl;
                    cout<<"#================================#"<<endl;
                    SearchtoDeleteAnak(mhs,jur);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
}

void menuupdate(list_induk &jur, list_anak &mhs){
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int a,b=1,c=1,d,ch;
        while (c == 1)
            {
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#    0.  Kembali                 #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           UPDATE DATA          #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#    1.  Update Jurusan          #"<<endl;
                cout<<"#    2.  Update Mahasiswa        #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d)
                {
                case 1:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Update Jurusan        #"<<endl;
                    cout<<"#================================#"<<endl;
                    SearchToEditInduk(jur);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Update Mahasiswa      #"<<endl;
                    cout<<"#================================#"<<endl;
                    SearchToEditAnak(mhs,jur);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
}

void menuview(list_induk &jur, list_anak &mhs){
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int c=1,d,ch;
    while (c==1)
            {
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#   0.  Kembali                  #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           View DATA            #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#   1.  Lihat Data Jurusan       #"<<endl;
                cout<<"#   2.  Lihat Data Mahasiswa     #"<<endl;
                cout<<"#   3.  Lihat Semua Data         #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d)
                {
                case 1:
                    system("cls");
                    cout<<"#====================================#"<<endl;
                    cout<<"#     0.  Kembali                    #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<"#             DATA JURUSAN           #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<endl;
                    printinfo_induk(jur);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#====================================#"<<endl;
                    cout<<"#     0.  Kembali                    #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<"#            DATA MAHASISWA          #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<endl;
                    printinfo_anak(mhs, jur);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 3:
                    viewAll(jur, mhs);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
}

void menusort(list_induk &jur, list_anak &mhs){
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int c=1,d,ch,o,t;
    while (c==1){
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#   0.  Kembali                  #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           Sort Data            #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#   1.  Sort Data Jurusan        #"<<endl;
                cout<<"#   2.  Sort Data Mahasiswa      #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d)
                {
                case 1:
                    system("cls");
                    cout<<"#====================================#"<<endl;
                    cout<<"#     0.  Kembali                    #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<"#          SORT DATA JURUSAN         #"<<endl;
                    cout<<"#   Berdasarkan:                     #"<<endl;
                    cout<<"#   1.  Nama Jurusan                 #"<<endl;
                    cout<<"#   2.  Akreditasi Jurusan           #"<<endl;
                    cout<<"#   3.  Kaprodi Jurusan              #"<<endl;
                    cout<<"#   4.  Lokasi Gedung Jurusan        #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<" Masukkan pilihan    : ";
                    cin>>o;
                    switch (o){
                    case 1:
                        system("cls");
                        cout<<"#====================================#"<<endl;
                        cout<<"#     0.  Kembali                    #"<<endl;
                        cout<<"#====================================#"<<endl;
                        cout<<"#       SORT DATA NAMA JURUSAN       #"<<endl;
                        cout<<"#====================================#"<<endl;
                        cout<<endl;
                        sorting_nama_induk(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 2:
                        system("cls");
                        cout<<"#==========================================#"<<endl;
                        cout<<"#     0.  Kembali                          #"<<endl;
                        cout<<"#==========================================#"<<endl;
                        cout<<"#       SORT DATA AKREDITASI JURUSAN       #"<<endl;
                        cout<<"#==========================================#"<<endl;
                        cout<<endl;
                        sorting_akreditasi_induk(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 3:
                        system("cls");
                        cout<<"#=======================================#"<<endl;
                        cout<<"#     0.  Kembali                       #"<<endl;
                        cout<<"#=======================================#"<<endl;
                        cout<<"#       SORT DATA KAPRODI JURUSAN       #"<<endl;
                        cout<<"#=======================================#"<<endl;
                        cout<<endl;
                        sorting_kaprodi_induk(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 4:
                        system("cls");
                        cout<<"#=============================================#"<<endl;
                        cout<<"#     0.  Kembali                             #"<<endl;
                        cout<<"#=============================================#"<<endl;
                        cout<<"#       SORT DATA LOKASI GEDUNG JURUSAN       #"<<endl;
                        cout<<"#=============================================#"<<endl;
                        cout<<endl;
                        sorting_lokasi_induk(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 5:
                        system("cls");
                        cout<<"#=============================================#"<<endl;
                        cout<<"#     0.  Kembali                             #"<<endl;
                        cout<<"#=============================================#"<<endl;
                        cout<<"#       SORT DATA KODE INVENTARIS JURUSAN       #"<<endl;
                        cout<<"#=============================================#"<<endl;
                        cout<<endl;
                        sorting_kodeinventaris_induk(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 0:
                        c=2;
                        break;
                    default :
                        system("cls");
                        cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                        cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    }
                case 2:
                    system("cls");
                    cout<<"#====================================#"<<endl;
                    cout<<"#     0.  Kembali                    #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<"#          SORT DATA MAHASISWA       #"<<endl;
                    cout<<"#   Berdasarkan:                     #"<<endl;
                    cout<<"#   1.  Nama Mahasiswa               #"<<endl;
                    cout<<"#   2.  Kelas Mahasiswa              #"<<endl;
                    cout<<"#   3.  Dosen Wali Mahasiswa         #"<<endl;
                    cout<<"#   4.  Angkatan Mahasiswa           #"<<endl;
                    cout<<"#   5.  IPK Mahasiswa                #"<<endl;
                    cout<<"#====================================#"<<endl;
                    cout<<" Masukkan pilihan    : ";
                    cin>>t;
                    switch (t){
                    case 1:
                        system("cls");
                        cout<<"#====================================#"<<endl;
                        cout<<"#     0.  Kembali                    #"<<endl;
                        cout<<"#====================================#"<<endl;
                        cout<<"#       SORT DATA NAMA MAHASISWA     #"<<endl;
                        cout<<"#====================================#"<<endl;
                        cout<<endl;
                        sorting_nama_anak(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 2:
                        system("cls");
                        cout<<"#==========================================#"<<endl;
                        cout<<"#     0.  Kembali                          #"<<endl;
                        cout<<"#==========================================#"<<endl;
                        cout<<"#       SORT DATA KELAS MAHASISWA          #"<<endl;
                        cout<<"#==========================================#"<<endl;
                        cout<<endl;
                        sorting_kelas_anak(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 3:
                        system("cls");
                        cout<<"#===========================================#"<<endl;
                        cout<<"#     0.  Kembali                           #"<<endl;
                        cout<<"#===========================================#"<<endl;
                        cout<<"#       SORT DATA DOSEN WALI MAHASISWA      #"<<endl;
                        cout<<"#===========================================#"<<endl;
                        cout<<endl;
                        sorting_doswal_anak(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 4:
                        system("cls");
                        cout<<"#==========================================#"<<endl;
                        cout<<"#     0.  Kembali                          #"<<endl;
                        cout<<"#==========================================#"<<endl;
                        cout<<"#       SORT DATA ANGKATAN MAHASISWA       #"<<endl;
                        cout<<"#==========================================#"<<endl;
                        cout<<endl;
                        sorting_angkatan_anak(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                     case 5:
                        system("cls");
                        cout<<"#=============================================#"<<endl;
                        cout<<"#     0.  Kembali                             #"<<endl;
                        cout<<"#=============================================#"<<endl;
                        cout<<"#       SORT DATA IPK MAHASISWA               #"<<endl;
                        cout<<"#=============================================#"<<endl;
                        cout<<endl;
                        sorting_ipk_anak(jur);
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    case 0:
                        c=2;
                        break;
                    default :
                        system("cls");
                        cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                        cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                        while ((ch = getch()) != EOF && ch != '0')
                            printf ("%c\n", ch);
                        break;
                    }

                }
    }
}

void menusearch (list_induk &jur, list_anak &mhs){
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int c=1,d,ch;
    while (c==1){
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#   0.  Kembali                  #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#        Searching Data          #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#   1.  Cari Data Jurusan        #"<<endl;
        cout<<"#   2.  Cari Data Mahasiswa      #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<" Masukkan pilihan    : ";
        cin>>d;
        switch (d){
        case 1:
            system("cls");
            cout<<"#================================#"<<endl;
            cout<<"#          Data Jurusan          #"<<endl;
            cout<<"#================================#"<<endl;
            SearchtoViewInduk(jur);
            while ((ch = getch()) != EOF && ch != '0')
                printf ("%c\n", ch);
            break;
        case 2:
            system("cls");
            cout<<"#================================#"<<endl;
            cout<<"#         Data Mahasiswa         #"<<endl;
            cout<<"#================================#"<<endl;
            SearchtoViewAnak(mhs,jur);
            while ((ch = getch()) != EOF && ch != '0')
                printf ("%c\n", ch);
            break;

        case 0:
            c=2;
            break;
        default :
            system("cls");
            cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
            cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
            while ((ch = getch()) != EOF && ch != '0')
                printf ("%c\n", ch);
            break;
        }
    }
}


