#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt
{
    public:
        BigDecimalInt(string n);
        BigDecimalInt(int n);
        friend ostream& operator<<(ostream& out , BigDecimalInt x) ;
        BigDecimalInt& operator+ ( BigDecimalInt x) ;
        BigDecimalInt& operator- ( BigDecimalInt x) ;

    private:
        string number ;

};

#endif // BIGDECIMALINT_H
