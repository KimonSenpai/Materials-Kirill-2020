#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int * A = new int[N + 1],
        * B = new int[N + 1],
        * C = new int[N + 2];
    C++;
    C[-1] = C[0] = B[0] = 3601;
    
    int * f = new int[N + 3];
    f += 2;
    f[-2] = f[-1] = 3601;
    f[0] = 0;

    for(int i = 1; i <= N; i++)
        cin >> A[i] >> B[i] >> C[i];
    
    for(int i = 1; i <= N; i++){
        f[i] = min(C[i - 2] + f[i - 3], 
            min(B[i - 1] + f[i - 2], A[i] + f[i - 1]));
    }
    cout << f[N] << '\n';
}