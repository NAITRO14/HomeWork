//“аблица выбора(вертикальные линии)
for (short x = 59; x <= 92; x += (92 - 59))
{
	for (short y = 5; y < 10; y++)
	{
		GotoXY(x, y);
		cout << "|";
	}
}

//“аблица выбора(горизонтальные линии)
for (short y = 5; y <= 9; y += 2)
{
	for (short x = 60; x < 92; x++)
	{
		GotoXY(x, y);
		cout << "-";
		continue;
	}
}