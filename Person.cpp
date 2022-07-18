#include "Person.h"
using namespace std;

int Employee::emp_generator = 100;

Person::Person()
{
	national_code = 0;
}

bool Person::login(std::string user, std::string pass)
{
	if (username == user && password == pass)
		return true;
	else
		return false;
}

Employee::Employee()
{
	emp_code = emp_generator++;
	salary = 0;
	hours_of_leave = 0;
	hours_of_overtime = 0;
}

Manager::Manager()
{
	username = "admin";
	password = "admin";
}

void Employee::leave_request()
{
	cout << "\tNumber of hours allowed for leave : ";
	if (15 - hours_of_leave > 0)
	{
		cout << 15 - hours_of_leave << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	int hour;
	cout << "\tHow many hours do you want for leave : ";
	cin >> hour;

	if (hour <= 0 || hour > 15)
	{
		cout << "\tInvalid input";
	}
	else
	{
		if (hours_of_leave + hour <= 15)
		{
			hours_of_leave += hour;
			leave_report(hour);
			cout << "\tRequest accepted\n";
			cout << "\tHours of leave : " << hours_of_leave;
		}
		else
		{
			char keep_going;
			int extra_hour = (hours_of_leave + hour) - 15;

			cout << '\t' << extra_hour * 100 << " thousand Toman will subtract from your salary, do you want to continue : (y/n) ";
			cin >> keep_going;
			if (keep_going == 'Y' || keep_going == 'y')
			{
				hours_of_leave += hour;
				salary -= (extra_hour * 100);
				leave_report(hour);
				cout << "\tRequest accepted\n";
				cout << "\tHours of leave : " << hours_of_leave;
			}
		}
	}
}

void Employee::overtime_request()
{
	cout << "\tNumber of hours allowed for overtime : ";
	int allowed_hours = 12 - hours_of_overtime;
	if ( allowed_hours > 0)
	{
		cout << allowed_hours << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	int hour;
	cout << "\tHow many hours do you want for overtime : ";
	cin >> hour;
	if (hour <= 0 || hour > 12)
	{
		cout << "\tInvalid input";
	}
	else
	{
		if (allowed_hours >= 0)
		{
			if (hour > allowed_hours)
			{
				cout << "\tHours that you have enterd is bigger than allowed hours\n";
			}
			else
			{
				hours_of_overtime += hour;
				salary += (hour * 120);
				overtime_report(hour);
				cout << "\tRequest accepted\n";
				cout << "\tHours of overtime : " << hours_of_overtime;
			}
		}
	}
}

void Employee::set_info()
{
	cout << "\t Enter fullname : (firstname lastname) ";
	cin >> f_name >> l_name;
	cout << "\t Enter national code : ";
	cin >> national_code;
	cout << "\t Enter date of birth : (ex: 1375/5/20)";
	cin >> date_of_birth;
	cout << "\t Enter username : ";
	cin >> username;
	cout << "\t Enter password : ";
	cin >> password;
	cout << "\t Enter salary : ";
	cin >> salary;

	cout << "\n\t Employee code : " << emp_code << endl;
}

void Customer::set_info()
{
	cout << "\t Enter fullname : (firstname lastname) ";
	cin >> f_name >> l_name;
	cout << "\t Enter national code : ";
	cin >> national_code;
	cout << "\t Enter date of birth : (ex: 1375/5/20)";
	cin >> date_of_birth;
	cout << "\t Enter username : ";
	cin >> username;
	cout << "\t Enter password : ";
	cin >> password;

	int size;
	cout << "\t How many accounts do you want to insert : ";
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		cout << "\t " << i + 1 << "th account : ";
		Account temp;
		temp.set_info(national_code);
		accounts.push_back(temp);
		create_acc_report();
	}
}

void Customer::show_info()
{
	cout << "\n\t Fullname : " << f_name << ' ' << l_name << endl;
	cout << "\t National code : " << national_code << endl;
	cout << "\t Birthday : " << date_of_birth << endl;
	cout << "\t Username : " << username << endl;
	cout << "\t Password : " << password << endl;
	cout << "\t Accounts : " << endl;
	for (int i = 0; i < accounts.size(); ++i)
	{
		cout << "\t " << i + 1 << "th account : ";
		accounts.at(i).show_info();
	}

}

void Employee::show_info()
{
	cout << "\n\t Fullname : " << f_name << ' ' << l_name << endl;
	cout << "\t National code : " << national_code << endl;
	cout << "\t Birthday : " << date_of_birth << endl;
	cout << "\t Username : " << username << endl;
	cout << "\t Password : " << password << endl;
	cout << "\t Employee code : " << emp_code << endl;
	cout << "\t Hours of leave : " << hours_of_leave << endl;
	cout << "\t Hours of overtime : " << hours_of_overtime << endl;
	cout << "\t Salary : " << salary << endl;
}

//search in account
int Customer::search_in_accounts(int t_acc_no)
{
	for (int i = 0; i < accounts.size(); ++i)
	{
		if (accounts.at(i).get_acc_no() == t_acc_no)
		{
			return i;
		}
	}

	return -1; // return -1 if account not found
}

void Customer::add_account()
{
	Account temp;
	temp.set_info(national_code);
	if (search_in_accounts(temp.get_acc_no()) == -1) // this mean that there is no account with this number
	{
		accounts.push_back(temp);
		create_acc_report();
		cout << "\t Account added succussfully\n";
	}
	else
	{
		cout << "\t Account with this number have already been added\n";
	}
	
}

void Customer::delete_account()
{
	long long int t_acc_no;
	cout << "\t Enter account number : ";
	cin >> t_acc_no;

	int index = search_in_accounts(t_acc_no);

	if (index == -1)
	{
		cout << "\t Account NOT found\n";
	}
	else
	{
		accounts.at(index).show_info();
		char keep_going;
		cout << "\t Are you sure to delete this account (y/n) : ";
		cin >> keep_going;

		if (keep_going == 'y' || keep_going == 'Y')
		{
			accounts.erase(accounts.begin() + index);
			accounts.shrink_to_fit();
			cout << "\t Account deleted succussfully\n";
		}
	}
}

void Customer::add_amount()
{
	long long int t_acc_no;
	cout << "\t Enter account number : ";
	cin >> t_acc_no;

	int index = search_in_accounts(t_acc_no);

	if (index == -1)
	{
		cout << "\t Account NOT found\n";
	}
	else
	{
		accounts.at(index).show_info();
		double amount;
		cout << "\t Enter amount : ";
		cin >> amount;
		accounts.at(index).add(amount);
	}
}

void Customer::subtract_amount()
{
	long long int t_acc_no;
	cout << "\t Enter account number : ";
	cin >> t_acc_no;

	int index = search_in_accounts(t_acc_no);

	if (index == -1)
	{
		cout << "\t Account NOT found\n";
	}
	else
	{
		if (accounts.at(index).get_status())
		{
			accounts.at(index).show_info();
			double amount;
			cout << "\t Enter amount : ";
			cin >> amount;
			accounts.at(index).subtract(amount);
		}
		else
		{
			accounts.at(index).show_info();
			cout << "\t Account is Inactive, you can not subtract\n";
		}
	}
}

void Customer::set_acc_status()
{
	long long int t_acc_no;
	cout << "\t Enter account number : ";
	cin >> t_acc_no;

	int index = search_in_accounts(t_acc_no);

	if (index == -1)
	{
		cout << "\t Account NOT found\n";
	}
	else
	{
		accounts.at(index).show_info();
		if (accounts.at(index).get_status())
		{
			cout << "\t Account is ACTIVE\n";
			char keep_going;
			cout << "\t Do you want to Inactive account (y/n) : ";
			cin >> keep_going;
			
			if (keep_going == 'y' || keep_going == 'Y')
			{
				accounts.at(index).set_status(false);
				acc_status_report('I');
				cout << "\t Status updated successfully\n";
			}
		}
		else
		{
			cout << "\t Account is INACTIVE\n";
			char keep_going;
			cout << "\t Do you want to active account (y/n) : ";
			cin >> keep_going;

			if (keep_going == 'y' || keep_going == 'Y')
			{
				accounts.at(index).set_status(true);
				acc_status_report('A');
				cout << "\t Status updated successfully\n";
			}
		}
	}
}

void Customer::login_report()
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Customer with national code " << national_code << " login in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

void Employee::login_report()
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Clerk with emp code " << emp_code << " login in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

void Customer::create_acc_report()
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Account with national code " << national_code << " created in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

void Employee::leave_report(int hour)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Clerk with national code " << national_code << " gets " << hour << " hours rest in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

void Employee::overtime_report(int hour)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		fout << "------------" << endl;
		fout << "Clerk with national code " << national_code << " gets " << hour << " hours overtime in date ";
		fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

void Customer::acc_status_report(char status)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);

	ofstream fout("report.txt", ios::app);

	if (fout.is_open())
	{
		if (status == 'A')
		{
			fout << "------------" << endl;
			fout << "Account with national code " << national_code << " activated in date ";
			fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		}
		else if (status == 'I')
		{
			fout << "------------" << endl;
			fout << "Account with national code " << national_code << " banned in date ";
			fout << lt.wYear << '/' << lt.wMonth << '/' << lt.wDay << " time " << lt.wHour << ':' << lt.wMinute << endl;
		}
		fout.close();
	}
	else
	{
		cerr << "\n\t Unable to open file\n";
	}
}

std::string Person::get_fname() { return f_name; }
std::string Person::get_lname() { return l_name; }
long long int Person::get_national_code() { return national_code; }
std::string Person::get_birthday() { return date_of_birth; }
std::string Person::get_username() { return username; }
std::string Person::get_password() { return password; }

std::vector <Account> Customer::get_accounts() { return accounts; }

int Employee::get_emp_code() { return emp_code; }
double Employee::get_salary() { return salary; }
int Employee::get_leave_hours() { return hours_of_leave; }
int Employee::get_overtime_hours() { return hours_of_overtime; }

void Person::set_fname(std::string str) { f_name = str; }
void Person::set_lname(std::string str) { l_name = str; }
void Person::set_national_code(long long int no) { national_code = no; }
void Person::set_birthday(std::string str) { date_of_birth = str; }
void Person::set_username(std::string str) { username = str; }
void Person::set_password(std::string str) { password = str; }

void Customer::set_accounts(std::vector <Account> t_accounts) { accounts = t_accounts; }

void Employee::set_emp_generator(int no) { emp_generator = no; }
void Employee::set_emp_code(int no) { emp_code = no; }
void Employee::set_salary(double no) { salary = no; }
void Employee::set_leave_hours(int hours) { hours_of_leave = hours; }
void Employee::set_overtime_hours(int hours) { hours_of_overtime = hours; }