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

    int greatestCommonDivisor(int n, int d) const;

public:
    rational();
    rational(int n);
    rational(int n, int d);

    int getNum() const;
    int getDenom() const;

    rational operator+(const rational& second) const;

    rational operator- (const rational& second) const;

    rational operator* (const rational& second) const;

    rational operator/ (const rational& second) const;
};
#endif //RATIONAL_RATIONAL_H
