#include <iostream>
#include <windows.h>
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


//start
int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));
	
	bool isMainIn = true;
	short manage;
	string border = "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";


	system("cls");
	while (isMainIn)
	{
		system("cls");
		SetColor(LightBlue, Black);
		GotoXY(0, 29); cout << "Монин Егор П414";
		short isIn = 1;



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
		GotoXY(46, 10); cout << "Закончить - 0";
		GotoXY(46, 8); cout << "Номер задания(1-2):";
		cin >> manage;
		switch (manage)
		{
		//Задание 1	<------------------------------------
		case 1:
		{
			while (isIn)
			{
				system("cls");
				const short row_max = 30;
				const short col_max = 30;
				short row, col;
				short arrayA[row_max][col_max] = {};
				short arrayB[row_max][col_max] = {};
				float arrayC[row_max][col_max] = {};
				float arrayD[row_max][col_max] = {};

				do
				{
					GotoXY(0, 2); SetColor(Yellow, Black); cout << "Размер больше 10 лучше не указывать"; GotoXY(0, 0); SetColor(LightCyan, Black);
					cout << "Введите количество строк(до 30):";
					cin >> row;
					cout << "Введите количество колонок(до 30):";
					cin >> col;
					system("cls");
				} while (row < 0 or row > 30 or col < 0 or col > 30);



				//а
					cout << "Матрица А" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayA[i][j] = rand() % 21 - 10;
						cout << setw(3) << arrayA[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);

				//а * 2
					cout << "Матрица А*2" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayA[i][j] *= 2;
						cout << setw(3) << arrayA[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);


				//b
					cout << "Матрица Б" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayB[i][j] = rand() % 41 - 20;
						cout << setw(3) << arrayB[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);

				//b * 3
					cout << "Матрица Б*3" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayB[i][j] *= 3;
						cout << setw(3) << arrayB[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);


				//d
					cout << "Матрица Д" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayD[i][j] = rand() % 61 - 30;
						cout << setw(3) << arrayD[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);

				//d * 1.8
					cout << "Матрица Д*1.8" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayD[i][j] *= 1.8;
						cout << setw(3) << arrayD[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);

				//c
					cout << "Матрица C" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayC[i][j] = (arrayA[i][j] - arrayB[i][j]) + arrayD[i][j];
						cout << setw(3) << arrayC[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);
				//таблица
				cout << endl << endl;
				SetColor(LightBlue, Black);
				for (short y = 10; y <= 16; y += 2)
				{
					for (short x = 70; x <= 100; x++)
					{
						GotoXY(x, y);
						cout << "-";
					}
				}

				for (short x = 70; x <= 100; x += 100 - 70)
				{
					for (short y = 10; y <= 16; y++)
					{
						GotoXY(x, y);
						cout << "|";
					}
				}
				SetColor(LightCyan, Black);

				GotoXY(71, 11); cout << "Повторить - 1	"; GotoXY(71, 13); cout << "Перейти в меню - 0";
				GotoXY(71, 15); cout << "Ввод:";
				cin >> isIn;
				system("cls");
			}
			
		}break;
		//Задание 2	<------------------------------------
		case 2:
		{
			system("cls");
			const short size_max = 12;
			short array[size_max][size_max] = {};
			short arrayAllSort[size_max][size_max] = {};
			short arrayRowSort[size_max][size_max] = {};
			short arrayColSort[size_max][size_max] = {};
			short arraySort[size_max * size_max] = {};
			short row, col, tmp, n = 0;
			while (isIn)
			{
				
				//Ввод
				do
				{
					cout << "Введите количество строк(от 1 до 10):";
					cin >> row;
					cout << "Введите количество колонок(от 3 до 10):";
					cin >> col;
					system("cls");
				} while (row < 1 or row > 10 or col < 3 or col > 10);

				cout << "Неотсортированный массив" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						array[i][j] = rand() % 61 - 30;
						cout << setw(3) << array[i][j] << "	";
					}
					cout << endl << endl;

				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);

				//перекладываение массива
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arraySort[n] = array[i][j];
						n++;
					}
				}
				//сортировка
				for (short i = 0; i < row * col; i++)
				{
					tmp = arraySort[i];
					for (short j = i - 1; j >= 0 && arraySort[j] > tmp; j--)
					{
						arraySort[j + 1] = arraySort[j];
						arraySort[j] = tmp;
					}
				}
				n = 0;
				
				//Отсортированный двумерный массив(полностью)
				cout << "Отсортированный двумерный массив" << endl;
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						arrayAllSort[i][j] = arraySort[n];
						n++;
						cout << arrayAllSort[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);


				n = 0;
				//--------
				//Отсортированный массив по строкам
				cout << "Отсортированный массив по строкам" << endl;
				for (short i = 0; i < row; i++)
				{
					//Очистка доп.массива
					for (short j = 0; j < row * col; j++)
					{
						arraySort[j] = 0;
					}
					//перекладываение массива
					for (short j = 0; j < col; j++)
					{
						arraySort[j] = array[i][j];
					}
					//sort
					for (short u = 0; u < col; u++)
					{
						tmp = arraySort[u];
						for (short j = u - 1; j >= 0 && arraySort[j] > tmp; j--)
						{
							arraySort[j + 1] = arraySort[j];
							arraySort[j] = tmp;
						}
					}
					//перекладывание
					for (short j = 0; j < col; j++)
					{
						arrayColSort[i][j] = arraySort[j];
						cout << arrayColSort[i][j] << "	";
					}
					cout << endl << endl;
				}
				SetColor(LightBlue, Black); cout << border << endl; SetColor(LightCyan, Black);


				//--------
				//Отсортированный массив по столбцам
				cout << "Отсортированный массив по столбцам" << endl;
				for (short i = 0; i < col; i++)
				{
					//Очистка доп.массива
					for (short j = 0; j < row * col; j++)
					{
						arraySort[j] = 0;
					}
					//перекладываение массива
					for (short j = 0; j < row; j++)
					{
						arraySort[j] = array[j][i];
					}
					//sort
					for (short u = 0; u < row; u++)
					{
						tmp = arraySort[u];
						for (short j = u - 1; j >= 0 && arraySort[j] > tmp; j--)
						{
							arraySort[j + 1] = arraySort[j];
							arraySort[j] = tmp;
						}
					}
					//перекладывание
					for (short j = 0; j < row; j++)
					{
						arrayRowSort[j][i] = arraySort[j];
					}
				}
				
				for (short i = 0; i < row; i++)
				{
					for (short j = 0; j < col; j++)
					{
						cout << arrayRowSort[i][j] << "	";
					}
					cout << endl << endl;
				}

				//Конец
				//таблица
				cout << endl << endl;
				SetColor(LightBlue, Black);
				for (short y = 10; y <= 16; y += 2)
				{
					for (short x = 70; x <= 100; x++)
					{
						GotoXY(x, y);
						cout << "-";
					}
				}

				for (short x = 70; x <= 100; x += 100 - 70)
				{
					for (short y = 10; y <= 16; y++)
					{
						GotoXY(x, y);
						cout << "|";
					}
				}
				SetColor(LightCyan, Black);

				GotoXY(71, 11); cout << "Повторить - 1	"; GotoXY(71, 13); cout << "Перейти в меню - 0";
				GotoXY(71, 15); cout << "Ввод:";
				cin >> isIn;
				system("cls");

			}
			
		}break;
		//все
		case 0:
		{
			isMainIn = false;
		}break;
		}


	}

	system("cls");
	GotoXY(40, 3);
	cout << "Программа остановлена пользователем"; Sleep(700); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << "." << endl;
	GotoXY(39, 4); system("pause");
}