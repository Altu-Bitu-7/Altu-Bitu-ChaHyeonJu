#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    cin>>a>>b;

    string ans(max(a.size(), b.size()), '0');   //더 긴 문자열의 길이 가짐

    bool carry = false;

    for(int i=0; i<ans.size(); i++)
    {
        int sum = 0;        //for문 돌아갈 때마다 초기화
        if(i<a.size()){
            sum += a[a.size() - i - 1] - '0';   //오른쪽 -> 왼쪽
        }

        if(i<b.size()){
            sum += b[b.size() - i - 1] - '0';
        }

        sum += carry;   //carry 있으면 1 더하기

        carry = sum / 10;   //sum이 10 이상이면 carry 1
        ans[ans.size() - i - 1] = sum % 10 + '0';   //일의 자릿수 ans에 문자열로 저장
    }

    if(carry){
        ans.insert(ans.begin(), carry + '0');
    }

    cout<<ans;

    return 0;
}