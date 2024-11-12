#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, k, c;
vector<int> sushi;
int eat[3001];

int sushiCount(int k) {
    int cnt = 0;

    for (int i = 0; i < k; i++){
        if (eat[sushi[i]] == 0){
            cnt++; //처음 먹는 경우
        }

        eat[sushi[i]]++; // 해당 초밥 먹음
    }
    return cnt;
}

int maxSushi(int cnt, int coupon){
    int max_cnt = 0;

    if(eat[coupon] == 0){
        max_cnt = cnt + 1;
    } 
    else{
        max_cnt = cnt;
    }

    for (int i = 1; i < n; i++){
        eat[sushi[i - 1]]--;

        if (eat[sushi[i - 1]] == 0){
            cnt--;
        } 

        int nextSushi = sushi[(i + k - 1) % n];

        if (eat[nextSushi] == 0){   //처음 먹는 경우
            cnt++;
        }
        eat[nextSushi]++;

        if (eat[coupon] == 0){  //쿠폰 적용->최대 수량 갱신
            max_cnt = max(max_cnt, cnt + 1);
        }
            
        else{
            max_cnt = max(max_cnt, cnt);
        }
            
    }
    return max_cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>d>>k>>c;

    sushi.resize(n);

    for(int i; i<n; i++){
        cin>>sushi[i];
    }

    int init = sushiCount(k);

    int max = maxSushi(init, c);

    cout<<max;

    return 0;
}