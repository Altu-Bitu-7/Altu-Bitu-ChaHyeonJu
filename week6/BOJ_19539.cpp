#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> h(n);
    long long total = 0, q = 0, r = 0;

    for(int i=0; i<n; i++){
        cin>>h[i];

        total += h[i];
        q += (h[i]/2);
        r += (h[i]%2);
    }

    if(total % 3 != 0 || r > q){    //물뿌리개 사용 횟수보다 2로 나누어떨어지지 않는 나무의 개수가 더 많으면 NO
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    
    return 0;
}
