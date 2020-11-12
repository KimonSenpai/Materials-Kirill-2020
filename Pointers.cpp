#include <iostream>
using namespace std;

int main(){
    int a = 3, b = 5;
    int* c = &a;
    for(int i = 0; i < 8; i++)
    cout << *(c + i) << ' ' ;
}