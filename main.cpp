#include <iostream>
#include "Account.h"
#include "Bank.h"
using namespace std;

int main()
{
	Bank mybank("bank", 123);
	mybank.read_from_file();
	while (true)
	{
		int menu_options;
		cout << "\n\t---------------\n";
		cout << "\t |1- Employee\n"
			<< "\t |2- Customer\n"
			<< "\t |3- Quit\n";
		cout << "\t |which one (1/2/3) ?? ";
		cin >> menu_options;
		system("CLS");// clear console
		if (menu_options == 1)
		{
			mybank.employee_login();
			
		}
		else if (menu_options == 2)
		{
			mybank.customer_login();
		}
		else if (menu_options == 3)
		{
			break;
		}
		else
		{
			cout << "\n\t Invlalid input";
		}
	}
	return 0;
}