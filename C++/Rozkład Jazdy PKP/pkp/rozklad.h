#include <iostream>
#include<fstream>
using namespace std;

class Rozklad
{
public:
    string stacja_z,stacja_do,p_stacja_z,p_stacja_do;
    int godzina,minuta,dzien,rok,miesiac,p_dzien,p_rok,p_miesiac,p_godzina,p_minuta;
    fstream plikIn,plikOut;
    void dodajPolaczenie();
    void szukajPolaczenie();
    void pokazRozklad();

};

