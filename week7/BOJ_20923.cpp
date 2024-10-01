#include <iostream>
#include <deque>

using namespace std;

deque<int> dodo;
deque<int> suyeon;
deque<int> gnd_do;
deque<int> gnd_su;


void halliGalli(int m){
    bool do_turn = true;
    int cnt = 0;

    while(true){
        cnt++;

        //카드 내려놓기
        if(do_turn){
            gnd_do.push_back(dodo.back());  
            dodo.pop_back();
        }
        else{
            gnd_su.push_back(suyeon.back());
            suyeon.pop_back();
        }

        //카드 수 0
        if(dodo.size() == 0){   
            cout << "su";
            break;
        }
        else if(suyeon.size() == 0){
            cout << "do";
            break;
        }

        //수연이 종 침
        if(gnd_do.size() != 0 && gnd_su.size() != 0 && gnd_do.back() + gnd_su.back() == 5){
            while(!gnd_do.empty()){   //도도 카드 -> 수연
                suyeon.push_front(gnd_do.front());
                gnd_do.pop_front();
            }
            while(!gnd_su.empty()){   //수연 카드 -> 수연
                suyeon.push_front(gnd_su.front());
                gnd_su.pop_front();
            }
        }

        //도도가 종 침
        else if((gnd_do.size() != 0 && gnd_do.back() == 5) || (gnd_su.size() != 0 && gnd_su.back() == 5)){
            while(!gnd_su.empty()){   //수연 카드 -> 도도
                dodo.push_front(gnd_su.front());
                gnd_su.pop_front();
            }
            while(!gnd_do.empty()){   //도도 카드 -> 도도
                dodo.push_front(gnd_do.front());
                gnd_do.pop_front();
            }
        }

        //m번 턴이 지나면 결과 계산
        if(cnt == m){
            int res = dodo.size() - suyeon.size();
            if(res < 0){
                cout << "su";
            }
            else if(res > 0){
                cout << "do";
            }
            else{
                cout << "dosu";
            }
            break;
        }

        // 턴 변경
        do_turn = !do_turn;  // 차례 변경
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    dodo.resize(n);
    suyeon.resize(n);

    for(int i = 0; i < n; i++){
        cin >> dodo[i] >> suyeon[i];
    }
    
    gnd_do.clear();
    gnd_su.clear();

    halliGalli(m);

    return 0;
}
