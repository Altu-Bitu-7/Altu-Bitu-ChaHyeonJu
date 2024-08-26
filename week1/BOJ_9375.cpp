#include <iostream>
#include <map>

using namespace std;

int main(){
    int t, n;
    cin>>t;
   
    for(int i=0; i<t; i++){
        cin>>n;
        
        map<string, int> clothes;
        int cnt=1;

        for(int j=0; j<n; j++){
            string cloth, type;
            cin>>cloth>>type;
            clothes[type]++;
        }

        for(auto iter:clothes){
            cnt *= (iter.second+1); 
        }
        
        cnt--;
        cout<<cnt<<'\n';
    }

}