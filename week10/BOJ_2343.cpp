#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int findMin(int n, int m, const int arr[]) {
    int l = *max_element(arr, arr + n);
    int r = 0; //최대값

    for (int i = 0; i < n; i++) {
        r += arr[i];
    }

    while (l <= r) {
        int mid = (l + r) / 2; //현재 탐색하는 블루레이 길이
        int sum = 0, cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (sum + arr[i] > mid) {
                sum = 0; //블루레이 길이를 초과하면 새 블루레이에 강의 담기
                cnt++;
            }
            sum += arr[i];
        }
        
        if (sum != 0){
           cnt++;
        } 

        if (cnt > m) {
            l = mid + 1; //필요한 블루레이가 많을 때
        } else {
            r = mid - 1; //필요한 블루레이가 적을 때
        }
    }

    return l;
}

int main() {
    int n, m;

    cin >> n >> m;

    int arr[100001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minLength = findMin(n, m, arr);

    cout << minLength;
    
    return 0;
}
