#include <bits/stdc++.h>
using namespace std;
int toInt(string s){
	bool f=0;
	int res=0;
	if(s[0]=='-')
		f=1,s=string(s.begin()+1,s.end());
	for(int i=0;i<s.size();i++)
		res=res*10+int(s[i]-'0');
	return f?-res:res;
}
string toString(int n){
	bool f=0;
	if(n<0){
		f=1;
		n*=-1;	
	}
	string res="";
	int temp=n%10;
	res=char(temp+'0');
	while(n/=10){
		temp=n%10;
		res+=char(temp+'0');
	}
	if(f)
		res+="-";
	return string(res.rbegin(),res.rend());
}
string cal(string s1,string s2,string op){
	if(op=="+")
		return toString(toInt(s1)+toInt(s2));
	if(op=="-")
		return toString(toInt(s2)-toInt(s1));
	if(op=="*")
		return toString(toInt(s1)*toInt(s2));
}
int main(){
	string s;
	int T=1;
	while(getline(cin,s)){
		string token;
		istringstream iss(s);
		vector<pair<string,int>> v;
		while(iss>>token){
			if((token[0]=='-'&&token.size()>1)||(token[0]>='0'&&token[0]<='9'))
				v.push_back({token,0});
			else if(token=="+"||token=="-"||token=="*")
				v.push_back({token,1});
			else v.push_back({token,2});
			while(v.size()>2){
				int sz=v.size();
				if(v[sz-1].second==0&&v[sz-2].second==0&&v[sz-3].second==1){
					string s1,s2,op;
					s1=v[sz-1].first;
					s2=v[sz-2].first;
					op=v[sz-3].first;
					v.pop_back();v.pop_back();v.pop_back();
					v.push_back({cal(s1,s2,op),0});
				}else break;
			}
		}
		cout<<"Case "<<T++<<": ";
		for(int i=0;i<v.size();i++)
			cout<<v[i].first<<' ';
		cout<<endl;
	}
}
