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
#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define INF 1000000000000000000
#define fix(x) cout<<fixed<<setprecision(x)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<double,double> co;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;

void solve();
double dis(co& x,co& y){
	return sqrt((x.xx-y.xx)*1.0*(x.xx-y.xx)+(x.yy-y.yy)*1.0*(x.yy-y.yy));
}
bool inCircle(co& O,co& p,int R){
	return (dis(O,p)<=R);
}
double alpha(co& O,co& A,co& B);
double geta(co& A,co& B);
double getb(co& A,co& B);
double getc(co& A,co& B);
double geta(co& O,co& A,co& B,int R);
double getb(co& O,co& A,co& B,int R);
double getc(co& O,co& A,co& B,int R);
double Ctriangle(co& A,co& B,co& C);
double hight(co& M,co& A,co& B);
double Striangle(co& A,co& B,co& C);
double Shalf(co& O,co& A,co& B,int R);
co po(co& O,co& A,co& B,int R);
double halfCircle(co& O,co& A,co& B,int R){
	double L=alpha(O,A,B)*2*R*M_PI/360;
	return L*R/2;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,t,R;
	cin>>n>>t>>R;
	vector<co> point(n+1);
	fora(i,1,n+1){
		cin>>point[i].xx>>point[i].yy;
	}
	co O;
	O=point[t];
	double total=0;
	fora(i,1,n+1){
		if(t==i||t==i%n+1)continue;
		co A=point[i],B=point[i%n+1];
		if(inCircle(O,A,R)&&inCircle(O,B,R)){
			total+=Striangle(O,A,B);
//			cout<<total<<endl;
		}else{
			total+=Shalf(O,A,B,R);
		}
	}
	fix(10)<<(M_PI*R*R)-total<<endl;
}
double hight(co& M,co& A,co& B){
	return double((1.0*abs(1.0*(A.yy-B.yy)*M.xx+(B.xx-A.xx)*M.yy+(B.yy*A.xx-B.xx*A.yy)))/(sqrt((1.0*(A.yy-B.yy)*(A.yy-B.yy))+(B.xx-A.xx)*(B.xx-A.xx))));
}
double Striangle(co& A,co& B,co& C){
	double S;
//	cout<<hight(A,B,C)<<endl;
	S=(1.0/2)*(dis(B,C)*hight(A,B,C));
//	cout<<hight(A,B,C)<<endl;
//	cout<<dis(B,C)<<endl;
	return S;
}
double alpha(co& O,co& A,co& B){
	double a=dis(O,A);
	double b=dis(O,B);
	double c=dis(A,B);
	return acos((a*a+b*b-c*c)/(2*a*b))*180.0/M_PI;
}
double Ctriangle(co& A,co& B,co& C){
	double a=dis(A,B);
	double b=dis(A,C);
	double c=dis(B,C);
	return a+b+c;
}
double Shalf(co& O,co& A,co& B,int R){
	double S=0;
	double L=(alpha(O,A,B)*Ctriangle(O,A,B))/360.0;
	co P1,P2;
	bool dk1=inCircle(O,A,R);
	bool dk2=inCircle(O,B,R);
	if(dk1||dk2){
		if(dk1){
			if(dis(O,A)==R){
				P2=po(O,O,B,R);
				S=halfCircle(O,A,P2,R);
			}else{
				P1=po(O,A,B,R);
				P2=po(O,O,B,R);
				S=Striangle(O,A,P1)+halfCircle(O,P1,P2,R);
			}
		}else{
			if(dis(O,B)==R){
				P2=po(O,O,A,R);
				S=halfCircle(O,B,P2,R);
			}else{
				P1=po(O,A,B,R);
				P2=po(O,O,A,R);
				S=Striangle(O,B,P1)+halfCircle(O,P1,P2,R);
			}	
		}
	}else{
		P1=po(O,O,A,R);
		P2=po(O,O,B,R);
		S=halfCircle(O,P1,P2,R);
	}
//	cout<<S<<endl;
	return S;
}
double geta(co& A,co& B){
	return (1.0*(A.yy-B.yy)/(A.xx-B.xx));
}
double getb(co& A,co& B){
	return -1;
}
double getc(co& A,co& B){
	return (B.yy-((B.xx*(A.yy-B.yy))/(A.xx-B.xx)));
}
double geta(co& O,co& A,co& B,int R){
	double a=geta(A,B);
	double b=getb(A,B);
//	cout<<a<<' '<<b<<endl;
	return (b*b+a);
}
double getb(co& O,co& A,co& B,int R){
	double a=geta(A,B);
	double b=getb(A,B);
	double c=getc(A,B);
	return (2*b*c+2*b*O.xx-2*O.yy*a);
}
double getc(co& O,co& A,co& B,int R){
	double a=geta(A,B);
	double b=getb(A,B);
	double c=getc(A,B);
	return (c*c+2*O.xx*c+a*(pow(O.xx,2)+pow(O.yy,2)-R*R));
}
co po(co& O,co& A,co& B,int R){
	double a=geta(O,A,B,R);
	double b=getb(O,A,B,R);
	double c=getc(O,A,B,R);
//	cout<<O.xx<<' '<<O.yy<<endl;
//	cout<<A.xx<<' '<<A.yy<<endl;
//	cout<<B.xx<<' '<<B.yy<<endl;
	double p1=(-b+sqrt(b*b-4*a*c))/(2*a);
	double p2=(-b-sqrt(b*b-4*a*c))/(2*a);
	double h1=(-(B.xx-A.xx)*p1-B.yy*A.xx+B.xx*A.yy)/(A.xx-B.yy);
	double h2=(-(B.xx-A.xx)*p2-B.yy*A.xx+B.xx*A.yy)/(A.xx-B.yy);
	co d1={h1,p1};
	co d2={h2,p2};
//	cout<<p1<<' '<<p2<<endl;
	return (dis(d1,B)<dis(d2,B))?d1:d2;
}
/*
4 1 2
0 0
1 0
1 1
0 1
*/
