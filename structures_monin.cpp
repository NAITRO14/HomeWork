#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include<conio.h>

#include <locale.h>  //библиотека для локали С

using namespace std;

enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void Goto(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

//подключение кнопок
enum keys
{
	t = 72,
	d = 80,
	r = 77,
	l = 75,
	ent = 13,
	esc = 27
};

//структуры для студентов(чтение/запись)
struct st_for_read {
	char f_name[32];
	char l_name[32];
	char group[16];
	int session[5];
	float avg_s;
};

struct student
{
	string f_name;
	string l_name;
	string group;
	int session[5];
	float avg_s;

	void makeArr()
	{
		for (short i = 0; i < 5; i++)
		{
			session[i] = rand() % 12 + 1;
		}
	}

	void avg_()
	{
		short T = 0;
		for (short i = 0; i < 5; i++)
		{
			T += session[i];
		}
		avg_s = T / 5.0;
	}

	void print()
	{
		SetColor(LightCyan, Black);
		cout << "Имя: " << f_name << endl;
		cout << "Фамилия: " << l_name << endl;
		cout << "Группа: " << group << endl;

		//вывод сессии
		cout << "Оценки по 5 предметам: ";
		for (short i = 0; i < 5; i++)
		{
			//цвета для оценок
			{
				if (session[i] <= 3) { SetColor(Red, Black); }
				else if (session[i] <= 6) { SetColor(Yellow, Black); }
				else if (session[i] <= 9) { SetColor(Cyan, Black); }
				else if (session[i] <= 12) { SetColor(LightGreen, Black); }
			}

			cout << session[i] << " ";
		}cout << endl;

		SetColor(LightCyan, Black);
		cout << "Средний балл: ";

		//цвета для оценок
		{
			if (avg_s <= 3) { SetColor(Red, Black); }
			else if (avg_s <= 6) { SetColor(Yellow, Black); }
			else if (avg_s <= 9) { SetColor(Cyan, Black); }
			else if (avg_s <= 12) { SetColor(LightGreen, Black); }
		}
		cout << avg_s << endl;
		SetColor(Magenta, Black);
		cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
		SetColor(LightCyan, Black);
	}

};

//создать массив студентов(р.р. - указатель)
student* createStud(short s_value);

//вывод сессии из файла в консоль
void printMas(FILE* f, student* students, short i);

//сортировка массива указателей
void sort(student*& students, short s_value);

//сохранение информации во внешние файлы(soted/unsorted)
void saveInf(short s_value, student* students, bool man);

//для стрелок
void paintText(short y);

//создание информации
void createData(short s_value, student* students);

//чтение информации из вн.ф
void readData();

//-----------main-----------
int main()
{
	setlocale(LC_ALL, "ru");
	setlocale(LC_NUMERIC, "C"); // для того чтобы поменять локалсь с русской на локаль С (для вывода точки вместо запятой в txt файле)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	//переменные для работы
	//количество учащихся(если будет меняться)
	short s_value = 10;
	float* avgs = new float[s_value];
	bool sure;
	short global_manage, isIn = true;
	short y;
	student* students = createStud(s_value);
	//переменные для работы



	//главный цикл
	while (isIn)
	{
		system("cls"); SetColor(White, Black);

		y = 2; isIn = true;
		paintText(y);
		while (isIn)
		{
			
			if (_kbhit())
			{
				switch (static_cast<keys>(_getch()))
				{
					
				//to top
				case t:
				{
					y--;
					if (y == 1) y = 3;
					paintText(y);
				}break;

				//to down
				case d:
				{
					y++;
					if (y == 4) y = 2;
					paintText(y);	
				}break;

				//select
				case ent:
				{
					system("cls");
					if (y == 2)
					{
						createData(s_value, students);
					}

					else if (y == 3)
					{
						readData();
					}

					SetColor(White, Black);
					cout << "Что бы вернуться в меню, нажмите 'down'" << endl;
					while (true)
					{
						if (static_cast<keys>(_getch() == d))
						{
							paintText(y);
							break;
						}
					}

				}break;

				case esc:
				{
					isIn = false;
				}
				//switch end
				}
			}
		}

	}
	//главный цикл
	


	//конец работы
	SetColor(Magenta, Black);
	system("cls"); Goto(40, 2);
	cout << "Программа остановлена пользователем"; Sleep(800); cout << " . "; Sleep(800); cout << ". "; Sleep(800); cout << "."; Goto(40, 2);
	SetColor(White, Black);
	system("pause");
}
//-----------main-----------


void sort(student*& students, short s_value)
{
	for (short i = 0; i < s_value - 1; i++)
	{
		for (short j = 0; j < s_value - i - 1; j++)
		{
			if (students[j].avg_s < students[j + 1].avg_s)
			{
				student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
}

void saveInf(short s_value, student* students, bool man)
{
	
	FILE* f = fopen("sortedList.txt", "w");
	if(!man) f = fopen("UnSortedList.txt", "w");

	if (!f) cout << "file not dound" << endl;
	else
	{
		if (!man)
		{
			fprintf(f, "UnSorted list\n");
		}
		else
		{
			fprintf(f, "Sorted list\n");
		}
		
		fprintf(f, "%-10s %-10s %-11s %-14s %-4s\n", "Name", "Last name", "Group", "Session", "Averege");
		for (short i = 0; i < s_value; i++)
		{
			fprintf(f, "%-10s %-10s %-4s ", students[i].f_name.c_str(), students[i].l_name.c_str(), students[i].group.c_str());
			printMas(f, students, i);
			fprintf(f, "%-4.2f\n", students[i].avg_s);

		}
		fclose(f);
	}
}

void paintText(short y)
{
	
	system("cls"); SetColor(White, Black);
	cout << "Программа вывода данных о студентах(и их создания для теста)\n" << endl;
	cout << "1|Cгенерировать данные\n2|Прочитать данные\nESC - выйти" << endl;
	if (y == 2)
	{
		Goto(0, y); SetColor(Yellow, Black); cout << "1|Cгенерировать данные";
	}
	else if (y == 3)
	{
		Goto(0, y); SetColor(Yellow, Black); cout << "2|Прочитать данные";
	}
}

void createData(short s_value, student* students)
{
	short mode;
	for (short i = 0; i < s_value; i++)
	{
		students[i].makeArr();
		students[i].avg_();
	}

	mode = 0;

	saveInf(s_value, students, mode);

	sort(students, s_value);

	SetColor(LightCyan, Black);

	cout << "Список группы П414" << endl << endl;

	for (short i = 0; i < s_value; i++)
	{
		students[i].print();
	}

	mode = 1;

	saveInf(s_value, students, mode);
}

void readData()
{
	
	FILE* f = fopen("sortedList.txt", "r");
	if (!f) {
		SetColor(LightRed, Black); system("cls");
		cout << "Кажется, вы еще не создали файл для чтения" << endl;
		cout << "Нечего мне читать !" << endl;
		Sleep(2500);
	}
	else
	{
		char buf[128];
		fgets(buf, sizeof(buf), f);	// пропустить sorted/Unsorted list
		fgets(buf, sizeof(buf), f); // пропустить name last name...

		st_for_read tmp;
		SetColor(Magenta, Black);
		printf("%-15s %-15s %-11s %-9s %s\n", "Name", "Last name", "Group", "Session", "Averege");
		SetColor(LightCyan, Black);
		while (fscanf(f, "%s %s %s |%i %i %i %i %i |%f", tmp.f_name, tmp.l_name, tmp.group, &tmp.session[0], &tmp.session[1], &tmp.session[2], &tmp.session[3], &tmp.session[4], &tmp.avg_s) == 9)
		{
			printf("%-15s %-15s: %-5s |%-2i %-2i %-2i %-2i %-2i| %.2f\n", tmp.f_name, tmp.l_name, tmp.group, tmp.session[0], tmp.session[1], tmp.session[2], tmp.session[3], tmp.session[4], tmp.avg_s);
		}
		fclose(f);

		
		SetColor(Magenta, Black);
		for (short i = 0; i < 11; i++)
		{
			Goto(61, i); cout << "||";
		}

		for (short i = 0; i < 63; i++)
		{
			Goto(i, 11); cout << "=";
		}cout << endl;
	}
}

student* createStud(short s_value)
{
	string group = "P414";

	student me = { "Егор", "Монин", group, {0}, 0 }; //1
	student bz = { "Захар", "Большаков", group, {0}, 0 }; //2
	student mr = { "Мария", "Рачейскова", group, {0}, 0 }; //3
	student ri = { "Иван", "Розинкин", group, {0}, 0 }; //4
	student gr = { "Регина", "Гилярова", group, {0}, 0 }; //5
	student gs = { "Александр", "Говряков", group, {0}, 0 }; //6
	student azg = { "Алексей", "Жуков", group, {0}, 0 }; //7
	student nd = { "Никита", "Девятов", group, {0}, 0 }; //8
	student va = { "Витория", "Афанасьева", group, {0}, 0 }; //9
	student sk = { "Светлана", "Кадерова", group, {0}, 0 }; //10

	student* s = new student[s_value]{ me, bz, mr, ri, gr, gs, azg, nd, va, sk };

	return s;
}

void printMas(FILE* f, student* students, short i)
{
	fprintf(f, "|");
	for (short j = 0; j < 5; j++)
	{
		fprintf(f, "%-3i ", students[i].session[j]);

	}
	fprintf(f, "|");

	
}
