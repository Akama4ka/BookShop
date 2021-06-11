#include<iostream>
#include "User.h"
#include "book.h"
#include<vector>
using namespace std;
void start();
int magazin();

int main(void) {
	setlocale(LC_ALL, "Russian");
	start();
}

int magazin() {
	book* B[20];
	int i = 0, r, t, choice;
	char titlebuy[20], authorbuy[20];
	while (1) {
		cout << "\n\n\t\tMENU"
			<< "\n1. Запись новой книги"
			<< "\n2. Купить книгу"
			<< "\n3. Поиск книги"
			<< "\n4. Редактирование сведений о книге"
			<< "\n5. Выход"
			<< "\n\nВведите свой выбор: ";
		cin >> choice;

		switch (choice) {
		case 1:	B[i] = new book;
			B[i]->feeddata();
			i++;	break;

		case 2: cin.ignore();
			cout << "\nВведите название книги: "; cin.getline(titlebuy, 20);
			cout << "Введите Автора книги: ";  cin.getline(authorbuy, 20);
			for (t = 0; t < i; t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					B[t]->buybook();
					break;
				}
			}
			if (t == 1)
				cout << "\nЭтой книги нет в наличии";

			break;
		case 3: cin.ignore();
			cout << "\nВведите название книги: "; cin.getline(titlebuy, 20);
			cout << "Введите Автора книги: ";  cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nКнига найдена успешно";
					B[t]->showdata();
					break;
				}
			}
			if (t == i)
				cout << "\nЭтой книги нет в наличии";
			break;

		case 4: cin.ignore();
			cout << "\nВведите название книги: "; cin.getline(titlebuy, 20);
			cout << "Введите Автора книги: ";  cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nКнига найдена успешно";
					B[t]->editdata();
					break;
				}
			}
			if (t == i)
				cout << "\nЭтой книги нет в наличии";
			break;

		case 5: exit(0);
		default: cout << "\nВведен Неверный Выбор";

		}
	}
	return 0;
 }
void start() {


	int choice, a;
	User name;
	while (1) {
		cout << "\n\n\t\tMENU"
			<< "\n1. Вход"
			<< "\n2. Новый пользователь"
			<< "\n3. Выход"
			<< "\n\nВведите свой выбор: ";
		cin >> choice;

		switch (choice) {
		case 1: cin.ignore();
			if (name.LoginandPaasword() == true)
				magazin();
			break;
		case 2: cin.ignore();
			cout << "Код доступа: " << endl; cin >> a;
			if (a == 1133) {
				name.Registor();
				break;
			}
			else {
				cout << "Неверный код";
				break;
			}
		case 3: cin.ignore();
			exit(true);
		default: cout << "\nВведен Неверный Выбор";
		}
	}
}
