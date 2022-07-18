#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <fstream>
#include <windows.h> // get system date and time

class Account
{
	bool status; // status of account : active or inactive
	long long int acc_no; // account number
	long long int cust_n_c; // national code of customer
	std::string opening_d; // opening date of account
	double balance;
public:
	Account(); // constructor

	void set_info(long long int n_code); // (argument is national code)
	void show_info();

	void add(double amount); // add amount to balance
	void subtract(double amount); // subtract amount from balance

	void add_report(double amount);
	void subtract_report(double amount);

	bool get_status();
	long long int get_acc_no();
	long long int get_cust_n_code();
	std::string get_opening_date();
	double get_balance();

	void set_status(bool t_status);
	void set_acc_no(long long int no);
	void set_cust_n_code(long long int no);
	void set_opening_date(std::string str);
	void set_balance(double no);
};

#endif 
