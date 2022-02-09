#include "Header.h"
#include <string>
#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

using namespace std;


mutex mx;

void Punkt::buy() {
		mx.lock();
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
		

		mx.unlock();

		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "ID для подтверждения " << this_thread::get_id() << " \t";
		cout << "Покупка совершена успешно! \n";
		

}

void Punkt::delivery(string item) {
	cout << "ID для доставки " << this_thread::get_id() << " \t";
		cout << item << " передан в доставку!\n\n";
}

void Punkt::confirm() {
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID для подтверждения " << this_thread::get_id() << " \t";
	cout << "Покупка совершена успешно! \n";
}

vector <string> Punkt::get_list() {
	return list;
}
