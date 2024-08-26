#include <iostream>
#include <set>

using namespace std;

int findString(const set<string>& s, int m)
{
    int cnt = 0;
    string str;

    for(int i=0; i<m; i++){
        cin>>str;
        if(s.find(str)!=s.end()){
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n,m;
    string str;
    
    set<string> s;
    
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>str;
        s.insert(str);
    }

    int cnt = findString(s, m);

    cout<<cnt;

    return 0;
}