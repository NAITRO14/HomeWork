#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
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
void border();
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
template <typename T1> void create(T1 array[], short size);
template <typename T1> void print(T1 array[], short size);
template <typename T1> void summa(T1 array[], short size);


int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));
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
			GotoXY(46, 8); cout << "Номер задания(1-3):";
			cin >> k;
			if (k > 3 or k < 0) { isInMain = true; }
			else { isInMain = false; }
		}
		if (k == 0) { break; }

		system("cls");
		//----------------------------------------
		const short size = 10;
		switch (k)
		{
		case 1:
		{
			short array[size] = {};

			create(array, size);
			print(array, size);
			border();
			summa(array, size);

		}break;
		case 2:
		{
			double array[size] = {};

			create(array, size);
			print(array, size);
			border();
			summa(array, size);

		}break;
		case 3:
		{
			char array[size] = {};

			create(array, size);
			print(array, size);
			border();
			summa(array, size);

		}break;
		//switch end
		}
		//------------------------------------------------
		bool YesNo;
		SetColor(LightBlue, Black);
		for (short y = 10; y <= 16; y += 2)
		{
			for (short x = 55; x <= 87; x++)
			{
				GotoXY(x, y);
				cout << "-";
			}
		}

		for (short x = 55; x <= 87; x += 87 - 55)
		{
			for (short y = 10; y <= 16; y++)
			{
				GotoXY(x, y);
				cout << "|";
			}
		}
		SetColor(LightCyan, Black); GotoXY(56, 11); cout << "Продолжить - (1)" << endl;
		GotoXY(56, 15); cout << "Закончить - (0)";
		GotoXY(56, 13); cout << "Ввод(1,0):";

		cin >> YesNo;
		if (YesNo == true) { system("cls"); isInMain = true; }
		else { break; }
	}
	system("cls");
	cout << "Вы вышли из программы" << endl;
	system("pause");
}

void border()
{
	cout << endl; SetColor(LightBlue, Black);
	for (short i = 0; i < 13; i++)
	{
		cout << "=*=";
	}
	cout << endl; SetColor(LightCyan, Black);
}

template<typename T1>
void create(T1 array[], short size)
{
	for (short i = 0; i < size; i++)
	{
		array[i] = (rand() % 26 + 65) + (rand() % 100 / 100.0);
	}
}

template<typename T1>
void print(T1 array[], short size)
{
	cout << "Все элементы массива" << endl;
	for (short i = 0; i < size; i++)
	{
		cout << array[i] << "	";
	}
}

template<typename T1>
void summa(T1 array[], short size)
{
	T1 sum_v = 0;
	cout << "Сумма всех элементов массива: ";
	for (short i = 0; i < size; i++)
	{
		sum_v += array[i];
	}
	cout << sum_v << endl;
}
