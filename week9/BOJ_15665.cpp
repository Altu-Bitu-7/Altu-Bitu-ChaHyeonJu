#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n,m;
set<int> numbers;
vector<int> sequence;

void printSequence(){
    for(int i = 0; i<m; i++){
        cout<<sequence[i]<<" ";
    }
    cout<<"\n";
}

void backtrack(int cnt){
    if(cnt == m){
        printSequence();
        return;
    }

    for(int i: numbers){
        sequence[cnt] = i;
        backtrack(cnt + 1);
    }
}

int main(){
    cin>>n>>m;    

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        numbers.insert(num);
    }
    sequence.assign(m,0);

    backtrack(0);

    return 0;
}