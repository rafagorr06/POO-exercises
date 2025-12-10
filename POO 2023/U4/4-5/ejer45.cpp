#include <iostream>
using namespace std;

class Complejo {
    int m_preal, m_pimag;
public:
    Complejo(float r, float i) : m_preal(r), m_pimag(i) {}
    int VerReal() const { return m_preal; };
    int VerImag() const { return m_pimag; };
    void CargarReal(int r) { m_preal = r; }
    void CargarImag(int i) { m_pimag = i; }
    bool operator==(const Complejo &b) const;
    int operator[] (int i) const;
    int& operator[] (int i);
};

bool Complejo::operator==(const Complejo &b) const {
    return (this->m_preal == b.m_preal && this->m_pimag == b.m_pimag);
}

int Complejo::operator[] (int i) const {
    if (i==0) return m_preal;
    else return m_pimag;
}

int& Complejo::operator[] (int i) {
    if (i==0) return m_preal;
    else return m_pimag;
}

Complejo operator+(const Complejo &a, const Complejo &b) {
    int preal = a.VerReal() + b.VerReal();
    int pimag = a.VerImag() + b.VerImag();
    Complejo c(preal,pimag);
    return c;
}

Complejo operator-(const Complejo &a, const Complejo &b) {
    int preal = a.VerReal() - b.VerReal();
    int pimag = a.VerImag() - b.VerImag();
    Complejo c(preal,pimag);
    return c;
}

ostream &operator<<(ostream &o, const Complejo &c) {
    o << c.VerReal() << " + " << c.VerImag() << "i" << endl;
    return o;
}

istream &operator>>(istream &i, Complejo &c) {
    int a; i >> a; c.CargarReal(a);
    int b; i >> b; c.CargarImag(b);
    return i;
}

int main() {
    Complejo a(2,4), b(0,0);
    // cin >> b;
    // Complejo c = a+b;
    // cout << c << endl;
    // c = a-b;
    // cout << c << endl;
    // Complejo d(0,0);
    // if (c==d) cout << "true" << endl;
    // else cout << "false" << endl;
    // Complejo e(-1,-3);
    // if (c==e) cout << "true" << endl;
    // else cout << "false" << endl << endl << endl;

    cout << a[0] << "+" << a[1] << "i" << endl;
    a[0] = 4; a[1] = 2;
    cout << a[0] << "+" << a[1] << "i" << endl;

    return 0;
}