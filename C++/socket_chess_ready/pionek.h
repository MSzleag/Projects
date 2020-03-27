#include "figura.h"
#pragma once
#ifndef PIONEK_H
#define PIONEK_H
class Pionek : public Figura
{
public:
    Pionek(char mKolor): Figura(mKolor) {}
    ~Pionek(){}

private:
    virtual char GetFigura(){
        return 'P';
    }

    bool MozliwePola(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8]){
        Figura* Docel = Plansza[DocWie][DocKol];
        if(Docel == 0){
            //Sprawdzanie czy docelowe pole jest niezajete
            if(ObcKol == DocKol){
                if(GetKolor() == 'W'){
                    if(DocWie == ObcWie + 2 && ObcWie == 1){
                        return true;
                    }
                    else if(DocWie == ObcWie + 1){
                        return true;
                    }
                    
                }else{
                    if(DocWie == ObcWie - 2 && ObcWie == 6){
                        return true;
                    }
                    else if (DocWie == ObcWie - 1){
                        return true;
                    }
                }
            }
        }
        else{
            //Sprawdzanie czy na polu docelowym jest pionek przecwinego koloru
            if((ObcKol == DocKol + 1)|| (ObcKol == DocKol - 1)){
                if(GetKolor() == 'W'){
                    if(DocWie == ObcWie + 1){
                        return true;
                    }
                }else{
                    if(DocWie == ObcWie - 1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif