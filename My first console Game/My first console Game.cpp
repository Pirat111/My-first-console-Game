#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <vector>
#include <list>

using namespace std;



class character
{
private:
	int health;		//Здоровье

	int strength;	//Сила
	
	int luck;		//Удача
	
	int apt;		//Аптечки
	
	int gold;		//Золото
	
	int luckp;      //Зелье удачи
	
	int put;	    //Патроны
	
	int lvl;		//Уровень
	
	int ass = 0;    //Ассортимент

	int pistol = 0;
	
	int shGun = 0;
	
	int ak = 0;

	vector<string> inventory = { "камень", "доска", "бревно" };

public:

	string name;

	character()
	{
		health = 1;

		strength = 5;
		
		luck = 2;
		
		gold = 1500000;
		
		apt = 5;
		
		luckp = 0;
		
		put = 0;
		
		lvl = 0;
	}

	character(int hp, int str)
	{
		
		health = hp;
		
		strength = str;
		
		luck = rand() % 76;
		
		gold = 2000;
		
		apt = 5;
		
		luckp = 0;
		
		put = 0;
		
		lvl = 1;
	}
	
	void printInfo()		// Вывод характеристик
	{
		getlimit();
		cout << "Имя: " << name << endl << "Здаровье: " << health << endl << "Уровень: " << lvl << endl;;
		cout << "Сила: " << strength << endl << "Удача: " << luck << endl << "Золото:" << gold << endl;
		cout << "---------------------" << endl;
		
	}
	
	void setHealth(int hp)	// Здоровье
	{
		health = hp;
	}
	
	void getHealth()
	{
		cout << health << endl;
	}
	
	void getDamage(int damage)	// Получаемый урон
	{
		int resistance;
		resistance = (damage * 20 / strength) + rand() % 4;
		if (health - resistance > 0)
		{
			health = health - resistance;

			cout << "Персонаж " << name << " получил " << resistance << " урона. Здоровье: " << health << endl;
		}
		else
		{
			health = 0;
			cout << "Персонаж " << name << " получил " << resistance << " урона. Игра окончена, " << name << "(!" << endl;
		}
	}
	
	void getHealing(int healing) // Восстановление здоровья аптечкой
	{
		if (health + healing >= 200)
		{
			apt -= 1;
			cout << "аптечка использована" << " + " << healing << " здоровья" << " аптечек осталось" << apt << endl;
			health = 200;
		}
		else
		{
			health += healing;
			apt -= 1;
			cout << "аптечка использована" << " + " << healing << " здоровья" << " аптечек осталось" << apt << endl;
		}

	}
	
	void getOpening()	// Открытие сундуков
	{
		int alt = 0, zp = rand() % 101;

		if (luck >= 38)
		{
			
			if (zp <= 75)
			{
				luck -= 13;
				cout << "персонаж открыл сундук ";
				alt = rand() % 21;
				cout << "В сундуке " << alt << " золота" << endl;
				gold += alt;
				setlevel(1);
			}
			else
			{
				luck -= 15;
				cout << "персонаж открыл сундук ";
				cout << "В сундуке нет золота" << endl;
			}
		}
		else
		{
			
			if (zp <= 25)
			{
				luck -= 13;
				cout << "персонаж открыл сундук ";
				alt = rand() % 21;
				cout << "В сундуке " << alt << " золота" << endl;
				gold += alt;
				setlevel(1);
			}
			else
			{
				luck -= 15;
				cout << "персонаж открыл сундук ";
				cout << "В сундуке нет золота" << endl;
			}
		}
		printInfo();
	}
	
	void getGunTraid()			// Тарговля в магазине
	{
		printInfo();


		cout << "You went to the <Goblin shop>";
		cout << "\nассортимент:" << endl;
		if (pistol == 0)
			cout << "1 - пистолет(50):13 золота" << endl;
		
		if (shGun == 0)
			cout << "2 - дробовик(75):25 золота" << endl;
			
		if (ak == 0)
			cout << "3 - AK-47	(100):50 золота" << endl;
			
		if (ass == 1)
			cout << "4 - патроны(25) : 5 gold" << endl;
		int ng;
		cin >> ng;

		if (ng == 1)
		{
			if (pistol == 0)
			{
				if (gold >= 5)
				{
					strength += 25;
					gold -= 5;
					cout << "Персонаж купил пистолет" << endl;
					pistol += 1;
				}
				else
					cout << "нет денег" << endl;
			}
		}
		else
			if (ng == 2)
			{
				if (shGun == 0)
				{
					if (gold >= 10)
					{
						strength += 50;
						gold -= 10;
						cout << "Персонаж купил дробовик" << endl;
						shGun += 1;
					}
					else
						cout << "нет денег" << endl;
				}
			}
			else
				if (ng == 3)
				{
					if (ak == 0)
						if (gold >= 15)
						{
							strength += 75;
							gold -= 15;
							cout << "Персонаж купил AK-47" << endl;
							ak += 1;
						}
						else
							cout << "нет денег" << endl;
				}
				else
					if (ng == 4)
					{
						if (ass == 1)
						{
							if (gold >= 5)
							{
								strength += 25;
								gold -= 5;
								cout << "Персонаж докупил патронов" << endl;
							}
							else 
								cout << "нет денег" << endl;
						}
					}

	}

	void potionTraider()
	{
		printInfo();
		cout << "\nассортимент:" << endl;
		cout << "1 -    аптечка:  5 золота" << endl;
		cout << "2 - залье удачи:10 золота" << endl;
		cout << "3 - Уровень +1:   " << lvl * 10 << " золота " << endl;

		int mg1;
		cin >> mg1;
		if (mg1 == 1)
		{
			if (gold >= 5)
			{
				apt += 1;
				gold -= 5;
				cout << "доступно " << apt << " аптечек" << endl;
			}
			else
				cout << "нет денег" << endl;
		}
		else
			if (mg1 == 2)
			{
				if (gold >= 5)
				{
					luckp += 1;
					gold -= 10;
					cout << "игрок купил зелье удачи" << endl;
				}
				else
					cout << "нет денег" << endl;
			}
			else
				if (mg1 == 3)
				{
					if (gold >= lvl * 10)
					{
						lvl += 1;
						gold -= lvl * 10;
						cout << "ты купил 1 уровень" << endl;
					}
					else
						cout << "нет денег" << endl;
				}


	}
	
	void getMinusGold(int mg)	// Забор золота
	{
		gold -= mg;
	}
	
	void getPlGold(int pg)		// Добавление золота
	{
		gold += pg;
	}
	
	void getwin()				// Выйгрыш в сражениях
	{
		getMinusGold(10);
		if (ass != 0)
		{
			if (strength >= 100 && health >= 100)
			{

				int zp1;
				zp1 = rand() % 100;
				if (zp1 <= 60)
				{
					gold += 20;
					health -= 25;
					strength -= 20;
					cout << "\nТы выйграл\n" << endl;
					setlevel(2);
				}
				else
				{
					gold -= 20;
					health -= 25;
					strength -= 20;
					cout << "\nТы проиграл\n" << endl;
				}
			}
			else
			{
				gold -= 20;
				health -= 25;
				strength -= 20;
				cout << "\nТы проиграл\n" << endl;
			}
		}
		else
			cout << "купи пушку" << endl;
		printInfo();
	}
	
	void getlimit()				// Установка лимита
	{							//сила
		if (strength >= 200)
			strength = 200;

		if (strength <= 0)
			strength = 0;
		//удача
		if (luck >= 100)
			luck = 100;

		if (luck <= 0)
			luck = 0;
		//золото
		if (gold >= 100)
			gold = 100;

		if (gold <= 0)
			gold = 0;
		//здоровье
		if (health >= 200)
			health = 200;

		if (health <= 0)
			health = 0;
	}
	
	void action()
	{
		cout << "1 - аптечка " << "     Доступно " << apt << endl;
		cout << "2 - зелье удачи " << " Доступно " << luckp << endl;
		int arr;
		cin >> arr;
		if (arr == 1)
		{
			if (apt > 0)
			{
				health += 25;
				apt -= 1;
				cout << "аптечка использована" << " + 25 здоровья" << " аптечек осталось" << apt << endl;
			}
			else
				cout << "Аптечек нет" << endl;
		}
		else
			if (arr == 2)
				if (luckp > 0)
				{
					luck += 25;
					cout << "Зелье удачи использовано" << endl;
				}
				else
					cout << "Зелье удачи не найдено" << endl;
	}
	
	void setlevel(int levl)
	{
		lvl += levl;
	}

	void craft()
	{
		cout << "Вы вошли в меню крафта. Какой предмет вы желаете скрафтить?" << endl;
		string tempCraft;
		getline(cin, tempCraft);
		if (tempCraft == "axe")
		{
			bool stick = false, stone = false;
			for (int i = 0; i < inventory.size(); i++)
			{
				if (inventory[i] == "stick")
				{
					stick = true;
				}
				if (inventory[i] == "stone")
				{
					stone = true;
				}
			}
			if (stick && stone)
			{
				cout << "Вы скрафтили топор, он помещен в инвентарь." << endl << "палка удалена" << endl
					<< "камень удален" << endl;
				vector<string>tempInventory;
				for (int i = 0; i < inventory.size(); i++)
				{
					if (inventory[i] != "stick" && inventory[i] != "stone")
					{
						tempInventory.push_back(inventory[i]);
					}
				}
				inventory.clear();
				inventory.push_back("axe");
				for (int i = 0; i < tempInventory.size(); i++)
				{
					inventory.push_back(tempInventory[i]);
				}
			}
			else
			{
				if (!stone && stick)
				{
					cout << "Не хватает камня" << endl;
				}
				else
				{
					if (stone && !stick)
					{
						cout << "Не хватает палки" << endl;
					}
					else
						if (!stone && !stick)
						{
							cout << "Не хватает палки и камня" << endl;
						}
				}
			}
		}
	}

	void cave()
	{
		getMinusGold(10);
		getOpening();
		getOpening();
	}

	void start()
	{
		int actn;
		while (true)
		{
			printInfo();
			cout << "Выбери действие:" << endl << "1 - пещера(10)" << endl << "2 - сражение(10)" << endl	//Список действий
				<< "3 - торговля" << endl << "4 - Выход" << endl << "5 - Действие" << endl;
			cin >> actn;
			if (actn == 1)
			{
				system("cls");
				cave();
			}
			else
				if (actn == 2)
				{
					system("cls");
					getwin();
				}
				else
					if (actn == 3)
					{
						system("cls");;
						choiceShop();
					}
					else
						if (actn == 4)
							for (;;);
						else
							if (actn == 5)
							{
								system("cls");
								action();
							}

		}

	}

	void choiceShop()
	{
		cout << "1 - potion" << endl << "2 - gun" << endl;
		int shops;
		cin >> shops;
		if (shops == 1)
			potionTraider();
		else
			if (shops == 2)
				getGunTraid();
	}

};

void main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	character a(200, rand() % 200);
	cout << "Игра" << endl;
	a.start();
}
