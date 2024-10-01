#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;

    vector<ll> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    ll speed = v[n-1];  //마지막 행성 기준으로 설정

    for(int i=n-2; i>=0; i--){
        if(speed % v[i] != 0){  //현재 속도가 필요한 속도의 배수가 아니면 배수로 설정
            speed = (speed / v[i] + 1) * v[i];  //배수로 맞추기 위해 +1
        }
    }

    cout<<speed<<'\n';

    return 0;

}