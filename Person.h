#ifndef PESRON_H
#define PERSON_H
#include <iostream>
#include <vector>
#include "Account.h"

class Person
{
protected:
	std::string f_name;
	std::string l_name;
	long long int national_code;
	std::string date_of_birth; // "1375/4/5"
	std::string username;
	std::string password;
public:
	Person();
	bool login(std::string user, std::string pass);
	virtual void login_report() = 0;
	virtual void show_info() = 0;
	virtual void set_info() = 0;

	
	std::string get_fname();
	std::string get_lname();
	long long int get_national_code();
	std::string get_birthday();
	std::string get_username();
	std::string get_password();

	void set_fname(std::string str);
	void set_lname(std::string str);
	void set_national_code(long long int no);
	void set_birthday(std::string str);
	void set_username(std::string str);
	void set_password(std::string str);
};

class Customer:public Person
{
private:
	std::vector <Account> accounts;
public:
	void login_report();
	void show_info();
	void set_info();

	int search_in_accounts(int t_acc_no);
	void add_account();
	void delete_account();

	void add_amount();
	void subtract_amount();

	void set_acc_status();
	void acc_status_report(char status);
	void create_acc_report();

	std::vector <Account> get_accounts();

	void set_accounts(std::vector <Account> t_accounts);
};

class Employee:public Person
{
protected:
	static int emp_generator;
	int emp_code;
	double salary;
	int hours_of_leave;
	int hours_of_overtime;
public:
	Employee();
	void leave_request();
	void overtime_request();

	void login_report();
	void leave_report(int hour);
	void overtime_report(int hour);
	void set_info();
	void show_info();

	int get_emp_code();
	double get_salary();
	int get_leave_hours();
	int get_overtime_hours();

	void set_emp_generator(int no);
	void set_emp_code(int no);
	void set_salary(double no);
	void set_leave_hours(int hours);
	void set_overtime_hours(int hours);
};

class Manager:public Employee
{
public:
	Manager();
};

#endif
