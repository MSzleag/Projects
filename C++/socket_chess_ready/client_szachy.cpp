#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include "figura.h"
#include "pionek.h"
#include "skoczek.h"
#include "goniec.h"
#include "wieza.h"
#include "krol.h"
#include "krolowa.h"
#include "plansza.h"
using namespace std;


class Szachy
{
public:
    Szachy(): TuraGracza('W'){}
    ~Szachy(){}

    void Start(int bytesRead, int bytesWritten, char clientSd){
        Instrukcja();
        PlanszaGry.Print();
        do{
            cout<<"Tura gracza: White(Client) "; 
            start1:
            char msg[1500];
            cout << "Ruch>";
            string data;
            getline(cin, data);
            memset(&msg, 0, sizeof(msg));//czyszczenie bufora
            strcpy(msg, data.c_str());
            int PoczWie = msg[0] - 49;
            int PoczKol = msg[1] - 49;
            int KoncWie = msg[3] - 49;
            int KoncKol = msg[4] - 49;
            int Promocja = msg[6] - 48;
            if(data == "exit")
            {
                //wysylanie wiadomosci o zakonczeniu polaczenia
                send(clientSd, (char*)&msg, strlen(msg), 0);
                break;
            }
            if(!GetNastRuch(PlanszaGry.Plansza,PoczWie, PoczKol, KoncWie, KoncKol, Promocja)){
                goto start1;
            }
            bytesWritten += send(clientSd, (char*)&msg, strlen(msg), 0);
            AltRuch();
            PlanszaGry.Print();
            cout<<"Tura gracza: Black(Server)."<<endl; 
            cout << "Oczekiwanie na ruch gracza Black(Server)..." << endl;
            memset(&msg, 0, sizeof(msg));//czyszczenie bufora
            bytesRead += recv(clientSd, (char*)&msg, sizeof(msg), 0);
            if(!strcmp(msg, "exit"))
            {
                cout << "Gracz Black(Server) opuscil sesje." << endl;
                break;
            }
            cout << "Ruch Gracza Black(Server): " << msg << endl;
            int PoczWie1 = msg[0] - 49;
            int PoczKol1 = msg[1] - 49;
            int KoncWie1 = msg[3] - 49;
            int KoncKol1 = msg[4] - 49;
            int Promocja1 = msg[6] - 48;
    
            GetNastRuch(PlanszaGry.Plansza,PoczWie1, PoczKol1, KoncWie1, KoncKol1, Promocja1);
            AltRuch();
            PlanszaGry.Print();
        }while(!GraSkoncz());
        PlanszaGry.Print();
    }

    bool GetNastRuch(Figura* Plansza[8][8], int PoczWie, int PoczKol, int KoncWie,int KoncKol, int Promocja){
        using namespace std;
        bool PrawidlowyRuch = false;
            //Sprawdz czy ruch jest zrobiony w polach planszy i czy aktulane pole figury i docelowe pole sa rozne
            if((PoczWie >= 0 && PoczWie <= 7) && (PoczKol >= 0 && PoczKol <= 7) && (KoncWie >=0 && KoncWie <=7) && (KoncKol >= 0 && KoncKol <= 7)){
                //zmienna do przechowywania obecnej figury 
                Figura* ObcFigura = Plansza[PoczWie][PoczKol];
                //sprawdz czy pionek jest takiego samego koloru co kolor tura gracza
                if((ObcFigura != 0) && (ObcFigura->GetKolor() == TuraGracza)){
                    //sprawdz czy pole docelowe jest prawidlowe
                    if(ObcFigura->MozliweRuchy(PoczWie, PoczKol, KoncWie, KoncKol, Plansza)){
                        //zrob ruch
                        Figura* Temp = Plansza[KoncWie][KoncKol];
                        Plansza[KoncWie][KoncKol] = Plansza[PoczWie][PoczKol];
                        Plansza[PoczWie][PoczKol] = 0;
                        //sprawdz czy obecny gracz nie jest w szachu
                        if(!PlanszaGry.Szach(TuraGracza)){
                            PrawidlowyRuch = true;
                        }else{//jesli jest w szachu cofnij ostatni ruch
                            cout<<"Krol jest w szachu!"<<endl;
                            Plansza[PoczWie][PoczKol] = Plansza[KoncWie][KoncKol];
                            Plansza[KoncWie][KoncKol] = Temp;
                        }
                        //Promocja pionka jesli dojdzie do krawedzi przeciwnika na odpowiednia figure wybrana przez gracza
                        if(PrawidlowyRuch && ObcFigura->GetFigura() == 'P' && (KoncWie == 7 || KoncWie == 0) && (0 < Promocja && Promocja <= 4)){
                            if(ObcFigura->GetKolor() == 'W'){
                                int i = Promocja;
                                switch(i)
                                {
                                    case 1:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Krolowa('W');
                                        break;
                                    case 2:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Goniec('W');
                                        break;
                                    case 3:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Skoczek('W');
                                        break;
                                    case 4:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Wieza('W');
                                        break;
                                }
                            }else{
                                int i = Promocja;
                                switch(i)
                                {
                                    case 1:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Krolowa('B');
                                        break;
                                    case 2:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Goniec('B');
                                        break;
                                    case 3:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Skoczek('B');
                                        break;
                                    case 4:
                                        Plansza[KoncWie][KoncKol] = 0;
                                        Plansza[KoncWie][KoncKol] = new Wieza('B');
                                        break;
                                }
                            
                            }
                            delete Temp;
                        }else if(PrawidlowyRuch && ObcFigura->GetFigura() == 'P' && (KoncWie == 7 || KoncWie == 0) && (0 >= Promocja || Promocja > 4)){
                            cout<<"Powtorz ruch i po spacji wybierz promocje "<<endl;
                            cout<<"Rodzaje promocji"<<endl;
                                cout<<"1 - Krolowa"<<endl;
                                cout<<"2 - Goniec"<<endl;
                                cout<<"3 - Skoczek"<<endl;
                                cout<<"4 - Wieza"<<endl;
                            Plansza[PoczWie][PoczKol] = Plansza[KoncWie][KoncKol];
                            Plansza[KoncWie][KoncKol] = Temp;
                            PrawidlowyRuch = false;
                        }else{
                            delete Temp;
                        }
                    }
                }
            }
            if(!PrawidlowyRuch){
                cout<<"Nieprawidlowy ruch!"<<endl;
                return false;
            }
        return true;
    }

    void AltRuch(){
        TuraGracza = (TuraGracza == 'W') ? 'B': 'W';
    }

    bool GraSkoncz(){
        //sprawdz czy obecny gracz moze wykonac ruch, jesli nie to szach-mat lub sytuacja bez wyjscia
        bool bRuch(false);
        bRuch = PlanszaGry.Ruch(TuraGracza);
        if(!bRuch){
            if(PlanszaGry.Szach(TuraGracza)){
                AltRuch();
                std::cout<<"Szach-mat, "<<TuraGracza<<" Wygrywa!"<<std::endl;
            }else{
                std::cout<<"Nie ma mozliwego ruchu!"<<std::endl;
            }
        }
        return !bRuch;
    }

    void Instrukcja(void){
        cout<<"Witamy w grze szachy online!"<<endl;
        cout<<"Ruchy sa wykonywane przez gracza na zmiane"<<endl;
        cout<<"Wykonywanie ruchu odbywa sie za pomoca wprowadzenia pola figury ktora chcemy wykonac ruch i pola docelowego."<<endl;
        cout<<"Numery wprowadzamy w taki sposob [NumerWierszaFigury][NumerKolumnyFigury] [NumerWierszaPolaDocelowego][NumerKolumnyPolaDocelowego]"<<endl;
        cout<<"Jesli pionek znajdzie sie na krawedzi planszy po stronie przeciwnika nalezy podac ruch i po spacji numer promocji"<<endl;
        cout<<"Rodzaje promocji"<<endl;
        cout<<"1 - Krolowa"<<endl;
        cout<<"2 - Goniec"<<endl;
        cout<<"3 - Skoczek"<<endl;
        cout<<"4 - Wieza"<<endl;
        cout<<"Przyklad [NumerWierszaFigury][NumerKolumnyFigury] [NumerWierszaPolaDocelowego][NumerKolumnyPolaDocelowego] [NumerPromocji]"<<endl;
        cout<<"Milej Gry"<<endl;
    }


private:
    CPlansza PlanszaGry;
    char TuraGracza;

};


int main(int argc, char *argv[])
{   Szachy Gra;
    //podajemy dwa argumenty IP i numer portu np. 127.0.0.1 12345
    if(argc != 3)
    {
        cerr << "Uzyj: IP_address & port" << endl; exit(0); 
    } 
    char *serverIp = argv[1]; int port = atoi(argv[2]); 
    //tworzymy gniazdo i polaczenie
    struct hostent* host = gethostbyname(serverIp); 
    sockaddr_in sendSockAddr;   
    bzero((char*)&sendSockAddr, sizeof(sendSockAddr)); 
    sendSockAddr.sin_family = AF_INET; 
    sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    sendSockAddr.sin_port = htons(port);
    int clientSd = socket(AF_INET, SOCK_STREAM, 0);
    //proba polaczenia z serverem 
    int status = connect(clientSd,(sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(status < 0)
    {
        cout<<"Nie mozna polaczyc sie z serverem!"<<endl;
        exit(0);
    }
    cout << "Polaczenie zostalo nawiazane!" << endl;
    int bytesRead, bytesWritten = 0;
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    Gra.Start(bytesRead, bytesWritten, clientSd);
    gettimeofday(&end1, NULL);
    close(clientSd);
    cout << "********Zakonczenie sesji********" << endl;
    cout << "Ilosc bajtow wyslanych: " << bytesWritten << " Ilosc bajtow odebranych: " << bytesRead << endl;
    cout << "Czas polaczenia(gry): " << (end1.tv_sec- start1.tv_sec) << " sekund" << endl;
    cout << "Polaczenie zakonczone." << endl;
    return 0;    
}