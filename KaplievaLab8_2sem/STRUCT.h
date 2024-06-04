#pragma once
//��������
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
	void print();
	int compare(const BUS& bus);
	int get_region();
	char* get_firm();
	char* get_number();
	/*int setDiagnosis();
	int setDay();
	int setMonth();
	int setYear();
	int setNWorkingDays();
	void setSurnane(char surname[m]);
	void setName(char name[m]);
	void setPatronymic(char patronymic[m]);*/
};