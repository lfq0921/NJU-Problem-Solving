#include <conio.h>
#include <iostream>
using namespace std;

void deal_with_input()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		cout << ch;//此处仅打印，你需要根据摁键的不同作出不同的处理 
	}
}

void display()
{
	system("cls");//clear the screen
	//打印显示的信息 
 } 
int count = 0;
int main()
{
	init();
	display();
	while(1)
	{
		deal_with_input();
		count = count + 1;
		if (count == ONE_SECOND)
		{
			deal_with_timer();
			count = 0;
		}
	}
	return 0;
 }
