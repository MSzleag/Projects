#include "Account.h"

Account::Account(long int id_nr, string passwd, string name, string surname)
    :ATM(name, surname)
{

    this->id_nr = id_nr;
    this->passwd = passwd;
    this->card_id = atoi(search_in_data(3, id_nr).c_str());
    this->balance = atoi(search_in_data(5, id_nr).c_str());

}

Account::Account(){}

long int Account::get_id_nr()
{
    return this->id_nr;
}

int Account::get_card_id()
{
    return this->card_id;
}

int Account::get_balance()
{
    return this->balance;
}

string Account::get_passwd()
{
    return this->passwd;
}

bool Account::check_pin(int& card_id)
{
    if (card_id == this->card_id) return true;
    else return false;
}

bool Account::sign_in(long int& id_nr, string& passwd)
{

    fstream data;
    data.open("Data.txt", ios::in);

    if (data.good() == false)
    {
        cout << "                            There's some problems with data files try again later";
        exit(0);
    }

    string str_id;
    string* searched;
    searched = new string[6];
    
    string* pointer;
    pointer = searched;
    
    for (int i = 0; getline(data, str_id); i++)
    {
        *pointer = str_id;
        if (*pointer == to_string(id_nr)) break;
        pointer++;
        if (i == 5)
        {
            pointer -= 6;
            i -= 6;
        }
    }

    if (decryption(*(searched + 3)) == passwd) return true;
    else return false;
    data.close();
}

string Account::search_in_data(int which,long int& id_nr) 
{
    fstream data;
    data.open("Data.txt", ios::in);

    if (data.good() == false)
    {
        cout << "                            There's some problems with data files try again later";
        exit(0);
    }
    
    string str_id;
    string *searched;
    searched = new string[6];
    
    string* pointer;
    pointer = searched;
    
    for (int i = 0; getline(data, str_id); i++)
    {
        *pointer = str_id;
        if (*pointer == to_string(id_nr)) break;
        pointer++;
        if (i == 5)
        {
            pointer -= 6;
            i -= 6;
        }
    }

    if (which == 4) return this->decryption(*(searched + which - 1));
    else return *(searched +which -1);
    data.close();
}

void Account::deposit(int& amount)
{
    vector <string> data_vector;

    fstream data;
    data.open("Data.txt", ios::in);

    if (data.good() == false)
    {
        cout << "                            There's some problems with data files try again later";
        exit(0);
    }

    string data_line;
    for (int i = 0; getline(data, data_line); i++)
    {
        data_vector.push_back(data_line);
    }

    data.close();

    this->balance += amount;

    for (int i = 0; i < data_vector.size(); i++)
    {
        if (data_vector[i] == to_string(this->id_nr))
        {
            data_vector[i - 1] = to_string(this->balance);
            break;
        }
    }

    data.open("Data.txt", ios::out | ios::trunc);

    if (data.good() == false)
    {
        cout << "                   There's some problems with data files try again later";
        exit(0);
    }


    for (int i = 0; i < data_vector.size(); i++)
    {
        data << data_vector[i] << endl;
    }

    data.close();
    cout << "Succes!" << endl;
}
void Account::withdraw(int& amount) 
{

    if (amount > this->balance) cout << "You don't have enough money for that";
    else
    {
        amount = amount * (-1);
        deposit(amount);
    }

}

void Account::transfer(long int& id_nr, int& amount)
{
    if (amount > this->balance) cout << "You don't have enough money for that" << endl;
    else if (search_in_data(6, id_nr) != to_string(id_nr)) cout << "This ID Number doesn't exists in our data" << endl;
    else
    {
        vector <string> data_vector;

        fstream data;
        data.open("Data.txt", ios::in);

        if (data.good() == false)
        {
            cout << "                            There's some problems with data files try again later";
            exit(0);
        }

        string data_line;
        for (int i = 0; getline(data, data_line); i++)
        {
            data_vector.push_back(data_line);
        }

        data.close();


        for (int i = 0; i < data_vector.size(); i++)
        {
            if (data_vector[i] == to_string(id_nr))
            {
                int new_balance = atoi(data_vector[i - 1].c_str()) + amount;
                data_vector[i - 1] = to_string(new_balance);
                break;
            }
        }

        data.open("Data.txt", ios::out | ios::trunc);

        if (data.good() == false)
        {
            cout << "                   There's some problems with data files try again later";
            exit(0);
        }


        for (int i = 0; i < data_vector.size(); i++)
        {
            data << data_vector[i] << endl;
        }

        data.close();
        withdraw(amount);
    }
    

}


void Account::change_passwd(string& passwd)
{
    vector <string> data_vector;

    fstream data;
    data.open("Data.txt", ios::in);

    if (data.good() == false)
    {
        cout << "                            There's some problems with data files try again later";
        exit(0);
    }

    string data_line;
    for (int i = 0; getline(data, data_line); i++)
    {
        data_vector.push_back(data_line);
    }

    data.close();


    for (int i = 0; i < data_vector.size(); i++)
    {
        if (data_vector[i] == to_string(id_nr))
        {
            data_vector[i - 2] = encryption(passwd);
            break;
        }
    }

    data.open("Data.txt", ios::out | ios::trunc);

    if (data.good() == false)
    {
        cout << "                   There's some problems with data files try again later";
        exit(0);
    }


    for (int i = 0; i < data_vector.size(); i++)
    {
        data << data_vector[i] << endl;
    }
    this->passwd = passwd;
    data.close();
}

void Account::change_pin(int& card_id)
{
    vector <string> data_vector;

    fstream data;
    data.open("Data.txt", ios::in);

    if (data.good() == false)
    {
        cout << "                            There's some problems with data files try again later";
        exit(0);
    }

    string data_line;
    for (int i = 0; getline(data, data_line); i++)
    {
        data_vector.push_back(data_line);
    }

    data.close();


    for (int i = 0; i < data_vector.size(); i++)
    {
        if (data_vector[i] == to_string(id_nr))
        {
            data_vector[i - 3] = to_string(card_id);
            break;
        }
    }

    data.open("Data.txt", ios::out | ios::trunc);

    if (data.good() == false)
    {
        cout << "                   There's some problems with data files try again later";
        exit(0);
    }


    for (int i = 0; i < data_vector.size(); i++)
    {
        data << data_vector[i] << endl;
    }
    this->card_id = card_id;
    data.close();
}

