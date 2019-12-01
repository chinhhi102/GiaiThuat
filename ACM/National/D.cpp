#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int main(){
#define int long long
    int r, c, k;
    cin >> r >> c >> k;
    string s[MAX];
    for(int i = 1; i <= r; i++){
        cin >> s[i];
        s[i] = '.' + s[i];
        s[i] += '.';
    }
    s[r + 1].resize(c + 2, '.');
    int vals[MAX] = {};
    for(int i = 1; i <= c; i++){
        cin >> vals[i];
    }
    int cyc[MAX][MAX] = {};
    for(int i = 0; i <= c + 1; i++){
        cyc[r + 1][i] = cyc[r + 1][i] = i;
    }
    for(int i = r; i >= 0; i--){
        for(int j = 1; j <= c; j++){
            cyc[i][j] = cyc[i + 1][j];
            if(s[i + 1][j] == 'R'){
                int t = j;
                while(s[i + 1][t] == 'R' || s[i + 1][t] == '?') t++;
                if(s[i + 1][t] == 'L' || s[i + 1][t] == 'X') cyc[i][j] = 0;
                else cyc[i][j] = cyc[i + 1][t];
            }
            if(s[i + 1][j] == 'L'){
                int t = j;
                while(s[i + 1][t] == 'L' || s[i + 1][t] == '?') t--;
                if(s[i + 1][t] == 'R' || s[i + 1][t] == 'X') cyc[i][j] = 0;
                else cyc[i][j] = cyc[i + 1][t];
            }
            if(s[i + 1][j] == '?'){
                int l = j;
                int r = j;
                while(s[i + 1][r] == 'R' || s[i + 1][r] == '?') r++;
                if(s[i + 1][r] == 'L' || s[i + 1][r] == 'X') r = 0;
                while(s[i + 1][l] == 'L' || s[i + 1][l] == '?') l--;
                if(s[i + 1][l] == 'R' || s[i + 1][l] == 'X') l = 0;
                cyc[i][j] = (vals[cyc[i + 1][l]] > vals[cyc[i + 1][r]] ? cyc[i + 1][l] : cyc[i + 1][r]);
            }
            if(s[i + 1][j] == 'X'){
                cyc[i][j] = 0;
            }
        }
    }
//  for(int i = 1; i <= c; i++) cout << cyc[0][i] << ' ';cout<<endl;
    int res = 0;
    for(int i = 1; i <= c; i++){
        int total = 0;
        int cur = cyc[0][i];
        int nL = k;
        while(nL && cur != cyc[0][cur]){
            total += vals[cur];
            nL--;
            cur = cyc[0][cur];
        }
        total += nL*vals[cur];
        res = max(res, total);
    }
    cout << res << endl;
}
/*
4 4 3
X..X
..L.
.?..
....
4 3 2 1

5 5 3
...XX
.....
.L?R.
.L?R.
.L?R.
1 2 3 4 5

4 4 5
X.X.
.?.R
....
....
2 3 4 5

1 5 4
LL.?L
3 4 5 6 7

2 2 3
.L
R.
2 3

4 4 1
....
..XX
....
???.
2 3 4 5

4 4 3
....
.L.L
.X.X
???.
2 3 4 5

5 6 3
......
R.....
.R..L.
..RL..
.....?
2 3 4 5 1000 5

2 5 1000000000
.....
..RL.
2 2 50 100 1000000000
*/
