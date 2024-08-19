#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N,M;
    string str;
    
    int cnt=0;
    set<string> S;
    
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>str;
        S.insert(str);
    }

    for(int i=0; i<M; i++){
        cin>>str;
        if(S.find(str)!=S.end()){
            cnt++;
        }
    }

    cout<<cnt;
}