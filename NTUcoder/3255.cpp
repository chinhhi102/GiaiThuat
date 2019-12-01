#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main(int argc, char const *argv[]){
#define int long long
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen("Electric//00.in","r",stdin);
//    freopen("out.txt","w",stdout);
    string s;
    int t,loc[255],val[255],last,res;
    loc['.']=loc[',']=loc['?']=loc['!']=loc['1']=1;
    loc['a']=loc['b']=loc['c']=loc['2']=2;
    loc['d']=loc['e']=loc['f']=loc['3']=3;
    loc['g']=loc['h']=loc['i']=loc['4']=4;
    loc['j']=loc['k']=loc['l']=loc['5']=5;
    loc['m']=loc['n']=loc['o']=loc['6']=6;
    loc['p']=loc['q']=loc['r']=loc['s']=loc['7']=7;
    loc['t']=loc['u']=loc['v']=loc['8']=8;
    loc['w']=loc['x']=loc['y']=loc['z']=loc['9']=9;
    loc['_']=loc['0']=0;
    val['.']=val['a']=val['d']=val['g']=val['j']=val['m']=val['p']=val['t']=val['w']=val['_']=1;
    val[',']=val['b']=val['e']=val['h']=val['k']=val['n']=val['q']=val['u']=val['x']=val['0']=2;
    val['?']=val['c']=val['f']=val['i']=val['l']=val['o']=val['r']=val['v']=val['y']=3;
	val['!']=val['2']=val['3']=val['4']=val['5']=val['6']=val['s']=val['8']=val['z']=4;
	val['1']=val['7']=val['9']=5;
    cin>>t,cin.ignore();
    while(t--){
        cin>>s;
        last=1;
        res=0;
        for(int i=0;i<s.size();i++){
            if(last!=loc[s[i]])res++;
            last=loc[s[i]];
            res+=val[s[i]];
        }
        cout<<res<<endl;
    }
    return 0;
}
