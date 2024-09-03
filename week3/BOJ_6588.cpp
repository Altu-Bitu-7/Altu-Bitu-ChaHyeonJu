#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

void getPrime(vector<bool>& prime){
    prime[0]=prime[1]=false;    //0, 1 제외

    for(int i=2; i*i<=MAX; i++){
        if(prime[i]==false){
            continue;  
        }

        for(int j=i+i; j<=MAX; j+=i){
            prime[j]==true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<bool> prime(MAX+1, true);

    getPrime(prime);

    while(true){
        cin>>n;

        if(n==0){
            break;
        }

        for(int a=3; a<=n/2; a+=2){ //홀수인 소수 구해야 함
             if(prime[a] && prime[n - a]){
                cout<<n<<" = "<<a<<" + "<<n-a<<'\n';
                break;
            }
            
            else{
                cout<<"Goldbach's conjecture is wrong.\n";
                break;
            }

        }        

    }
    
    return 0;
}