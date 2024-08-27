#include <iostream>
#include <stack>

using namespace std;

string inTopost(const string& str){
    stack<char> op;
    string ans = "";

    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            ans += str[i];
        }

        if(str[i] == '('){
            op.push(str[i]);
        }

        else if(str[i] == ')'){
            while(!op.empty() && op.top() != '('){
                ans += op.top();
                op.pop();
            }
            op.pop();   // '(' pop
        }

        else if(str[i] == '*' || str[i] == '/'){
            while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                ans += op.top();
                op.pop();
            }
            op.push(str[i]);
        }

        else if(str[i] == '+' || str[i] == '-'){
            while(!op.empty() && op.top() != '('){
                ans += op.top();
                op.pop();
            }
            op.push(str[i]);
        }
    }
    while(!op.empty()){
        ans += op.top();
        op.pop();
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;
    cin>>str;

    cout<<inTopost(str);

    return 0;
}