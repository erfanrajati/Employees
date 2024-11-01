#include <iostream>
#include <string>
#include <vector>

using namespace std;
// ----------------------------------------- Data Structures -----------------------------------------


class Date {
public:
	
	int day, month, year;
	
	Date() {}
	
	Date(int day, int month, int year) {
		this -> day = day;
		this -> month = month;
		this -> year = year;
	}	

	string displayDate() {
		return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
	}
};


class Employee {
public:
	string name, family;
	Date birth;
	int years_worked, days_off;
	long salary; // because there are so many zeroes

	string username, password;
	
	Employee() {}
};


class Developer : public Employee {
public:
	string title;
	string type;
	string specialty;
	int age;

	Developer(string name, string family, Date birth, string specialty, string title, string type, string username, string password) { 
		this -> name = name;
		this -> family = family;
		this -> birth = birth;
		this -> specialty = specialty;
		this -> type = type;
		this -> title = title;
		this -> username = username;
		this -> password = password;
		
		age = 2023 - birth.year;
		years_worked = 0;
	}


	// head manager will have access to setters and getters
	// the admin will also have access to their team's getters, but not setters!
	// each employee will be able to set/change their username and password.
	// to do this, my approach is to use try\catch blocks in UI to show errors if other emplyees tried to access info.

	//----------------- setters -----------------


	void set_title(string title) {
		this -> title = title;
	}
	
	void set_daysOff(int days_off) {
		this -> days_off = days_off;
	}

	void set_salary(long salary) {
		this -> salary = salary;
	}

	void set_years_worked(int years_worked) { 
		/* 
		In actual projects, years worked will automatically update. 
		No need for a setter. 
		*/
		this -> years_worked = years_worked;
	}

	void set_user_pass(string username, string password) {
		this -> username = username;
		this -> password = password;
	}



	//----------------- getters -----------------

	string get_curricular_info() {
		
		return 
			name + " " + family + "'s curriculum:\n" + 
			"Years worked: " + to_string(years_worked) + "\n" +
			"Days off allocated: " + to_string(days_off) + "\n" +
			"Salary: " + to_string(salary) + "\n" +
			"Title: " + title + "\n";
	}

	string extract_curricular_info() {
		return
			name + " " + family + " " + to_string(age) + " " + title + " " +
			to_string(years_worked) + " " + to_string(salary) + " " + to_string(days_off) + "\n";
	}
};


class Designer : public Developer {
public:
	Designer(string name, string family, Date birth, string specialty, string title, string type, string username, string password) :
	Developer(name, family, birth, specialty, title, type, username, password) {}
};


class Tester : public Developer {
public:
	Tester(string name, string family, Date birth, string specialty, string title, string type, string username, string password) :
	Developer(name, family, birth, specialty, title, type, username, password) {}
};


class Manager : public Developer {
public:
	Manager(string name, string family, Date birth, string specialty, string title, string type, string username, string password) :
	Developer(name, family, birth, specialty, title, type, username, password) {}
};


vector<Developer> developers;
vector<Designer> designers;
vector<Tester> testers;
vector<Manager> managers;
