#pragma once
class book
{

private:
	char* author, * title, * publisher;
	float* price;
	int* stock;
public:
	book() {
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = new float;
		stock = new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[], char[]);
	void buybook();

};
