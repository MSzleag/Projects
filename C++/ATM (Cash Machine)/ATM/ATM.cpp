#include "ATM.h"

ATM::ATM() {}

ATM::ATM(string &name, string &surname) 
{
    this-> name = name;
    this-> surname = surname;
}

void ATM::logo() {



    cout << "************************************************* Welcome **************************************************************" << endl;
    cout << "****************************************** MMMfinance Bank Client ******************************************************" << endl;
    cout << endl;
    cout << "                           _        _           _         _           _        _ " << endl;
    cout << "                          /* *     /* *        /* *     /* *        /* *     /* * " << endl;
    cout << "                         / /* *   / /* *      / /* *   / /* *      / /* *   / /* * " << endl;
    cout << "                        / /  * * / /  * *    / /  * * / /  * *    / /  * * / /  * * " << endl;
    cout << "                       / /    *_/_/    * *  / /    *_/_/    * *  / /    *_/_/    * * " << endl;
    cout << "                      / /                *_/_/                *_/_/               * * " << endl;
    cout << "                     / /                                                           * * " << endl;
    cout << "                    /_/                                                             *_* " << endl;
    cout << endl;
}

string ATM::get_name() 
{
    return this->name;
}

string ATM::get_surname() 
{
    return this->surname;
}

int ATM::generate_id()
{
    srand(time(NULL));
    return (rand() % 10000 + 9999)* (rand() % 10000 + 9999);
}

int ATM::generate_pin_code() 
{
    srand(time(NULL));
    return rand() % 1000 + 999;
}

string ATM::encryption(string &passw)
{
    char* array;
    array = new char[passw.length()];
    char* pointer;
    pointer = array;

    for (int i = 0; i < passw.length(); i++)
    {
       
        pointer = &passw[i];
        *pointer = (((*pointer - 33) + (42)) % 94) + 33;

        pointer++;
    }
    delete[]array;
    return passw;
}

string ATM ::decryption(string &passw)
{
    char* array;
    array = new char[passw.length()];
    char* pointer;
    pointer = array;

    for (int i = 0; i < passw.length(); i++)
    {

        pointer = &passw[i];
        if ((*pointer - 42) >= 33) *pointer = *pointer - (42);
        else *pointer = *pointer - 42 + 94;

        pointer++;
    }
    delete[]array;
    return passw;

}

void ATM::sign_up() 
{
    fstream data;
    data.open("Data.txt", ios::out | ios::app);
    
    if (data.good() == false)
    {
        cout << "                   There's some problems with data files try again later";
        exit(0);
    }
    
    long int id = this->generate_id();
    int pin = this->generate_pin_code();
    cout << "                                SAVE THIS NUMBERS !!" << endl;
    cout << "                         Your ID ACCOUNT NUMBER: " << id << endl;
    cout << "                      Your CREDIT CARD PIN CODE: " << pin << endl;

    string passwd;
    
    while (1)
    {
        
        string pass_check;
        
        cout << "                              Write your Password: " << endl;
        cin >> passwd;
        cout << "                             Repeat your Password: " << endl;
        cin >> pass_check;
        
        if (passwd == pass_check)
        {
            break;
        }
       
        system("cls");
        cout << "                        Your Passwords didn't match Try again" << endl;
    }
    
    
    data << this->name << endl;
    data << this->surname << endl;
    data << pin << endl;
    data << this->encryption(passwd) << endl;
    data << 0 << endl;
    data << id << endl;
    data.close();
    
    cout << "                      Your account have been successfully created" << endl;
    system("pause");
    
}
