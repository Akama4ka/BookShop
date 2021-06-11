#include "User.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool User::LoginandPaasword() {
	string username, password, un, ps;
	cout << "Ваш Логин" << " "; cin >> username;
	cout << "Ваш пароль" << " "; cin >> password;
	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, ps);
	if (un == username && ps == password) {
		return true;
	}
	else
	   return false;
}
void User::Registor() {
	string username, password;
	cout << "Введите ваш логин" << " "; cin >> username;
	cout << "Введите ваш пароль" << " "; cin >> password;
	ofstream file;
	file.open(username + ".txt");
	file << username << endl<< password;
	file.close();
}
