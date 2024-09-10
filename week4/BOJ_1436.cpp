#include <iostream>

using namespace std;

int find(int n){
    int cnt=0;

    for(int i=666; ; i++){
        string res = to_string(i);
        
        if(res.find("666") != string::npos){    //"666"을 포함하는지 확인
            cnt++;
        }

        if(n==cnt){     //n번째 숫자 찾으면 반환 
            return i;
        }        
    }
    
}

int main(){
    int n;
    cin>>n;

    cout<<find(n);   

    return 0;
}