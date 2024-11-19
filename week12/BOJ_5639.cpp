#include <iostream>
#include <vector>
using namespace std;


int node[10001];

void post(int start, int end){
    if(start >= end) return; //두 수가 같아지며 종료
    
    int root = node[start];
    int delim = start+1;

    //root 노드보다 큰 노드를 발견하면 종료
    while(delim < end){
        if(root < node[delim]){
           break; 
        } 

        delim++;
    }

    post(start+1,delim);
    post(delim,end);

    cout << root << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0); 

    int num;
    int idx = 0;

    while(cin >> num){
        node[idx++] = num;
    } 

    post(0,idx);

    return 0;

}