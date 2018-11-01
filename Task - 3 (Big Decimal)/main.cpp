#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

ostream& operator<<(ostream& out , BigDecimalInt x) ;

int main()
{
    string x , y ;
    string out = "1- Add \n2- Subtract \n0- End \n" ;
    int choice ;

    while (cout << out && cin >> choice && choice != 0)
    {
        bool valid = true ;

        if (choice != 1 && choice != 2 )  cout << "Input Error \n" ;

        cout << "\nEnter First  Num : " ; cin >> x ;
        cout << "Enter Second Num : "   ; cin >> y ;

        ///**---------------------------------------**///
        ///** Check The Validity of the first digit **///
        ///**---------------------------------------**///

        if ( (x[0] != '-') &&  ( (x[0]-'0') < 0 || (x[0]-'0') > 9) )
            valid = false ;

        if ( (y[0] != '-') &&  ( (y[0]-'0') < 0 || (y[0]-'0') > 9) )
            valid = false ;

        ///**---------------------------------------**///
        ///** Check The Validity of the rest of Num **///
        ///**---------------------------------------**///

        for(int i=1 ; i<x.length() ; i++)
            if ((int)(x[i]-'0') < 0 || (int) (x[i]-'0') > 9 )
                valid = false ;

        for(int i=1 ; i<y.length() ; i++)
            if ((int)(y[i]-'0') < 0 || (int) (y[i]-'0') > 9 )
                valid = false ;


        if (valid)
        {
            BigDecimalInt num1(x) , num2(y) ;
            cout << "\nYour Result is   : " ;
            if      (choice == 1) cout <<  num1 + num2 << endl ;
            else if (choice == 2) cout <<  num1 - num2 << endl ;
            system("PAUSE");
        }
        else
            cout << "Input Error \n" , system("PAUSE");
        system("CLS") ;
    }
    return 0;
}

ostream& operator<<(ostream& out , BigDecimalInt x)
{
    out << x.number ;
    return out ;
}


