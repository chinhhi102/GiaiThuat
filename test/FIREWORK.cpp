#include"FIREWORK.h"
#include"console.h"
#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

void DrawLove(char firework[][42], int td)
{
	int mau = 9;
	int Case = 0;
	int count = 0;
	int x, y;
	srand(time(NULL));
	{
		mau = 12;
		clrscr();
		for(int i = 0; i<21; i++)
		{
			y = i;
			for(int j = 0; j<42; j++)
			{
				x = j + td;
				gotoXY(x, y);
				if(firework[i][j] == '3')
				{
					TextColor(mau);
					cout<<(char)219;
				}
				if(firework[i][j] == 'a')
				{
					TextColor(mau);
					cout<<(char)201;
				}
				if(firework[i][j] == 'c')
				{
					TextColor(mau);
					cout<<(char)187;
				}	
			}
		}
		Sleep(500);
	}
	clrscr();
}
void Draw(char firework[][42], int td)
{
	int mau = 9;
	int Case = 0;
	int count = 0;
	int x, y;
	srand(time(NULL));
	while(count < 6)
	{
		switch(Case)
		{
		case 0:
			{
				clrscr();
				int dem = 0;
				for(int i = 19; dem<10; dem++)
				{
					clrscr();
					y = i;
					gotoXY(20+td, y);
					TextColor(15);
					putchar(186);
					Sleep(100);
					i--;
				}
				Case++;
				break;
			}
		case 1:
			{
				gotoXY(20+td, 9);
				mau = 9 + rand() % (16 - 9);
				TextColor(mau);
				cout<<firework[9][19];
				Sleep(100);
				Case++;
				break;
			}

		case 2:
			{
				clrscr();
				mau = 9 + rand() % (16 - 9);
				for(int i = 0; i<18; i++)
				{
					y = i;
					for(int j = 0; j<42; j++)
					{
						x = j + td;
						gotoXY(x, y);
						if(firework[i][j] == 'a')
						{
							TextColor(mau);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'a';
									
						}
					}
							
				}
				Case++;
				Sleep(100);
				break;
			}
		case 3:
			{
				mau = 9 + rand() % (16 - 9);
				clrscr();
				for(int i = 0; i<18; i++)
				{
					y = i;
					for(int j = 0; j<42; j++)
					{
						x = j + td;
						gotoXY(x, y);
						if(firework[i][j] == 'b')
						{
							TextColor(mau);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'b';
						}
					}
				}
				Case ++;
				Sleep(150);
				break;
			}
		case 4:
			{
				clrscr();
				for(int i = 0; i<18; i++)
				{
					mau = 9 + rand() % (16 - 9);
					int Mau = 9 + rand() % (16 - 9);
					y = i;
					for(int j = 0; j<42; j++)
					{
						x = j + td;
						gotoXY(x, y);
						if(firework[i][j] == 'c')
						{
							TextColor(mau);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'c';
						}
						else if(firework[i][j] == 'b')
						{
							TextColor(Mau);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'b';
						}
					}
				}
				Case++;
				Sleep(150);
				break;
			}
		case 5:
			{
				mau = 9 + rand() % (16 - 9);
				int mau1 = 9 + rand() % (16 - 9);
				int mau2 = 9 + rand() % (16 - 9);
				if(mau2 >15) mau2 = 10;
				clrscr();
				for(int i = 0; i<18; i++)
				{
					y = i;
					for(int j = 0; j<42; j++)
					{
						x = j + td;
						gotoXY(x, y);
						if(firework[i][j] == 'd')
						{
							TextColor(mau);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'd';
						}
						else if(firework[i][j] == 'b')
						{
							TextColor(mau1);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'b';
						}
						else if(firework[i][j] == 'c')
						{
							TextColor(mau2);
							firework[i][j] = '.';
							cout<<firework[i][j];
							firework[i][j] = 'c';
						}
					}
				}
				Case = 0;
				Sleep(200);
				break;
			}
		}
		count++;
	}
	clrscr();
}
