#include <iostream>
using namespace std;


class Vector{
public:
    double x, y;

    Vector(double x, double y): x(x), y(y) {}
    Vector(): x(0), y(0) {}

    double Abs() {
        return sqrt(x*x + y*y);
    }

    Vector operator+(const Vector& v) {
        return Vector(x + v.x, y + v.y);
    }

    double operator*(const Vector& v) {
        return x * v.x + y * v.y;
    }

    double operator^(const Vector& v) {
        return x*v.y - y*v.x;
    }

    Vector operator*(double val){
        return Vector(val*x, val*y);
    }

    friend Vector operator*(double val, Vector v){
        return v*val;
    }

    Vector operator-(Vector v){
        return *this + (-1)*v;
    }

    friend istream& operator>>(istream& in, Vector& v) {
        in >> v.x >> v.y;
        return in;
    }
};


int main(){
    Vector A, B, C, D;
    cin >> A >> B >> C >> D;
    Vector AB = B - A;
    Vector CD = D - C;

    Vector nAB(-AB.y, AB.x);
    Vector nCD(-CD.y, CD.x);
    
    if((nAB*(C - A))*(nAB*(D - A)) <= 0 && (nCD*(A - C))*(nCD*(B - C)) <= 0)
        cout << "Intersection\n";
    else
        cout << "No intersection\n";
    
    

}