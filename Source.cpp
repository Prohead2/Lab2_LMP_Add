#include "My_List.h"
#include <Windows.h>

void task(DLIST& list)
{
	ptrNODE p = list.get_begin();
	int min_cost = p->info.GetCost();
	while (p && p->info.GetCost() == min_cost)
	{
		if (p == list.get_begin())
		{
			std::cout << p->info.GetShopName() << ": " << p->info.GetName() << " ";
		}
		else if (p->prev->info.GetShopName() == p->info.GetShopName())
		{
			std::cout << p->info.GetName() << " ";
		}
		else if (p->prev->info.GetShopName() != p->info.GetShopName())
		{
			std::cout << std::endl << p->info.GetShopName() << ": " << p->info.GetName() << " ";
		}
		
		p = p->next;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag)
	{
		std::ifstream file("products.txt");
		if (file)
		{
			DLIST list("products.txt");
			file.close();
			list.print();
			task(list);
		}

		char choice;
		bool label = true;
		while (label)
		{
			std::cout << std::endl << "Желаете начать заново или выйти? 1 - заново, 2 - выйти ";
			std::cin >> choice;
			switch (choice)
			{
			default:
				std::cout << "Неверный ввод!" << std::endl;
				label = true;
				break;
			case '1':
				flag = true;
				label = false;
				break;
			case '2':
				flag = false;
				label = false;
				break;
			}
		}
	}
	std::cin.get();
}
