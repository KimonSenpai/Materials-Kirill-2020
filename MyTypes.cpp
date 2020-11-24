#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Vector{
    double r, phi, z;
    int n;
};

bool cmp(const Vector& a, const Vector& b){
    if(abs(a.phi - b.phi) < 0.00000005)
        return a.r < b.r;
    return a.phi < b.phi;
}

int main(){
    //cout << 1.0 << (1.0/199)*199 << '\n';
    //return 0;


    double x, y, z;
    cin >> x >> y >> z;
    int k;
    cin >> k;
    vector<Vector> mas(k);

    for(int i = 0; i < k; i++){
        double xx, yy, zz;
        cin >> xx >> yy >> zz;
        mas[i].r = sqrt((xx - x)*(xx - x) + (yy - y)*(yy - y));
        mas[i].phi = atan2(yy - y, xx - x);
        mas[i].z = zz - z;
        mas[i].n = i+1;
    }
    sort(begin(mas), end(mas), cmp);
    double curPhi = 0;
    vector<Vector>::iterator high;
    Vector maxObj = {0, 0, 0, 0};
    for(auto p = begin(mas); p != end(mas); p++){
        if(abs(curPhi - p->phi) < 0.0000005){
            if(maxObj.z < p->z)
                maxObj = *p;
            high = p;
            curPhi = p->phi;// (*p).phi
            continue;
        }

        if(high->r/p->r > high->z/p->z){
            if(maxObj.z < p->z)
                maxObj = *p;
            high = p;
        }
    }
    cout << maxObj.n << '\n';
    
}