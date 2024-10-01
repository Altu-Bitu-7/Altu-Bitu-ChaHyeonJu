#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> setDp(vector<int>& arr, int n){
    vector<int> dp(n, 1);   //자기 자신만 있어도 길이는 1

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){    //수열이 증가하는 경우
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n, 0);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> dp = setDp(arr, n);

    cout<<*max_element(dp.begin(), dp.end())<<'\n';    //가장 큰 값 반환 
    
    return 0;
}