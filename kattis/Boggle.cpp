#include<bits/stdc++.h>
using namespace std;
bool use[4][4];
bool found=false;
void dfs(vector<vector<char>> boggle, string s, int i,int j, int id){
	if(id==s.size()){
		found=true;
		return;
	}	
	for(int x=-1;x<=1;x++){
		for(int y=-1;y<=1;y++){
			if(i+x>=0 && i+x<4 && j+y>=0 && j+y<4 && !use[i+x][j+y] && s[id]==boggle[i+x][j+y]){
				use[i+x][j+y]=true;
				dfs(boggle,s,i+x,j+y,id+1);
				if(found)
					return;
				use[i+x][j+y]=false;
			}
		}
	}
}
bool check(vector<vector<char>> boggle, string s){
	memset(use,0,sizeof use);
	found=false;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[0]==boggle[i][j]){
				use[i][j]=true;
				dfs(boggle,s,i,j,1);
				if(found)
					return true;
				use[i][j]=false;
			}
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	vector<string> dist(n);
	for(int i=0;i<n;i++)
		cin>>dist[i];
	int m;
	cin>>m;
	int points[]={0,0,0,1,1,2,3,5,11};
	for(int i=0;i<m;i++){
		vector<vector<char>> boggle(4,vector<char>(4));
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				cin>>boggle[j][k];
		int total=0,count=0;
		string word="";
		for(int j=0;j<n;j++){
			if(check(boggle, dist[j])){
				count++;
				if(dist[j].size()>word.size()){
					word=dist[j];
				}else if(dist[j].size() == word.size() && dist[j] < word){
					word=dist[j];
				}
				total+=points[dist[j].size()];
			}
		}
		cout<<total<<" "<<word<<" "<<count<<endl;
	}
}
