#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x, double C){
    return x*x + sqrt(x) - C;
}

const double EPS = 1e-7;

double Search(double C, double l, double r){
    double mid = l + (r - l) / 2;

    if(r - l < EPS)
        return mid;

    if(f(l, C)*f(mid, C) < 0)
        return Search(C, l, mid);
    return Search(C, mid, r);

}

int main(){
    double C;
    cin >> C;
    cout << setprecision(6) << fixed << Search(C, 0, 1e5) << '\n';
    return 0;
}
