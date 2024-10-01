#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int t, k;

void rotate(deque<int>& gear, int dir){
    if(dir==1){     //시계 방향 -> 오른쪽으로 밀기
        int tmp = gear.back();
        gear.pop_back();
        gear.push_front(tmp);
    }
    else{           //반시계 방향 -> 왼쪽으로 밀기
        int tmp = gear.front();
        gear.pop_front();
        gear.push_back(tmp);
    }
}

vector<int> checkRotation(vector<deque<int>>& gear, int num, int dir, int t){
    vector<int> check(t+1, 0);
    check[num]=dir;

    //회전시킨 톱니바퀴의 왼쪽 톱니바퀴를 회전시킬지 확인 
    for(int i=num-1; i>=1; i--){
        if(gear[i][2] != gear[i+1][6]){
            check[i] = -check[i+1];
        }
        else{
            break;
        }
    }

    //회전시킨 톱니바퀴의 오른쪽 톱니바퀴를 회전시킬지 확인
    for(int i=num+1; i<=t; i++){
        if(gear[i-1][2] != gear[i][6]){
            check[i] = -check[i-1];
        }
        else{
            break;
        }
    }

    return check;
}

int count12(vector<deque<int>>& gear){
    int cnt=0;

    for(int i=0; i<gear.size(); i++){
        cnt += gear[i][0];  //12시 방향 톱니바퀴
    }

    return cnt;
}

int main(){
    cin>>t;

    vector<deque<int>> gear(t+1);   //1부터 시작

    for(int i=1; i<=t; i++){
        string str;
        cin>>str;

        //string을 int로 변환
        for(char c : str){
            gear[i].push_back(c - '0');
        }
    }

    cin>>k;

    for(int i=0; i<k; i++){
        int num, dir;
        cin>>num>>dir;

        vector<int> check = checkRotation(gear, num, dir, t);

        for(int j=1; j<=t; j++){
            if(check[j] != 0){
                rotate(gear[j], check[j]);
            }
        }
    }

    cout<<count12(gear)<<'\n';

    return 0;
}