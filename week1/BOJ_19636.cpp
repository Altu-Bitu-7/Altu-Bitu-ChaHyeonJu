#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int w, i0, t, d, i, a;  
    cin>>w>>i0>>t;
    cin>>d>>i>>a;

    int w1=w; //일일 기초 대사량 변화 반영X
    int w2=w; //일일 기초 대사량 변화 반영O

    int meta=i0; //일일 기초 대사량

    for(int day=0; day<d; day++){
        w1 += (i-i0-a);
        
        w2 += (i-meta-a);
        if(abs(i-meta-a) > t){
            meta+=floor((i-meta-a)/2);
        }
    }
    

    if(w1<=0){
        cout<<"Danger Diet"<<'\n';
    }
    else{
        cout<<w1<<" "<<i0<<'\n';
    }      


    if(w2<=0 || meta<=0){
        cout<<"Danger Diet";
    }
    else{
        cout<<w2<<" "<<meta<<" ";

        if(meta<i0){
            cout<<"YOYO";
        }
        else{
            cout<<"NO";
        }
    }
    

}