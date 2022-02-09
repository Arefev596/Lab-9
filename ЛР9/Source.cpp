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
		cout << "ID äëÿ ïîêóïêè " << this_thread::get_id() << " \t";
		cout << "Âûáåðèòå òîâàð, êîòîðûé õîòèòå êóïèòü: \n";
		cout << "Eat(17Ð)\t Headphones(8990Ð)\t Cucumber(79Ð)\n";
		string pokupka;
		int kolvo;
		cin >> pokupka;
		cout << "Ââåäèòå êîëè÷åñòâî òîâàðà: \n";
		cin >> kolvo;
		if (pokupka == "eat") {
			price = 17 * kolvo;
		}
		if (pokupka == "headphones") {
			price = 8990 * kolvo;
			int b; // добавляю из VSStudio комментарий для проверки
			setLocale(LC_ALL, "ru"); // добавляю просто для проверки работы GitHub
		}
		if (pokupka == "cucumber")
		{
			price = 79 * kolvo;
		}
	
		list.push_back(pokupka);
		

		mx.unlock();

		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "ID äëÿ ïîäòâåðæäåíèÿ " << this_thread::get_id() << " \t";
		cout << "Ïîêóïêà ñîâåðøåíà óñïåøíî! \n";
		

}

void Punkt::delivery(string item) {
	cout << "ID äëÿ äîñòàâêè " << this_thread::get_id() << " \t";
		cout << item << " ïåðåäàí â äîñòàâêó!\n\n";
}

void Punkt::confirm() {
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID äëÿ ïîäòâåðæäåíèÿ " << this_thread::get_id() << " \t";
	cout << "Ïîêóïêà ñîâåðøåíà óñïåøíî! \n";
}

vector <string> Punkt::get_list() {
	return list;
}
