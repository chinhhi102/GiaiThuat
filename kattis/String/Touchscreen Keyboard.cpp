#include<bits/stdc++.h>
using namespace std;
struct data{
	int tong;
	string s;
};
bool dk(data a,data b){
	return (a.tong==b.tong)?(a.s<b.s):(a.tong<b.tong);
}
int main(){
	int n,h[255],c[255];
	scanf("%d",&n);
	h['q']=h['w']=h['e']=h['r']=h['t']=h['y']=h['u']=h['i']=h['o']=h['p']=c['q']=c['a']=c['z']=1;
	h['a']=h['s']=h['d']=h['f']=h['g']=h['h']=h['j']=h['k']=h['l']=c['w']=c['s']=c['x']=2;
	h['z']=h['x']=h['c']=h['v']=h['b']=h['n']=h['m']=c['e']=c['d']=c['c']=3;
	c['r']=c['f']=c['v']=4;
	c['t']=c['g']=c['b']=5;
	c['y']=c['h']=c['n']=6;
	c['u']=c['j']=c['m']=7;
	c['i']=c['k']=8;
	c['o']=c['l']=9;
	c['p']=10;
	while(n--){
		string s;
		int m;
		cin>>s>>m;int sum;data d[m];
		for(int i=0;i<m;i++){
			sum=0;
			cin>>d[i].s;
			for(int j=0;j<d[i].s.size();j++){
				sum+=(abs(h[s[j]]-h[d[i].s[j]])+abs(c[s[j]]-c[d[i].s[j]]));
			}
			d[i].tong=sum;
		}
		sort(d,d+m,dk);
		for(int i=0;i<m;i++)cout<<d[i].s<<" "<<d[i].tong<<endl;
	}
}
