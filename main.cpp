#include <iostream>
#include "LinkedList.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


using namespace std;

int main()
{
    list_induk jur;
    list_anak mhs;
    createlist_induk(jur);
    createlist_anak(mhs);
    adr_induk ai;
    adr_anak aa;
    infotypeinduk ii;
    infotypeanak ia;
    char input[100];

    int a,b=1,c=1,d,ch;
    //char n;
    while (b==1){
    system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#           MENU UTAMA           #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#    1.  Input Data              #"<<endl;
        cout<<"#    2.  Delete Data             #"<<endl;
        cout<<"#    3.  Update Data             #"<<endl;
        cout<<"#    4.  View Data               #"<<endl;
        cout<<"#    5.  Search Data             #"<<endl;
        cout<<"#    6.  Sort Data               #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#    0.  Exit                    #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<" Masukkan pilihan    : ";
        cin>>a;
        switch (a){
        case 1:
            menuinsert(jur, mhs);
            c=1;
            break;
        case 2:
            menudelete(jur, mhs);
            c=1;
            break;
        case 3:
            menuupdate(jur, mhs);
            break;
        case 4:
            menuview(jur, mhs);
            c=1;
            break;
        case 5:
            menusearch(jur,mhs);
            c=1;
            break;
        case 6:
            menusort(jur,mhs);
            c=1;
            break;
        case 0:
            b=2;
            system("cls");
            cout<<"#================================#"<<endl;
            cout<<"#             KELUAR             #"<<endl;
            cout<<"#================================#"<<endl;
            cout<<"#          Terima Kasih          #"<<endl;
            cout<<"#================================#"<<endl;
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
    return 0;
}
