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
//void to_dollor(float _rub, short _manage);
//void verify(int _num1, int _num2);

float to_dollor(float _rub, short _manage);
bool verify(int _num1, int _num2);

int main()
{
	setlocale(LC_ALL, "ru");
	short k;
	bool isInMain = true;
	while (true)
	{
		while (isInMain)
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
			GotoXY(46, 8); cout << "Номер задания(1-2):";
			cin >> k;
			if (k > 2) { isInMain = true; }
			else { isInMain = false; }
		}
		if (k == 0) { break; }

		
		switch (k)
		{
		case 1:
		{
			system("cls");
			short manage;
			float rub;
			bool isIn = true;
			while (isIn)
			{
				cout << "Что вы хотите сделать?" << endl;
				cout << "1 - перевести в евро\n2 - перевести в доллары" << endl;
				cin >> manage;
				if (manage < 1 or manage > 2) { isIn = true; system("cls"); }
				else { isIn = false; }
			}
			cout << "Введите количество рублей: ";
			cin >> rub;

			switch (manage)
			{
			case 1:
			{
				cout << to_dollor(rub, manage) << " Евр." << endl;
			}break;
			case 2:
			{
				cout << to_dollor(rub, manage) << " Дол." << endl;
			}break;
			}
			//to_dollor(_rub, manage);
		}break;
		case 2:
		{
			system("cls");
			int num1, num2;
			cout << "Введите делимое: ";
			cin >> num1;
			cout << "Введите делитель: ";
			cin >> num2;

			if (verify(num1, num2) == true) { cout << "Числа делятся без остатка" << endl; }
			else { cout << "Числа не делятся без остатка" << endl; }
			//verify(num1, num2);
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
		else { break; }
	}
	system("cls");
	cout << "Вы вышли из программы" << endl;
	system("pause");
}	
//вариант функций без возвр. значения(в switch просто вызвать их)

//void to_dollor(float _rub, short _manage)
//{
//	if (_manage == 1) { cout << _rub / 84.19 << endl; }
//	if (_manage == 2) { cout << _rub / 92.34 << endl; }
//}
//
//void verify(int _num1, int _num2)
//{
//	
//	if (_num1 % _num2 == 0) { cout << "Числа делятся без остатка" << endl ; }
//	else { cout << "Числа не делятся без остатка" << endl; }
//	
//}

float to_dollor(float _rub, short _manage)
{
	if (_manage == 1) { return _rub / 84.19; }
	if (_manage == 2) { return _rub / 92.34; }
}

bool verify(int _num1, int _num2)
{
	bool answ;
	if (_num1 % _num2 == 0) { answ = true; }
	else { answ = false; }
	return answ;
}
