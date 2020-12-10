#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char** matr = new char*[n + 1];
    for(int i = 1; i <= n; i++)
        matr[i] = new char[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> matr[i] + 1;

    for(int i = 1; i <= n/2; i++)
        for(int j = 1; j <= n - 2*(i - 1); j++)
            matr[n - i + 1][i + j - 1] = matr[n - (i + j - 1) + 1][n - (n - i + 1) + 1];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            matr[i][j] = matr[j][i];
    for(int i = 1; i <= n; i++)
        cout << matr[i] + 1 << '\n';
}