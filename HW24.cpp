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

short*** create(short& list, short& row, short& col);
void init(short ***&array, short& list, short& row, short& col);
void print(short***& array, short& list, short& row, short& col);



int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL)); SetColor(LightCyan, Black);

	

	short* list = new short();
	short* row = new short();
	short* col = new short();
	short*** array = create(*list, *row, *col);
	init(array, *list, *row, *col);
	print(array, *list, *row, *col);
}


short*** create(short& list, short& row, short& col)
{
	do
	{
		cout << "Введите количество листов(не менее 1 и не более 15)" << endl;
		cout << "Листы: ";
		cin >> list;
		system("cls");
	} while (list < 1 or list > 15);
	
	do
	{
		cout << "Введите количество строк(не менее 1 и не более 20)" << endl;
		cout << "Строки: ";
		cin >> row;
		system("cls");
	} while (row < 1 or row > 20);

	do
	{
		cout << "Введите количество столбцов(не менее 1 и не более 10)" << endl;
		cout << "Столбцы: ";
		cin >> col;
		system("cls");
	} while (col < 1 or col > 10);

	short*** array = new short**[list];
	for (short i = 0; i < list; i++)
	{
		array[i] = new short* [row];
		for (short j = 0; j < row; j++)
		{
			array[i][j] = new short[col];
		}
	}

	return array;
}

void init(short***&array, short& list, short& row, short& col)
{
	for (short i = 0; i < list; i++)
	{
		for (short j = 0; j < row; j++)
		{
			for (short o = 0; o < col; o++)
			{
				array[i][j][o] = rand() % 100;
			}
		}
	}
}

void print(short***& array, short& list, short& row, short& col)
{
	short n = 1;
	for (short i = 0; i < list; i++)
	{
		cout << "Лист: " << n << endl;
		n++;
		for (short j = 0; j < row; j++)
		{
			for (short o = 0; o < col; o++)
			{
				cout << setw(4) << array[i][j][o] << "	";
			}
			cout << endl;
		}
		cout << endl;
	}
}
