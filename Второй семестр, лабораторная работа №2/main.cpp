#include <iostream>
using namespace std;

static int global_id = 1; 

class vect {
public:
    int dim; 
    double a, b;
    int num;
    static int count; 

    vect(double a = 0, double b = 0) : a(a), b(b) {
        dim = 2; 
        num = global_id++; 
        count++; 
        cout << "Vector " << num << " constructed, total vectors: " << count << "\n";
    }

    ~vect() {
        cout << "Vector " << num << " destructed, remaining vectors: " << --count << "\n";
    }

    vect operator+(const vect& v) const {
        return vect(a + v.a, b + v.b);
    }

    vect operator-(const vect& v) const {
        return vect(a - v.a, b - v.b);
    }

    vect operator-() const {
        return vect(-a, -b);
    }

    double operator*(const vect& v) const {
        return a * v.a + b * v.b;
    }

    vect operator*(double k) const {
        return vect(a * k, b * k);
    }

    vect& operator=(const vect& v) {
        if (this != &v) {
            a = v.a;
            b = v.b;
        }
        return *this;
    }

    void print() const {
        cout << "(" << a << ", " << b << ")\n";
    }
};

int vect::count = 0;

class matr {
public:
    int dim; 
    double a, b, c, d; 
    int num; 
    static int count; 

    matr(double a = 0, double b = 0, double c = 0, double d = 0) : a(a), b(b), c(c), d(d) {
        dim = 2; 
        num = global_id++;
        count++;
        cout << "Matrix " << num << " constructed, total matrices: " << count << "\n";
    }

    ~matr() {
        cout << "Matrix " << num << " destructed, remaining matrices: " << --count << "\n";
    }

    matr operator+(const matr& m) const {
        return matr(a + m.a, b + m.b, c + m.c, d + m.d);
    }

 
    matr operator-(const matr& m) const {
        return matr(a - m.a, b - m.b, c - m.c, d - m.d);
    }

    matr operator-() const { 
        return matr(-a, -b, -c, -d);
    }

    matr operator*(const matr& m) const {
        return matr(a * m.a + b * m.c, a * m.b + b * m.d, c * m.a + d * m.c, c * m.b + d * m.d);
    }

    vect operator*(const vect& v) const {
        return vect(a * v.a + b * v.b, c * v.a + d * v.b);
    }

    matr operator*(double k) const {
        return matr(a * k, b * k, c * k, d * k);
    }

    matr& operator=(const matr& m) {
        if (this != &m) {
            a = m.a;
            b = m.b;
            c = m.c;
            d = m.d;
        }
        return *this;
    }

    void print() const {
        cout << "(" << a << ", " << b << ")\n";
        cout << "(" << c << ", " << d << ")\n";
    }
};

int matr::count = 0; 

int main() {
    vect v1(1, 2), v2(3, 4); matr m1(1, 2, 3, 4), m2(5, 6, 7, 8);
  
    cout << "---------------------------------------------------""\n";

    cout << "Vector amount: ";

    (v1 + v2).print();

    cout << "---------------------------------------------------""\n";
    cout << "Matrix multiplication: ";

    (m1 * v1).print();

    cout << "---------------------------------------------------""\n";

    return 0;
}