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
		cout << "ID ��� ������� " << this_thread::get_id() << " \t";
		cout << "�������� �����, ������� ������ ������: \n";
		cout << "Eat(17�)\t Headphones(8990�)\t Cucumber(79�)\n";
		string pokupka;
		int kolvo;
		cin >> pokupka;
		cout << "������� ���������� ������: \n";
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
		cout << "ID ��� ������������� " << this_thread::get_id() << " \t";
		cout << "������� ��������� �������! \n";
		

}

void Punkt::delivery(string item) {
	cout << "ID ��� �������� " << this_thread::get_id() << " \t";
		cout << item << " ������� � ��������!\n\n";
}

void Punkt::confirm() {
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID ��� ������������� " << this_thread::get_id() << " \t";
	cout << "������� ��������� �������! \n";
}

vector <string> Punkt::get_list() {
	return list;
}
