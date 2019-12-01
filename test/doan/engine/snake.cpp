/*  SUBMARINE GAME PROGRAM */




/*************************************************

Application: Submarine Game
Compiled on: DevC++
Programmer : Doan Cong Chinh, Huynh Vu Bao Nhan, Do Tan Dat
OS         : Window 98,2000,XP
             Vista,Windows7

***************************************************/




/* Declaration of Header Files */

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "dos.h"
#include "time.h"
#include "windows.h"
#include "string.h"

#define up 0
#define down 1
#define left 2
#define right 3


/* Global Declaration */

int x[100], y[100], i, length = 6,dem(0), score = 0, l_k = up , eat = 0, xf[100]={}, yf[100]={},gt,skip(500),fskip(0),lv(0),xw[100],yw[100],raw[10]={ },m(1),wall(0);
char ch;
bool flag=0;
/* Declaration of Functions */

void Food(void);
void Food1(void);
void Food2(void);
void rectangle(int x, int y, int l, int b);
void fillcolor(int x1, int y1, int x2, int y2);
void rectangle1(int x, int y, int l, int b);
void rectangle2(void);
void Level1(void);
void Level2(void);
void Level3(void);
void Level4(void);
void Instruction(void);
void Start(void);
void sub(int x,int y);
void deleteSub(int x,int y);
void gotoxy(int x, int y);
int Wall();
void creatWall(int x,int y);
void deleteWall(int x,int y);
COORD coord = { 0, 0 };

main(void)
{
	system("cls");
	Start();
	Instruction();
	while (1){
		Level1();
		i = 0, length = 6, score = 0, l_k = up , eat = 0,gt=0,skip=500,fskip=0,lv=0,m=0,wall=0,dem=0;
		for(int p = 0; p < 100; p++){
			x[p]=0;
			y[p]=0;
			xw[p]=0;
			yw[p]=0;
			xf[p]=59;
			yf[p]=0;
		}
	}
	
	_getch();
	//return 0;
}

/* Level 1 */

void Level1(void)
{
	system("cls");
	rectangle2();
	/* Positioning the snake initally */

		x[0] = 9;
		x[1] = 9;
		y[0] = 7;
		y[1] = 7;

	/*************************************/
    START:
	
	//system("cls");
	

	/*********************************/



	while (1)  /* Infinite Loop    */
	{
	//system("cls");
	sub(x[0],y[0]);
	gotoxy(65, 3);
	printf("%c",219);
	rectangle1(1, 1, 60, 24);
	rectangle1(63, 13, 78, 18);
	rectangle1(63, 1, 78, 6);
	rectangle1(63, 7, 78, 12);
	rectangle1(63, 19, 78, 24);
	
	
	gotoxy(66, 3);
	printf("%cSUBMARINE%c",15,15);
	gotoxy(67, 8);
	printf(" LEVEL ");
	gotoxy(70, 10);
	printf("1");
	gotoxy(67, 14);
	printf(" SCORE ");
	gotoxy(67, 21);
	printf(" GAMING ");
	gotoxy(65, 3);
		
		while (_kbhit() == 0) /* Do Nothing */
		{
			gotoxy(69, 16);
			printf("%d", score);
			
			/* Submarine Structure */
			gotoxy(x[1], y[1]);
			deleteSub(x[1],y[1]);
			gotoxy(x[0], y[0]);
			sub(x[0],y[0]);
			
			if (l_k == up && flag){
				flag = 0;
				y[1]--;
			}
			if (l_k == down && flag){
				flag = 0;
				y[1]++;
			}
			if (l_k == right && flag){
				flag = 0;
				x[1]++;
			}
			if (l_k == left && flag){
				flag = 0;
				x[1]--;
			}
			
			
			Food();
			int ha = Wall();
			/****************************/
			rectangle1(1, 1, 60, 24);
			gotoxy(65, 3);
			if(y[0]+1 > 22 || ha == 1){     /*hit floor*/
			Sleep(1000);
			gotoxy(65, 21);
			printf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			return;
			exit(0);
		}
		}
		ch = _getch();
		if (ch == 32)
		{
			
			gotoxy(65, 21);
			printf("%c PAUSED... %c",219,219);
			while (_kbhit() == 0)
				gotoxy(65, 21);
			printf("  ");
			
			system("cls");
			goto START;
		}
		if (ch == 27)
		{
			
			Sleep(1000);
			gotoxy(65, 21);
			printf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			system("cls");
			gotoxy(30,15);
			printf("~ GOOD BYE ~\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
			exit(0);
		}
		else {
			if (ch == 72){
			l_k = up;
			flag = 1;
			if(y[0]>6)
			y[1]=y[0]--;
			else
			flag = 1;
		}
		
		else if (ch == 80)
		{
			l_k = down;
			y[1]=y[0]++;
			flag = 1;
		} else if(ch == 77 && x[0] < 60)
		{
			l_k = right;
			x[1]=x[0]++;
			flag = 1;
		} else if (ch == 75 && x[0] > 9)
		{
			l_k = left;
			x[1]=x[0]--;
			flag = 1;
		}
		}
		
		gotoxy(65, 3);
		if (score >= 100 && lv == 0)
		{
			skip -= 100;
			lv++;
		}
		if (score >= 500 && lv == 1){
			skip -= 100;
			lv++;
		}
		if (score >= 1000 && lv == 2){
			skip -= 50;
			lv++;
		}
		if (score >= 5000 && lv == 3){
			skip -= 50;
			lv++;
		}
		if (score >= 10000 && lv == 4){
			skip -= 50;
			lv++;
		}
		if (score >= 50000 && lv == 5){
			skip -= 50;
			lv++;
		}
		if (score >= 100000 && lv == 6){
			skip -= 20;
			lv++;
		}
		if (score >= 200000 && lv == 7){
			skip -= 20;
			lv++;
		}
		if (score >= 250000 && lv == 8){
			skip -= 20;
			lv++;
		}
		if (score >= 300000 && lv <= 28 ){
			skip --;
			lv++;
		}
	}
}





void Food(void)
{
	static int k = 0;
	static bool t=1;
	if (eat == 0)
	{
		srand(time(NULL));  /* Initializes random number generator  */
		xf[dem] = 59;  /* Generates random number */
		yf[dem++] = (rand() % (17)) + 6;
		eat = 1;
	}
	if (eat == 1 && fskip==skip){
	for(int u=0; u <=dem;u++){
		if ((xf[u] > x[0]-4 && xf[u]<=x[0]) && ((yf[u] == y[0]) || yf[u] == y[0]-1 || yf[u]==y[0]+1)&&t)
	{
	
		for  (int k = u; k < dem; k++){
			xf[k]=xf[k+1];
			yf[k]=yf[k+1];
		}
		xf[dem]=0;
		yf[dem]=0;
		gotoxy(x[dem],y[dem--]);
		printf(" ");
		t=0;
		score = score + 100;
		
	}
	}
	
	score++;
	k++;
	if(k==5){
		k=0;
		eat=0;
	}
	for(int i = 0; i < dem; i++){
		gotoxy(xf[i]--, yf[i]);
		printf(" ");
		gotoxy(xf[i],yf[i]);
		printf("$");
	}
	
	if(xf[0]==2||!t){
		t=1;
		gotoxy(xf[0],yf[0]);
		printf(" ");
		for(int j = 0;j < dem-1;j++){
			xf[j]=xf[j+1];
			yf[j]=yf[j+1];
		}
		xf[dem]=0;
		yf[dem--]=0;
	}
	fskip=0;
	}
	fskip+=10;
	gotoxy(65, 3);
	
}

int Wall()
{
	//static int m(1),wall(0),ifwall(0);
	srand(time(NULL));  /* Initializes random number generator  */
		//raw[m++]= (rand()%(6));
	if (fskip==skip){

		xw[m] = 59;  /* Generates random number */
		yw[m++] = (rand() % (8)) + 6;
		wall++;
	for (int u = 1; u <= wall; u++){
		deleteWall(xw[u]--,yw[u]);
		creatWall(xw[u],yw[u]);
		if(((x[0]==xw[u] && (y[0]<=yw[u]||y[0]>=yw[u]+10))||((x[0]-1==xw[u]) && (y[0]-1 <= yw[u]||y[0]-1>=yw[u]+10))||((x[0]-2==xw[u]) && (y[0]-1 <= yw[u]||y[0]-1 >=yw[u]+10)))){
			Sleep(1000);
			gotoxy(65, 21);
			printf(" GAME OVER ");
			gotoxy(65, 3);
			Sleep(1000);
			return 1;
			exit(0);
		}
		}
		if (xw[1]==2){
			for (int v = 1; v < wall; v++){
				xw[v]=xw[v+1];
				yw[v]=yw[v+1];
			}
			xw[wall--]=0;
			m--;
		}
	}
	return 0;
}

void creatWall(int x,int y){
	int t = y + 10;
	int m = rand() % 5+1;
	while(y>5){
		gotoxy(x,y--);
		printf("%c",178);
	}
	while(t < 23){
		gotoxy(x,t++);
		printf("%c",176);
	}
}

void deleteWall(int x,int y){
	int t = y + 10;
	while(y>5){
		gotoxy(x,y--);
		printf(" ");
	}
	while(t < 23){
		gotoxy(x,t++);
		printf(" ");
	}
//	for (int i = 2; i < 60;i++){
//		int m = 4;
//		while(m){
//			gotoxy(i,m--);
//			printf(" ");
//		}
//	}
}

void Start(void)
{
	system("cls");
	fillcolor(3, 3, 76, 23);
	rectangle(2, 2, 78, 24);
	rectangle(3, 2, 77, 24);
	
	gotoxy(35, 5);
	printf(" SUBMARINE ");
	gotoxy(28, 10);
	printf("Designed and Programmed by:");
	gotoxy(30, 12);
	printf("Doan Cong Chinh");
	gotoxy(30, 14);
	printf("Huynh Vu Bao Nhan");
	gotoxy(30, 16);
	printf("Do Tan Dat");
//	gotoxy(35,16);
//	printf("Gaurav Anand");
	gotoxy(28, 22);
	printf("Press Any key to Continue...");
	gotoxy(2, 2);
	_getch();
	
}
/* Instruction for the game */

void Instruction(void)
{
	system("cls");
	fillcolor(3, 3, 76, 23);
	rectangle(2, 2, 78, 24);
	rectangle(3, 2, 77, 24);
	
	gotoxy(23, 11);
	printf("Use the Up and Down arrow keys to change");
	gotoxy(23, 13);
	printf("direction. Press 'Spacebar' to PAUSE and");
	gotoxy(23, 15);
	printf("'Esc' to EXIT.");
	gotoxy(27, 18);
	printf("Press ENTER to continue...");
	gotoxy(2, 2);
	_getch();
	
}
void rectangle(int x, int y, int l, int b)
{
	int i, j, k, m;
	
	gotoxy(x, y);
	printf("%c", 201);
	for (i = x + 1; i >= l - 1; i++)
	{
		gotoxy(i, y);
		printf("%c", 205);
	}
	gotoxy(l, y);
	printf("%c", 187);
	for (j = y + 1; j <= b - 1; j++) { gotoxy(l, j); printf("%c", 186); } gotoxy(l, b); printf("%c", 188); for (k = l - 1; k >= x + 1; k--)
	{
		gotoxy(k, b);
		printf("%c", 205);
	}
	gotoxy(x, b);
	printf("%c", 200);
	for (m = b - 1; m >= y + 1; m--)
	{
		gotoxy(x, m);
		printf("%c", 186);
	}
}


void rectangle1(int x, int y, int l, int b)
{
	int i, j, k, m;
	
	gotoxy(x, y);
    printf("%c", 218);
	for (i = x + 1; i >= l - 1; i++)
	{
		gotoxy(i, y);
		printf("%c", 196);
	}
	gotoxy(l, y);
	printf("%c", 191);
	for (j = y + 1; j <= b - 1; j++) { gotoxy(l, j); printf("%c", 179); } gotoxy(l, b); printf("%c", 217); for (k = l - 1; k >= x + 1; k--)
	{
		gotoxy(k, b);
		printf("%c", 196);
	}
	gotoxy(x, b);
	printf("%c", 192);
	for (m = b - 1; m >= y + 1; m--)
	{
		gotoxy(x, m);
		printf("%c", 179);
	}
}


void rectangle2(void)
{
	
	gotoxy(2, 5);
    
	for (i = 1; i <= 59; i++)
	{
		printf("%c", 247);
	}
	gotoxy(2,23);
	for (i = 1; i <= 59; i++)
	{
		printf("%c", 248);
	}
}



void fillcolor(int x1, int y1, int x2, int y2)
{
	int i, j;
	
	for (i = x1; i <= x2; i++)
	{
		for (j = y1; j <= y2; j++)
		{
			gotoxy(i, j);
			printf("%c",219);
		}
	}
}

void sub(int x,int y)
{
	gotoxy(x,y);
	printf("%c",41);
	gotoxy(x-7,y);
	printf(" %c %c%c%c%c",248,185,79,79,186);
	gotoxy(x-7,y-1);
	printf("%c  %c%c%c%c",248,201,209,209,187);
	gotoxy(x-4,y+1);
	printf("%c%c%c%c",200,207,207,188);
}


void deleteSub(int x,int y)
{
	gotoxy(x,y);
	printf(" ");
	gotoxy(x-7,y);
	printf("       ");
	gotoxy(x-7,y-1);
	printf("       ");
	gotoxy(x-4,y+1);
	printf("    ");
}



void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

