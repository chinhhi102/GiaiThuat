#pragma once
class LETTER
{
private:
	char c;
	char letter[9][15];
	char letter_uni[4][4];
public:
	LETTER();
	LETTER(char);
	LETTER(char, int);
	void To_Big_char();
	void To_unikey();
	void Draw(int X,int  Y, int color);
	void draw_uni(int X, int Y, int color);
};

