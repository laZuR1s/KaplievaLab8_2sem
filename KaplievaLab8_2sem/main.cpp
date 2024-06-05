#include "DLIST.h"
#include<string>
std::string task(DLIST list, char* car);

//IV.«Автобус»
//Структура записи :
//? Государственный регистрационный номер :
//? регион(3 знака)
//? номер(6 знаков)
//? Фирма - производитель
//? ФИО водителя
//? Номер маршрута
//? Состояние(в парке, на маршруте)
//3. Определить регионы, в которых работает наибольшее количество автобусов заданной фирмы производителя.

int main()
{
	SetConsoleOutputCP(1251);
	std::ifstream file("input.txt");
	if (file)
	{
		DLIST list;
		list.create_by_order(file, [](int a, int b) {return a <= b; });
		list.print();
		std::cout << "Введите марку автомобиля: ";
		char car[35]{};
		std::cin.getline(car, 35);
		std::cout << task(list, car) << '\n';
	}
	else std::cout << "file error\n";
	file.close();
	return 0;
}

std::string task(DLIST list, char* car)
{
	std::string result = "";
	int cnt{ 0 }, cnt_max{};
	ptrDNODE ptr = list.get_head()->next;
	int region = ptr->info->get_region();
	while (ptr)
	{

		
		if (ptr->info->get_region() == region)
		{
			if (strcmp(ptr->info->get_firm(), car) == 0)
				++cnt;
		}
		else
		{
			if (cnt > cnt_max)
			{
				cnt_max = cnt;
				result = std::to_string(region);
			}
			else
				if (cnt == cnt_max)
					result += ", " + std::to_string(region);
				region = ptr->info->get_region();
			cnt=0;
		}
		ptr = ptr->next;
	}
	if (cnt > cnt_max)
	{
		result = std::to_string(region);
	}
	else if (cnt == cnt_max)
	{
		result += ", " + std::to_string(region);
	}

	return result;
}

