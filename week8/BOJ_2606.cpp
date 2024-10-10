#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int cnt=0;
int n, p;

queue <int> q;
int g[MAX][MAX];
bool visited[MAX]={0,};

void BFS(int s){
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        s=q.front();
        q.pop();

        for(int i=1;i<=n;i++){
            if(g[s][i]==1 && visited[i]==0){ 
                q.push(i);
                visited[i]=true;
                cnt++;
            }
        }
    }   
}

int main(){
    cin>>n>>p;

    for(int i=0; i<p; i++){
        int start, end;
        cin>>start>>end;

        g[start][end] = 1;
        g[end][start] = 1;
    }

    BFS(1);

    cout<<cnt<<'\n';

    
    return 0;
}