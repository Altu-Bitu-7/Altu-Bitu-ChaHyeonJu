#include <bits/stdc++.h>

using namespace std;

int n, k, l, cur_sec = 0, cur_dir = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[102][102];

deque<pair<int, int>> snake;
vector<pair<int, char>> dir;

bool simulate(){
    //cur_dir 방향으로 1초 진행
    int nx = snake.back().first + dx[cur_dir];
    int ny = snake.back().second + dy[cur_dir];

    cur_sec++;

    if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1){
        return false;
    }

    snake.push_back({nx, ny});

    //옮긴 곳이 사과면 종료
    if (board[nx][ny] == 2){
        board[nx][ny] = 1;

        return true;
    }

    //옮긴 곳이 사과가 아니면 꼬리 삭제
    board[nx][ny] = 1;
    board[snake.front().first][snake.front().second] = 0;

    snake.pop_front();

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;

    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;

        board[x - 1][y - 1] = 2;
    }

    cin >> l;

    for (int i = 0; i < l; i++){
        int sec;
        char str;

        cin>>sec>>str;

        dir.push_back({sec, str});
    }
    
    board[0][0] = 1;    //뱀 위치

    snake.push_back({0, 0});

    int dir_index = 0;

    while (1){
        if (cur_sec == dir[dir_index].first){

            if (dir[dir_index].second == 'L'){
                cur_dir = (cur_dir + 3) % 4;
                dir_index++;
            }

            else{
                cur_dir = (cur_dir + 1) % 4;
                dir_index++;
            }
        }

        if (!simulate()){
            cout << cur_sec << '\n';
            break;
        }
    }
}