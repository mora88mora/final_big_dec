#include <bits/stdc++.h>
using namespace std ;

class BigDecimalInt
{
private :
    string snum ;
    vector<int>num ;
    char SIGN ;
public :
    BigDecimalInt(string decStr) ;
    BigDecimalInt(int decInt) ;

    BigDecimalInt operator + (BigDecimalInt &num2) ;
    BigDecimalInt operator - (BigDecimalInt &num2) ;

    void sum(vector<int>v1, vector<int>v2,vector<int>&res, string & num ) ;
    void sub(vector<int>v1, vector<int>v2,vector<int>&res, char & sign , char c1 , char c2, string & num) ;

    char &getsign() { return SIGN ; }
    void setsign(char c) { SIGN=c ;}

    string &getnum() { return snum ; }
    void setnum(string n) { snum=n ; }

    vector<int>&getvec() { return num ; }
    string getstr () {return snum;}

    void setvector( vector<int> v) {
        int x;
        for (int i=0 ;i<v.size();i++){
            x=v[i];
            num.push_back(x);
        }
    }

    void resize( int n ) { while(n--) { num.insert(num.begin() , 0) ; } }
    void check ()
    {
        while(num[0]==0) { num.erase(num.begin()) ; }
        while(snum[0]=='0') { snum.erase(0,1) ; }
    }

    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt &num2);
    int size() { return snum.size() ; } ;
    int sign();
    friend ostream& operator << (ostream& out, BigDecimalInt b);

};
