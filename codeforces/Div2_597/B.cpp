#include<bits/stdc++.h>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int R, P, S;
		cin >> R >> P >> S;
		string s;
		cin >> s;
		map<char,int> co;
		for(int i = 0; i < s.size(); i++)
			co[s[i]]++;
		int sum = 0;
		int mR = min(R, co['S']);
		int mP = min(P, co['R']);
		int mS = min(S, co['P']);
		R -= mR;
		P -= mP;
		S -= mS;
		sum = mR + mP + mS;
		if(sum >= (n + 1)/2){
			cout << "YES" << endl;
			for(int i = 0; i < n; i++){
				if(s[i] == 'S' && mR > 0){
					s[i] = 'R';
					mR--;
				}else if(s[i] == 'R' && mP > 0){
					s[i] = 'P';
					mP--;
				}else if(s[i] == 'P' && mS > 0){
					s[i] = 'S';
					mS--;
				}else{
					if(R > 0) s[i] = 'R', R--;
					else if(P > 0) s[i] = 'P', P--;
					else s[i] = 'S', S--;
				}
			}
			cout << s << endl;
		}else{
			cout << "NO" << endl;
		}
	}	
}
