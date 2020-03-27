#include<iostream>
#include "rozklad.h"
#include<fstream>
#include <cstdlib>
int numer;

using namespace std;

void Rozklad::dodajPolaczenie()
{
    plikOut.open("polaczenia.txt",ios::out | ios::app);

    cout<<endl<<"Nazwa stacji z ktorej chcesz wyjechac: ";
    cin>>stacja_z;
    cout<<endl<<"Nazwa stacji do ktorej chcesz dojechac: ";
    cin>>stacja_do;
    cout<<endl<<"Rok wyjazdu: ";
    cin>>rok;
    cout<<endl<<"Miesiac wyjazdu: ";
    cin>>miesiac;
    cout<<endl<<"Dzien wyjazdu: ";
    cin>>dzien;
    cout<<endl<<"Godzina wyjazdu: ";
    cin>>godzina;
    cout<<endl<<"Minuta wyjazdu: ";
    cin>>minuta;
    cout<<endl<<"Dodano polaczenie ze stacji: "<<stacja_z<<" do stacji "<<stacja_do<<". Data: "<<dzien<<" "<<miesiac<<" "<<rok<<" godzina: "<<godzina<<":"<<minuta<<endl;
    plikOut<<stacja_z<<" "<<stacja_do<<" "<<dzien<<" "<<miesiac<<" "<<rok<<" "<<godzina<<" "<<minuta<<endl;

    plikOut.close();
}

void Rozklad::szukajPolaczenie()
{
    plikIn.open("polaczenia.txt",ios::in);
    if(!plikIn)
    {
        cout<<"Plik nie istnieje.";
        exit(1);
    }


    cout<<endl<<"Nazwa stacji z ktorej chcesz wyjechac: ";
    cin>>stacja_z;
    cout<<endl<<"Nazwa stacji do ktorej chcesz dojechac: ";
    cin>>stacja_do;
    cout<<endl<<"Rok wyjazdu: ";
    cin>>rok;
    cout<<endl<<"Miesiac wyjazdu: ";
    cin>>miesiac;
    cout<<endl<<"Dzien wyjazdu: ";
    cin>>dzien;
    cout<<endl<<"Godzina wyjazdu: ";
    cin>>godzina;
    cout<<endl<<"Minuta wyjazdu: ";
    cin>>minuta;
    cout<<"Dostepne przejazdy w podanym terminie: "<<endl;

    while(plikIn.good()==true)
    {
        plikIn>>p_stacja_z;
        if( !plikIn ) break;
        plikIn>>p_stacja_do>>p_dzien>>p_miesiac>>p_rok>>p_godzina>>p_minuta;

        if(p_stacja_z==stacja_z && p_stacja_do==stacja_do && p_rok==rok && p_miesiac==miesiac && p_dzien==dzien && p_godzina>=godzina)
        {
            if(p_godzina==godzina && p_minuta>=minuta)
            {
            cout<<endl<<"Polaczenie ze stacji "<<p_stacja_z<<" do stacji "<<p_stacja_do<<". Data: "<<p_dzien<<" "<<p_miesiac<<" "<<p_rok<<" godzina: "<<p_godzina<<":"<<p_minuta<<endl;
            }
        }
    }

    plikIn.close();


}

void Rozklad::pokazRozklad()
{
    cout<<endl<<"----------------------------------ROZKLAD JAZDY---------------------------------"<<endl<<endl<<endl;
    plikIn.open("polaczenia.txt",ios::in);
    if(!plikIn)
    {
        cout<<"Plik nie istnieje.";
        exit(1);
    }
    while(plikIn.good()==true)
    {

        plikIn>>p_stacja_z;
        if( !plikIn ) break;
        plikIn>>p_stacja_do>>p_dzien>>p_miesiac>>p_rok>>p_godzina>>p_minuta;
        cout<<endl<<"Polaczenie ze stacji "<<p_stacja_z<<" do stacji "<<p_stacja_do<<". Data: "<<p_dzien<<" "<<p_miesiac<<" "<<p_rok<<" godzina: "<<p_godzina<<":"<<p_minuta<<endl;
    }
    plikIn.close();
}

