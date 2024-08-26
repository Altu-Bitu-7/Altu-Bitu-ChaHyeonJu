#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, n, suc;
    cin>>t;
    
    while (t--)
    {
        cin>>n;
        vector<pair <int, int>> rank;
        
        for(int i=0; i<n; i++){
            int doc, in;
            cin>>doc>>in;

            rank.push_back({doc,in});
        }
        sort(rank.begin(), rank.end());

        int tmp=0;
        suc=1;
        
        for(int i=0; i<n; i++){
            if(rank[tmp].second > rank[i].second){
                suc++;
                tmp=i;
            }
        }
        cout<<suc<<'\n';
    }
    

}