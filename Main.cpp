#include<iostream>
#include<Windows.h>
#include <stdlib.h>
using namespace std;
#include "book.h"
#include"User.h"
#include "Admin.h"

void start();
int magazin();

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	start();
}

int magazin() {
	book* B[20];
	int i = 0, r, t, choice;
	char titlebuy[20], authorbuy[20];
	while (1) {
		cout << "\n\n\t\tMENU"
			<< "\n1. Записать новую книгу"
			<< "\n2. Купить книгу"
			<< "\n3. Поиск книги"
			<< "\n4. Редактирование сведений о книге"
			<< "\n5. Вывод всех книг"
			<< "\n6. Очистка консоли"
			<< "\n7. Выход"
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
			case 5:
				cout << "Вывод всех имеющихся книг" << endl;
				for (t = 0; t < i; t++) {
					B[t]->showdata();
				}
				break;
			case 6: 
				system("cls");
				break;
			case 7:
				system("cls");
				main();
			default: cout << "\nВведен Неверный Выбор";
				break;
			}
		

	}
	return 0;
 }
void start() {

	int choice, a;
	Admin name;
	while (1) {
		cout << "\n\n\t\tMENU"
			<< "\n1. Вход"
			<< "\n2. Выход"
			<< "\n\nВведите свой выбор: ";
		cin >> choice;
			switch (choice) {
			case 1: cin.ignore();
				if (name.LoginandPaasword() == true && name.CheckingAdmin() == true) {
					system("cls");
					while (1) {
						cout << "\n\n\t\tMENU"
							<< "\n1.Перейти в магазин"
							<< "\n2.Добавить пользователя"
							<< "\n3.Поиск пользователя"
							<< "\n4.Отредактировать данные пользователя"
							<< "\n5.Удалить пользователя"
							<< "\n6.Очистка консоли"
							<< "\n7.Выход"
							<< "\n\nВведите свой выбор: ";
						cin >> choice;
							switch (choice) {
							case 1:cin.ignore();
								system("cls");
								magazin();
								break;
							case 2:cin.ignore();
								system("cls");
								while (1) {
									cout << "\n\n\t\tДобавление пользователя"
										<< "\n1.Обычный пользователь"
										<< "\n2.Администратор"
										<< "\n3.Выход"
										<< "\n\nВведите свой выбор: ";
									cin >> choice;
									if (choice == 1 | choice == 2 | choice == 3) {
										switch (choice) {
										case 1:cin.ignore();
											name.Registor();
											break;
										case 2:cin.ignore();
											name.Registor();
											name.createAdmin();
											break;
										case 3:
											break;

										}
									}
									break;
							case 3:cin.ignore();
								if (name.filesearch() == true) {
									cout << "Пользователь существует" << endl;
							
								}
								else {
									cout << "Пользователь не существует" << endl;
								}
								break;
							case 4:cin.ignore();
								name.createUser();
								break;
							case 5:cin.ignore();
								name.deleteUser();
								break;
							case 6:cin.ignore();
								system("cls");
								break;
							case 7:cin.ignore();
								system("cls");
								start();
								break;
							default: cout << "\nВведен Неверный Выбор";
								break;
								}
							}
						
						
					}


			case 2: cin.ignore();
				exit(true);
			default:
				cout << "\nВведен Неверный Выбор";
				break;

				}
				else if (name.LoginandPaasword() == true && name.CheckingAdmin() == false) {
					magazin();
					break;
				}
				else if (name.LoginandPaasword() == false && name.CheckingAdmin() == false) {
					cout << "Нервеный логин или пароль" << endl;
					break;
				}
			}

		
		
		
	}
}
