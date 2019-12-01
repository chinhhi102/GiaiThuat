#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll _sieve_size=10001;
bitset<10001> bs,vis;
void sieve(){
	bs.set();
	bs[0]=bs[1]=0;
	for(int i=2;i<=_sieve_size;i++)if(bs[i])
		for(int j=i*i;j<=_sieve_size;j+=i)bs[j]=0;
}
int l,r,step;
bool founded;
void bfs(queue<int> &q){
	queue<int> nq;
	while(!q.empty()&&!founded){
		int n=q.front();
		q.pop();
		if(!vis[n])continue;
		vis[n]=0;
		int digit[4],temp=n;
		for(int i=0;i<4;i++,temp/=10)
			digit[i]=temp%10;
		for(int i=0;i<4;i++){
			for(int j=0;j<10;j++){
				if((i==3&&j==0)||(digit[i]==j))continue;
				temp=n;
				temp=temp-(digit[i]*pow(10,i))+j*pow(10,i);
				if(bs[temp])
					if(temp==r)
						founded=1;
					else if(vis[temp])
						nq.push(temp);
			}
		}
	}
	q=nq;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	sieve();
	int T;
	cin>>T;
	while(T--){
		vis.set();
		queue<int> q;
		int cur;
		founded=0;
		step=0;
		cin>>l>>r;
		q.push(l);
		founded=(l==r);
		while(!q.empty()&&!founded){
			bfs(q);
			step++;
		}
		founded?cout<<step<<endl:cout<<"Impossible"<<endl;
	}
}
