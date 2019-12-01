#include<bits/stdc++.h>
using namespace std;
#define int long long
struct numdef{
	int num[3];
	numdef(int a, int b, int c){
		num[0] = a;
		num[1] = b;
		num[2] = c;
		sort(num, num + 3);
	}
};
vector<numdef> pytagos, temp;
#define MAXSIZE 30000001
int arrA[MAXSIZE] = {}, arrB[MAXSIZE] = {}, arrC[MAXSIZE] = {};
//map<int,int> arrA, arrB, arrC;
#undef int
int main(){
#define int long long
#define MAX 5478
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int a, b, c;
	for(int i = 1; i*i < MAXSIZE; i++)
		for(int j = i + 1; j*j < MAXSIZE; j++){
			a = i*i + j*j;
			b = j*j - i*i;
			c = 2 * i * j;
			pytagos.push_back(numdef(a, b, c));
		}
	int na, nb, nc;
	cin >> na >> nb >> nc;
	int x, maxn = 0;
	for(int i = 0; i < na; i++)	cin >> x, arrA[x]++, maxn = max(maxn, x);
	for(int i = 0; i < nb; i++) cin >> x, arrB[x]++, maxn = max(maxn, x);
	for(int i = 0; i < nc; i++) cin >> x, arrC[x]++, maxn = max(maxn, x);
	int res = 0;
//	arrA[8]++, arrB[15]++, arrC[17]++;
	for(int i = 0; i < pytagos.size(); i++){
		vector<int> temp (pytagos[i].num, pytagos[i].num + 3);
		if(temp[0] > maxn || temp[1] > maxn || temp[2] > maxn) continue;
		res += (arrA[temp[0]] * arrB[temp[1]] * arrC[temp[2]]);
		res += (arrA[temp[1]] * arrB[temp[0]] * arrC[temp[2]]);
	}
	cout << res << endl;
}
