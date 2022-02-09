#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Punkt {
public:
	string pokupka;
	int kolvo;
	string item;
	int price = 1;
	void buy();
	void delivery(string item);
	void confirm();
	vector <string> get_list();
	vector <string> list;
};