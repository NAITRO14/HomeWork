#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	short k;
	//Начало
	while(true)
	{
		cout << "Введите номер задания, которое хотите проверить(1-4):";
		cin >> k;
		if (k < 1 or k > 4) { cout << "Задания нет в списке" << endl; continue; }
		switch(k)
			{
			//Задание 1
			case 1:
			{
				float y;
				short count = 1;
				cout << "Значения y для x[-2;2] с шагом в 0.5" << endl;
				for (float x = -2; x <= 2; x += 0.5)
				{
					y = -2.4 * x * x + 5 * x - 3; 

					cout << "x" << count<< "|" << y << endl;
					count++;
			
				}
			}break;
			//задание 2
			case 2:
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
						cout << "Остаток на " << count << " год:" << sum << endl;
						count++;
					}
					else
					{

						cout << "Деньги закончатся через " << count << " год" << endl;
					}

				}




			}break;
			case 3:
			{
				short f = 0;
				for (short x = -10; x <= 20; x++)
				{
					if (x % 5 == 0) { continue; }
					if (x % 2 == 0) { f = x * x - 13; if (f >= 300) { break; }}
					if (x % 3 == 0) { f = 3 * x + 10; }
					//if (f >= 300) { break; } //f редактор считает не инициализированной, но эта строчка и не нужна, ведь f не будет больше 300
					cout << f << endl;
				}



			}break;
			case 4:
			{
				char symbol;
				short len;
				string orien;
				cout << "Введите любой символ:";
				cin >> symbol;
				cout << "Введите длинну линии:";
				cin >> len;
				cout << "Укажите ориентацию линии(вертикальную - vert, горизональную - horiz):";
				cin >> orien;
				if (orien == "vert")
				{
					for (short i = 0; i < len; i++) { cout << symbol << endl; }
				}
				if (orien == "horiz")
				{
					short i = 0;
					for (; i <= len; i++) { cout << symbol; if (i == len) { cout << "" << endl; }}
					
				}
			}break;
			//switch
			}
		bool YesNo;
		cout << "Хотите продолжить?(Введите 1 - если да, 0 - если нет)" << endl;
		cout << "Ввод(1,0):";
		cin >> YesNo;
		if (YesNo == true) { system("cls"); }
		if (YesNo != true) { system("cls"); cout << "Вы вышли из программы" << endl; break; }
	}
	
}