#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int comp(string A, string B)
{
    int A_sum=0, B_sum=0;

    if(A.size() != B.size()){
        return A.size()<B.size();  //짧은 순서대로
    }
    
    for(int i=0; i<A.size(); i++){  //숫자 합 작은 순서대로
        if(A[i]>='0' && A[i]<='9'){
            A_sum += A[i] - '0';
        }
        if(B[i]>='0' && B[i]<='9'){
            B_sum += B[i] - '0';
        }
    }

    if(A_sum != B_sum){
        return A_sum < B_sum;
    }

    else{
        return A < B;  //사전순으로
    }
    
}

int main()
{
    int N;
    cin>>N;

    vector<string> num(N); //미리 할당

    for(int i=0; i<N; i++){
        cin>>num[i];
    }

    sort(num.begin(),num.end(),comp);

    for(int i=0; i<N; i++){
        cout<<num[i]<<'\n';
    }

}