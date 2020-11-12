#include <iostream>
#include <string>
using namespace std;

int main(){
    int s1, s2;
    s1 = s2 = 0;
    string str;
    cin >> str;
    for(char c: str)
        s1 += c - '0';
    cin >> str;
    for(char c: str)
        s2 += c - '0';
    cout << (s1 + s2) % 9 << '\n';
}