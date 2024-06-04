#include "DLIST.h"
#include<string>
std::string task(DLIST list,char* car);

int main()
{
    SetConsoleOutputCP(1251);
    std::ifstream file("input.txt");
    if (file)
    {
        DLIST list;
        list.create_by_order(file, [](int a, int b) {return a >= b; });
        list.print();
        std::cout << "Введите марку автомобиля: ";
        char car[35]{};
        std::cin.getline(car, 35);
        std::cout << task(list,car) << '\n';
    }
    else std::cout << "file error\n";
    file.close();
    std::cin.get();
    return 0;
}


std::string task(DLIST list, char* car)
{
    std::string result = "";
    int cnt{1 }, cnt_max{};
    ptrDNODE ptr = list.get_head()->next;
    int region = ptr->info->get_region();
    while (ptr->next)
    {

        if (strcmp(ptr->info->get_firm(),car) ==0&& ptr->info->get_region() == ptr->next->info->get_region())
            ++cnt;
        else
        {
            if (cnt > cnt_max)
            {
                cnt_max = cnt;

                result = std::to_string(ptr->info->get_region());
            }
            else
            if (cnt == cnt_max)
                result += ", " + std::to_string(ptr->info->get_region());
           
        }
        cnt = 1;
        ptr = ptr->next;
    }
   
    return result;
}

