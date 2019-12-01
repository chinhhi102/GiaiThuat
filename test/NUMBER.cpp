#include "NUMBER.h"
#include "console.h"
#include<iostream>
using namespace std;

NUMBER::NUMBER()
{

}

NUMBER::NUMBER(int num)
{
	Number = num;
	To_char();
}

void NUMBER::To_char()
{
	switch(Number)
	{
	case 0:
		{
			char _number[9][15]={
				"a111111111111c", 
				"21111111111112",  
				"2 2        2 2",  
				"2 2        2 2",   
				"2 2        2 2",
				"2 2        2 2",
				"2 2        2 2",
				"211111111112 2",
				"b111111111111d"};

			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}
	case 1:
		{
			char _number[9][15]={
				"   a1111c     ",   //a góc trên bên trái
				"   b111 2     ",   //b góc dưới bên trái
				"      2 2     ",   //c góc trên bên phải
				"      2 2     ",   //d góc dưới bên phải
				"      2 2     ",
				"      2 2     ",
				"      2 2     ",
				" a11112 11111c",
				" b11111111111d"};
			
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}
	case 2:
		{
			char _number[9][15]={
				"a111111111111c", 
				"21111111111c 2",  
				"           2 2",  
				"           2 2",   
				"a111111111111d",
				"2 2           ",
				"2 2           ",
				"2 b11111111112",
				"b111111111111d"};

			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}

	case 3:
		{
			char _number[9][15]={
				"a111111111111c", 
				"21111111111c 2",  
				"           2 2",  
				"           2 2",   
				"    1111111d d",
				"           2 2",
				"2 c        2 2",
				"2 b11111111112",
				"b111111111111d"};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}

	case 4:
		{
			char _number[9][15]={
				"a1c      a1c  ", 
				"2 2      2 2  ",  
				"2 2      2 2  ",  
				"2 2      d b  ",   
				"2 b1111111111 ",
				"b111111  c a  ",
				"         2 2  ",
				"         2 2  ",
				"         b1d  "};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}
	case 5:
		{
			char _number[9][15]={
				"a11111111111c ", 
				"2 a1111111c 2 ",  
				"2 2           ",  
				"2 b1111111111c",   
				"b1111111111c 2",
				"           2 2",
				"           2 2",
				"2 b11111111d 2",
				"b111111111111d"};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}

	case 6:
		{
			char _number[9][15]={
				"a11111111111c ", 
				"2 a1111111c 2 ",  
				"2 2           ",  
				"2 b1111111111c",   
				"2 1111111112 2",
				"2 2        2 2",
				"2 2        2 2",
				"2 211111111d 2",
				"b111111111111d"};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}
	case 7:
		{
			char _number[9][15]={
				" a11111111111c", 
				" 2 a1111111c 2",  
				" b1d     a1dad",  
				"       a1d ad ",   
				"    111111111 ",
				"      2 2     ",
				"     ad bc    ",
				"     2   2    ",
				"     b111d    "};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}
	case 8:
		{
			char _number[9][15]={
				"   a111111c   ", 
				"   2 a11c 2   ",  
				"  ad b11d bc  ",  
				"a1d11111111b1c",   
				"2 a11111111c 2",
				"2 2        2 2",
				"2 2        2 2",
				"2 b11111111d 2",
				"b111111111111d"};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}

	case 9:
		{
			char _number[9][15]={
				"a111111111111c", 
				"2 a11111111c 2",  
				"2 2        2 2",  
				"2 2        2 2",   
				"b11111111112 2",
				"           2 2",
				"           2 2",
				"2 111111111d 2",
				"b111111111111d"};
			for(int k = 0; k<9; k++)
				for(int j = 0; j<15; j++)
				{
					number[k][j] = _number[k][j];
				}
			break;
		}
	}
}

void NUMBER::Draw(int i, int j, int x,int  y, int color)
{
	int _x = x;
	for(int _i = 0; _i<i; _i++)
	{
		for(int _j = 0; _j < j; _j++)
		{
			TextColor(color);
			gotoXY(x, y);
			if(number[_i][_j] == '1') number[_i][_j] = 205;
			else if(number[_i][_j] == '2') number[_i][_j] = 186;
			else if(number[_i][_j] == 'a') number[_i][_j] = 201;
			else if(number[_i][_j] == 'b') number[_i][_j] = 200;
			else if(number[_i][_j] == 'c') number[_i][_j] = 187;
			else if(number[_i][_j] == 'd') number[_i][_j] = 188;
			
			
			putchar(number[_i][_j]);

			x++;
		}
		x = _x;
		y++;
	}
}
