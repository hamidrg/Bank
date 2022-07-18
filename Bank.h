#ifndef BANK_H
#define BANK_H
#include "Person.h"

class Bank
{
private:
	std::string name;
	int code;
	std::vector <Employee> employees;
	std::vector <Customer> customers;
	Manager manager;
public:
	Bank(std::string n, int c);
	void manager_menu();
	void employee_menu(int index);
	void customer_menu(int index);

	//login:
	void employee_login();
	void customer_login();
	bool check_manager(std::string user, std::string pass);
	int check_employees(std::string user, std::string pass);
	int check_customers(std::string user, std::string pass);

	//search methods:
	int search_in_employees(int _emp_code);
	int search_in_customers(int _n_code);

	void show_manager_info();
	void show_employee_info(int index);
	void show_customer_info(int index);

	void add_employee();
	void delete_employee();

	void add_customer();
	void delete_customer();

	void make_an_account();
	void delete_an_account();

	void add_amount_to_acc(int index);
	void subtract_amount_from_acc(int index);

	void set_status_of_acc();

	void write_in_file();
	void write_manager();
	void write_employees();
	void write_customers();

	void read_from_file();
	void read_manager();
	void read_employees();
	void read_customers();
};


#endif