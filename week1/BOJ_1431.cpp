#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sumNum(const string& str)
{
    int sum = 0;
    for(int i=0; i<str.size(); i++){  //숫자 합
        if(str[i]>='0' && str[i]<='9'){
            sum += str[i] - '0';
        }
    }
    return sum;

}

bool cmp(const string& A, const string& B) //중간에 값 바뀌지 않도록 상수로 선언
{
    if(A.size() != B.size()){
        return A.size()<B.size();  //짧은 문자열 우선
    }
    
    int A_sum=sumNum(A), B_sum=sumNum(B);

    if(A_sum != B_sum){    //길이 같은 경우, 숫자 합 작은 문자열 우선
        return A_sum < B_sum;
    }

    return A < B;  //길이, 숫자 합 모두 같은 경우, 사전순 정렬
    
}

int main()
{
    int n;
    cin>>n;

    vector<string> num(n); //미리 할당

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num.begin(),num.end(),cmp);

    for(int i=0; i<n; i++){
        cout<<num[i]<<'\n';
    }

    return 0;

}