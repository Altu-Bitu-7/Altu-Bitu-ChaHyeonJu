#include <iostream>
#include <vector>
#include <queue>
 
#define pi pair<int, int>
 
using namespace std;
 
int n, m, x;
const int INF = 1e9+7;

vector<pi> graph[2][1001]; 
vector<int> dist[2];
int resdist[1001];
 
void input(){
    int u, v, t;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> t;
        graph[0][u].push_back(make_pair(t, v));
        graph[1][v].push_back(make_pair(t, u));
    }
    dist[0].resize(n+1, INF);
    dist[1].resize(n+1, INF);
}
 
void Dijstra(int k){
    dist[k][x] = 0;
    
    priority_queue<pi, vector<pi>, greater<pi>> que;
    que.push({0, x});
    
    while(!que.empty()){
        int min_cost = que.top().first;
        int now = que.top().second;
        que.pop();
        
        if(min_cost > dist[k][now]){
             continue;
        }
        
        for(int i = 0; i < graph[k][now].size(); i++){
            int next = graph[k][now][i].second;
            int next_cost = min_cost + graph[k][now][i].first;
            
            if(next_cost < dist[k][next]){
                dist[k][next] = next_cost;
                que.push({next_cost, next});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    
    Dijstra(1); //정점->x 최단거리
    Dijstra(0); //x->정점 최단거리
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, dist[0][i] + dist[1][i]);
    }
    
    cout << res;
    
    return 0;
}
