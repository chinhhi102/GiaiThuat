#include<bits/stdc++.h>
using namespace std;
int n,m,id[100001],c[100001],l[100001],st[4*100001],ran[100001];
vector<int> p[100001];
int d=0;
int res=-1;
int left(int p){return p<<1;}
int right(int p){return (p<<1)+1;}
void build_st(int p,int l,int r){
	if(l==r){
		st[p]=id[l];
	}else{
		build_st(left(p),l,(l+r)/2);
		build_st(right(p),(l+r)/2+1,r);
		st[p]=(c[st[left(p)]]>c[st[right(p)]]?st[left(p)]:st[left(p)]);
	}
}
void upt(int p,int l,int r,int x){
	if(x<l||x>r)return;
	if(l==r){
		if(l==x){
			c[id[x]]=0;
		}
	}else{
		upt(left(p),l,(l+r)/2,x);
		upt(right(p),(l+r)/2+1,r,x);
		st[p]=(c[id[st[left(p)]]]>c[id[st[right(p)]]]?id[st[left(p)]]:id[st[left(p)]]);
	}
}
int rmq(int p,int l,int r,int u,int v){
	if(l>v||r<u)return 0;
	if(l>=u&&r<=v)
		return st[p];
	int p1=rmq(left(p),l,(l+r)/2,u,v);
	int p2=rmq(right(p),(l+r)/2+1,r,u,v);
	return c[p1]>c[p2]?p1:p2;
}
int re_id[100001]={};
void dfs(int parent){
	id[d]=parent;
	re_id[parent]=d++;
	for(int i=0;i<p[parent].size();i++)
		dfs(p[parent][i]);
	ran[parent]=d-1;
}
int total=0;
int S[100001]={},num[100001]={};
void dfs2(int parent){
	for(int i=0;i<p[parent].size();i++){
		dfs2(p[parent][i]);
		S[parent]+=S[p[parent][i]];
		num[parent]+=num[p[parent][i]];
	}
	num[parent]++;
	S[parent]+=c[parent];
	while(S[parent]>m){
		int x=rmq(1,1,n,re_id[parent],ran[parent]);
		S[parent]-=c[x];
		num[parent]--;
		upt(1,1,n,re_id[x]);
	}
	res=max(res,num[parent]*l[parent]);
}
int main(){
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x>>c[i]>>l[i];
		p[x].push_back(i);
	}
	dfs(0);
	build_st(1,1,n);
	dfs2(0);
	cout<<res;
}
