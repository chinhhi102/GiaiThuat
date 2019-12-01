#include<bits/stdc++.h>
using namespace std;
struct person{
    string first;
    string last;
};
bool cmp(person p1, person p2) {return (p1.last==p2.last)?p1.first<p2.first:p1.last<p2.last;}
int main(){
    vector<person>v;
    string first,last;
    map<string,int>names;
    while(cin>>first&&cin>>last){
        person p;
        p.first=first;
        p.last=last;
        v.push_back(p);
        names[first]++;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first;
        if(names[v[i].first]>1){
            cout<<" "<<v[i].last;
        }
        cout<<endl;
    }
}
