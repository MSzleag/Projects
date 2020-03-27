#include "Account.h"

using namespace std;


int main()
{
	while (1)
	{
		system("cls");

		Account start;
		start.logo();

		cout << "                                       Click your chosen option" << endl;
		cout << "                                              1.SIGN IN" << endl;
		cout << "                                              2.SIGN UP" << endl;
		cout << "                                              3.EXIT" << endl;


		char choise;
		choise = _getch();

		switch (choise)
		{
		case '1':
		{
			long int id_new;
			string passwd;
			while (1)
			{

				for (int i = 0; i < 3; i++)
				{
					system("cls");

					start.logo();

					cout << "                                    Enter your ID Number" << endl;
					cin >> id_new;

					cout << "                                    Enter your Password" << endl;
					cin >> passwd;
				
					if (start.sign_in(id_new, passwd) == false)
					{
						cout << "Wrong ID Number or Password Try Again";
						system("pause");
					}
					else
					{
						Account logged(id_new, passwd, start.search_in_data(1, id_new), start.search_in_data(2, id_new));
						while (1)
						{
							system("cls");

							start.logo();
							cout << "                                       Welcome " << logged.get_name() << " " << logged.get_surname() << endl;
							cout << "                                       Click your chosen option" << endl;
							cout << "                                              1.Withdraw Money" << endl;
							cout << "                                              2.Deposit Money" << endl;
							cout << "                                              3.Transfer Money" << endl;
							cout << "                                              4.Change Card ID" << endl;
							cout << "                                              5.Change Password" << endl;
							cout << "                                              6.Exit" << endl;

							int amount, pin;
							long int id;
							choise = _getch();

							switch (choise)
							{
							case '1':
							{
								for (size_t i = 0; i < 3; i++)
								{
									cout << "                                       Enter your Card PIN" << endl;
									cin >> pin;
									if (logged.get_card_id() == pin)
									{
										cout << "                                   How much money you want to Withdraw?" << endl;
										cin >> amount;
										logged.withdraw(amount);
										break;
									}
									else 
									{
										cout << "                                    Wrong PIN" << endl;
										break;
									}
									
								}
								break;
							}

							case '2':
							{
								for (size_t i = 0; i < 3; i++)
								{
									cout << "                                       Enter your Card PIN" << endl;
									cin >> pin;
									if (logged.get_card_id() == pin)
									{
										cout << "                                   How much money you want to Deposit?" << endl;
										cin >> amount;
										logged.deposit(amount);
										break;
									}
									else
									{
										cout << "                                    Wrong PIN" << endl;
										break;
									}

								}

								break;
							}

							case '3':
							{
								for (size_t i = 0; i < 3; i++)
								{
									cout << "                                       Enter your Card PIN" << endl;
									cin >> pin;
									if (logged.get_card_id() == pin)
									{
										cout << "                                   Enter ID Number of your target account" << endl;
										cin >> id;
										cout << "                                   How much money you want to Transfer?" << endl;
										cin >> amount;

										logged.transfer(id, amount);
										break;
									}
									else
									{
										cout << "                                    Wrong PIN" << endl;
										break;
									}

								}

								break;
							}

							case '4':
							{
								cout << "                                       Enter old Card PIN" << endl;
								cin >> pin;
								if (logged.check_pin(pin))
								{

									for (int i = 0; i < 3; i++)
									{
										int* new_pin;
										new_pin = &pin;

										cout << "                               Enter your new PIN" << endl;
										cin >> *new_pin;

										int pin_check;
										cout << "                               Confirm your new PIN" << endl;
										cin >> pin_check;

										if (pin == pin_check)
										{
											logged.change_pin(*new_pin); 
											cout << "                                    Succes!" << endl; 
											break;
										}
										else
										{
											cout << "                               Error with Confirmation try again" << endl;
										}
									}

								}
								
								else
								{
									cout << "Wrong PIN" << endl; system("pause"); break;
								}
								break;
							}

							case '5':
							{
								cout << "                                   Enter old Password" << endl;
								cin >> passwd;
								if (logged.get_passwd() == passwd)
								{

									for (int i = 0; i < 3; i++)
									{
										string* new_passwd;
										new_passwd = &passwd;

										cout << "                               Enter your new Password" << endl;
										cin >> *new_passwd;

										string passwd_check;
										cout << "                               Confirm your Password" << endl;
										cin >> passwd_check;

										if (passwd == passwd_check)
										{
											logged.change_passwd(*new_passwd);
											cout << "                                    Succes!" << endl;
											break;
										}

										else
										{
											cout << "                               Error with Confirmation try again" << endl;
										}
										
									}

								}

								else
								{
									cout << "Wrong Password" << endl; 
									system("pause"); 
									break;
								}
								break;
							}

							case '6': exit(0);

							default: cout << "Wrong Input" << endl; break;
							}
							system("pause");
						}
					}
				}
				break;

			}
			break;
			

		}

		case '2':
		{
			system("cls");
			start.logo();
			string name, surname;
			
			cout << "                                      EXIT TO GO BACK " << endl;
			cout << "                                      Enter your Name" << endl;
			cin >> name;

			if (name == "exit" || name == "EXIT")
			{
				break;
			}
			
			cout << "                                    Enter your Surname" << endl;
			cin >> surname;

			if ( surname == "exit" || surname == "EXIT")
			{
				break;
			}
			
			ATM new_account(name,surname);
			new_account.sign_up();
			
			break;
		}

		case '3': exit(0);
		
		default: cout << endl << "                                  Wrong Input  "; system("pause"); break;

		}
	}
}


