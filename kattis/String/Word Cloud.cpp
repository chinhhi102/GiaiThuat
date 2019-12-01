#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
int ceildiv(int top,int bot){
    return (top+bot-1)/bot;
}
typedef struct{
    string word;
    int freq;
    int fontsize;
    int width;
    int height;
}word;
bool cmp(word& w1,word& w2){
    return w1.word<w2.word;
}
int main(){
	io;
	solve();
	return 0;
}
void solve(){
	int n,m;
    int currcase=1;
    while(cin>>n&&cin>>m&&n!=0&&m!=0){
        vector<word> v;
        int maxfreq=0;
        fora(i,0,m){
            word w;
            cin>>w.word>>w.freq;
            maxfreq=max(maxfreq,w.freq);
            if(w.freq>=5){
                v.pb(w);
            }
        }
        for(auto& i:v){
            i.fontsize=8+ceildiv(40*(i.freq-4),(maxfreq-4));
            i.height=i.fontsize;
            i.width=ceildiv(9*i.word.length()*i.height,16);
        }
        int currwidth=0;
        int totalheight=0;
        int currheight=0;
        for(auto& i:v){
            if(currwidth+i.width>n){
                totalheight+=currheight;
                currwidth=0;
                currheight=0;
            }
            currwidth+=i.width+10;
            currheight=max(currheight,i.height);
        }
        totalheight += currheight;
        cout<<"CLOUD "<<currcase++<<": "<<totalheight<<endl;
    }
}
