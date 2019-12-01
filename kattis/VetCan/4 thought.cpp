#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

int eval(int a, int b, char op){
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return -1;
}

char* tostring(int x){
	char ans[10];
	int i=0;
	if(x==0)return "0";
	while(x>0){
		ans[i++]=x%10+'0';
		x/=10;
	}
	ans[i]='\0';
	return strrev(ans);
}

int main(){
    map<int, string> ans;
    map<int, char> m;
    m[0] = '*';
    m[1] = '/';
    m[2] = '+';
    m[3] = '-';
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
            	vector<int> nums;
            	nums.push_back(4);nums.push_back(4);nums.push_back(4);nums.push_back(4);
                vector<char> ops;
                ops.push_back(m[i]);ops.push_back(m[j]);ops.push_back(m[k]);
				for(int it = 0; it < ops.size(); ++it){
                    if(ops[it] == '*' || ops[it] == '/'){               
                        nums[it] = eval(nums[it], nums[it+1], ops[it]);
                        nums.erase(nums.begin()+it+1);
                        ops.erase(ops.begin()+it);
                        --it;
                    }
                }
                for(int it = 0; it < ops.size(); ++it){                 
                    nums[it] = eval(nums[it], nums[it+1], ops[it]);
                    nums.erase(nums.begin()+it+1);
                    ops.erase(ops.begin()+it);
                    --it;
                }
                ans[nums[0]] = "4 " + string(1,m[i]) + " 4 " + string(1,m[j]) + " 4 " + string(1,m[k]) + " 4 = " + string(tostring(nums[0]));
            }
        }
    }

    int mm;
    cin >> mm;
    while(mm--){
        int nn;
        cin >> nn;
        if(ans.find(nn) != ans.end()){
            cout << ans[nn] << endl;
        } else {
            cout << "no solution" << endl;
        }
    }


    return 0;
}
