#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include <cstdint>
#include <filesystem>
using namespace std;
#include "Admin.h"
void Admin::deleteUser() {
	cout << "Логин пользователя" << " "; cin >> username;
	string Way = username+".txt";
	if ((searchUser(username + ".txt") == true)) {
		if (remove(Way.c_str()) == 0)
			cout << "Пользователь удалён" << endl;
		else
			cerr << "Ошибка: " << strerror(errno)<< '\n';
	}
	else
		cout << "Пользователь не обнаружен" << endl;
}

void Admin::createAdmin() {
	ofstream file;
	string cod;
	cin >> cod;
	file.open(username + ".txt",ios::app);
	file << cod << endl;
	file.close();
}
void Admin::createUser() {

	ofstream file;
	cout << "Введите логин пользователя" << " "; cin >> username;
	string oldusername = username+".txt";
	cout << "Введите новый логин" << " "; cin >> username;
	if (searchUser(username+".txt") == false) {
		string Way = username + ".txt";
		if (rename(oldusername.c_str(), Way.c_str()) == 0) {
			file.open(username + ".txt");
			cout << "Введите новый пароль" << " "; cin >> password;
			file << username << endl << password;
			file.close();
		}
		else
			cout << "Error";
	}
	else if (searchUser(username+".txt") == true)
		cout << "Пользователь с данным логином  уже существует" << endl;
}
bool Admin::filesearch() {
	string un;
	cout << "Логин" << " "; cin >> username;
	ifstream read(username + ".txt");
	getline(read, un);
	if (un == username) {
		return true;
	}
	else
		return false;
}

bool Admin::CheckingAdmin() {
	string file_in, word_in, word_fn;
	file_in = username + ".txt";
	ifstream in(file_in.c_str(), std::ios::in);
	if (!in.good())
	{
		std::clog << "Не удалось открыть файл\n";
		exit(1);
	}
	 word_fn="1133";
	while (in >> word_in)
		if (word_in == word_fn)
		{
			in.close();
			return true;
		}
	return false;
	in.close();
	return 0;

}
