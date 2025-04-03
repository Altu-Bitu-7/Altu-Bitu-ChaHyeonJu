#include <iostream>
#include <vector>

using namespace std;

int board[52][52];
bool check[52][52];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cleanRoom(int n, int m, int r, int c, int d) {
    int sum = 0;

    while (true) {
        if (!check[r][c]) { //현재 위치 청소
            check[r][c] = true;
            sum++;
        }

        bool moved = false;

        for (int i = 0; i < 4; i++){
            d = (d + 3) % 4;    //왼쪽으로 회전

            int nx = r + dx[d];
            int ny = c + dy[d];

            if (board[nx][ny] == 0 && !check[nx][ny]) { //청소 안했으면
                r = nx;
                c = ny;
                moved = true;
                break;
            }
        }

        if (!moved) {
            int back = (d + 2) % 4; //후진
            int bx = r + dx[back];
            int by = c + dy[back];

            if (board[bx][by] == 1) {   //벽
                break;
            } 
            
            // 벽이 아니면 후진
            r = bx;
            c = by;
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, c, d;
    cin >>n>>m>>r>>c>>d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int result = cleanRoom(n, m, r, c, d);
    cout << result << "\n";

    return 0;
}
