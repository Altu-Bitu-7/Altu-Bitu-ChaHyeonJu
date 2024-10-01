#include <iostream>

using namespace std;

int alpha[26];
string s;

string makePalin(string s){
    string ans="";
    int cnt = 0;

    for(int i=0; i<26; i++){
        if(alpha[i]%2==1){
            cnt++;
        }
    }
    if(cnt>1){      //홀수 개 알파벳이 2개 이상이면 펠린드롬 만들 수 없음
        return "I'm Sorry Hansoo";
    }

    //알파벳의 반을 앞에 붙여줌
    for(int i=0; i<26; i++){
        for(int j=0; j<alpha[i]/2; j++){
            ans += i + 'A';
        }
    }

    //홀수 개의 알파벳 중앙에 붙여줌
    for(int i=0; i<26; i++){
        if(alpha[i] % 2){
            ans += i + 'A';
            break;
        }
    }

    //남은 알파벳 붙여줌
    for(int i=25; i>=0; i--){
        for(int j=0; j<alpha[i]/2; j++){
            ans += i + 'A';
        }
    }

    return ans;
}

int main(){
    cin>>s;

    for(int i=0; i<s.size(); i++){
        alpha[s[i] - 'A']++;    //알파벳 개수 카운트
    }

    cout<<makePalin(s)<<'\n';

}