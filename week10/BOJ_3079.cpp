#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, m, num;
vector<int> v;

bool canAccommodate(const vector<int>& v, ll time, ll m) {
    ll cnt = 0;
    
    for (int usage : v) {
        cnt += time / usage; //대기 가능한 사람
        if (cnt >= m) {
            return true;
        }
    }
    return cnt >= m;
}

ll findMin(const vector<int>& v, ll M) {
    ll start = 1;
    ll end = v.back() * M;

    while (start <= end) {
        ll mid = (start + end) / 2;

        if (canAccommodate(v, mid, M)) {
            end = mid - 1; //충분하면 시간을 줄임
        } else {
            start = mid + 1; //부족하면 시간을 늘림
        }
    }

    return start;
}

int main() {

    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    ll minTime = findMin(v, m);

    cout << minTime;

    return 0;
}
