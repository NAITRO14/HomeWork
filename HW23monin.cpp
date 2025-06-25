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

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));
	while (true)
	{
		system("cls"); SetColor(LightCyan, Black);
		short list, row, col, n =1;

		//получение размеров массива
		cout << "Укажите размерности трехмерного массива" << endl; Sleep(1500); 
		while(true)
		{
			system("cls"); SetColor(LightCyan, Black);
			cout << "До 10 листов" << endl;
			cout << "Листы: ";
			cin >> list;
			if (1 < list and list < 10) { break; }
			else{ SetColor(LightRed, Black); cout << "Недопустимое количество листов" << endl; Sleep(2000); system("cls"); }
		}
		
		while (true)
		{
			system("cls"); SetColor(LightCyan, Black);
			cout << "До 20 строк" << endl;
			cout << "Строки: ";
			cin >> row;
			if (1 < row and row < 20) { break; }
			SetColor(LightRed, Black); cout << "Недопустимое количество строк" << endl; Sleep(2000); system("cls");
		}

		while (true)
		{
			system("cls"); SetColor(LightCyan, Black);
			cout << "До 15 колонок" << endl;
			cout << "Колонки: ";
			cin >> col;
			if (1 < col and col < 15) { system("cls"); break; }
			SetColor(LightRed, Black); cout << "Недопустимое количество колонок" << endl; Sleep(2000); system("cls");
		}


		//инициализация массива
		double*** array = new double** [list];
		for (short i = 0; i < list; i++)
		{
			array[i] = new double* [row];
			for (short j = 0; j < row; j++)
			{
				array[i][j] = new double[col];
			}
		}

		for (short i = 0; i < list; i++)
		{
			for (short j = 0; j < row; j++)
			{
				for (short o = 0; o < col; o++)
				{
					array[i][j][o] = (rand() % 100) + ((rand() % 100) / 100.0);
				}
			}
		}

		for (short i = 0; i < list; i++)
		{
			SetColor(Magenta, Black); cout << "=*=*=*=*=*=*=*=**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl; SetColor(LightCyan, Black);
			cout << "Лист "; SetColor(Yellow, Black); cout << n << endl; SetColor(LightCyan, Black);
			for (short j = 0; j < row; j++)
			{
				for (short o = 0; o < col; o++)
				{
					cout << setw(5) << array[i][j][o] << "	";
				}
				cout << endl;
			}
			n++;
		}
		n = 1;

		for (short i = 0; i < list; i++)
		{
			for (short j = 0; j < row; j++)
			{
				delete[] array[i][j];
			}
			delete[] array[i];
		}
		delete[] array;
		delete array;

		system("pause");
	}
	
}