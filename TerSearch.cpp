#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;

double f(double x, double L){
    return x*x*L - x*x*x;
}

double Search(double L, double l, double r){
    if(r - l < EPS)
        return (r + l) / 2;
    double p1, p2;
    p1 = l + (r - l)/3;
    p2 = l + 2*(r - l)/3;
    if(f(p1, L) == f(p2, L))
        return Search(L, p1, p2);
    if(f(p1, L) > f(p2, L))
        return Search(L, l, p2);
    
    return Search(L, p1, r);
}

int main(){
    double l;
    cin >> l;
    cout << Search(l, 0, l);
}