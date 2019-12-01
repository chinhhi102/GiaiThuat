#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-8;
const double pi=3.1415926535897932384626;
struct TPoint{
	int type; // 0=left, 1=right
	double angle; // Between 0 and 2*pi
	int ix;
	TPoint(int a,double b,int c):type(a),ix(c){angle=fmod(b+2*pi,2*pi);}
};
bool operator<(const TPoint &a,const TPoint &b){
	if(fabs(a.angle-b.angle)>EPS)
		return a.angle<b.angle;
	return a.type<b.type;
};

int main(){
	int N,n,d,m;
	cin>>N;
	while(N--){
		cin>>n>>d;
		vector<TPoint> v;
		for(int i=m=0;i<n;i++) {
			double x,y;
			cin>>x>>y;
			if(x*x+y*y-EPS<d*d)
				continue;
			double a=atan2(y,x);
			double t=asin(d/sqrt(x*x+y*y));
			v.push_back(TPoint(0,a-t,m));
			v.push_back(TPoint(1,a+t,m++));
		}
		sort(v.begin(),v.end());
		int best=m;
		for(int i=0;i<v.size();i++){
			int cnt=0;
			vector<bool> mark(m,false);
			vector<int> list;
			for(int k=0;k<v.size();k++){
				int j=(i+k)%v.size();
				if(v[j].type==0){
					mark[v[j].ix]=true;
					list.push_back(v[j].ix);
				}else if(mark[v[j].ix]){
					cnt++;
					for(int l=0;l<list.size();l++)
						mark[list[l]]=false;
					list.clear();
				}
			}
			cnt+=list.size();
			if(cnt<best)
				best=cnt;
		}
		cout<<best<<endl;
	}
	return 0;
}
