#include "Account.h"
using namespace std;

Account::Account()
{
	status = false;
	acc_no = 0;
	cust_n_c = 0;
	balance = 0;
}

//get information
void Account::set_info(long long int n_code)
{
	cout << "\n\t Enter account number : ";
	cin >> acc_no;
	cust_n_c = n_code; //set national code
	cout << "\t Enter account opening date : ";
	cin >> opening_d;
	cout << "\t Enter balance : ";
	cin >> balance;

	//active account after get information
	status = true;
}

//print information
void Account::show_info()
{
	cout << "\n\t  Account number : " << acc_no << '\n';
	cout << "\t  Account opening date : " << opening_d << '\n';
	cout << "\t  Balance : " << balance << '\n';
	cout << "\t  Account status : ";
	if (status)
		cout << "Active\n";
	else
		cout << "Inactive\n";
}

void Account::add(double additional)
{
	balance += additional;
	add_report(additional);
	cout << "\t Amount added successfully\n";
}

void Account::subtract(double amount)
{
	if (status)
	{
		if (balance > amount)
		{
			balance -= amount;
			subtract_report(amount);
			cout << "\t Amount subtracted successfully\n";
		}
		else
		{
			cout << "\t Balance is NOT enough\n";
		}
	}
	else
	{
		cout << "\t Account is Inactive, you can not subtract\n";
	}
}

void Account::add_report(double amount)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Account with national code " << cust_n_c << " added balance with amount " << amount << " in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

void Account::subtract_report(double amount)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Account with national code " << cust_n_c << " subtracted from balance with amount " << amount << " in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

bool Account::get_status() { return status; }
long long int Account::get_acc_no() { return acc_no; }
long long int Account::get_cust_n_code() { return cust_n_c; }
std::string Account::get_opening_date() { return opening_d; }
double Account::get_balance() { return balance; }

void Account::set_status(bool t_status) { status = t_status; }
void Account::set_acc_no(long long int no) { acc_no = no; }
void Account::set_cust_n_code(long long int no) { cust_n_c = no; }
void Account::set_opening_date(std::string str) { opening_d = str; }
void Account::set_balance(double no) { balance = no; }