#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    int arr[1000001];
    int res[1000001];

    stack<int> nge;
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=n-1; i>=0; i--){      //뒤에서부터 확인
        while(!nge.empty() && nge.top() <= arr[i]){
            nge.pop();
        }

        if(nge.empty()){
            res[i] = -1;    //마지막 원소의 NGE는 -1
        }
        else{
            res[i] = nge.top(); //stack의 top이 NGE
        }
        
        nge.push(arr[i]);
    
    }

    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }

    return 0;
}