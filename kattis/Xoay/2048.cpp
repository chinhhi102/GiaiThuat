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

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
int in[4][4];

void rotate(int d){
	int temp[4][4];
	fora(i,0,4){
    	fora(j,0,4){
    		switch(d){
    			case 0:{
    				return;
					break;
				}
    			case 1:{
    				temp[i][j]=in[j][3-i];
					break;
					}
				case 2:{
					temp[i][j]=in[i][3-j];
					break;
				}
				case 3:{
					temp[i][j]=in[3-j][i];
					break;
				}
			}
		}
	}
	fora(i,0,4){
		fora(j,0,4)
			in[i][j]=temp[i][j];
	}
}
int main(){
	io;
	for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cin>>in[i][j];
        }
    }
    int d;
    cin>>d;
    rotate(d);
    fora(i,0,4){
        fora(j,0,4){
            fora(k,j+1,4){
                if (in[i][k] == 0) {	//o tiep theo = 0 thi xet o tiep
                	continue;
                }else if (in[i][j] == in[i][k]) { //neu 2 o bang nhau thi o hien taij *2
                    in[i][j] *= 2;
                    in[i][k] = 0;
                    break;
                }else if (in[i][j] == 0) {	//neu ong hien tai =0 va o tiep theo !=0 thi ong hien tai bang o tiep theo, o tiep theo =0
                    in[i][j] = in[i][k];
                    in[i][k] = 0;
                    j--;
                    break;
                }else if (k != j + 1) { 	//neu o tiep theo co so va o tiep theo ko phai o lien ke thi o lien ke bang o tiep theo
                    in[i][j + 1] = in[i][k];
                    in[i][k] = 0;
                    break;
                }else {					// neu o tiep theo va o hien tai deu co so thi thoat vong lap
                    break;
                }
            }
        }
    }
    rotate((4-d)%4);
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << in[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
