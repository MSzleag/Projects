#include "figura.h"
#include "pionek.h"
#include "skoczek.h"
#include "goniec.h"
#include "wieza.h"
#include "krol.h"
#include "krolowa.h"
#include "iostream"
#pragma once
#ifndef PLANSZA_H
#define PLANSZA_H
using namespace std;


class CPlansza
{
    public:
        CPlansza(){
            //inicjalizacja planszy
            for(int Wie = 0; Wie < 8; ++Wie){
                for(int Kol = 0; Kol < 8; ++Kol){
                    Plansza[Wie][Kol] = 0;
                }
            }
            //Rozmieszczanie i ustawianie czarnych figur
            for(int Kol = 0; Kol < 8; ++Kol){
                Plansza[6][Kol] = new Pionek('B');
            }
            Plansza[7][0] = new Wieza('B');
            Plansza[7][1] = new Skoczek('B');
            Plansza[7][2] = new Goniec('B');
            Plansza[7][3] = new Krol('B');
            Plansza[7][4] = new Krolowa('B');
            Plansza[7][5] = new Goniec('B');
            Plansza[7][6] = new Skoczek('B');
            Plansza[7][7] = new Wieza('B');
            //Rozmieszczanie i ustawianie bialych figur
            for(int Kol = 0; Kol < 8; ++Kol){
                Plansza[1][Kol] = new Pionek('W');
            }
            Plansza[0][0] = new Wieza('W');
            Plansza[0][1] = new Skoczek('W');
            Plansza[0][2] = new Goniec('W');
            Plansza[0][3] = new Krol('W');
            Plansza[0][4] = new Krolowa('W');
            Plansza[0][5] = new Goniec('W');
            Plansza[0][6] = new Skoczek('W');
            Plansza[0][7] = new Wieza('W');
        }
        //deinicjalizacja pol planszy
        ~CPlansza(){
            for(int Wie = 0; Wie <8; ++Wie){
                for(int Kol = 0; Kol < 8; ++Kol){
                    delete Plansza[Wie][Kol];
                    Plansza[Wie][Kol] = 0;
                }
            }
        }

        void Print(){
            using namespace std;
            const int PoleSzer = 4;
            const int PoleWyso = 3;
            for(int Wie = 0; Wie<8*PoleWyso; ++Wie){
                int PoleWie = Wie/PoleWyso;
                //Boki z numerami
                if(Wie % 3 == 1){
                    cout<<"-"<<(char)('1' + 7 - PoleWie)<<"-";
                }else{
                    cout<<"---";
                }
                //pole szachowe
                for(int Kol = 0; Kol < 8*PoleSzer; ++Kol){
                    int PoleKol = Kol/PoleSzer;
                    if(((Wie %3) == 1) && ((Kol % 4 ) == 1 || (Kol % 4 ) == 2) && Plansza[7-PoleWie][PoleKol]!= 0){
                        if((Kol % 4) == 1 ){
                            cout<<Plansza[7-PoleWie][PoleKol]->GetKolor();
                        }else{
                            cout<<Plansza[7-PoleWie][PoleKol]->GetFigura();
                        }
                    }else{
                        if((PoleWie + PoleKol) % 2 == 1){
                            cout<<"*";
                        }else{
                            cout<<" ";
                        }
                    }
                }
                cout<<endl;
            }
            //Dol z numerami
            for(int Wie = 0; Wie <PoleWyso; ++Wie){
                if(Wie % 3 == 1){
                    cout<<"---";
                    for(int Kol = 0; Kol < 8*PoleSzer; ++Kol){
                        int PoleKol = Kol/PoleSzer;
                        if((Kol % 4) == 1){
                            cout<<(PoleKol + 1);
                        }else{
                            cout<<"-";
                        }
                    }
                    cout<<endl;
                }else{
                    for(int Kol = 1; Kol <9*PoleSzer; ++Kol){
                        cout<<"-";
                    }
                    cout<<endl;
                }
            }
            cout<<"\n";
            cout<<"\n";
            cout<<"\n";

        }

        bool Szach(char mKolor){
            //Znajdowanie krola
            int KrolWie;
            int KrolKol;
            for(int Wie = 0; Wie<8; ++Wie){
                for(int Kol = 0; Kol <8; ++Kol){
                    if(Plansza[Wie][Kol] != 0){
                        if(Plansza[Wie][Kol]->GetKolor() == mKolor){
                            if(Plansza[Wie][Kol]->GetFigura() == 'K'){
                                KrolKol = Kol;
                                KrolWie = Wie;
                            }
                        }
                    }
                }
            }
            //Sprawdzanie czy przecwine pionki moga zbic Krola
            for(int Wie = 0; Wie <8; ++Wie){
                for(int Kol = 0; Kol <8; ++Kol){
                    if(Plansza[Wie][Kol] != 0){
                        if(Plansza[Wie][Kol] -> GetKolor() != mKolor){
                            if(Plansza[Wie][Kol]->MozliweRuchy(Wie,Kol,KrolWie,KrolKol, Plansza)){
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }

        bool Ruch(char mKolor){
            //sprawdzanie po wszystkich figurach
            for(int Wie = 0; Wie <8; ++Wie){
                for(int Kol = 0; Kol<8; ++Kol){
                    if(Plansza[Wie][Kol] != 0){
                        //Jesli to jest pionek gracza ktory obecnie ma ture, sprawdz mozliwe ruchy
                        if(Plansza[Wie][Kol]->GetKolor() == mKolor){
                            for(int RuchWie = 0; RuchWie <8; ++RuchWie){
                                for(int RuchKol = 0; RuchKol <8; ++RuchKol){
                                    if(Plansza[Wie][Kol]->MozliweRuchy(Wie,Kol,RuchWie,RuchKol, Plansza)){
                                        //Zrob ruch i sprawdz czy krol jest w szachu 
                                        Figura* Temp = Plansza[RuchWie][RuchKol];
                                        Plansza[RuchWie][RuchKol] = Plansza[Wie][Kol];
                                        Plansza[Wie][Kol] == 0;
                                        bool bRuch = !Szach(mKolor);
                                        //wroc ruch
                                        Plansza[Wie][Kol] = Plansza[RuchWie][RuchKol];
                                        Plansza[RuchWie][RuchKol] = Temp;
                                        if(bRuch){
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return false;
        }

    
    Figura* Plansza[8][8];
};

#endif