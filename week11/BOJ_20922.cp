#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[100002];

int longestSub(int n, int k, const vector<int>& sub) {
    int end = 0;
    int answer = 0; 

    for (int i = 0; i < n; i++) {
        while (end < n && visited[sub[end]] < k) {
            visited[sub[end]]++; //현재 숫자 등장 횟수 증가
            end++;             //끝 포인터 이동
        }

        answer = max(answer, end - i);

        if (end == n){
            break;
        }

        visited[sub[i]]--; //해당 숫자의 등장 횟수 감소
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> sub(n);
    for (int i = 0; i < n; i++) {
        cin >> sub[i];
    }

    int result = longestSub(n, k, sub);
    cout << result << '\n';

    return 0;
}
