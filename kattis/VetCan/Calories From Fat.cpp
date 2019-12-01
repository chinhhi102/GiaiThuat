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
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int main(){
	int multiplier[5] = {9, 4, 4, 4, 7};
	while(true){
    	string S; getline(cin, S);
    	if(S == "-") break;
	    double total_calories = 0, fat_calories = 0;
    	do{
      		istringstream iss(S);
      		string fat; iss >> fat;
      		iss.str(S); iss.clear();
		    double curr_total = 0, curr_tot_percent = 0;
      		for(int i = 0; i < 5; i++) {
        		string curr; iss >> curr;
        		char type = curr.back(); curr.pop_back();
				if(type == 'C'){
          			curr_total += stoi(curr);
        		}
		        else if(type == 'g'){
        			curr_total += stoi(curr) * multiplier[i];
        		}else{
          				curr_tot_percent += stoi(curr);
        			}
		    }
		    curr_total = (curr_total * 100)/(100 - curr_tot_percent);
      		total_calories += curr_total;
      		char type = fat.back(); fat.pop_back();
    		if(type == 'C'){
        		fat_calories += stoi(fat);
      		}
		    else if(type == 'g'){
        		fat_calories += stoi(fat) * multiplier[0];
      		}else{
		        fat_calories += (stoi(fat) * curr_total)/100;
      		}
			getline(cin, S);
		}while(S != "-");
		cout << round(fat_calories/total_calories * 100) << "%" << endl;
	}
	return 0;
}
