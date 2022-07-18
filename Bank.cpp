#include <iostream>
#include "Bank.h"
using namespace std;

Bank::Bank(std::string n, int c)
{
	name = n;
	code = c;
}

//employee login
void Bank::employee_login()
{
	string pass, user;
	cout << "\t Enter username : ";
	cin >> user;
	cout << "\t Enter password : ";
	cin >> pass;

	bool check = false;
	if (check_manager(user, pass))
	{
		check = true;
		manager.login_report();
		manager_menu();
	}

	if (check == false)
	{
		int result = check_employees(user, pass);
		if (result == -1)
		{
			cout << "\t Username or password is incorrect\n";
		}
		else
		{
			employees.at(result).login_report();
			employee_menu(result);
		}
	}
}

//customer login
void Bank::customer_login()
{
	string pass, user;
	cout << "\t Enter username : ";
	cin >> user;
	cout << "\t Enter password : ";
	cin >> pass;

	int result = check_customers(user, pass);
	if (result == -1)
	{
		cout << "\t Username or password is incorrect\n";
	}
	else
	{
		customers.at(result).login_report();
		customer_menu(result);
	}
}

//manager menu
void Bank::manager_menu()
{
	while (true)
	{
		int menu_options;
		cout << "\n\t---------------\n";
		cout << "\t |1- Leave request\n"
			<< "\t |2- Overtime request\n"
			<< "\t |3- Show my profile\n"
			<< "\t |4- Add a customer\n"
			<< "\t |5- Delete a customer\n"
			<< "\t |6- Show information of customer\n"
			<< "\t |7- Make an account for customer\n"
			<< "\t |8- Set status of an account\n"
			<< "\t |9- Delete an account\n"
			<< "\t |10- Show information of employee\n"
			<< "\t |11- Add an employee\n"
			<< "\t |12- Delete an employee\n"
			<< "\t |13- Quit\n";
		cout << "\t |which one  ?? ";
		cin >> menu_options;
		system("CLS");// clear console
		if (menu_options == 1)
		{
			manager.leave_request();
		}
		else if (menu_options == 2)
		{
			manager.overtime_request();
		}
		else if (menu_options == 3)
		{
			show_manager_info();
		}
		else if (menu_options == 4)
		{
			add_customer();
		}
		else if (menu_options == 5)
		{
			delete_customer();
		}
		else if (menu_options == 6)
		{
			long long int t_n_code;
			cout << "\t Enter national code : ";
			cin >> t_n_code;
			int index = search_in_customers(t_n_code);

			if (index == -1)
			{
				cout << "\t Customer NOT found\n";
			}
			else
			{
				show_customer_info(index);
			}
		}
		else if (menu_options == 7)
		{
			make_an_account();
		}
		else if (menu_options == 8)
		{
			set_status_of_acc();
		}
		else if (menu_options == 9)
		{
			delete_an_account();
		}
		else if (menu_options == 10)
		{
			int t_emp_code;
			cout << "\t Enter employee code : ";
			cin >> t_emp_code;
			int index = search_in_employees(t_emp_code);

			if (index == -1)
			{
				cout << "\t Employee Not found\n";
			}
			else
			{
				show_employee_info(index);
			}
		}
		else if (menu_options == 11)
		{
			add_employee();
		}
		else if (menu_options == 12)
		{
			delete_employee();
		}
		else if (menu_options == 13)
		{
			write_in_file();
			break;
		}
		else
		{
			cout << "\n\t Invlalid input";
		}
	}
}

//employee menu
void Bank::employee_menu(int index)
{
	while (true)
	{
		int menu_options;
		cout << "\n\t---------------\n";
		cout << "\t |1- Leave request\n"
			<< "\t |2- Overtime request\n"
			<< "\t |3- Show my profile\n"
			<< "\t |4- Add Customer\n"
			<< "\t |5- Delete Customer\n"
			<< "\t |6- Show information of customer\n"
			<< "\t |7- Make an account for customer\n"
			<< "\t |8- Set status of an account\n"
			<< "\t |9- Delete an account\n"
			<< "\t |10- Quit\n";
		cout << "\t |which one  ?? ";
		cin >> menu_options;
		system("CLS");// clear console
		if (menu_options == 1)
		{
			employees.at(index).leave_request();
		}
		else if (menu_options == 2)
		{
			employees.at(index).overtime_request();
		}
		else if (menu_options == 3)
		{
			show_employee_info(index);
		}
		else if (menu_options == 4)
		{
			add_customer();
		}
		else if (menu_options == 5)
		{
			delete_customer();
		}
		else if (menu_options == 6)
		{
			long long int t_n_code;
			cout << "\t Enter national code : ";
			cin >> t_n_code;
			int index = search_in_customers(t_n_code);

			if (index == -1)
			{
				cout << "\t Customer NOT found\n";
			}
			else
			{
				show_customer_info(index);
			}
		}
		else if (menu_options == 7)
		{
			make_an_account();
		}
		else if (menu_options == 8)
		{
			set_status_of_acc();
		}
		else if (menu_options == 9)
		{
			delete_an_account();
		}
		else if (menu_options == 10)
		{
			write_in_file();
			break;
		}
		else
		{
			cout << "\n\t Invlalid input";
		}
	}
}

//customer menu
void Bank::customer_menu(int index)
{
	while (true)
	{
		int menu_options;
		cout << "\n\t---------------\n";
		cout << "\t |1- Add amount to account\n"
			<< "\t |2- Subtract from account\n"
			<< "\t |3- Show my profile\n"
			<< "\t |4- Quit\n";
		cout << "\t |which one  ?? ";
		cin >> menu_options;
		system("CLS");// clear console
		if (menu_options == 1)
		{
			add_amount_to_acc(index);
		}
		else if (menu_options == 2)
		{
			subtract_amount_from_acc(index);
		}
		else if (menu_options == 3)
		{
			show_customer_info(index);
		}
		else if (menu_options == 4)
		{
			write_in_file();
			break;
		}
		else
		{
			cout << "\n\t Invlalid input";
		}
	}
}

bool Bank::check_manager(std::string user, std::string pass)
{
	if (manager.login(user, pass))
	{
		if (manager.get_national_code() == 0)
		{
			manager.set_info();
		}
		return true;
	}
	else
		return false;
}

int Bank::check_employees(std::string user, std::string pass)
{
	// search in employee
	for (int i = 0; i < employees.size(); ++i)
	{
		if (employees.at(i).login(user, pass))
		{
			return i;
		}
	}
	return -1; // if employee not found return -1
}

int Bank::check_customers(std::string user, std::string pass)
{
	// search in customers
	for (int i = 0; i < customers.size(); ++i)
	{
		if (customers.at(i).login(user, pass))
		{
			return i;
		}
	}

	return -1; // if customer not found return -1
}

//search in employees
int Bank::search_in_employees(int _emp_code)
{
	for (int i = 0; i < employees.size(); ++i)
	{
		if (employees.at(i).get_emp_code() == _emp_code)
		{
			return i;
		}
	}
	return -1; // if employee not found return -1
}

//search in customers
int Bank::search_in_customers(int _n_code)
{
	for (int i = 0; i < customers.size(); ++i)
	{
		if (customers.at(i).get_national_code() == _n_code)
		{
			return i;
		}
	}

	return -1; // if customer not found return -1
}

void Bank::add_employee()
{
	Employee t_emp;
	t_emp.set_info();
	employees.push_back(t_emp);
}

void Bank::delete_employee()
{
	int t_emp_code;
	cout << "\tEnter employee code : ";
	cin >> t_emp_code;
	int index = search_in_employees(t_emp_code);

	if (index == -1)
	{
		cout << "\t Employee Not found\n";
	}
	else
	{
		employees.at(index).show_info();
		char check;
		cout << "\t Are you sure you want to delete this employee (y/n) : ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			employees.erase(employees.begin() + index);
			employees.shrink_to_fit();
			cout << "\t Employee deleted successfully\n";
		}
	}
}

void Bank::show_manager_info()
{
	manager.show_info();
}

void Bank::show_employee_info(int index)
{
	employees.at(index).show_info();
}

void Bank::show_customer_info(int index)
{
	customers.at(index).show_info();
}

void Bank::add_customer()
{
	Customer temp;
	temp.set_info();
	if (search_in_customers(temp.get_national_code()) == -1) // this mean there is no one with this national code
	{
		customers.push_back(temp);
		cout << "\t Customer added successfully\n";
	}
	else
	{
		cout << "\t Customer with this national code have already been added\n";
	}
}

void Bank::delete_customer()
{
	long long int t_n_code;
	cout << "\t Enter national code : ";
	cin >> t_n_code;
	int index = search_in_customers(t_n_code);

	if (index == -1)
	{
		cout << "\t Customer Not found\n";
	}
	else
	{
		customers.at(index).show_info();
		char check;
		cout << "\t Are you sure you want to delete this customer (y/n) : ";
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			customers.erase(customers.begin() + index);
			customers.shrink_to_fit();
			cout << "\t Customer deleted successfully\n";
		}
	}
}

void Bank::make_an_account()
{
	long long int t_n_code;
	cout << "\t Enter national code : ";
	cin >> t_n_code;
	int index = search_in_customers(t_n_code);

	if (index == -1)
	{
		cout << "\t Customer Not found\n";
	}
	else
	{
		customers.at(index).add_account();
	}
}

void Bank::delete_an_account()
{
	long long int t_n_code;
	cout << "\t Enter national code : ";
	cin >> t_n_code;
	int index = search_in_customers(t_n_code);

	if (index == -1)
	{
		cout << "\t Customer Not found\n";
	}
	else
	{
		customers.at(index).delete_account();
	}
}

void Bank::add_amount_to_acc(int index)
{
	customers.at(index).add_amount();
}

void Bank::subtract_amount_from_acc(int index)
{
	customers.at(index).subtract_amount();
}

void Bank::set_status_of_acc()
{
	long long int t_n_code;
	cout << "\t Enter national code : ";
	cin >> t_n_code;
	int index = search_in_customers(t_n_code);

	if (index == -1)
	{
		cout << "\t Customer Not found\n";
	}
	else
	{
		customers.at(index).set_acc_status();
	}
}

void Bank::write_manager()
{
	ofstream fout("manager.txt", ios::trunc);

	if (fout.is_open())
	{
		fout << manager.get_fname() << '\t';
		fout << manager.get_lname() << '\t';
		fout << manager.get_national_code() << '\t';
		fout << manager.get_birthday() << '\t';
		fout << manager.get_username() << '\t';
		fout << manager.get_password() << '\t';
		fout << manager.get_emp_code() << '\t';
		fout << manager.get_salary() << '\t';
		fout << manager.get_leave_hours() << '\t';
		fout << manager.get_overtime_hours() << '\n';
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open manager.txt file\n";
	}
}

void Bank::write_employees()
{
	ofstream fout("employee.txt", ios::trunc);

	if (fout.is_open())
	{
		fout << employees.size() << '\n';
		for (int i = 0; i < employees.size(); ++i)
		{
			fout << employees.at(i).get_fname() << '\t';
			fout << employees.at(i).get_lname() << '\t';
			fout << employees.at(i).get_national_code() << '\t';
			fout << employees.at(i).get_birthday() << '\t';
			fout << employees.at(i).get_username() << '\t';
			fout << employees.at(i).get_password() << '\t';
			fout << employees.at(i).get_emp_code() << '\t';
			fout << employees.at(i).get_salary() << '\t';
			fout << employees.at(i).get_leave_hours() << '\t';
			fout << employees.at(i).get_overtime_hours() << '\n';
		}
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open employee.txt file\n";
	}
}

void Bank::write_customers()
{
	ofstream fout("customer.txt", ios::trunc);

	if (fout.is_open())
	{
		fout << customers.size() << '\n';
		for (int i = 0; i < customers.size(); ++i)
		{
			fout << customers.at(i).get_fname() << '\t';
			fout << customers.at(i).get_lname() << '\t';
			fout << customers.at(i).get_national_code() << '\t';
			fout << customers.at(i).get_birthday() << '\t';
			fout << customers.at(i).get_username() << '\t';
			fout << customers.at(i).get_password() << '\t';
			fout << customers.at(i).get_accounts().size() << '\t';
			for (int j = 0; j < customers.at(i).get_accounts().size(); ++j)
			{
				fout << customers.at(i).get_accounts().at(j).get_status() << '\t';
				fout << customers.at(i).get_accounts().at(j).get_acc_no() << '\t';
				fout << customers.at(i).get_accounts().at(j).get_cust_n_code() << '\t';
				fout << customers.at(i).get_accounts().at(j).get_opening_date() << '\t';
				fout << customers.at(i).get_accounts().at(j).get_balance() << '\t';
			}
			fout << '\n';
		}
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open employee.txt file\n";
	}
}

void Bank::write_in_file()
{
	write_manager();
	write_employees();
	write_customers();
}

void Bank::read_manager()
{
	ifstream fin("manager.txt", ios::in);

	if (fin.is_open())
	{
		string str;
		long long int no;
		double amount;

		fin >> str; // read firstname
		manager.set_fname(str);
		fin >> str; // read lastname
		manager.set_lname(str);
		fin >> no; // read national code
		manager.set_national_code(no);
		fin >> str; // read birthday
		manager.set_birthday(str);
		fin >> str; // read username
		manager.set_username(str);
		fin >> str; // read password
		manager.set_password(str);
		fin >> no; // read employee code
		manager.set_emp_code(no);
		fin >> amount; // read salary
		manager.set_salary(amount);
		fin >> no; // read leave hours
		manager.set_leave_hours(no);
		fin >> no; // read overtime hours
		manager.set_overtime_hours(no);

		fin.close();
	}
	else
	{
		cerr << "\n\t Unable to open manager.txt file\n";
	}
}

void Bank::read_employees()
{
	ifstream fin("employee.txt", ios::in);

	if (fin.is_open())
	{
		int size;
		string str;
		long long int no;
		double amount;

		fin >> size; // read size of employees vector
		for (int i = 0; i < size; ++i)
		{
			Employee temp;
			fin >> str; // read firstname
			temp.set_fname(str);
			fin >> str; // read lastname
			temp.set_lname(str);
			fin >> no; // read national code
			temp.set_national_code(no);
			fin >> str; // read birthday
			temp.set_birthday(str);
			fin >> str; // read username
			temp.set_username(str);
			fin >> str; // read password
			temp.set_password(str);
			fin >> no; // read employee code
			temp.set_emp_code(no);
			fin >> amount; // read salary
			temp.set_salary(amount);
			fin >> no; // read leave hours
			temp.set_leave_hours(no);
			fin >> no; // read overtime hours
			temp.set_overtime_hours(no);

			employees.push_back(temp);
		}
		fin.close();
	}
	else
	{
		cerr << "\n\t Unable to open employee.txt file\n";
	}
}

void Bank::read_customers()
{
	ifstream fin("customer.txt", ios::in);

	if (fin.is_open())
	{
		int size1, size2;
		string str;
		long long int no;
		double amount;

		fin >> size1; // read size of customers vector
		for (int i = 0; i < size1; ++i)
		{
			Customer temp;
			fin >> str; // read firstname
			temp.set_fname(str);
			fin >> str; // read lastname
			temp.set_lname(str);
			fin >> no; // read national code
			temp.set_national_code(no);
			fin >> str; // read birthday
			temp.set_birthday(str);
			fin >> str; // read username
			temp.set_username(str);
			fin >> str; // read password
			temp.set_password(str);

			vector <Account> t_accounts;
			fin >> size2; // read size of accounts vector
			for (int j = 0; j < size2; ++j)
			{
				Account temp2;
				fin >> no; // read status : 1 for active, 2 for inactive
				temp2.set_status(no);
				fin >> no; // read account number
				temp2.set_acc_no(no);
				fin >> no; // read customer national code
				temp2.set_cust_n_code(no);
				fin >> str; // read opening date of account
				temp2.set_opening_date(str);
				fin >> amount; // read account balance
				temp2.set_balance(amount);

				t_accounts.push_back(temp2);
			}
			temp.set_accounts(t_accounts);
			customers.push_back(temp);
		}
		fin.close();
	}
	else
	{
		cerr << "\n\t Unable to open customer.txt file\n";
	}
}

void Bank::read_from_file()
{
	read_manager();
	read_employees();
	read_customers();
}