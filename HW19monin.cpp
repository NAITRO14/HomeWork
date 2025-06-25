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
//------------------------------------------------------
//int
void create(short array[], short size);
void print(short array[], short size);
void summa(short array[], short size);

//double
void create(double array[], short size);
void print(double array[], short size);
void summa(double array[], short size);

//char
void create(char array[], short size);
void print(char array[], short size);
void summa(char array[], short size);


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
			short sum_v = 0;
			short array[size] = {};

			create(array, size);
			print(array, size);
			border();
			summa(array, size);

		}break;
		case 2:
		{
			double sum_v = 0;
			double array[size] = {};

			create(array, size);
			print(array, size);
			border();
			summa(array, size);

		}break;
		case 3:
		{
			short sum_v = 0;
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

//int
void create(short array[], short size)
{
	for (short i = 0; i < size; i++)
	{
		array[i] = rand() % 11;
	}
}

void print(short array[], short size)
{
	cout << "Все элементы массива";
	for (short i = 0; i < size; i++)
	{
		if (i % 5 == 0) { cout << endl; }
		cout << array[i] << "	";
	}
}

void summa(short array[], short size)
{
	cout << endl << "Сумма всех элементов массива" << endl;
	short sum = 0;
	for (short i = 0; i < size; i++)
	{
		sum += array[i];
	}
	cout << sum << endl;
}

//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

//double
void create(double array[], short size)
{
	double tmp1 = 0, tmp2 = 0;

	for (short i = 0; i < size; i++)
	{
		tmp1 = rand() % 10;
		tmp2 = rand() % 101;
		if (tmp2 == 100) { array[i] = tmp1 + 1; continue; }
		array[i] = tmp1 + (tmp2 / 100);
	}
}

void print(double array[], short size)
{
	cout << "Все элементы массива";
	for (short i = 0; i < size; i++)
	{
		if (i % 5 == 0) { cout << endl; }
		cout << setw(4) << array[i] << "	";
	}
}

void summa(double array[], short size)
{
	cout << endl << "Сумма всех элементов массива" << endl;
	double sum = 0;
	for (short i = 0; i < size; i++)
	{
		sum += array[i];
	}
	cout << sum << endl;
}

//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

//char
void create(char array[], short size)
{
	for (short i = 0; i < size; i++)
	{
		array[i] = rand() % 26 + 65;
	}
}

void print(char array[], short size)
{
	cout << "Все элементы массива";
	for (short i = 0; i < size; i++)
	{
		if (i % 5 == 0) { cout << endl; }
		cout << array[i] << "	";
	}
}

void summa(char array[], short size)
{
	cout << endl << "Сумма всех элементов массива" << endl;
	short sum = 0;
	for (short i = 0; i < size; i++)
	{
		sum += array[i];
	}
	cout << char(sum) << endl;
	border();
	cout << "Сумма индексов элементов равна "; SetColor(Yellow, Black); cout << sum; SetColor(LightCyan, Black); cout << ", по этому индексу может не быть символа, поэтому вывод может быть пустым" << endl;
}
