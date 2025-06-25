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

template <typename T1> void create(T1 ar[], short row);
template <typename T1> void print(T1 ar[], short row);
template <typename T1> void max_or_min(T1 ar[], short row, short min_max);

template <typename T1> void create(T1 ar[][30], short row, short col);
template <typename T1> void print(T1 ar[][30], short row, short col);
template <typename T1> void max_or_min(T1 ar[][30], short row, short min_max, short col);

template <typename T1> void create(T1 ar[][30][30], short row, short col, short list);
template <typename T1> void print(T1 ar[][30][30], short row, short col, short list);
template <typename T1> void max_or_min(T1 ar[][30][30], short row, short min_max, short col, short list);

int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL)); SetColor(LightCyan, Black);
	
	while (true)
	{
		const short size = 30;
		short mas, type, min_max, row, col, list;

		//Одномерные
		short sh_ar_1[size] = {}; double do_ar_1[size] = {}; char ch_ar_1[size] = {};

		//Двумерные
		short sh_ar_2[size][size] = {}; double do_ar_2[size][size] = {}; char ch_ar_2[size][size] = {};

		//Трехмерные
		short sh_ar_3[size][size][size] = {}; double do_ar_3[size][size][size] = {}; char ch_ar_3[size][size][size] = {};

		//мерность массива
		do
		{
			cout << "Введите  мерность массива(1-3)" << endl;
			cin >> mas;
			system("cls");
		} while (mas < 1 or mas > 3);

		//тип данных массива
		do
		{
			cout << "Какого типа данных масив нужен?" << endl;
			cout << "1|short\n2|double\n3|char" << endl;
			cin >> type;
			system("cls");
		} while (type < 1 or type > 3);
		
		
		//указание размеров массива
		if (mas == 1)
		{
			do
			{
				cout << "Введите  размер массива(5-30)" << endl;
				cin >> row;
				system("cls");
			} while (row < 5 or row > 30);
		}
		else if (mas == 2)
		{
			do
			{
				cout << "Введите  размер массива(5-30)" << endl;
				cout << "Количество строк" << endl;
				cin >> row;
				cout << "Количество колонок" << endl;
				cin >> col;
				system("cls");
			} while (row < 5 or row > 30 or col < 5 or col > 30);
		}
		else if (mas == 3)
		{
			do
			{
				cout << "Введите  размер массива(5-30)" << endl;
				cout << "Количество строк" << endl;
				cin >> row;
				cout << "Количество колонок" << endl;
				cin >> col;
				cout << "Количество листов" << endl;
				cin >> list;
				system("cls");
			} while (row < 5 or row > 30 or col < 5 or col > 30 or list < 5 or list > 30);
		}

		//элемент для вывода
		do
		{
			cout << "Вы хотите увидеть минимальный или максимальный элемент массива?(1-2)" << endl;
			cin >> min_max;
			system("cls");
		} while (min_max < 1 or min_max > 2);

		//Вызов функций
		if (mas == 1) 
		{ 
			if (type == 1)
			{
				create(sh_ar_1, row);
				print(sh_ar_1, row);
				max_or_min(sh_ar_1, row, min_max);
			}
			else if (type == 2)
			{
				create(do_ar_1, row);
				print(do_ar_1, row);
				max_or_min(do_ar_1, row, min_max);
			}
			else if (type == 3)
			{
				create( ch_ar_1, row);
				print(ch_ar_1, row);
				max_or_min(ch_ar_1, row, min_max);
			}
		}

		if (mas == 2)
		{
			if (type == 1)
			{
				create(sh_ar_2, row, col);
				print(sh_ar_2, row, col);
				max_or_min(sh_ar_2, row, min_max, col);
			}
			else if (type == 2)
			{
				create(do_ar_2, row, col);
				print(do_ar_2, row, col);
				max_or_min(do_ar_2, row, min_max, col);
			}
			else if (type == 3)
			{
				create(ch_ar_2, row, col);
				print(ch_ar_2, row, col);
				max_or_min(ch_ar_2, row, min_max, col);
			}
		}

		if (mas == 3)
		{
			if (type == 1)
			{
				create(sh_ar_3, row, col, list);
				print(sh_ar_3, row, col, list);
				max_or_min(sh_ar_3, row, min_max, col, list);
			}
			else if (type == 2)
			{
				create(do_ar_3, row, col, list);
				print(do_ar_3, row, col, list);
				max_or_min(do_ar_3, row, min_max, col, list);
			}
			else if (type == 3)
			{
				create(ch_ar_3, row, col, list);
				print(ch_ar_3, row, col, list);
				max_or_min(ch_ar_3, row, min_max, col, list);
			}
		}


		system("pause");
		system("cls");
	}
	

}

//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------

//one
//ctreate
template<typename T1>
void create(T1 ar[], short row)
{
	for (short i = 0; i < row; i++)
	{
		ar[i] = ((rand() % 25 + 65) + (rand() % 100 / 100.0));
	}
}

//print
template<typename T1>
void print(T1 ar[], short row)
{
	cout << "Весь массив:" << endl;
	for (short i = 0; i < row; i++)
	{
		cout << setw(4) << ar[i] << "	";
	}
	cout << endl;
}

//MaxMin
template<typename T1>
void max_or_min(T1 ar[], short row, short min_max)
{
	T1 tmp_for_max = 0, tmp_for_min = 100;
	for (short i = 0; i < row; i++)
	{
		if (tmp_for_max < ar[i]) { tmp_for_max = ar[i]; }
	}

	for (short i = 0; i < row; i++)
	{
		if (tmp_for_min > ar[i]) { tmp_for_min = ar[i]; }
	}
	
	if (min_max == 1) { cout << "Минимальное значение:"; SetColor(Yellow, Black); cout << tmp_for_min << endl; }
	else { cout << "Максимальное значение:"; SetColor(Yellow, Black); cout << tmp_for_max << endl; }
	SetColor(LightCyan, Black);
}

//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------

//two
//create
template<typename T1>
void create(T1 ar[][30], short row, short col)
{
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			ar[i][j] = ((rand() % 25 + 65) + (rand() % 100 / 100.0));
		}
	}
}

//print
template<typename T1>
void print(T1 ar[][30], short row, short col)
{
	cout << "Весь массив:" << endl;
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			cout << setw(4) << ar[i][j] << "	";
		}
		cout << endl;
	}
}

//MaxMin
template<typename T1>
void max_or_min(T1 ar[][30], short row, short min_max, short col)
{
	T1 tmp_for_max = 0, tmp_for_min = 100;
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			if (tmp_for_max < ar[i][j]) { tmp_for_max = ar[i][j]; }
			if (tmp_for_min > ar[i][j]) { tmp_for_min = ar[i][j]; }
		}
		
	}

	if (min_max == 1) { cout << "Минимальное значение:"; SetColor(Yellow, Black); cout << tmp_for_min << endl; }
	else { cout << "Максимальное значение:"; SetColor(Yellow, Black); cout << tmp_for_max << endl; }
	SetColor(LightCyan, Black);
}

//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------

//three
//create
template<typename T1>
void create(T1 ar[][30][30], short row, short col, short list)
{
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			for (short l = 0; l < list; l++)
			{
				ar[i][j][l] = ((rand() % 26 + 65) + (rand() % 100 / 100.0));
			}
		}
	}
}

//print
template<typename T1>
void print(T1 ar[][30][30], short row, short col, short list)
{

	cout << "Весь массив:" << endl;

	for (short i = 0; i < row; i++)
	{
		cout << "Лист " << i + 1 << endl;
		for (short j = 0; j < col; j++)
		{
			for (short l = 0; l < list; l++)
			{
				cout << setw(4) << ar[i][j][l] << "	";
			}
			cout << endl;
		}
		cout << endl;
	}
}

template<typename T1>
void max_or_min(T1 ar[][30][30], short row, short min_max, short col, short list)
{
	T1 tmp_for_max = 0, tmp_for_min = 100;
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			for (short l = 0; l < list; l++)
			{
				if (tmp_for_max < ar[i][j][l]) { tmp_for_max = ar[i][j][l]; }
				if (tmp_for_min > ar[i][j][l]) { tmp_for_min = ar[i][j][l]; }
			}
		}
	}

	if (min_max == 1) { cout << "Минимальное значение:"; SetColor(Yellow, Black); cout << tmp_for_min << endl; }
	else { cout << "Максимальное значение:"; SetColor(Yellow, Black); cout << tmp_for_max << endl; }
	SetColor(LightCyan, Black);
}



