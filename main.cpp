#include <fstream>
#include "Classes.h"

bool fullAccess;
int vecLength;
string errorLog;


using namespace std;


// ----------------------------------------- Manager Menu -----------------------------------------


void managerActions(string name, string family) {
	cout << "Choose your preferd action: " << endl;
	cout << "1. Delete user" << endl;
	cout << "2. Edit user" << endl;
	cout << "3. Get user info" << endl;

	char userIn;
	cin >> userIn;

	switch (userIn) {
		case '1': /*run Delete command*/ break;
		case '2': /*run Edit command*/ break;
		case '3': /*run Get user info command*/ break;
		default: cout << "Wrong input. Try again" << endl; break;
	}
}


int searchUser() {
	string name, family;
	cout << "Enter the full name of the user (name lastname):" << endl;
	cin >> name >> family;
	
	for (int i = 0; i < developers.size(); i++) {
		if ((developers[i].name == name) && (developers[i].family == family)) {
			cout << "User found." << endl;
			managerActions(name, family);
			return 0;
		}
	}
	for (int i = 0; i < designers.size(); i++) {
		if ((designers[i].name == name) && (designers[i].family == family)) {
			cout << "User found." << endl;
			managerActions(name, family);
			return 0;
		}
	}
	for (int i = 0; i < testers.size(); i++) {
		if ((testers[i].name == name) && (testers[i].family == family)) {
			cout << "User found." << endl;
			managerActions(name, family);
			return 0;
		}
	}

	cout << "User not found. Try again." << endl;
}


int getUsersList() {
	string message = "";

	vecLength = developers.size();
	message += "\nDevelopers: \n";
	for (int i = 0; i < vecLength; i++) {
		message += to_string(++i) + ". "; 
		message += developers[i].name + " " + developers[i].family + "\n";
	}

	vecLength = designers.size();
	message += "\n\nDesigners: \n";
	for (int i = 0; i < vecLength; i++) {
		message += to_string(++i) + ". "; 
		message += designers[i].name + " " + designers[i].family + "\n";
	}

	vecLength = testers.size();
	message += "\n\nTesters: \n";
	for (int i = 0; i < vecLength; i++) {
		message += to_string(++i) + ". "; 
		message += testers[i].name + " " + testers[i].family + "\n";
	}
	
	cout << "To write the list in a .txt file, type F. To show the list in console, type C: ";
	char userIn;
	cin >> userIn;

	if ((userIn == 'F') || (userIn == 'f')) {
		fstream data("Employees_List.txt");
		data << message;
		data.close();
		return 0;
	} else if ((userIn == 'C') || (userIn == 'c')) {
		cout << message << endl;
		return 0;
	}
}


void managerMenu() {
	cout << "\nChoose your prefered option: " << endl;
	cout << "1. Search Users" << endl;
	cout << "2. Get Users list" << endl;
	// cout << "3. Get all held records" << endl;

	char userIn;
	cin >> userIn;

	switch (userIn) {
		case '1': searchUser(); break;
		case '2': getUsersList(); break;
		// case '3': /*getHeldRecords();*/ break;
		default: cout << "Wrong input. Try again." << endl; break;
	}
	
}
 

// ----------------------------------- User Menu ------------------------------------------------


void registerUser(char ch, string name, string family, Date birth, string specialty, string title, string type, string username, string password) {
	switch (ch) {
		case '1': {
			Developer dev(name, family, birth, specialty, title, type, username, password);
			developers.push_back(dev);
			cout << "\nUser registered successfully! Follow the log in menu." << endl;
			break;
		}

		case '2': {
			Designer des(name, family, birth, specialty, title, type, username, password);
			designers.push_back(des);
			cout << "\nUser registered successfully! Follow the log in menu." << endl;
			break;
		}

		case '3': {
			Tester test(name, family, birth, specialty, title, type, username, password);
			testers.push_back(test);
			cout << "\nUser registered successfully! Follow the log in menu." << endl;
			break;
		}

		case '4': {
			Manager mgr(name, family, birth, specialty, title, type, username, password);
			managers.push_back(mgr);
			cout << "\nUser registered successfully! Follow the log in menu." << endl;
			break;
		}
	}
}


int logInUser(char ch, string username, string password) {
	switch (ch) {
		case '1':
			for (int i = 0; i < vecLength; i++) {
				if ((developers[i].username == username) && (developers[i].password == password)) {
					cout << "\nLog in Successful" << endl;
					cout << "Weolcome back " << developers[i].name << " " << developers[i].family << "." << endl;
					return 0;
				}
			}
			cout << "User not found. Try again." << endl;
			return 0;
		
		case '2':
			for (int i = 0; i < vecLength; i++) {
				if ((designers[i].username == username) && (designers[i].password == password)) {
					cout << "\nLog in Successful" << endl;
					cout << "Weolcome back " << designers[i].name << " " << designers[i].family << "." << endl;
					return 0;
				}
			}
			cout << "User not found. Try again." << endl;
			return 0;
		
		case '3':
			for (int i = 0; i < vecLength; i++) {
				if ((testers[i].username == username) && (testers[i].password == password)) {
					cout << "\nLog in Successful!" << endl;
					cout << "Weolcome back " << testers[i].name << " " << testers[i].family << "." << endl;
					return 0;
				}
			}
			cout << "User not found. Try again." << endl;
			return 0;

		case '4':
			for (int i = 0; i < vecLength; i++) {
				if ((managers[i].username == username) && (managers[i].password == password)) {
					cout << "\nLog in Successful!" << endl;
					cout << "Weolcome back " << managers[i].name << " " << managers[i].family << "." << endl;
					return 0;
				}
			}
			cout << "User not found. Try again." << endl;
			return 0;
	}
}


void logInMenu() {
	cout << "\nYou are now following the Log In menu." << endl;
	cout << "Choose what defines you best." << endl;
	cout << "1. Developer" << endl;
	cout << "2. Designer" << endl;
	cout << "3. Tester" << endl;
	cout << "4. Manager" << endl;

	cout << "Type here: ";
	char userIn;
	cin >> userIn;

	cout << "\nUsername: ";
	string username;
	cin >> username;

	cout << "Password: ";
	string password;
	cin >> password;
	
	// if user exixts raise errors

	switch (userIn) {
		case '1':
			vecLength = developers.size();
			logInUser(userIn, username, password);
		break;

		case '2':
			vecLength = designers.size();
			logInUser(userIn, username, password);
		break;

		case '3':
			vecLength = testers.size();
			logInUser(userIn, username, password);
		break;

		case '4':
			vecLength = managers.size();
			logInUser(userIn, username, password);
			// raise error if user not found.
			cout << "You are signed in as a Manager." << endl;
			cout << "Full access to all employee records granted." << endl;
			managerMenu();
		break;

		default:
			cout << "Wrong input! Try again." << endl;
		break;
	}
}


bool userExists(char ch, string username) {
	switch (ch) {
		case '1':
			for (int i = 0; i < vecLength; i++) {
				if (developers[i].username == username) {
					return true;
				}
			}
		break;

		case '2':
			for (int i = 0; i < vecLength; i++) {
				if (designers[i].username == username) {
					return true;
				}
			}
		break;

		case '3':
			for (int i = 0; i < vecLength; i++) {
				if (testers[i].username == username) {
					return true;
				}
			}
		break;
	}
	return false;
}


int registerMenu() {
	cout << "\nYou are now following the Resgister menu." << endl;
	cout << "Choose what defines you best." << endl;
	cout << "1. Developer" << endl;
	cout << "2. Designer" << endl;
	cout << "3. Tester" << endl;
	cout << "4. Manager" << endl;
	
	cout << "Type here: ";
	char userIn;
	cin >> userIn;

	if ((userIn != '1') && (userIn != '2') && (userIn != '3') && (userIn != '4')) {
		cout << "Wrong input. Try again." << endl;
		return 0;
	}

	string name, family;
	cout << "\nType your full name (Name Lastname): ";
	cin >> name >> family;

	int d, m, y;
    cout << "\nType your birth date (dd mm yyyy): ";
    cin >> d >> m >> y;
	Date birth(d, m, y);

	// for non manager users only.
	if ((userIn == '1') || (userIn == '2') || (userIn == '3')) {
		string specialty;
		cout << "\nType your specialty (f.e. ML_Expert): ";
		cin >> specialty;
		
		string title;
		cout << "\nChoose your title: " << endl;
		cout << "1. Junior" << endl;
		cout << "2. Senior" << endl;
		cout << "3. Admin" << endl;

		cout << "Type here: ";
		char ch;
		cin >> ch;
		switch (ch) {
			case '1': title = "Junior"; break;
			case '2': title = "Senior";	break;
			case '3': title = "Admin"; break;	
			default: cout << "Wrong input! Try again." << endl; return 0;;
		}

		string type;
		cout << "\nType your working type: " << endl;
		cout << "1. Full Time" << endl;
		cout << "2. Part Time" << endl;
		cout << "3. Project Based" << endl;
		cout << "Type here: ";
		cin >> ch;
		switch (ch) {
			case '1': title = "Full Time"; break;
			case '2': title = "Part Time";	break;
			case '3': title = "Project Based"; break;	
			default: cout << "Wrong input! Try again." << endl; return 0;;
		}
		
		string username, password;
		cout << "\nSet username and password (user pass): ";
		cin >> username >> password;
		
		if (userExists(userIn, username)) {
			cout << "User already exists! Start over and try Log in menu." << endl;
			return 0;
		}

		registerUser(userIn, name, family, birth, specialty, title, type, username, password);

	} else { // for managers only.
		string username, password;
		cout << "\nSet username and password (user pass): ";
		cin >> username >> password;
		
		if (userExists(userIn, username)) {
			cout << "User already exists! Start over and try Log in menu." << endl;
			return 0;
		}

		registerUser(userIn, name, family, birth, "specialty", "title", "type", username, password);
	}
}


int menu() {
	
	cout << "Welcome back, please choose your preferred option." << endl;
	cout << "1. Log In" << endl;
	cout << "2. Register" << endl;

	cout << "Type here: ";
	char userIn;
	cin >> userIn;

	switch (userIn) {
		case '1': logInMenu(); break;
		case '2': registerMenu(); break;;
		default: cout << "Wrong input! Restart the program." << endl; return 0;
	}
}


// ----------------------------------------- Main function -----------------------------------------


int main() {
	x:

	menu();

	cout << "\nEnter 0 to exit the program." << endl;
	cout << "Enter 1 to start over." << endl;
	cout << "Type here: ";

	bool input;
	cin >> input;
	cout << "\n";

	if (input) goto x; 
	else return 0;
}



// ----------------------------------------- Credits ------------------------------------------


/*
Regards

Author: Eddie Snow
*/


