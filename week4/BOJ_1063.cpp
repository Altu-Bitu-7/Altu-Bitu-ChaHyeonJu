#include <iostream>
#include <string>

using namespace std;

const int SIZE = 8;

void getPosition(string& pos, int& x, int& y){
    x=pos[0]-'A'+1; //열을 숫자 좌표로 변환
    y=pos[1]-'0';   //행을 숫자 좌표로 변환
}

void setPosition(string& pos, int& x, int& y){
    pos="";
    pos += (char)('A' + x - 1); //열을 문자로 변환
    pos += (char)('0' + y);     //행을 문자로 변환
}

void getDirection(char& command, int& x, int& y){
    if(command == 'R'){
        x++;        
    }
    else if(command == 'L'){
        x--;        
    }
    else if(command == 'B'){
        y--;        
    }
    else if(command == 'T'){
        y++;        
    }
}

bool is_possible(int x, int y){
    return 0<x && x<=SIZE && 0<y && y<=SIZE;
}

int main(){
    string king, stone, direction;
    int n, kx, ky, sx, sy;
    
    cin>>king>>stone>>n;
    
    getPosition(king, kx, ky);
    getPosition(stone, sx, sy);

    while(n--){
        cin>>direction;
        
        int x=0,y=0;

        for(int i=0; i<direction.length(); i++){
            getDirection(direction[i], x, y);
        }
        
        int new_kx = kx + x;
        int new_ky = ky + y;

        if(is_possible(new_kx, new_ky)){    //킹이 이동 가능한지
            if(new_kx==sx && new_ky==sy){   //킹이 돌과 같은 위치로 이동할 때
                int new_sx = sx + x;
                int new_sy = sy + y;

                if(is_possible(new_sx, new_sy)){
                    sx=new_sx;
                    sy=new_sy;
                }

                else{   //돌 이동 불가
                    continue;   //킹도 이동하지 않음
                }
            }
            kx = new_kx;
            ky = new_ky;
        }
    }

    setPosition(king, kx, ky);
    setPosition(stone, sx, sy);

    cout<<king<<'\n'<<stone;

    return 0;
}