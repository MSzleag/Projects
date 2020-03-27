#include <iostream>
#include "rozklad.h"
#include <cstdlib>
using namespace std;

int main()
{
    Rozklad p1;
    int numer;
    do{
    cout<<endl<<"1.Dodaj polaczenie."<<endl<<"2.Wyszukaj polaczenie"<<endl<<"3.Pokaz caly rozklad jazdy."<<endl<<"4.Zakoncz"<<endl<<endl;
    cin>>numer;
    switch(numer)
    {
        case 1:
            p1.dodajPolaczenie();
            break;
        case 2:
            p1.szukajPolaczenie();
            break;
        case 3:
            p1.pokazRozklad();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"Podano zly numer, sprobuj ponownie";
            break;
    }
    }while(numer!=4);




    return 0;
}
