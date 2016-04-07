//
// Created by gorbatov on 03.04.16.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H
class rational{
private:
    int num;
    int denom;

    int gcd(int m, int n) const
    {
        int r;
        if((m == 0) || (n == 0))
            return 0;
        else if((m < 0) || (n < 0))
            return -1;

        do
        {
            r = m % n;
            if(r == 0)
                break;
            m = n;
            n = r;
        }
        while(true);

        return n;
    }

    int greatestCommonDivisor(int n, int d) const{
        if (n < 0) {
            n = -n;
            return gcd(n,d); }
        if (d < 0) {
            d = -d;
            return gcd(n,d);
        }
        return gcd(n,d);
    };

public:
    rational(){
        this -> num = 0;
        this -> denom = 0;
    }
    rational(int n){
        this -> num = n;
        this -> denom = 1;
    }
    rational(int n, int d){
        this -> num = n;
        this -> denom =d;
        if ((denom < 0) && (num > 0)) {
            num = -num;
            denom = -denom;
        }
        int gcd = greatestCommonDivisor(num, denom);
        num = num / gcd;
        denom = denom / gcd;
    }

    int getNum() const{
        return this -> num;
    }
    int getDenom() const {
        return this -> denom;
    }

    rational operator+(const rational& second) const{
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

    rational operator- (const rational& second) const{
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

    rational operator* (const rational& second) const{
        rational result;
        result.denom = this -> denom * second.denom;
        result.num = this -> num * second.num;
        int gcd = greatestCommonDivisor(result.num,result.denom);
        result.num = result.num / gcd;
        result.denom = result.denom /gcd;
        return  result;
    }

    rational operator/ (const rational& second) const{
        rational result;
        result.num = second.denom;
        result.denom = second.num;
        result = result * *this;
        return  result;
    }
};
#endif //RATIONAL_RATIONAL_H
