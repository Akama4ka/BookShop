#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include "User.h"


bool User::LoginandPaasword() {
	string un, ps;
	cout << "Логин" << " "; cin >> username;
	cout << "Пароль" << " "; cin >> password;
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
	cout << "Введите ваш логин" << " "; cin >> username;
	if (searchUser(username + ".txt") == false) {
		cout << "Введите ваш пароль" << " "; cin >> password;
		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();
	}
	else if (searchUser(username+".txt") == true)
		cout << "Пользователь с данным логином уже существует" << endl;
}
bool User::searchUser(std::string filePath) {
		bool isExist = false;
		std::ifstream fin(filePath.c_str());
		if (fin.is_open())
			isExist = true;
		fin.close();
		return isExist;
}
