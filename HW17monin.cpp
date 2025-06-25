#include <iostream>
#include <windows.h>
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


void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
//----------------------------------------------------------
void border();

//задание 1
void first_ex();
//задание 2
void second_ex();
//задание 3
void third_ex();
//задание 4
void fourth_ex();

int main()
{
	setlocale(LC_ALL, "ru");
	short k;
	while (true)
	{
		system("cls");
		SetColor(LightBlue, Black);
		for (short y = 5; y <= 11; y += 2)
		{
			for (short x = 45; x <= 77; x++)
			{
				GotoXY(x, y);
				cout << "-";
			}
		}

		for (short x = 45; x <= 77; x += 77 - 45)
		{
			for (short y = 5; y <= 11; y++)
			{
				GotoXY(x, y);
				cout << "|";
			}
		}
		
		SetColor(LightCyan, Black); GotoXY(46, 6); cout << "Какое задание хотите проверить?" << endl;
		GotoXY(46, 10); cout << "Закончить - (0)";
		GotoXY(46, 8); cout << "Номер задания(1-4):";
		cin >> k;
		if (k == 0) { break; }
		if (k < 1 or k > 4) { GotoXY(46, 8); SetColor(LightRed, Black); cout << "Задания нет в списке" << endl; Sleep(1500); system("cls"); continue; }
		system("cls");
		switch (k)
		{
		case 1:
		{
			first_ex();
		}break;

		case 2:
		{
			second_ex();
		}break;

		case 3:
		{
			third_ex();
		}break;

		case 4:
		{
			fourth_ex();
		}break;
		}
		bool YesNo;
		SetColor(LightBlue, Black);
		for (short y = 5; y <= 11; y += 2)
		{
			for (short x = 45; x <= 77; x++)
			{
				GotoXY(x, y);
				cout << "-";
			}
		}

		for (short x = 45; x <= 77; x += 77 - 45)
		{
			for (short y = 5; y <= 11; y++)
			{
				GotoXY(x, y);
				cout << "|";
			}
		}

		SetColor(LightCyan, Black); GotoXY(46, 6); cout << "Продолжить - (1)" << endl;
		GotoXY(46, 10); cout << "Закончить - (0)";
		GotoXY(46, 8); cout << "Ввод(1,0):";

		cin >> YesNo;
		if (YesNo == true) { system("cls"); }
		
	}
	system("cls");
	cout << "Вы вышли из программы" << endl;
	system("pause");
}

void border()
{
	SetColor(LightBlue, Black);
	for (short i = 0; i < 15; i++)
	{
		cout << "=*=";
	}
	cout << endl;
	(LightCyan, Black);
}

void first_ex()
{
	float y;
	short count = 1;
	cout << "Значения y для x[-2;2] с шагом в 0.5" << endl;
	border();
	SetColor(Yellow, Black);
	for (float x = -2; x <= 2; x += 0.5)
	{
		y = -2.4 * x * x + 5 * x - 3;

		cout << "x" << count << "|" << y << endl;
		count++;
	}
}

void second_ex()
{
	//С учетом того, что сначала начисляются проценты, а потом снимают деньги 
	float sum = 1000000;
	short sub = 100000;
	short count = 1;
	while (sum > 0)
	{
		sum = sum + (sum * 0.08);
		if ((sum -= 100000) > 0)
		{
			SetColor(LightCyan, Black);
			cout << "Остаток на "; SetColor(Yellow, Black); cout << count; SetColor(LightCyan, Black); cout << " год:"; SetColor(Yellow, Black); cout << sum << endl;
			count++;
		}
		else
		{
			border();
			SetColor(LightCyan, Black);
			cout << "Деньги закончатся через "; SetColor(Yellow, Black);  cout << count; SetColor(LightCyan, Black); cout << " год" << endl;
		}

	}
}

void third_ex()
{
	SetColor(Yellow, Black);
	short f = 0;
	for (short x = -10; x <= 20; x++)
	{
		if (x % 5 == 0) { continue; }
		if (x % 2 == 0) { f = x * x - 13; if (f >= 300) { break; } }
		if (x % 3 == 0) { f = 3 * x + 10; }
		if (f >= 300) { break; }
		cout << f << endl;
	}
}

void fourth_ex()
{
	char symbol;
	short len;
	string orien;
	cout << "Введите любой символ:"; SetColor(Yellow, Black);
	cin >> symbol; SetColor(LightCyan, Black);
	cout << "Введите длинну линии:"; SetColor(Yellow, Black);
	cin >> len; SetColor(LightCyan, Black);
	cout << "Укажите ориентацию линии(вертикальную - vert, горизональную - horiz):"; SetColor(Yellow, Black);
	cin >> orien;
	border(); SetColor(Yellow, Black);
	if (orien == "vert")
	{
		for (short i = 0; i < len; i++) { cout << symbol << endl; }
	}
	if (orien == "horiz")
	{
		short i = 0;
		for (; i <= len; i++) { cout << symbol; if (i == len) { cout << "" << endl; } }

	}
}
