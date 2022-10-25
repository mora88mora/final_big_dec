#include "BigDecimalInt.h"
BigDecimalInt :: BigDecimalInt(string decStr)
{
    if(decStr[0]=='+')
    {
        SIGN='+' ; snum=decStr.substr(1) ;
        for(int i=1; i<decStr.size(); i++) { num.push_back( decStr[i]-'0' ) ; }
    }
    else if (decStr[0]=='-')
    {
        SIGN='-' ; snum=decStr.substr(1) ;
        for(int i=1; i<decStr.size(); i++) { num.push_back( decStr[i]-'0' ) ; }
    }
    else
    {
        SIGN='+' ; snum=decStr ;
        for(int i=0; i<decStr.size(); i++) {
            num.push_back( decStr[i]-'0' ) ;
        }
    }
}

BigDecimalInt :: BigDecimalInt(int decInt) : BigDecimalInt(to_string(decInt))
{
}

void BigDecimalInt :: sum (vector<int>v1, vector<int>v2,vector<int>&res, string & num )  // function to sum two numbers ( a+b )
{
    int rem=0 , sm=0;
    for(int i=v1.size()-1; i>=0; i--)
    {
        sm=v1[i]+v2[i]+rem ;
        if(sm>9) { res[i]=sm%10 ; rem=1 ; }
        else { res[i]=sm ; rem=0 ; }
    }
    if(rem>0) { res.insert(res.begin(),rem) ; }
    for(auto &i:res) { num+= char (i+'0') ; }
}

void BigDecimalInt :: sub(vector<int>v1, vector<int>v2,vector<int>&res, char & sign , char c1 , char c2 , string & num ) // function to sub. two numbers ( a-b )
{
    char c ;
    for(int i=0; i<v1.size(); i++)
    {
        if(v1[i]>v2[i]) { c='+' ; break ; }
        if(v1[i]<v2[i]) { v1.swap(v2) ;  c='-' ; break ; }
    }
    for(int i=v1.size()-1; i>=0; i--)
    {
        if(v1[i]>=v2[i]) { res[i]=v1[i]-v2[i] ; }
        else
        {
            res[i] = v1[i]+10 -v2[i] ;
            for(int j=i-1; j>=0; j--)
            {
                if(v1[j]==0) { v1[j]=9 ; }
                else { v1[j]-- ; break ; }
            }
        }
    }
    if(c=='+') { if(c1=='-') { sign='-' ; } else { sign='+' ; } }
    else { if(c2=='-') { sign='-' ; } else { sign='+' ; } }
    for(auto &i:res) { num+= char (i+'0') ; }
}

BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt &num2)
{
    BigDecimalInt res("") ;                                                       // make new object to put the result in it
    if(snum.size()>num2.size()) { num2.resize(snum.size()-num2.size()) ; }        // put zeros if there is exist
    else if (num2.size()>snum.size()) { snum.resize(num2.size()-snum.size()) ; }  // put zeros if there is exist
    res.resize(num2.getvec().size()) ;                                              // make size of result same as first and second BigDecimalInt


    if(SIGN == num2.getsign())
    {
        sum(num,num2.getvec(),res.getvec(),res.getnum()) ;
        if(SIGN == '-') { res.setsign('-') ; } else { res.setsign('+') ; }
    }
    else
    {
        sub(num, num2.getvec(), res.getvec(), res.getsign(), SIGN, num2.getsign(), res.getnum()) ;
    }
    res.check() ;
    return res ;
}

BigDecimalInt BigDecimalInt :: operator - (BigDecimalInt &num2){
    vector<int> n1 (num);
    vector<int> n2 (num2.getvec());
    vector<int> n3,n4 ;
    char c; string s;
    BigDecimalInt result("") ;




    if ((SIGN == '+' and num2.getsign() == '+' )  or (SIGN == '-' and num2.getsign() == '-' )  ){
        if (n2.size()>n1.size()){
            for (int i= n1.size() -1 ; i<=0 ;i--  ){
                if (n2[i]< n1[i] ){
                    n3[i]=n2[i]+10 - n1[i];
                    n2[i-1]=n2[i-1]-1;
                }
                else {
                    n3[i]=n2[i]- n1[i];

                }
            }
            int x;   c ='-';
            for (int i=0; i < n2.size()-n1.size();i++ ){
                x= n2[i];
                n4.push_back(x);
            }

            for (int i=0; i < n3.size();i++ ){
                x= n3[i];
                n4.push_back(x);
            }


        }

        else if (n2.size()<n1.size()) {
            for (int i= n2.size() -1 ; i<=0 ;i--  ){
                if (n1[i]< n2[i] ){
                    n3[i]=n1[i]+10 - n2[i];
                    n1[i-1]=n1[i-1]-1;
                }
                else {
                    n3[i]=n1[i]- n2[i];

                }
            }

            int x;   c ='+';
            for (int i=0; i < n1.size()-n2.size();i++ ){
                x= n1[i];
                n4.push_back(x);
            }

            for (int i=0; i < n3.size();i++ ){
                x= n3[i];
                n4.push_back(x);
            }



        }

        else {
            if (n2>n1){
                for (int i= n1.size() -1 ; i<=0 ;i--  ){
                    if (n2[i]< n1[i] ){
                        n4[i]=n2[i]+10 - n1[i];
                        n2[i-1]=n2[i-1]-1;
                    }
                    else {
                        n4[i]=n2[i]- n1[i];

                    }
                }
                c ='-';

            }

            else {
                for (int i= n2.size() -1 ; i<=0 ;i--  ){
                    if (n1[i]< n2[i] ){
                        n4[i]=n1[i]+10 - n2[i];
                        n1[i-1]=n1[i-1]-1;
                    }
                    else {
                        n4[i]=n1[i]- n2[i];

                    }
                }

                c ='+';


            }
        }

    }

    else if ((SIGN == '+' and num2.getsign() == '-') or (SIGN == '-' and num2.getsign() == '+')  ){

        if (n2.size()>n1.size()){
            for (int i= n1.size() -1 ; i<=0 ;i--  ){
                if (n1[i]+n2[i]>9){
                    n3[i]=n1[i]+n2[i]-10;
                    n2[i-1]+=1;
                }
                else{
                    n3[i]=n1[i]+n2[i];

                }
            }
            int x;   c ='+';
            for (int i=0; i < n2.size()-n1.size();i++ ){
                x= n2[i];
                n4.push_back(x);
            }

            for (int i=0; i < n3.size();i++ ){
                x= n3[i];
                n4.push_back(x);
            }


        }

        else  {
            for (int i= n2.size() -1 ; i<=0 ;i--  ){
                if (n1[i]+n2[i]>9){
                    n3[i]=n1[i]+n2[i]-10;
                    n1[i-1]+=1;
                    if (i==0 and n2.size()==n1.size() )
                        n4.push_back(1);
                }
                else{
                    n3[i]=n1[i]+n2[i];

                }
            }

            int x;   c ='+';
            for (int i=0; i < n1.size()-n2.size();i++ ){
                x= n1[i];
                n4.push_back(x);
            }

            for (int i=0; i < n3.size();i++ ){
                x= n3[i];
                n4.push_back(x);
            }

        }




    }

    if (SIGN == '-' and num2.getsign() == '+'  ){
        c='-';
    }

    if (SIGN == '-' and num2.getsign() == '-'  ) {
        if (c=='+')
            c= '-';
        else
            c= '+';
    }


    result.setsign(c);
    result.setvector(n4);
    for(auto &i:n4) { s+= char (i+'0') ; }
    result.setnum(s);

    return result;



}

BigDecimalInt BigDecimalInt :: operator = (BigDecimalInt &num2)
{
    snum = num2.getstr();
    num = {0} ;
    for (int i = 0; i < num2.getvec().size(); ++i) { num[i] = num2.getvec()[i]; }
    SIGN = num2.getsign();
}

bool BigDecimalInt::operator>(BigDecimalInt num2) {
    if (SIGN == '+' and num2.getsign() == '-')
        return true;
    if (SIGN == '-' and num2.getsign() == '+')
        return false;
    if (SIGN == '+' and num2.getsign() == '+'){
        if (num.size() > num2.getvec().size())
            return true;
        else if (num.size() < num2.getvec().size())
            return false;
        else{
            for (int i = 0; i < num.size(); ++i) {
                if(num[i] > num2.getvec()[i])
                    return true;
                else if(num[i] < num2.getvec()[i])
                    return false;
            }
            return false;
        }
    }
    if (SIGN == '-' and num2.getsign() == '-'){
        if (num.size() < num2.getvec().size())
            return true;
        else if (num.size() > num2.getvec().size())
            return false;
        else{
            for (int i = 0; i < num.size(); ++i) {
                if(num[i] < num2.getvec()[i])
                    return true;
                else if(num[i] > num2.getvec()[i])
                    return false;
            }
            return false;
        }
    }

}

bool BigDecimalInt::operator<(BigDecimalInt num2){
    if (SIGN == '+' and num2.getsign() == '-')
        return false;
    else if (SIGN == '-' and num2.getsign() == '+')
        return true;
    else if (SIGN == '+' and num2.getsign() == '+'){
        if (num.size() > num2.getvec().size())
            return false;
        else if (num.size() < num2.getvec().size())
            return true;
        else{
            for (int i = 0; i < num.size(); ++i) {
                if(num[i] > num2.getvec()[i])
                    return false;
                else if(num[i] < num2.getvec()[i])
                    return true;
            }
            return false;
        }
    }
    if (SIGN == '-' and num2.getsign() == '-'){
        if (num.size() < num2.getvec().size())
            return false;
        else if (num.size() > num2.getvec().size())
            return true;
        else{
            for (int i = 0; i < num.size(); ++i) {
                if(num[i] < num2.getvec()[i])
                    return false;
                else if(num[i] > num2.getvec()[i])
                    return true;
            }
            return false;
        }
    }
}

bool BigDecimalInt::operator==(BigDecimalInt num2) {
    if (SIGN == '+' and num2.getsign() == '-')
        return false;
    if (SIGN == '-' and num2.getsign() == '+')
        return false;
    if (SIGN == '+' and num2.getsign() == '+'){
        if (num.size() > num2.getvec().size())
            return false;
        else if (num.size() < num2.getvec().size())
            return false;
        else{
            for (int i = 0; i < num.size(); ++i) {
                if(num[i] > num2.getvec()[i])
                    return false;
                else if(num[i] < num2.getvec()[i])
                    return false;
            }
            return true;
        }
    }
    if (SIGN == '-' and num2.getsign() == '-'){
        if (num.size() < num2.getvec().size())
            return false;
        else if (num.size() > num2.getvec().size())
            return false;
        else{
            for (int i = 0; i < num.size(); ++i) {
                if(num[i] < num2.getvec()[i])
                    return false;
                else if(num[i] > num2.getvec()[i])
                    return false;
            }
            return true;
        }
    }
}

int BigDecimalInt::sign() {
    if (SIGN == '+')
        return 1;
    else
        return 0;
}

ostream &operator<<(ostream &out, BigDecimalInt b) {
    if(b.SIGN == '+')
        out << b.snum;
    else if (b.SIGN == '-')
        out << '-'+b.snum;
    return out;
}
