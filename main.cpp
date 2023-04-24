#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
//#define DEBUG
using namespace std;
const string FailName = "Your_data.txt";
const string FailId = "Human_id.txt";
class Human
{
private:
	string name;
	double age;
	string familia;
	string telefon;
public:
	Human()
	{
		name = ""; age = 0;
		
		
	}
	Human(string name, double age, string telefon, string familia)
	{
		this->age = age;
		this->name = name;
		this->familia = familia;
		this->telefon = telefon;
	}
	void PrintAll()
	{
		std::cout << "Имя: " << name << endl;
		std::cout << "Возраст: " << age << endl;
		cout << "Фамилия: " << familia << endl;
		cout << "Телефон: " << telefon << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "ru");
	int id = 0;

	string name = "";
	double age = 0;

	std::cout << "нажмиты 1-чтобы записать данные.\nнажмите 2-чтобы получить данные.\nнажмите 3-чтобы удалить файл с данными." << endl;

	while (true)
	{
		fstream HUMAN(FailName, fstream::in | fstream::out | fstream::app);

		cout << "введите ваш выбор: ";
		id = _getch();
		
		if (id == 27) { HUMAN.close(); return 0; };
#ifdef DEBUG
		std::cout << id << endl;
#endif
		if (id == 49)
		{
			fstream failid1(FailId, fstream::app | fstream::in | fstream::out);

			string str = "";
			string id2;
			
			if (failid1.is_open())
			{
				while (!failid1.eof())
				{
					while (getline(failid1, str))
					{
						id2 = str;
					}
				}
			}
			else
			{
				cout << "ошибка открытия файла" << endl;
				system("pause");
				return -1;
			}
			const char* c_inp = id2.c_str();
			failid1.close();
			int id12 = atoi(c_inp);
			
#ifdef DEBUG
			cout << "была нажата цифра 1" << endl;
#endif 
			string familia;
			string telefone;
			cout << "1" << endl;
			SetConsoleCP(1251);
			std::cout << "введите имя человека(без пробелов): ";
			int proverca = _getch();
			if (proverca == 13)
			{
				name = "Небыло введено";
				cout << endl;
			}
			else
			{
				std::cin >> name;
			}

			cout << "Введите фамилию человека(если ее нету просто пропустите): ";
			proverca = _getch();
			if (proverca == 13)
			{
				familia = " ";
				cout << endl;
			}
			else
			{
				cin >> familia;
			}

			cout << "Введите телефон человека(если его нету пропустите поле(записывать без пробелов)): ";
			proverca = _getch();
			if (proverca == 13)
			{
				telefone = "телефон небыл введен";
				cout << endl;
			}
			else
			{
				cin >> telefone;
			}

			std::cout << "Введите возраст человека: ";
			proverca = _getch();
			if (proverca == 13)
			{
				age = 0;
				cout << endl;
			}
			else
			{
				cin >> age;
			}
			fstream fai(FailId, fstream::app | fstream::in | fstream::out);
			++id12;
			fai << to_string(id12) << '\n';
			fai.close();

			fstream failid2(FailName, fstream::app | fstream::in | fstream::out);
			Human human(name, age, familia, telefone);
			
			if (failid2.is_open())
			{
				string intId = to_string(id12);

				failid2 << '\n';

				failid2 << intId << '\n';

				failid2.write((char*)&human, sizeof(Human));

				cout << "Данные записались в файл!" << std::endl;
				SetConsoleCP(866);
				failid2.close();
			}
			else
			{
				cout << "файл не найден перезапустите приложение\n";
				system("pause");
				return -1;
			}
			
		}
		else if (id == 50)
		{
#ifdef DEBUG
			cout << "была нажата цифра 2" << endl;
#endif 
			cout << "2" << endl;
			if (HUMAN.is_open())
			{
				string str;
				Human pnt;
				int a;
				cout << "Пожалуйста введите индекс человека: ";
				cin >> a;
				cout << endl;

				while (getline(HUMAN, str))
				{
					if (str == to_string(a))
					{
						Human print;
						HUMAN.read((char*)&print, sizeof(Human));
						print.PrintAll();
						system("pause");
						break;
					}
				}
				HUMAN.close();
			}
			else
			{
				cout << "файл не найден перезапустите приложение\n";
				system("pause");
				return -1;
			}
		}
		else if(id==51)
		{
#ifdef DEBUG
			cout << "была нажата цифра 3" << endl;
#endif
			cout << "3" << endl;
			
			fstream s(FailName);
			fstream x(FailId);
			const char* c_inp = FailName.c_str();
			const char* ChI = FailId.c_str();
			s.close();
			x.close();
			HUMAN.close();
			
			remove(c_inp);
			remove(ChI);
			cout << "Данные успешно удалины!" << endl;
		}
		else
		{
			cout << "такой команды нету" << endl;
		}
		HUMAN.close();
		cout << endl;
	}
	system("pause");
	return 0;
}