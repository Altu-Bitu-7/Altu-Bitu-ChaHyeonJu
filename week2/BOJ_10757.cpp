#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    cin>>a>>b;

    string ans(max(a.size(), b.size()), '0');

    bool carry = false;

    for(int i=0; i<ans.size(); i++)
    {
        int sum = 0;
        if(i<a.size()){
            sum += a[a.size() - i - 1] - '0';
        }

        if(i<b.size()){
            sum += b[b.size() - i - 1] - '0';
        }

        sum += carry;

        carry = sum / 10;
        ans[ans.size() - i - 1] = sum % 10 + '0';
    }

    if(carry){
        ans.insert(ans.begin(), carry + '0');
    }

    cout<<ans;

    return 0;
}