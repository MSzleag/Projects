#include "figura.h"
#pragma once
#ifndef GONIEC_H
#define GONIEC_H
class Goniec: public Figura
{
public:
    Goniec(char mKolor): Figura(mKolor){}
    ~Goniec(){}
private:
    virtual char GetFigura(){
        return 'G';
    }
    bool MozliwePola(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8]){
        if((DocKol - ObcKol == DocWie - ObcWie) || (DocKol - ObcKol == ObcWie - DocWie)){
            //spawdzamy czy wszytkie pola po przekatnej sa puste aby wykonac ruch
            int WieOffset = (DocWie - ObcWie > 0) ? 1 : -1;
            int KolOffset = (DocKol - ObcKol > 0) ? 1 : -1;
            int SpraWie;
            int SpraKol;
            for(SpraWie = ObcWie + WieOffset, SpraKol = ObcKol + KolOffset; SpraWie != DocWie; SpraWie = SpraWie + WieOffset, SpraKol = SpraKol + KolOffset){
                if(Plansza[SpraWie][SpraKol] != 0){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

#endif
