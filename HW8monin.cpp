#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	short k;
	//������
	while(true)
	{
		cout << "������� ����� �������, ������� ������ ���������(1-4):";
		cin >> k;
		if (k < 1 or k > 4) { cout << "������� ��� � ������" << endl; continue; }
		switch(k)
			{
			//������� 1
			case 1:
			{
				float y;
				short count = 1;
				cout << "�������� y ��� x[-2;2] � ����� � 0.5" << endl;
				for (float x = -2; x <= 2; x += 0.5)
				{
					y = -2.4 * x * x + 5 * x - 3; 

					cout << "x" << count<< "|" << y << endl;
					count++;
			
				}
			}break;
			//������� 2
			case 2:
			{
				//� ������ ����, ��� ������� ����������� ��������, � ����� ������� ������ 
				float sum = 1000000;
				short sub = 100000; 
				short count = 1;
				while (sum > 0)
				{
					sum = sum + (sum * 0.08); 
					if ((sum -= 100000) > 0)
					{
						cout << "������� �� " << count << " ���:" << sum << endl;
						count++;
					}
					else
					{

						cout << "������ ���������� ����� " << count << " ���" << endl;
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
					//if (f >= 300) { break; } //f �������� ������� �� ������������������, �� ��� ������� � �� �����, ���� f �� ����� ������ 300
					cout << f << endl;
				}



			}break;
			case 4:
			{
				char symbol;
				short len;
				string orien;
				cout << "������� ����� ������:";
				cin >> symbol;
				cout << "������� ������ �����:";
				cin >> len;
				cout << "������� ���������� �����(������������ - vert, ������������� - horiz):";
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
		cout << "������ ����������?(������� 1 - ���� ��, 0 - ���� ���)" << endl;
		cout << "����(1,0):";
		cin >> YesNo;
		if (YesNo == true) { system("cls"); }
		if (YesNo != true) { system("cls"); cout << "�� ����� �� ���������" << endl; break; }
	}
	
}