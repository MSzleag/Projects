#include "figura.h"
#pragma once
#ifndef KROLOWA_H
#define KROLOWA_H
class Krolowa : public Figura
{
public:
    Krolowa(char mKolor): Figura(mKolor){}
    ~Krolowa(){}
private:
    virtual char GetFigura(){
        return 'Q';
    }
    bool MozliwePola(int ObcWie, int ObcKol, int DocWie, int DocKol, Figura* Plansza[8][8])
    {
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
        }else if((DocKol - ObcKol == DocWie - ObcWie) || (DocKol - ObcKol == ObcWie - DocWie)){
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