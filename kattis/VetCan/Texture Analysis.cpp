#include<bits/stdc++.h>
using namespace std;
int main(){
	int dem(1);
	string s;
	while(getline(cin,s)){
		if(s[0]=='E')break;
		int d=0,f=1,res(0),mes(0);
		for(int i=0;i<s.size();i+=d+1){
			if(s.size()==1)res=1;
			for(int j=i+1;j<s.size()&&f;j++){
				if(s[i]==s[j]){f=0;break;}
				else d++;
			}
			for(int j=i+1;j<s.size()&&f==0;j++){
				if(s[i]==s[j])
					if(j-i==d+1){res=1;break;}
					else{res=0;mes=1;break;} 
			}
			if(i==s.size()-1)mes=1;
			if(mes)break;
		}
		res?printf("%d EVEN\n",dem):printf("%d NOT EVEN\n",dem);dem++;
	}
}
