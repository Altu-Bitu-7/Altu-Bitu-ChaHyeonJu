#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getStepDp(vector<int>& step, int n){
    vector<int> dp(n, 0);

    dp[0] = step[0];
    dp[1] = step[0] + step[1];
    dp[2] = max(step[0]+step[2], step[1]+step[2]);  //1, 3 밟음 vs 2, 3 밟음
    
    //dp[n-3]+step[n-1]+step[n]과 dp[n-2]+step[n] 비교
    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-3]+step[i-1]+step[i], dp[i-2]+step[i]);
    }

    return dp[n-1];
}

int main(){
    int n;
    cin>>n;

    vector<int> step(n, 0);

    for(int i=0; i<n; i++){
        cin>>step[i];
    }

    cout<<getStepDp(step, n);
    
    return 0;
}