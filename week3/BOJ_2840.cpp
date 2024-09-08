#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic; //pair 타입 ic로 정의
const int ALPHA = 26;   //알파벳 개수

string printWheel(int n, int idx, vector<char>& wheel){
    string ans=""; //알파벳 출력될 string
    
    for(int i=idx+n; i>idx; i--){   //idx부터 시계방향으로 알파벳 출력
        ans += wheel[i%n];  //배열의 인덱스 초과하지 않도록 나머지 연산 사용
    }
    return ans; //ans 반환
}

string makeWheel(int n, int k, vector<ic>& record){
    vector<char> wheel(n,'?');  //길이 n, 바퀴 ?로 초기화
    vector<bool> is_avaliable(ALPHA, false);    //알파벳 중복 체크

    int idx = 0;  //화살표가 가리키는 idx 0으로 초기화

    for(int i=0; i<k; i++){
        int s=record[i].first;  //화살표가 가리키는 글자 변하는 횟수
        char ch=record[i].second;   //회전 멈춘 후 가리키는 문자

        idx=(idx+s)%n;  //회전 후 화살표가 가리키는 idx
        
        if(wheel[idx]==ch){ //현재 idx에 같은 문자 있으면 넘어감
            continue;
        }

        if(wheel[idx] != '?' || is_avaliable[ch-'A']){  //현재 idx에 다른 문자 or 문자 이미 사용되면 ! 반환
            return "!"; //존재할 수 없음
        }

        wheel[idx]=ch;  //바퀴에 문자 할당
        is_avaliable[ch-'A']=true;  //문자 사용되었으므로 true로 변경
    }
    return printWheel(n, idx, wheel);   //바퀴 상태 반환
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, k;
    cin>>n>>k;

    vector<ic> record(k);   //바퀴 기록 저장

    for(int i=0; i<k; i++){ 
        cin>>record[i].first>>record[i].second; //이동한 칸 수, 문자 입력
    }

    cout<<makeWheel(n,k,record);    //구성된 바퀴의 상태 출력
    
    return 0;
}