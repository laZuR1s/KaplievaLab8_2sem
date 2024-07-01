#include "DLIST.h"
#include<string>

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message);
int check_file(std::ifstream& file);
int task_menu();

std::string task(DLIST list, char* car);

constexpr int str_maxlen = 64;

int main()
{
	SetConsoleOutputCP(1251);

	bool correctfile{ false };
	do
	{
		char filename[str_maxlen];
		std::cout << "������� ��� �����\n>>> ";
		std::cin.getline(filename, str_maxlen);
		std::ifstream inp_file(filename);
		switch (check_file(inp_file))
		{
		case -1:
			std::cout << "���� �� ������\n";
			break;
		case 0:
			std::cout << "���� ����\n";
			break;
		default:
			correctfile = true;
			std::cout << "���������� ����\n";
			DLIST list;
			char car[35]{};
			list.create_by_order(inp_file, [](int a, int b) {return a <= b; });
			int choice{};
			do
			{
				choice = task_menu();
				switch (choice)
				{
				case 1:
					list.print();
					break;
				case 2:
				{
					std::ofstream out_file("output.txt");
					list.print(out_file);
					break;
				}
				case 3:
					std::cout << "������� ����� ����������: ";
					std::cin.getline(car, 35);
					std::cout <<"�������, � ������� �������� ���������� ���������� ��������� �������� ����� ������������� " << task(list, car) << '\n';

				default:
					break;
				}
			} while (choice != 4);
		}
	} while (!correctfile);
}

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message)
{
	std::cout << message << "\n>>> ";
	while (!(std::cin >> x && condition(x)))
	{
		std::cout << "������ �����!" << '\n';
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << message << "\n>>> ";
	}
}

int check_file(std::ifstream& file)
{
	int res = 1;
	if (!file)
	{
		res = -1; // ���� �� ������!
	}
	else
		if (file.peek() == EOF)
			res = 0; // ���� ������!
	return res;
}

int task_menu()
{
	std::cout << "\n����\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. ������� ������ �� �����\n";
	std::cout << "2. ������� ������ � ����\n";
	std::cout << "3. ��������� ������\n";
	std::cout << "4. ����� �� ���������\n";
	std::cout << "-----------------------------------------------------\n";

	std::function<bool(int)> foo;
	foo = [](int x)->bool {return x >= 1 && x <= 4; };
	int choice;
	validation(choice, foo, "");
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
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

