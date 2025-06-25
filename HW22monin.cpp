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
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

template <typename T1> void sum(T1 &a, T1 &b);
template <typename T1> void mul(T1& a, T1& b);
template <typename T1> void sub(T1& a, T1& b);
template <typename T1> void divi(T1& a, T1& b);

//с передачей ссылки
//template <typename T1> void sum(T1* a, T1& b);
//template <typename T1> void mul(T1* a, T1& b);
//template <typename T1> void sub(T1* a, T1& b);
//template <typename T1> void divi(T1* a, T1& b);




int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));
	short x, var;
	bool control, isInMain, YesNo;

	while (true)
	{
		SetColor(LightBlue, Black);
		//horizontal
		for (short y = 4; y <= 10; y+= 2)
		{
			for (short x = 40; x < 85; x++)
			{
				GotoXY(x, y); cout << "-";
				if (y == 10 and x == 55) { break; }
			}
		}
		//vertical
		for (short i = 0; i < 4; i ++)
		{
			if (i == 0) { x = 40; }
			if (i == 1) { x = 55; }
			if (i == 2) { x = 70; }
			if (i == 3) { x = 85; }

			control = true;

			for (short y = 4; y <= 10; y ++)
			{
				if (y == 9 and (i == 2 or i == 3)) { break; }

				while (control)
				{
					if (i == 1) { y = 6; }
					if (i == 2) { y = 6; }
					control = false;
				}

				GotoXY(x, y); cout << "|";
				
				
			}
		}
		SetColor(LightCyan, Black);
		GotoXY(41, 5); cout << "С какими переменными будем работать ?" << endl;
		GotoXY(41, 7); cout << "1|short"; GotoXY(56, 7); cout << "2|float"; GotoXY(71, 7); cout << "3|char";
		GotoXY(41, 9); cout << "Ввод:";
		SetColor(Yellow, Black);
		cin >> var;
		if (var == 0) { break; }
		

		system("cls");
		switch (var)
		{
		case 1:
		{
			short a, b;
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;


			SetColor(LightCyan, Black); cout << "Переменная а: "; SetColor(Yellow, Black); cout << a; SetColor(LightCyan, Black); cout << endl << "Переменная b: "; SetColor(Yellow, Black); cout << b << endl << endl;
			sum(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a + b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			mul(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a * b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			sub(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a - b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			divi(a, b); //вещественная часть отброшена
			SetColor(LightCyan, Black);
			cout << "|a = a / b|:"; SetColor(Yellow, Black); cout << "~" << a << endl;
		}break;
		case 2:
		{
			float a, b;
			a = (rand() % 10) + ((rand() % 11) / 10.0);
			b = (rand() % 10) + ((rand() % 11) / 10.0);


			SetColor(LightCyan, Black); cout << "Переменная а: "; SetColor(Yellow, Black); cout << a; SetColor(LightCyan, Black); cout << endl << "Переменная b: "; SetColor(Yellow, Black); cout << b << endl << endl;
			sum(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a + b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			mul(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a * b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			sub(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a - b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			divi(a, b); //вещественная часть отброшена
			SetColor(LightCyan, Black);
			cout << "|a = a / b|: "; SetColor(Yellow, Black); cout << a << endl;
		}break;
		case 3:
		{
			char a, b;
			a = rand() % 26 + 63;
			b = rand() % 26 + 63;

			SetColor(LightCyan, Black); cout << "Переменная а: "; SetColor(Yellow, Black); cout << a; SetColor(LightCyan, Black); cout << endl << "Переменная b: "; SetColor(Yellow, Black); cout << b << endl << endl;
			sum(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a + b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			mul(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a * b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			sub(a, b);
			SetColor(LightCyan, Black);
			cout << "|a = a - b|: "; SetColor(Yellow, Black); cout << a << endl << endl;
			divi(a, b); //вещественная часть отброшена
			SetColor(LightCyan, Black);
			cout << "|a = a / b|:"; SetColor(Yellow, Black); cout << a << endl;
		}break;

		//switch end
		}
		
		SetColor(LightBlue, Black);
		for (short y = 4; y <= 10; y += 2)
		{
			for (short x = 55; x <= 87; x++)
			{
				GotoXY(x, y);
				cout << "-";
			}
		}

		for (short x = 55; x <= 87; x += 87 - 55)
		{
			for (short y = 4; y <= 10; y++)
			{
				GotoXY(x, y);
				cout << "|";
			}
		}
		SetColor(LightCyan, Black); GotoXY(56, 9); cout << "Продолжить - (1)" << endl;
		GotoXY(56, 7); cout << "Закончить - (0)";
		GotoXY(56, 5); cout << "Ввод(1,0):";

		cin >> YesNo;
		if (YesNo == true) { system("cls"); isInMain = true; }
		else { break; }
	}
	SetColor(LightRed, Black);
	system("cls");
	cout << "Вы вышли из программы" << endl;
	system("pause");
}

template<typename T1>
void sum(T1 &a, T1 &b)
{
	a += b;
}

template<typename T1>
void mul(T1& a, T1& b)
{
	a *= b;
}

template<typename T1>
void sub(T1& a, T1& b)
{
	a -= b;
}

template<typename T1>
void divi(T1& a, T1& b)
{
	a /= b;
}

//с передачей ссылки
//Если использовать этот метод, то при вызове функции нужно передовать в нее ссылку на переменную --> sum(&a, &b)
//И затем работать с объектом по ссылке --> {*a /= *b}

//template<typename T1>
//void sum(T1* a, T1* b)
//{
//	*a += *b;
//}
//
//template<typename T1>
//void mul(T1* a, T1* b)
//{
//	*a *= *b;
//}
//
//template<typename T1>
//void sub(T1* a, T1* b)
//{
//	*a -= *b;
//}
//
//template<typename T1>
//void divi(T1* a, T1* b)
//{
//	*a /= *b;
//}
