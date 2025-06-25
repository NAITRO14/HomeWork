#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;

//подключения
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

void prepearing();

void task1();
void task2();
void task3();
void task4();
void task5();

int main()
{
	while (true)
	{
		prepearing();
		short manage;

		SetColor(LightCyan, Black);
		GotoXY(45, 6); cout << "Введите номер задания(1-5)" << endl;
		GotoXY(45, 8); cout << "Ввод:";
		cin >> manage;

		if (1 > manage or manage > 5) { SetColor(Red, Black); GotoXY(45, 8); cout << "Такаого задания нет"; Sleep(2000); system("cls"); continue; }

		//---------------------
		char rubbish[1];
		gets_s(rubbish, 1); // - действие чтобы очистить буфер от \n(без него функция ввобда пропускается)
		//---------------------

		switch (manage)
		{
		case 1: { task1(); }break;
		case 2: { task2(); }break;
		case 3: { task3(); }break;
		case 4: { task4(); }break;
		case 5: { task5(); }break;
		}
	}
	
	
}

void prepearing()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetColor(Blue, Black);
	for (short x = 44; x <= 77; x += (77 - 44))
	{
		for (short y = 5; y < 10; y++)
		{
			GotoXY(x, y);
			cout << "|";
		}
	}

	for (short y = 5; y <= 9; y += 2)
	{
		for (short x = 45; x < 77; x++)
		{
			GotoXY(x, y);
			cout << "-";
			continue;
		}
	}
}

void task1()
{
	//1
	system("cls");
	SetColor(LightCyan, Black);
	short n = 0;
	char string[26] = {};

	cout << "Введите строку(до 25 символов)" << endl;
	gets_s(string, 26);

	for (short i = 0; i < 26; i++)
	{
		if (string[i] == '\0') { break; }
		n++;
	}
	cout << "Символов занято:" << n << endl;
	cout << "Символов свободно:" << (25 - n) << endl;

	SetColor(Blue, Black);
	system("pause");
}

void task2()
{
	//2
	system("cls");
	SetColor(LightCyan, Black);
	short n = 0; // - всего символов в строке
	short start, end;
	char string[26] = {};

	cout << "Введите строку(до 25 символов)" << endl;
	gets_s(string, 26);
	for (short i = 0; i < 26; i++)
	{
		n++;
		if (string[i] == '\0') { break; }
	}

	while (true)
	{
		cout << "Введите начало диапозона: ";
		cin >> start;
		cout << "Введите конец диапозона:  ";
		cin >> end;
		if (start-1 < n and end-1 < n) { break; }
		else { cout << "Вы вышли за рамки строки" << endl; Sleep(2000); system("cls"); }
	}

	cout << "Итог: ";
	for (short i = start - 1; i <= end - 1; i++)
	{
		cout << string[i];
	}cout << endl;
	
	SetColor(Blue, Black);
	system("pause");
}

void task3()
{
	system("cls");
	SetColor(LightCyan, Black);
	short n = 0; // - всего символов в строке
	short start, end; // - вместо m и n start и end
	short m = 0;
	char string[26] = { 0 };

	cout << "Введите строку(до 25 символов)" << endl;
	gets_s(string, 26);
	for (short i = 0; i < 26; i++)
	{
		n++;
		if (string[i] == '\0') { break; }
	}

	while (true)
	{
		//сделать проверку! <------------------------------
		cout << "Введите начало диапозона: ";
		cin >> start;
		cout << "Введите конец диапозона:  ";
		cin >> end;
		if (start-1 < n and end-1 < n) { break; }
		else { cout << "Вы вышли за рамки строки" << endl; Sleep(2000); system("cls"); }
	}
	char* nString = new char[n - (end - start)];
	start -= 1;
	end -= 1;

	for (short i = 0; i < start; i++)
	{
		nString[m] = string[i];
		m++;
	}

	for (short i = end+1; i < n; i++)
	{
		nString[m] = string[i];
		m++;
	}

	cout << "Итог: ";
	for (short i = 0; i < m; i++)
	{
		cout << nString[i];
	}cout << endl;

	SetColor(Blue, Black);
	system("pause");
}

void task4()
{
	system("cls");
	SetColor(LightCyan, Black);
	short n = 0; // - всего символов в строке
	char symb;
	char string[26] = {};
	bool any = false; // - для проверки если ли совпадения

	cout << "Введите строку(до 25 символов)" << endl;
	gets_s(string, 26);
	for (short i = 0; i < 26; i++)
	{
		n++;
		if (string[i] == '\0') { break; }
	}

	cout << "Ввдите символ для поиска: ";
	cin >> symb;

	cout << "Совпадения: ";
	for (short i = 0; i < n; i++)
	{
		if (string[i] == symb) { cout << i + 1 << " "; any = true; }
	}

	if (any == false) { cout << "Совпадений не обнаружено" << endl; }

	SetColor(Blue, Black);
	system("pause");
}

void task5()
{
	system("cls");
	SetColor(LightCyan, Black);
	short n = 0; // - всего символов в строке
	short num;
	char symb;
	char string[26] = {};
	bool any = false; // - для проверки если ли совпадения

	cout << "Введите строку(до 25 символов)" << endl;
	gets_s(string, 26);
	for (short i = 0; i < 26; i++)
	{
		n++;
		if (string[i] == '\0') { break; }
	}

	cout << "Ввдите символ для поиска: ";
	cin >> symb;

	cout << "Последее совпадение: ";
	for (short i = 0; i < n; i++)
	{
		if (string[i] == symb) { num = i + 1; any = true; }
	}

	if (any == true) { cout << num ;cout << endl; }
	else { cout << "Совпадений не обнаружено" << endl; }

	SetColor(Blue, Black);
	system("pause");
}
