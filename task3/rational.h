//
// Created by gorbatov on 03.04.16.
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <cstdio>
#include <cstdlib>

class rational{
private:
    bool positive;
    int num;
    int denom;

    int greatestCommonDivisor(int m, int n)
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

public:
    rational(){
        this -> positive = true;
        this -> num = 0;
        this -> denom = 0;
    }
    rational(int n){
        if (n < 0){
            this -> positive =false;
            this -> num = -n;
            this -> denom = 1;
        }
        else{
            this -> positive = true;
            this -> num = n;
            this -> denom = 1;
        }

    }
    rational(int n, int d){
        if ((n < 0) || (d < 0)) {
            this -> positive = false;
            if (n < 0) {
                this->num = -n;
                this->denom = d;
                int gcd = greatestCommonDivisor(num, denom);
                num = num / gcd;
                denom = denom / gcd;
            }
            else {
                this->num = n;
                this->denom = -d;
                int gcd = greatestCommonDivisor(num, denom);
                num = num / gcd;
                denom = denom / gcd;
            }

        } else {
            this -> positive = true;
            this->num = n;
            this->denom = d;
            int gcd = greatestCommonDivisor(num, denom);
            num = num / gcd;
            denom = denom / gcd;
        }

    }
    int getNum() const{
        if (this -> positive == false) return -num;
        return this -> num;
    }
    int getDenom() const {
        return this -> denom;
    }

    rational operator+(const rational& second) {
        rational result;
        if (this -> positive == true) {
            result.denom = this->denom * second.denom;
            int multi_first = result.denom / this->denom;
            int multi_sec = result.denom / second.denom;
            result.num = (this->num * multi_first) + (second.num * multi_sec);
            int gcd = greatestCommonDivisor(result.num, result.denom);
            int temp = result.num;
            result.num = temp / gcd;
            temp = result.denom;
            result.denom = temp / gcd;
        }
        if (this -> positive == false){
            result.positive = false;
            result.denom = this->denom * second.denom;
            int multi_first = result.denom / this->denom;
            int multi_sec = result.denom / second.denom;

        }
        return result;
    }

    rational operator- (const rational& second){
        rational result;
        result.denom = this -> denom * second.denom;
        int multi_first = result.denom / this -> denom;
        int multi_sec = result.denom / second.denom;
        result.num = (this -> num * multi_first) - (second.num * multi_sec);
        return  result;
    }

    rational operator* (const rational& frac){
        rational result;
        return  result;
    }

    rational operator/ (const rational& frac){
        rational result;
        return  result;
    }
};
#endif //RATIONAL_RATIONAL_H
