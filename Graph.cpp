#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int in, out;
    int weight;
};
vector<set<int>> nw;//невзвешеный

vector<bool> f;
vector<int> f2;

bool DFS(int i, int j){
    if(nw[i].count(j))
        return true;
    f[i] = true;
    for(int k: nw[i])
        if(!f[k] && DFS(k, j))
            return true;
    return false;
}
void DFS(int i, int mark){
    f2[i] = mark;
    for(int k: nw[i])
        if(f2[k] != mark)
            DFS(k, mark)
}
int main(){
    /*vector<Edge> e;
    //list<Edge> le;
    
    //nw[i].insert(j);
    vector<map<int, int>> w;//взвешеный
    for(int j: nw[i])
        cout << j;
    auto x = 8;
    */

    int k = 0;
    for(int i = 0; i < n; i++){
        if(f2[i] == 0){
            k++;
            DFS2(i, k);
        }
    }
    

}