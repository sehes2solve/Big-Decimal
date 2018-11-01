#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

BigDecimalInt::BigDecimalInt(string n)
{
    number = n;
}

BigDecimalInt::BigDecimalInt(int n)
{
    number = n;
}



BigDecimalInt& BigDecimalInt::operator+ ( BigDecimalInt x)
{
    string first  = this -> number ;
    string second = x.number ;
    string result ;
    short carry = 0;
    int FirstIsBigger = 1 , SecondIsbigger = 0;
    bool negative1 = false ,negative2 = false , testswap = false ;

    if (first [0] == '-') /// mark that first is negative and the remove - symbol
    {
        negative1 = !negative1 ;
        reverse(first .begin() , first .end()) ;
        first .pop_back();
        reverse(first .begin() , first .end()) ;
    }
    if (second[0] == '-') /// mark that second is negative and the remove - symbol
    {
        negative2 = !negative2 ;
        reverse(second.begin() , second.end()) ;
        second.pop_back();
        reverse(second.begin() , second.end()) ;
    }

    if (second.length() == first.length()) /// make first value is the bigger number
        for(int i=0 ; i<first.length() ; i++)
            if ( (second[i] > first[i]) && (first[i] != '-') && (second[i] != '-') )
                {
                    swap(negative1      , negative2     ) ;
                    swap(first          , second        ) ;
                }

    if(second.length()> first.length()) /// make first value is the bigger number
        swap(first,second) , swap(negative1 , negative2 ) ;


    if (negative1 || negative2)
    {
        this->number = first ;
        x.number = second ;
        BigDecimalInt y = *this ;

        if (negative2 && !negative1)
            *this = y - x ;

        else if (negative1 && !negative2)
            *this = x - y ;

        else
        {
            *this = x + y ;
            reverse(this->number.begin() , this->number.end() );
            this->number += '-' ;
            reverse(this->number.begin() , this->number.end() );
        }

        return *this ;
    }

    else

    {
        long long digit1 = first.length() - 1 ;
        long long digit2 = second.length() - 1 ;
        for (int i = digit1 ; i>=0 ; i--)
        {
            int add = first[i] - '0' + second[digit2] - '0' + carry ; /// addition digit

            if (digit2>=0 && add < 10)             /// sum with no carry
            {
                result += (char) (add + '0') ;
                carry = 0;
            }
            else if (digit2>=0 && add >= 10) /// sum with carry
            {
                add = first[i] - '0' + second[digit2] - '0' + carry ;
                carry = add/10 ;
                add = add % 10 ;
                result += char(add + '0');
            }
            else
            {
                add = first[i] - '0' + carry ;
                carry = add/10 ;
                add = add % 10 ;
                result += char(add + '0') ;
            }
            digit2--;
        }

        if (carry)
            result += '1';

        reverse(result.begin(), result.end());

        this -> number = result ;
        return *this ;
    }
}



BigDecimalInt& BigDecimalInt::operator- ( BigDecimalInt x)
{
    string first  = this -> number ;
    string second = x.number ;
    string result ;
    short borrow = 0;
    int FirstIsBigger = 1 , SecondIsbigger = 0;


    long long digit1 = first.length() - 1 ;
    long long digit2 = second.length() - 1 ;

    bool negative1 = false ,negative2 = false , testswap = false ;
    if (first [0] == '-')
    {
        negative1 = !negative1 ;
        reverse(first .begin() , first .end()) ;
        first .pop_back();
        reverse(first .begin() , first .end()) ;
        digit1-- ;
    }
    if (second[0] == '-')
    {
        negative2 = !negative2 ;
        reverse(second.begin() , second.end()) ;
        second.pop_back();
        reverse(second.begin() , second.end()) ;
        digit2--;
    }

    if (second.length() == first.length())
        for(int i=0 ; i<first.length() ; i++)
            if (second[i] > first[i])
                swap(SecondIsbigger , FirstIsBigger) , testswap = true ;

    if(second.length()> first.length() || SecondIsbigger  )
    {
        swap(first     , second    );
        swap(digit1    , digit2    );
        swap(negative1 , negative2 );
        swap(SecondIsbigger , FirstIsBigger) ;

        testswap = true ;
    }
    if ( ( (negative1 || negative2) && (negative1!=negative2) ))
    {
        this->number = first ;
        x.number = second ;
        BigDecimalInt y = *this ;
        *this = y + x ;
        if ( (negative1 && SecondIsbigger && testswap) || (FirstIsBigger && negative2 && testswap) || (!testswap && FirstIsBigger && negative1) )
        {
            reverse(this->number.begin() , this->number.end() );
            this->number += '-' ;
            reverse(this->number.begin() , this->number.end() );
        }
        return *this ;
    }
    else if (negative1 && negative2)
    {
        this->number = first ;
        x.number = second ;
        BigDecimalInt y = *this ;

        if (testswap)   *this = y - x;
        else            *this = x - y;

        return *this;
    }
    else
    {
        for (int i = digit1 ; i>=0 ; i--)
        {

            int subtract = first[i] - second[digit2] + borrow ;

            if (digit2>=0 && subtract < 0)
            {
                borrow = -1;
                result += (char) (subtract + 10 + '0');
            }
            else
            {
                if (digit2>=0)
                    result += char(subtract+'0') , borrow = 0;

                else if ( (first[i]-'0' + borrow ) > 0)
                    result += char(first[i] + borrow) , borrow = 0;

                else if ( (first[i]-'0' + borrow ) == 0)
                    borrow = 0;

                else if (borrow && first[i]-'0' == 0)
                    result += char(9+'0') ;


            }
            digit2--;
        }

        if (borrow || testswap)
            result += '-' ;
        reverse(result.begin(), result.end());

        this -> number = result ;
        return *this ;

    }

}
