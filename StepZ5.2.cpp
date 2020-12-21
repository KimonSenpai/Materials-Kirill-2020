//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

struct Weight_t{
    float D;
    bool Cu;

    bool operator<(Weight_t w){
        if(D != w.D)
            return D > w.D;
        if(Cu != w.Cu)
            return Cu > w.Cu;
        return false;
    }

    bool operator==(Weight_t w){
        return (D == w.D && Cu == w.Cu);
    }
};

map<char, map<char, Weight_t>> tree;

char mf, mt;
set<char> flags;
bool dfs(char From, char To) {
    if(From == To) {
        mf = mt = To;
        return true;
    }

    flags.insert(From);

    for(auto node: tree[From]) {
        if(flags.count(node.first))
            continue;

        bool res = dfs(node.first, To);

        if(res) {
            if(mf == mt) {
                mf = From;
                mt = To;
            } else if(tree[mf][mt] < tree[From][node.first]) {
                mf = From;
                mt = node.first;
            }
            return true;
        }
    }

    return false;

}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char f, t;
        float d;
        string m;
        cin >> f >> t >> d >> m;
        tree[f][t] = {d, m == "Cu"};
        tree[t][f] = {d, m == "Cu"};

    }
    char From, To;
    cin >> From >> To;
    if(!dfs(From, To)) {
        cout << "Something went wrong!\n";
        return 0;
    }
    if(mf > mt)
        swap(mf, mt);
    cout << mf << ' ' << mt << '\n';
}