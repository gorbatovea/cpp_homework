#include "rational.h"

int rational::greatestCommonDivisor(int n, int d) const{
    if (n < 0) {
        n = -n;
        return gcd(n,d); }
    if (d < 0) {
        d = -d;
        return gcd(n,d);
    }
    return gcd(n,d);
}

rational::rational(){
    num = 0;
    denom = 0;
}
rational::rational(int n){
    num = n;
    denom = 1;
}
rational::rational(int n, int d){
    num = n;
    denom =d;
    if ((denom < 0) && (num > 0)) {
        num = -num;
        denom = -denom;
    }
    int gcd = greatestCommonDivisor(num, denom);
    num = num / gcd;
    denom = denom / gcd;
}

int rational::getNum() const{
    return num;
}

int rational::getDenom() const {
    return denom;
}

rational rational::operator+(const rational& second) const{
    rational result;
    result.denom = this -> denom * second.denom;
    int multi_first = result.denom / this -> denom;
    int multi_sec = result.denom / second.denom;
    result.num = (this -> num * multi_first) + (second.num * multi_sec);
    int gcd = greatestCommonDivisor(result.num , result.denom);
    int temp = result.num; result.num = temp / gcd;
    temp = result.denom; result.denom = temp / gcd;
    return result;
}

rational rational::operator- (const rational& second) const{
    rational result;
    result.denom = this -> denom * second.denom;
    int multi_first = result.denom / this -> denom;
    int multi_sec = result.denom / second.denom;
    result.num = (this -> num * multi_first) - (second.num * multi_sec);
    int gcd = greatestCommonDivisor(result.num , result.denom);
    int temp = result.num; result.num = temp / gcd;
    temp = result.denom; result.denom = temp / gcd;
    return result;
}

rational rational::operator* (const rational& second) const{
    rational result;
    result.denom = this -> denom * second.denom;
    result.num = this -> num * second.num;
    int gcd = greatestCommonDivisor(result.num,result.denom);
    result.num = result.num / gcd;
    result.denom = result.denom /gcd;
    return  result;
}

rational rational::operator/ (const rational& second) const{
    rational result;
    result.num = second.denom;
    result.denom = second.num;
    result = result * *this;
    return  result;
}