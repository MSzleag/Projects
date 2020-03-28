#include "figura.h"
#pragma once
#ifndef KROL_H
#define KROL_H

class Krol:public Figura
{
public:
    Krol(char mKolor): Figura(mKolor){}
    ~Krol(){}
private:
    virtual char GetFigura(){
        return 'K';
    }
    bool MozliwePola(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8])
    {   //sprawdzamy wszykie pola mozliwe dla ruchu krola 
        int WieD = DocWie - ObcWie;
        int KolD = DocKol - ObcKol;

        if(((WieD >= -1) && (WieD <= 1)) && ((KolD >= -1) && (KolD <= 1)))
        {
            return true;
        }
        return false;
    }

};
#endif