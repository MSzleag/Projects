#pragma once
#include "ATM.h"
class Account :
	public ATM
{
private:
	int card_id;
	long int id_nr, balance;
	string passwd;
public:	
	
	Account(long int id_nr, string passwd, string name, string surname);
	Account();
	
	long int get_id_nr();
	int get_card_id();
	int get_balance();
	string get_passwd();


	bool sign_in(long int& id_nr, string& passwd);
	
	string search_in_data(int which,long int& id_nr); // variable which is the number that represents what you want to find in data file.
													 // 1-name 2-surname 3-Card PIN 4-passwd 5-Balance 6-ID Number

	void withdraw(int& amount);
	void deposit(int& amount);
	void transfer(long int& id_nr, int& amount);

	bool check_pin(int& card_id);
	void change_passwd(string& passwd);
	void change_pin(int& card_id);
};

