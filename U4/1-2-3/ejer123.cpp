#include <iostream>
using namespace std;

class Racional {
    float num, den;
public:
    Racional(float n, float d) : num(n), den(d) {}
    float VerNum() const { return num; };
    float VerDen() const { return den; };
    void CargarNum(float n);
    void CargarDen(float d);
    Racional operator+(Racional b);
    Racional operator*(Racional b);
    Racional &operator++();
    Racional operator++(int);
    bool operator<(const Racional &c) const;
    bool operator<=(const Racional &c) const;
    bool operator>(const Racional &c) const;
    bool operator>=(const Racional &c) const;
    bool operator==(const Racional &c) const;
    bool operator!=(const Racional &c) const;
    bool operator<(float x) const;
};

ostream &operator<<(ostream &o, const Racional &c) {
    o << c.VerNum() << " / " << c.VerDen() << endl;
    return o;
}

istream &operator>>(istream &i, Racional &c) {
    float a; i>>a; c.CargarNum(a);
    float b; i>>b; c.CargarDen(b);
    return i;
}

void Racional::CargarNum(float n) { num = n; }
void Racional::CargarDen(float d) { den = d; }

Racional Racional::operator+(Racional b) {
    float num = this->num*b.VerDen() + b.VerNum()*this->den;
    float den = this->den*b.VerDen();
    Racional c(num,den);
    return c;
}

Racional Racional::operator*(Racional b) {
    float num = this->num*b.VerNum();
    float den = this->den*b.VerDen();
    Racional c(num,den);
    return c;
}

Racional &Racional::operator++(){
    num += den;
    return *this;
}

Racional Racional::operator++(int){
    Racional aux = *this;
    num += den;
    return aux;
}

bool Racional::operator<(const Racional &c) const {
    return (this->num / this->den) < (c.num / c.den);}
bool Racional::operator<=(const Racional &c) const {
    return (this->num / this->den) <= (c.num / c.den);}
bool Racional::operator>(const Racional &c) const {
    return (this->num / this->den) > (c.num / c.den);}
bool Racional::operator>=(const Racional &c) const {
    return (this->num / this->den) >= (c.num / c.den);}
bool Racional::operator==(const Racional &c) const {
    return (this->num / this->den) == (c.num / c.den);}
bool Racional::operator!=(const Racional &c) const {
    return (this->num / this->den) != (c.num / c.den);}
bool Racional::operator<(float x) const {
    return (this->num / this->den) < (x);
}

int main() {
    Racional a(3,5), c(1,5);
    // ++a;
    // cout << a.VerNum() << " / " << a.VerDen() << endl;
    // a++;
    // cout << a.VerNum() << " / " << a.VerDen() << endl;

    operator<<(cout,a);
    cout << a;
    // operator>>(cin,c);
    // operator<<(cout,c);
    // cin >> c;
    // cout << c << a;

    // if(a<c) cout << "true" << endl;
    // else cout << "false" << endl;
    // if(a<10) cout << "true" << endl;
    // else cout << "false" << endl;
    // if(a>c) cout << "true" << endl;
    // else cout << "false" << endl;


    return 0;
}