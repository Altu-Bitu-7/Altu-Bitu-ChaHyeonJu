#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool snack(const vector<int>& snacks, int length, int m) {
    int cnt = 0;

    for (int snack : snacks) {
        cnt += snack / length;
    }
    return cnt >= m;    //m명 이상에게 나눠줄 수 있으면 true

}

int getMax(const vector<int>& snacks, int m) {  //줄 수 있는 최대 길이
    int low = 1;
    int high = snacks.back();
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (snack(snacks, mid, m)) {
            result = mid;
            low = mid + 1;
        } 
        
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int m, n, input;
    cin >> m >> n;

    vector<int> snacks(n);

    for (int i = 0; i < n; i++) {
        cin >> snacks[i];
    }

    sort(snacks.begin(), snacks.end());

    int max = getMax(snacks, m);

    cout << max;

    return 0;
}
