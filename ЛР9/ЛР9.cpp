#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "Header.h"

using namespace std;

mutex mt;

ostream& operator << (ostream& os, const vector<string>& c)
{
	for (int i = 0; i < c.size(); i++)
	{
		os << c[i];
		os << "  ";
	}
	return os;
}

void confirm() {
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID для подтверждения " << this_thread::get_id() << " \t";
	cout << "Покупка совершена успешно! \n";
}

void buy() {
	vector <string> list;
	int price;
	cout << "ID для покупки " << this_thread::get_id() << " \t";
	cout << "Выберите товар, который хотите купить: \n";
	cout << "Eat(17Р)\t Headphones(8990Р)\t Cucumber(79Р)\n";
	string pokupka;
	int kolvo;
	cin >> pokupka;
	cout << "Введите количество товара: \n";
	cin >> kolvo;
	if (pokupka == "eat") {
		price = 17 * kolvo;
	}
	if (pokupka == "headphones") {
		price = 8990 * kolvo;
	}
	if (pokupka == "cucumber")
	{
		price = 79 * kolvo;
	}
	
	list.push_back(pokupka);

	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID для подтверждения " << this_thread::get_id() << " \t";
	cout << "Покупка совершена успешно! \n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	Punkt ozon;
	cout << "Выберите функцию:\n";
	int welche;
	cout << "1. Один поток\t2.Два потока\n";
	cin >> welche;
	switch (welche) {
	case 1:
			ozon.buy();
			ozon.buy();
			cout << endl;
	case 2:
		cout << "1.Кольцо \t2.Звезда\n";
		int whale;
		cin >> whale;
		bool stop = true;
		vector <string> first;

		switch (whale) {
		case 1: {
			thread th([&]() { //лямбда выражение
				ozon.buy();
				ozon.confirm();

				});

			thread th2([&]() {
				ozon.buy();
				ozon.confirm();
				});

			th.join();
			th2.join();
		}

		case 2: {

			thread th3(buy);
			thread th4(buy);
			th3.join();
			th4.join();
		}

		}
	}

	return 0;
}