#include <iostream>
#include <cmath>

using namespace std;

int calculate(int n, int m) {   //최대 거리 계산
    int tmp, maxDist = 0, prv = 0;

    for (int i = 0; i < m; i++) {
        cin >> tmp;

        if (i == 0) {   //시작할 때 최대거리는 시작점-첫 번째 값
            if (maxDist < tmp - prv) {
                maxDist = tmp - prv;
            }

        } else {    //중간값 기준으로 바꿈
            int dist = ceil(double(tmp - prv) / 2);

            if (maxDist < dist) {
                maxDist = dist;
            }
        }
        prv = tmp;
    }

    if (maxDist < n - prv) {    //마지막 값에서 끝까지의 거리
        maxDist = n - prv;
    }

    return maxDist;
}

int main() {
    int n, m;
    cin>>n>>m;

    int max = calculate(n, m);
    cout<<max;

    return 0;
}
