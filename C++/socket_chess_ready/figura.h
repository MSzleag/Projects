#pragma once
#ifndef FIGURA_H
#define FIGURA_H


class Figura
{
public:
    Figura(char mKolor) : mcKolor(mKolor) {}
    ~Figura(){}                              
    virtual char GetFigura() = 0;            
    char GetKolor(){                         
        return mcKolor;
    }

    bool MozliweRuchy(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8]){
        Figura* Docel = Plansza[DocWie][DocKol];
        if ((Docel == 0) || (mcKolor != Docel->GetKolor())){
            return MozliwePola(ObcWie, ObcKol, DocWie, DocKol, Plansza);
        }
        return false;
    }
private:
    virtual bool MozliwePola(int ObcWie, int ObcKol,int DocWie, int DocKol, Figura* Plansza[8][8]) = 0;
    char mcKolor;
};

#endif