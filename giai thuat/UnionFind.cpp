#include "D:\\baiTapLapTrinh\competitive_programming.h"
class UnionFind{
	private:
		vi p,rank,setSize;
		int numSets;
	public:
		UnionFind(int N){
			numSets=N;
			p.assign(N,0);
			rank.assign(N,0);
			setSize.assign(N,1);
			fora(i,0,N)
				p[i]=i;
				
		}
		int findSet(int i){
			return (p[i]==i)?i:(p[i]=findSet(p[i]));
		}
		bool isSameSet(int i,int j){
			return findSet(i)==findSet(j);
		}
		void unionSet(int i,int j){
			if(!isSameSet(i,j)){
				numSets--;
				int x=findSet(i);
				int y=findSet(j);
				if(rank[x]>rank[y])
					p[y]=x,setSize[x]+=setSize[y];
				else
					p[x]=y,setSize[y]+=setSize[x],rank[y]+=(rank[x]==rank[y]);
			}
		}
		int numDisJoinSet(){
			return numSets;
		}
		int sizeOfSet(int i){
			return setSize[findSet(i)];
		}
};	
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	UnionFind UF(5);
}
