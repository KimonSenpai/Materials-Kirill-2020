#include <iostream>
using namespace std;

int Count(){
    static int count = 0;
    return ++count;
}

int main(){
    cout << Count() << '\n'
         << Count() << '\n';
}