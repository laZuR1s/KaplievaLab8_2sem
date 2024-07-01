#pragma once
//автобусы
#include <iostream>
#include <fstream>
#include <cstring>
const int m = 35;

struct BUS
{
private:
	char number[m], firm[m], FIO[m], status[m];
	int region, num_route;
public:
	BUS() {}
	BUS(std::ifstream& file);
	void print(std::ostream& stream=std::cout);
	int compare(const BUS& bus);
	int get_region();
	char* get_firm();

};
