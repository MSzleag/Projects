#include "figura.h"
#pragma once
#ifndef SKOCZEK_H
#define SKOCZEK_H
class Skoczek : public Figura
{
public:
    Skoczek(char mKolor): Figura(mKolor){}
    ~Skoczek(){}
private:
    virtual char GetFigura(){
        return 'S';
    }
    bool MozliwePola(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8]){
        //Docelowe pole jest nie zajete lub zajete przez pionka przeciwnika
        if((ObcKol == DocKol + 1) || (ObcKol == DocKol -1)){
            if ((ObcWie == DocWie + 2) || (ObcWie == DocWie - 2)){
                return true;
            }
        }
        if((ObcKol == DocKol + 2) || (ObcKol == DocKol -2)){
            if ((ObcWie == DocWie + 1) || (ObcWie == DocWie - 1)){
                return true;
            }
        }
        return false;

    }

};

#endif