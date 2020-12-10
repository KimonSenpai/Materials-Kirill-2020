#include <iostream>
#include <string>
using namespace std;

int read(){
    int a = 0;
    for(int i = 0; i < 4; i++){
        int dig = 0;
        for(int j = 0; j < 4; j++){
            char c = cin.get();
            dig = 2*dig + (c - '0');
        }
        a = 10*a + dig;
    }
    return a;
}

void write(int a){
    string res = "";
    for(int i = 0; i < 4; i++){
        int dig = a%10;
        for(int j = 0; j < 4; j++){
            char d = '0' + dig%2;
            res = string({d}) + res;
            dig /= 2;
        }
        a /= 10;
    }
    cout << res << '\n';
}

int main(){
    int a = read();
    cin.get();
    int b = read();
    int sum = a + b;
    if(sum > 9999) {
        cout << "OVERFLOW\n";
    } else {
        write(sum);
    }
    
}