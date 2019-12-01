#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include"console.h"
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include"NUMBER.h"
#include"FIREWORK.h"
#include"LETTER.h"
using namespace std;

const int X = 35;
const int Y = 8;

void Count_down()
{
	srand(time(NULL));
	int color;
	NUMBER _1(1), _2(2), _3(3), _4(4), _5(5), _6(6), _7(7), _8(8), _9(9);
	color = 9 + rand() % (16-9);
	//_1.Draw(9, 15, X, Y, color);
	//_0.Draw(9, 15, X+22, Y, color);
	//Sleep(1100);
	//clrscr();

	color = 9 + rand() % (16-9);
	_9.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_8.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_7.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_6.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_5.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();
	
	color = 9 + rand() % (16-9);
	_4.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_3.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_2.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();

	color = 9 + rand() % (16-9);
	_1.Draw(9, 15, X+15, Y, color);
	Sleep(1100);
	clrscr();
}

void Happy(int color)
{
	LETTER h('h'), a('a'), p('p'), y('y');

	h.Draw(X-21, Y - 5, color);
	a.Draw(X-6, Y - 5, color);
	p.Draw(X+10, Y - 5, color);
	p.Draw(X+26, Y - 5, color);
	y.Draw(X+41, Y - 5, color);

	
}

void New(int color)
{
	LETTER n('n'), e('e'), w('w'), r('r');

	n.Draw(X-32, Y+7, color);
	e.Draw(X-16, Y+7, color);
	w.Draw(X, Y+7, color);
}

void Year(int color)
{
	LETTER y('y'), e('e'), a('a'), r('r');

	y.Draw(X+18, Y+7, color);
	e.Draw(X+34, Y+7, color);
	a.Draw(X+50, Y+7, color);
	r.Draw(X+66, Y+7, color);
}

void Nam_moi_thanh_cong(int color)
{
	LETTER k('k',1), v('v', 1), u('u',1), s('s',1), y('y',1), n('n',1), m('m',1), a('a',1), c('c',1), g('g',1), h('h',1), w('w',1), O('O',1), z('z',1);
	LETTER i('i',1) , t('t',1), f('f',1), o('o',1), q('q',1);

	n.draw_uni(X-25, Y-7, color);
	a.draw_uni(X-22, Y-7, color);
	w.draw_uni(X-22, Y-9, color);
	m.draw_uni(X-19, Y-7, color);

	m.draw_uni(X-14, Y-7, color);
	O.draw_uni(X-11, Y-7, color);
	z.draw_uni(X-11, Y-9, color);
	i.draw_uni(X-7, Y-7, color);

	t.draw_uni(X-2, Y-7,color);
	h.draw_uni(X+1, Y-7, color);
	a.draw_uni(X+4, Y-7, color);
	f.draw_uni(X+4, Y-9, color);
	n.draw_uni(X+7, Y-7, color);
	h.draw_uni(X+10, Y-7, color);

	c.draw_uni(X+15, Y-7, color);
	o.draw_uni(X+18, Y-7, color);
	q.draw_uni(X+18, Y-9, color);
	n.draw_uni(X+21, Y-7, color);
	g.draw_uni(X+24, Y-6, color);

}

void An_khang_thinh_vuong(int color)
{
	LETTER k('k',1), v('v', 1), u('u',1), s('s',1), y('y',1), n('n',1), m('m',1), a('a',1), c('c',1), g('g',1), h('h',1), w('w',1), O('O',1), z('z',1);
	LETTER i('i',1) , t('t',1), f('f',1), o('o',1), q('q',1), j('j',1);

	a.draw_uni(X-25, Y, color);
	n.draw_uni(X-22, Y, color);

	k.draw_uni(X-17, Y,color);
	h.draw_uni(X-14, Y, color);
	a.draw_uni(X-11, Y, color);
	n.draw_uni(X-8, Y, color);
	g.draw_uni(X-5, Y+1, color);

	t.draw_uni(X, Y,color);
	h.draw_uni(X+3, Y, color);
	j.draw_uni(X+6, Y+2, color);
	i.draw_uni(X+6, Y, color);
	n.draw_uni(X+9, Y, color);
	h.draw_uni(X+12, Y, color);

	v.draw_uni(X+17, Y,color);
	u.draw_uni(X+20, Y, color);
	j.draw_uni(X+24, Y+2, color);
	O.draw_uni(X+24, Y, color);
	n.draw_uni(X+28, Y, color);
	g.draw_uni(X+32, Y+1, color);
}

void Van_su_nhu_y(int color)
{
	LETTER k('k',1), v('v', 1), u('u',1), s('s',1), y('y',1), n('n',1), m('m',1), a('a',1), c('c',1), g('g',1), h('h',1), w('w',1), O('O',1), z('z',1);
	LETTER i('i',1) , t('t',1), f('f',1), o('o',1), q('q',1), j('j',1);

	v.draw_uni(X-25, Y+7,color);
	j.draw_uni(X-22, Y+9,color);
	a.draw_uni(X-22, Y+7, color);
	n.draw_uni(X-19, Y+7, color);

	s.draw_uni(X-13, Y+7,color);
	j.draw_uni(X-10, Y+9,color);
	u.draw_uni(X-10, Y+7,color);

	n.draw_uni(X-5, Y+7,color);
	h.draw_uni(X-2, Y+7,color);
	u.draw_uni(X+1, Y+7,color);

	y.draw_uni(X+8, Y+8,color);
	z.draw_uni(X+8, Y+5,color);
}

void Name(int color)
{
	LETTER c('c',1), v('v',1), O('O',1), D('D',1), g('g',1), o('o',1), a('a',1),f('f',1), n('n',1), t('t',1), h('h',1), u('u',1), z('z',1),j('j',1), i('i',1),b('b',1), q('q',1), e('e',1), x('x',1), d('d',1), m('m',1), y('y',1), L('L',1), r('r',1);
	g.draw_uni(X-25, Y-6,color);
	u.draw_uni(X-22, Y-7,color);
	z.draw_uni(X-22, Y-9,color);
	i.draw_uni(X-19, Y-7,color);
	
	t.draw_uni(X-16, Y,color);
	h.draw_uni(X-13, Y,color);
	z.draw_uni(X-10, Y,color);
	a.draw_uni(X-10,  Y,color);
	o.draw_uni(X-7,  Y+1,color);
//	n.draw_uni(X-4,  Y+1,color);
//	
//	t.draw_uni(X-7, Y+7,color);
//	r.draw_uni(X-5, Y+7,color);
//	O.draw_uni(X-2, Y+7,color);
//	f.draw_uni(X-2, Y+5,color);
//	n.draw_uni(X+1, Y+7,color);
//	n.draw_uni(X+5, Y+7,color);
//	g.draw_uni(X+8, Y+8,color);
}
void Tiep_tuc(int color)
{
	LETTER c('c',1), v('v',1), k('k',1), p('p',1), s('s',1), O('O',1), D('D',1), g('g',1), o('o',1), a('a',1),f('f',1), n('n',1), t('t',1), h('h',1), u('u',1), z('z',1),j('j',1), i('i',1),b('b',1), q('q',1), e('e',1), x('x',1), d('d',1), m('m',1), y('y',1), L('L',1), r('r',1);
	t.draw_uni(X-25, Y-5,color);
	i.draw_uni(X-22, Y-5,color);
	e.draw_uni(X-19, Y-4,color);
	q.draw_uni(X-19, Y-7,color);
	p.draw_uni(X-16, Y-3,color);
		
	t.draw_uni(X-10, Y-5,color);
	j.draw_uni(X-7,  Y-3,color);
	u.draw_uni(X-7,  Y-5,color);
	c.draw_uni(X-4,  Y-5,color);
	
	c.draw_uni(X+2,  Y-5,color);
	r.draw_uni(X+5,  Y-5,color);
	u.draw_uni(X+8,  Y-5,color);
	s.draw_uni(X+11, Y-4,color);
	h.draw_uni(X+14, Y-5,color);
	
	c.draw_uni(X-25, Y+3,color);
	h.draw_uni(X-22, Y+3,color);
	i.draw_uni(X-19, Y+3,color);
	z.draw_uni(X-19, Y+1,color);
	n.draw_uni(X-16, Y+3,color);
	h.draw_uni(X-13, Y+3,color);
	
	D.draw_uni(X-7,  Y+3,color);
	i.draw_uni(X-4,  Y+3,color);
	
	k.draw_uni(X+2, Y+3,color);
	k.draw_uni(X+5, Y+3,color);
	k.draw_uni(X+8, Y+3,color);
}
void Firework()
{
	int color;
	char firework[19][42] = {                     //[14][]
		"            d  d  d    d                 ",
		"        d  d dd   d d d  d   dd          ",
		"   d d  d d d d d  c  dd  d d d d  d     ",
		" d  d  d d  d cdcdccddccc c d d  d  d    ",
		"d  d dd d  cdc ccdcdcdc c c cc d   d d   ",  //.  a  b  c  d
		" d d dd d cdccdcbd bd b dd c cc  d d  d  ",
		"d  d dd  cdcdcbdbabadbadbd cdcdc d d d   ",
		" d d d  ccc dbcbaccac.db b d c dc d d   d",
		"   d ddcdcdcb b.cca..adcdcb dd c  d d  d ",
		" d  d d cdc d bcb d|a dcdb c dc c  d d  d",
		" d d  d  cdcdb bcdc|  cbcbdd cdc  d  d   ",
		"  d d d ccdc dbdb c| bbd cdcdc d d  d d  ",
		" d d  d  cdcdcdc db|b d c cdc d  d d     ",
		"  d d d d c dcdccd |c dccdc    dd  d  d  ",
		"   d  d d d  dcd c |c c c d  d d  d d    ",
		"     d  d d d  d  d| d     d d  d        ",
		"        d     d  d |d  d   d  d          ",
		"          d d  d   |  d  d d             ",
		"                d  | d  d                "};
	
		srand(time(NULL));
		
	char love[21][42] = {                     //[14][]
		"     cccccaa                  ccaaaa     ",
		"    cc33333aa                cc3333aa    ",
		"   cc3333333aa              cc333333aa   ",
		"  cc333333333aa            cc33333333aa  ",
		" cc33333333333aa          cc3333333333aa ",  //.  a  b  c  d
		"cc3333333333333aa        cc333333333333aa",
		"cc33333333333333aa      cc3333333333333aa",
		"cc3333333333333333aa  cc333333333333333aa",
		"cc33333333333333333aacc3333333333333333aa",
		"  cc333333333333333333333333333333333aa  ",
		"   cc3333333333333333333333333333333aa   ",
		"    cc3333333333333333333333333333aa     ",
		"     cc3333333333333333333333333aa       ",
		"       cc333333333333333333333aa         ",
		"         cc33333333333333333aa           ",
		"           cc3333333333333aa             ",
		"             cc333333333aa               ",
		"               cc33333aa                 ",
		"                 cc3aa                   ",
		"                   3                     "};

		int color_h = 14;
		int color_n = 11;
		int color_y = 13;

		int count = 0;
		for(int i = 0; i<=6; i++)
		{
			int vitri = rand() % (70);
			Draw(firework, vitri);
			DrawLove(love, vitri);
			switch(count)
			{
			case 0:
				{	
					Happy(0);
					Sleep(80);
					Happy(color_h-8);
					Sleep(80);
					Happy(color_h);
					Sleep(300);
					Happy(color_h-8);
					Sleep(80);
					Happy(0);
					count++;
					break;
				}
			case 1:
				{	
					New(0);
					Sleep(80);
					New(color_n-8);
					Sleep(80);
					New(color_n);
					Sleep(300);
					New(color_n-8);
					Sleep(80);
					New(0);
					count++;
					break;
				}
			case 2:
				{
					Year(0);
					Sleep(80);
					Year(color_y-8);
					Sleep(80);
					Year(color_y);
					Sleep(300);
					Year(color_y-8);
					Sleep(80);
					Year(0);
					count++;
					break;
				}
			case 3:
				{
					Happy(0); New(0); Year(0);
					Sleep(100);
					Happy(color_h-8); New(color_n-8); Year(color_y-8);
					Sleep(100);
					Happy(color_h); New(color_n); Year(color_y);
					Sleep(2000);
					Happy(color_h-8); New(color_n-8); Year(color_y-8);
					Sleep(100);
					Happy(0); New(0); Year(0);
					Sleep(100);
					count++;
					break;
				}
			case 4:
				{
					NUMBER _2(2), _0(0), _1(1), _8(8);
					_2.Draw(9, 15, X+5, Y, 0);
					_0.Draw(9, 15, X+21, Y, 0);
					_1.Draw(9, 15, X+37, Y, 0);
					_8.Draw(9, 15, X+53, Y, 0);

					Sleep(100);

					_2.Draw(9, 15, X+5, Y, 6);
					_0.Draw(9, 15, X+21, Y, 6);
					_1.Draw(9, 15, X+37, Y, 6);
					_8.Draw(9, 15, X+53, Y, 6);

					Sleep(100);

					_2.Draw(9, 15, X+5, Y, 14);
					_0.Draw(9, 15, X+21, Y, 14);
					_1.Draw(9, 15, X+37, Y, 14);
					_8.Draw(9, 15, X+53, Y, 14);

					Sleep(200);

					for(int k = 0; k<=40; k++)
					{
						color = 9 +rand() % (16-9);
						_2.Draw(9, 15, X+5, Y, color);
						color = 9 +rand() % (16-9);
						_0.Draw(9, 15, X+21, Y, color);
						color = 9 +rand() % (16-9);
						_1.Draw(9, 15, X+37, Y, color);
						color = 9 +rand() % (16-9);
						_8.Draw(9, 15, X+53, Y, color);
						Sleep(50);
					}
					
					_2.Draw(9, 15, X+5, Y, 14);
					_0.Draw(9, 15, X+21, Y, 14);
					_1.Draw(9, 15, X+37, Y, 14);
					_8.Draw(9, 15, X+53, Y, 14);

					Sleep(100);

					_2.Draw(9, 15, X+5, Y, 6);
					_0.Draw(9, 15, X+21, Y, 6);
					_1.Draw(9, 15, X+37, Y, 6);
					_8.Draw(9, 15, X+53, Y, 6);

					Sleep(100);

					_2.Draw(9, 15, X+5, Y, 0);
					_0.Draw(9, 15, X+21, Y, 0);
					_1.Draw(9, 15, X+37, Y, 0);
					_8.Draw(9, 15, X+53, Y, 0);

					Sleep(100);

					count++;
					break;
				}
			case 5:
				{
					Name(0);
					Sleep(100);
					Name(6);
					Sleep(200);
					Name(10);
					Sleep(3000);
					clrscr();
					
					Nam_moi_thanh_cong(0);
					Sleep(100);
					Nam_moi_thanh_cong(3);
					Sleep(200);
					Nam_moi_thanh_cong(11);
					Sleep(2000);
					

					An_khang_thinh_vuong(0);
					Sleep(100);
					An_khang_thinh_vuong(6);
					Sleep(200);
					An_khang_thinh_vuong(14);
					Sleep(2000);

					Van_su_nhu_y(0);
					Sleep(100);
					Van_su_nhu_y(5);
					Sleep(200);
					Van_su_nhu_y(13);
					Sleep(2000);

					Nam_moi_thanh_cong(3);
					Sleep(200);
					Nam_moi_thanh_cong(0);
					
					An_khang_thinh_vuong(6);
					Sleep(200);
					An_khang_thinh_vuong(0);

					Van_su_nhu_y(5);
					Sleep(200);
					Van_su_nhu_y(0);
					Sleep(2000);
					
//					Tiep_tuc(1);
//					Sleep(200);
//					Tiep_tuc(2);
//					Sleep(200);
//					Tiep_tuc(3);
//					Sleep(200);
//					Tiep_tuc(4);
//					Sleep(200);
//					Tiep_tuc(5);
//					Sleep(200);
//					Tiep_tuc(6);
//					Sleep(200);
//					Tiep_tuc(7);
//					Sleep(200);
//					Tiep_tuc(8);
//					Sleep(200);
//					Tiep_tuc(9);
//					Sleep(200);
//					Tiep_tuc(10);
//					Sleep(2000);
					count++;
					break;
				}
			case 6:
				{
					gotoXY(X, Y);
					TextColor(0);
					cout<<"Created by: Doan Cong Chinh";
					Sleep(200);

					gotoXY(X, Y);
					TextColor(7);
					cout<<"Created by: Doan Cong Chinh";
					Sleep(400);

					gotoXY(X, Y);
					TextColor(15);
					cout<<"Created by: Doan Cong Chinh";
					Sleep(3000);

					gotoXY(X, Y);
					TextColor(7);
					cout<<"Created by: Doan Cong Chinh";
					Sleep(200);

					gotoXY(X, Y);
					TextColor(0);
					cout<<"Created by: Doan Cong Chinh";
					Sleep(100);
				}
			}
		}
}


int main()
{
	Count_down();
	Firework();
	return 0;
}
