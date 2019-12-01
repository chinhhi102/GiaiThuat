#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <list>
//#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
using namespace std;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x)
#define scf(x) scanf("%f",&x)
#define scll(x) scanf("%lld",&x)
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define fix(x) cout<<fixed<<setprecision(x)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;
vector<string> menu;
int curr=0;
struct diemThi{
	string hoTen;
	float diemTin,diemNN,diemTB;
	int xl;
	diemThi(){
		diemTin=0;
		diemNN=0;
		diemTB=0;
	}
};
typedef struct diemThi diemThi;
bool cmd(diemThi x,diemThi y){
	return x.diemTB>y.diemTB;
}
void Nhap(diemThi diem[],bool xuat[],int n){
	fora(i,curr,n+curr){
		xuat[i]=1;
		cin.ignore();
		printf("Nhap ho ten hs %d : ",i+1);
		getline(cin,diem[i].hoTen);
		diem[i].hoTen.resize(30,' ');
		do{
			printf("Nhap diem Tin : ");
			cin>>diem[i].diemTin;
			if (cin.fail()||diem[i].diemTin<double(0)||diem[i].diemTin>double(10)){
				cin.clear();
				cin.ignore(32767, '\n');
				printf("Nhap sai diem sinh vien\n");
				diem[i].diemTin=-1;
			}
		}while(diem[i].diemTin<double(0)||diem[i].diemTin>double(10));
		do{
			printf("Nhap diem Ngoai Ngu : ");
			cin>>diem[i].diemNN;
			if (cin.fail()||(diem[i].diemNN<double(0)||diem[i].diemNN>double(10))){
				cin.clear();
				cin.ignore(32767, '\n');
				printf("Nhap sai diem sinh vien\n");
				diem[i].diemNN=-1;
			}
		}while(diem[i].diemNN<double(0)||diem[i].diemNN>double(10));
		diem[i].diemTB=(diem[i].diemTin+diem[i].diemNN)/2;
		diem[i].xl=diem[i].diemTB>=9?0:diem[i].diemTB>=8?1:diem[i].diemTB>=6.5?2:diem[i].diemTB>=5?3:4;
		printf("\n");
	}
	curr+=n;
}
void row1(int n,int dk){
	fora(i,0,n)
		printf("%c",(i==39||i==48||i==71||i==87)?dk==1?194:dk==2?193:197:196);
}
void row2(int n,int dk){
	fora(i,0,n)
 		printf("%c",(i==39)?dk==1?194:dk==2?193:197:196);
}
void bangDiem(diemThi diem[],bool xuat[],int n){
	string xeploai[6]={"Xsac","Gioi","Kha","TBinh","Yeu"};
	printf("%c",218);row1(96,1);printf("%c\n",191);
	printf("%cHo Ten\t\t\t\t\t%cDiem Tin%cDiem Ngoai Ngu\t%cDiem TB\t%cXeploai %c\n",179,179,179,179,179,179);
	printf("%c",195);row1(96,0);printf("%c\n",180);
	for(int i=0;i<n;i++){
		if(xuat[i])
			printf("%c%s\t\t%c%.3f\t %c%.2f\t\t\t%c%.3f\t\t%c%s\t %c\n",179,diem[i].hoTen.c_str(),179,diem[i].diemTin,179,diem[i].diemNN,179,diem[i].diemTB,179,xeploai[diem[i].xl].c_str(),179);
		else
			xuat[i]=1;
	}
	printf("%c",192);row1(96,2);printf("%c\n",217);
}
void gioi(diemThi diem[],bool xuat[],int n){
	printf("\nDanh sach sinh vien dat loai gioi : \n");
	fora(i,0,n){
		if(diem[i].diemTB>=8)
			xuat[i]=1;
		else
			xuat[i]=0;
	}
	bangDiem(diem,xuat,n);
}
void lai(diemThi diem[],bool xuat[],int n){
	printf("\nDanh sach sinh vien thi lai : \n");
	fora(i,0,n){
		if(diem[i].diemTin<5||diem[i].diemNN<5)
			xuat[i]=1;
		else
			xuat[i]=0;
	}
	bangDiem(diem,xuat,n);
}
void caonhat(diemThi diem[],bool xuat[],int n){
	printf("\nDanh sach sinh vien dat diem cao nhat : \n");
	int maxx=0,index=0;
	fora(i,0,n){
		if(diem[i].diemTB>=maxx){
			xuat[i]=1;
			xuat[index]=0;
			index=i;
		}else
			xuat[i]=0;
	}
	bangDiem(diem,xuat,n);
}
void sapxep(diemThi diem[],bool xuat[],int n){
	printf("\nDanh sach sinh vien theo thu tu diem TB giam dan : \n");
	sort(diem,diem+n,cmd);
	bangDiem(diem,xuat,n);
}
void mn(){
	int n;
	diemThi diem[1000];
	bool xuat[1000]={};
	int choose=0;
	menu.pb("Nhap diem sinh vien");
	menu.pb("Xem bang diem sinh vien");
	menu.pb("Xem sinh vien thi lai");
	menu.pb("Xem sinh vien gioi");
	menu.pb("Xem sinh vien co diem cao nhat");
	menu.pb("Xem bang diem sap xep sinh vien");
	do{
		system("cls");
		printf("%c",218);row2(55,1);
		printf("%c\n%cDanh Sach Chon\t\t\t\t%cMa Chon\t%c\n",191,179,179,179);
		printf("%c",195);row2(55,0);printf("%c\n",180);
		fora(i,0,menu.size()){
			menu[i].resize(39,' ');
			cout<<char(179)<<menu[i]<<char(179)<<i+1<<"\t\t"<<char(179)<<endl;
			//printf("%c %s %c %d \t\t %c \n",179,ch,179,i+1,179);
		}
		string be="Thoat";
		be.resize(39,' ');
		cout<<char(179)<<be<<char(179)<<0<<"\t\t"<<char(179)<<endl;
		printf("%c",192);row2(55,2);printf("%c\n",217);
		printf("--------------------------------------------------------------------------------------------------------------\n");
		do{
			printf("Ban chon : ");
			cin>>choose;
			if (cin.fail()){
				cin.clear();
				cin.ignore(32767, '\n');
				choose=1000;
			}
		}while(choose<1&&choose>menu.size());
		switch(choose){
			case 1:{
				do{
					printf("So sinh vien muon nhap : ");
					cin>>n;
					if (cin.fail()){
						cin.clear();
						cin.ignore(32767, '\n');
						printf("\nNhap sai so sinh vien\n");
					}
				}while(n<=0);
				Nhap(diem,xuat,n);
				system("pause");
				break;
			}
			case 2:{
				bangDiem(diem,xuat,curr);
				system("pause");
				break;
			}
			case 3:{
				lai(diem,xuat,curr);
				system("pause");
				break;
			}
			case 4:{
				gioi(diem,xuat,curr);
				system("pause");
				break;
			}
			case 5:{
				caonhat(diem,xuat,curr);
				system("pause");
				break;
			}
			case 6:{
				sapxep(diem,xuat,curr);
				system("pause");
				break;
			}
		}
	}while(choose);
}
int main(){
	io;
	mn();
	return 0;
}
