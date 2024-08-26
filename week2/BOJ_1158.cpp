#include <iostream>
#include <queue>

using namespace std;



int main(){
    int n, k;
    cin>>n>>k;

    queue<int> q;

    for(int i=1; i<=n; i++){
        q.push(i);
    }

    cout<<'<';

    while (!q.empty())
    {
        for(int i=0; i<k-1; i++){ //k-1번까지 뒤로 보내기 
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    
        cout<<q.front();
        q.pop();  // k번째 값 pop

        if(q.size()>0){
            cout<<','<<" ";
        }
    }

    cout<<'>';
    

    return 0;
}