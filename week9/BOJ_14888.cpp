#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int op[4];
int sequence[11];
int max_num = INT_MIN, min_num = INT_MAX;

void backtrack(int cnt, int total){
    if (cnt == n - 1){
        max_num = max(max_num, total);
        min_num = min(min_num, total);
        return;
    }

    for (int i = 0; i < 4; i++){
        if (op[i] == 0){
            continue;
        }
        op[i]--;

        switch (i){
            case 0:
                backtrack(cnt + 1, total + sequence[cnt + 1]);
                break;
            case 1:
                backtrack(cnt + 1, total - sequence[cnt + 1]);
                break;
            case 2:
                backtrack(cnt + 1, total * sequence[cnt + 1]);
                break;
            case 3:
                backtrack(cnt + 1, total / sequence[cnt + 1]);
                break;
        }

        op[i]++;
    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> sequence[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> op[i];
    }

    backtrack(0, sequence[0]);

    cout << max_num << "\n" << min_num;

    return 0;
}
