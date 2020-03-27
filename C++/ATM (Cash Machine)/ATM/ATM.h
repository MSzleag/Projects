#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class ATM
{
private:
string name, surname;

public:
	
	ATM(string &name, string &surname);
	ATM();
	
	void logo();
	
	string get_name();
	string get_surname();
	
	void sign_up();
	
	string encryption(string &passw);
	string decryption(string &passw);
	
	int generate_id();
	int generate_pin_code();
};

