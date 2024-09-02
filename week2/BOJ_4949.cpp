#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str)
{
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        char curr=str[i];

        if(curr == '(' || curr == '['){
            s.push(curr);
        }

        if(curr == ')'){
            if(!s.empty() && s.top() == '('){
                s.pop();
            }
            else{
                return false;
            }
        }

        else if(curr == ']'){
            if(!s.empty() && s.top() == '['){
                s.pop();
            }
            else{
                return false;
            }
        }

    }
    return s.empty();
}

int main(){
    
    while(true)
    {
        string str;
        getline(cin, str);

        if(str == "."){
            break;
        }

        if(isBalanced(str)){
            cout<<"yes\n";
        }
        else
            cout<<"no\n";

    }

    return 0;
}