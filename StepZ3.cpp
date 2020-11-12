#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()

{
    int n, m, r = 0;

    cin >> n >> m;

    vector<string> a(n);

    while (r < n) {
        string s;

        getline(cin, s);

        ++r;
    }

    vector<string> res(2*n);
    for(int i = n; i < 2*n; i++){
        res[i] = string(a[i - n].rbegin(), a[i-n].rend()) + a[i-n];
    }
    for(int i = 0; i < n; i++)
        res[i] = res[2*n - 1 - i];
    for(auto s: res)
        cout << s << '\n';

    return 0;
}