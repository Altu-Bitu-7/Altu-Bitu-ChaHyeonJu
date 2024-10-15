#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int n,target_x,target_y,m;
int g[MAX][MAX];
int visited[MAX];

queue<int> q;

void BFS(int s) {
    q.push(s);

    while(!q.empty()) {
        s = q.front();
        q.pop();

        for(int i=1;i<=n;i++) {
            if(g[s][i]!=0 && !visited[i]) {
                q.push(i);
                visited[i]=visited[s]+1; 
            }
        }
    }
}

int main() {
    cin>>n;
    cin>>target_x>>target_y;
    cin>>m;

    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;

        g[x][y]=1;
        g[y][x]=1;
    }

    BFS(target_x);

    if(visited[target_y]==0){
        visited[target_y]=-1;
    }
        
    cout<<visited[target_y];

    return 0;
}