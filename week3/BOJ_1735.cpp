#include <iostream>

using namespace std;

int getGcd(int a, int b){   //최대공약수
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int getLcm(int d1, int d2){   //최소공배수
    int gcd = getGcd(d1,d2);
    return (d1 * d2 / gcd);
}

int main(){
    int n1, d1;
    cin>>n1>>d1;

    int n2, d2;
    cin>>n2>>d2;

    int denom = getLcm(d1, d2); //분모

    int numer = n1*(denom/d1) + n2*(denom/d2);  //분자의 합

    //기약분수 형태로 변환
    int gcd = getGcd(denom, numer);
    denom /= gcd;
    numer /= gcd;

    cout<<numer<<" "<<denom;
    
    return 0;
}