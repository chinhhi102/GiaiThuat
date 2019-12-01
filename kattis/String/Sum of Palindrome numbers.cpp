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
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define INF 1000000000000000000
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
void solve(int n);
int kt(int k)
{
	int z=0,c=0,s=k;
	while (s!=0)
	{
		z=z*10+s%10;
		s=s/10;
	}
	if(k==z)
	return 0;
	return 1;
}
int vt(int a[],int t,int z)
{
		int l=0,r=t-1,k;
	 while (l<=r)
    {
        k = (l+r)/2;
        if(a[k] == z||(a[k]<z&&z<a[k+1]))
        {
        return k;
		}
        else if(a[k]>z)
            r = k-1;
        else
            l = k+1;
            
    }
    return -1;
}

int main(){
	io;
	int n,z;
	int a[200];
	a[0]=1;  a[1]=2;  a[2]=3;  a[3]=4;  a[4]=5;  a[5]=6;  
	a[6]=7;  a[7]=8;  a[8]=9;  a[9]=11;  a[10]=22;  a[11]=33;  a[12]=44;  
	a[13]=55;  a[14]=66;  a[15]=77;  a[16]=88;  a[17]=99;  a[18]=101;  a[19]=111;  
	a[20]=121;  a[21]=131;  a[22]=141;  a[23]=151;  a[24]=161;  a[25]=171;  a[26]=181;  
	a[27]=191;  a[28]=202;  a[29]=212;  a[30]=222;  a[31]=232;  a[32]=242;  a[33]=252;  
	a[34]=262;  a[35]=272;  a[36]=282;  a[37]=292;  a[38]=303;  a[39]=313;  a[40]=323;  
	a[41]=333;  a[42]=343;  a[43]=353;  a[44]=363;  a[45]=373;  a[46]=383;  a[47]=393;  
	a[48]=404;  a[49]=414;  a[50]=424;  a[51]=434;  a[52]=444;  a[53]=454;  a[54]=464;  
	a[55]=474;  a[56]=484;  a[57]=494;  a[58]=505;  a[59]=515;  a[60]=525;  a[61]=535;  
	a[62]=545;  a[63]=555;  a[64]=565;  a[65]=575;  a[66]=585;  a[67]=595;  a[68]=606;  
	a[69]=616;  a[70]=626;  a[71]=636;  a[72]=646;  a[73]=656;  a[74]=666;  a[75]=676;  
	a[76]=686;  a[77]=696;  a[78]=707;  a[79]=717;  a[80]=727;  a[81]=737;  a[82]=747;  
	a[83]=757;  a[84]=767;  a[85]=777;  a[86]=787;  a[87]=797;  a[88]=808;  a[89]=818;  
	a[90]=828;  a[91]=838;  a[92]=848;  a[93]=858;  a[94]=868;  a[95]=878;  a[96]=888;  
	a[97]=898;  a[98]=909;  a[99]=919;  a[100]=929;  a[101]=939;  a[102]=949;  a[103]=959;  
	a[104]=969;  a[105]=979;  a[106]=989;  a[107]=999;  a[108]=1001;  a[109]=1111;  a[110]=1221;  
	a[111]=1331;  a[112]=1441;  a[113]=1551;  a[114]=1661;  a[115]=1771;  a[116]=1881;  a[117]=1991;  
	a[118]=2002;  a[119]=2112;  a[120]=2222;  a[121]=2332;  a[122]=2442;  a[123]=2552;  a[124]=2662;  
	a[125]=2772;  a[126]=2882;  a[127]=2992;  a[128]=3003;  a[129]=3113;  a[130]=3223;  a[131]=3333;  
	a[132]=3443;  a[133]=3553;  a[134]=3663;  a[135]=3773;  a[136]=3883;  a[137]=3993;  a[138]=4004;  
	a[139]=4114;  a[140]=4224;  a[141]=4334;  a[142]=4444;  a[143]=4554;  a[144]=4664;  a[145]=4774;  
	a[146]=4884;  a[147]=4994;  a[148]=5005;  a[149]=5115;  a[150]=5225;  a[151]=5335;  a[152]=5445;  
	a[153]=5555;  a[154]=5665;  a[155]=5775;  a[156]=5885;  a[157]=5995;  a[158]=6006;  a[159]=6116;  
	a[160]=6226;  a[161]=6336;  a[162]=6446;  a[163]=6556;  a[164]=6666;  a[165]=6776;  a[166]=6886;  
	a[167]=6996;  a[168]=7007;  a[169]=7117;  a[170]=7227;  a[171]=7337;  a[172]=7447;  a[173]=7557;  
	a[174]=7667;  a[175]=7777;  a[176]=7887;  a[177]=7997;  a[178]=8008;  a[179]=8118;  a[180]=8228;  
	a[181]=8338;  a[182]=8448;  a[183]=8558;  a[184]=8668;  a[185]=8778;  a[186]=8888;  a[187]=8998;  
	a[188]=9009;  a[189]=9119;  a[190]=9229;  a[191]=9339;  a[192]=9449;  a[193]=9559;  a[194]=9669;  
	a[195]=9779;  a[196]=9889;  a[197]=9999; 
	cin>>n;
	int xx=1;
	while(n!=0){
	cin>>z;
	if(kt(z)==0){
		cout<<"Case #"<<xx<<endl<<1<<" "<<z<<endl;
		n--;
		xx++;
		continue;
	}
    int a1,a2,a3;
    int co=0;
    int k=vt(a,198,z);
    for(int i=k;i>=0;i--){
    	int s=0,j=0;
    	if(co==2){
			cout<<"Case #"<<xx<<endl<<co<<" "<<a1<<" "<<a2<<endl;	
    		break;
		}
    	while (a[i]+a[j]<=z){
    		s=a[i]+a[j];
    		if(s>z) continue;
			if(s==z){
    			co=2;a1=a[i];	a2=a[j];break;
			}else {
				for(int i1=j+1;i1<i;i1++){
						s=a[i]+a[j]+a[i1];
						if(s>z)
    					break;
							if(s==z){
    							co=3;
    							a1=a[i];
    							a2=a[i1];
    							a3=a[j];
    							break;
							}
					}
			}
			j++;
		}
	}
	if(co==3)
			cout<<"Case #"<<xx<<endl<<co<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
	n--;
	xx++;
}
	return 0;
}
