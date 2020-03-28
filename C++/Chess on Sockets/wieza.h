#include "figura.h"
#pragma once
#ifndef WIEZA_H
#define WIEZA_H
class Wieza: public Figura
{
public:
    Wieza(char mKolor): Figura(mKolor){}
    ~Wieza(){}
private:
    virtual char GetFigura(){
        return 'W';
    }
    bool MozliwePola(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8]){
        if(ObcWie == DocWie){
            //sprawdzamy czy wszytkie pola po kolumnie sa puste aby wykonac ruch 
            int KolOffset = (DocKol - ObcKol > 0) ? 1 : -1;
            for(int SpraKol = ObcKol + KolOffset; SpraKol != DocKol; SpraKol = SpraKol + KolOffset){
                if(Plansza[ObcWie][SpraKol] != 0){
                    return false;
                }
            }
            return true;
        }else if(DocKol == ObcKol){
            //sprawdzamy czy wszykie pola po wierszu sa puste aby wykonac ruch
            int WieOffset = (DocWie - ObcWie > 0) ? 1 : -1;
            for(int SpraWie = ObcWie + WieOffset; SpraWie != DocWie; SpraWie = SpraWie + WieOffset){
                if(Plansza[SpraWie][ObcKol] != 0){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
#endif