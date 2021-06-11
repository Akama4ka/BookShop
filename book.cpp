#include "book.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void book::feeddata() {
	cin.ignore();
	cout << "\nИмя Автора: ";      cin.getline(author, 20);
	cout << "Название книги: ";       cin.getline(title, 20);
	cout << "Издатель: ";   cin.getline(publisher, 20);
	cout << "Цена книги: ";            cin >> *price;
	cout << "Позиция на складе: ";   cin >> *stock;

}

void book::editdata() {

	cout << "\nИмя Автора: ";      cin.getline(author, 20);
	cout << "Название книги: ";       cin.getline(title, 20);
	cout << "Издатель: ";   cin.getline(publisher, 20);
	cout << "Цена книги: ";            cin >> *price;
	cout << "Позиция на складе: ";   cin >> *stock;


}

void book::showdata() {
	cout << "\nИмя автора: " << author;
	cout << "\nНазвание книги: " << title;
	cout << "\nИздатель: " << publisher;
	cout << "\nЦена: " << *price;
	cout << "\nПозиция на складе: " << *stock;

}

int book::search(char tbuy[20], char abuy[20]) {
	if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
		return 1;
	else return 0;

}

void book::buybook() {
	int count;
	cout << "\nКол-во книг,которые хотите купить ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;
		cout << "\n успешно";
		cout << "\nцена. " << (*price) * count;
	}
	else
		cout << "\nНеобходимых копий нет в наличии";
}
