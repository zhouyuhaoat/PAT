/*
 *	author:		zhouyuhao
 *	created:	2025-05-12 20:10:46
 *	modified:	2025-05-12 20:16:46
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */

/*
    @pintia psid=994805260223102976 pid=994805287624491008 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1034 有理数四则运算
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805287624491008
*/

// @pintia code=start
#include <cstdint>
#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
private:
    int64_t numerator, denominator;

    void simplify() {
        int64_t gcd = std::gcd(numerator, denominator); // gcd(0, x) = x
        numerator /= gcd, denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator, denominator = -denominator;
        }
    }

public:
    Fraction(int64_t num = 0, int64_t denom = 1) : numerator(num), denominator(denom) {
        simplify();
    }

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) { // left-hand side; right-hand side
        int64_t gcd = std::gcd(lhs.denominator, rhs.denominator);
        int64_t lcm = lhs.denominator / gcd * rhs.denominator; // Least Common Multiple
        int64_t num = lhs.numerator * (lcm / lhs.denominator) + rhs.numerator * (lcm / rhs.denominator);
        return Fraction(num, lcm);
    }

    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
        int64_t gcd = std::gcd(lhs.denominator, rhs.denominator);
        int64_t lcm = lhs.denominator / gcd * rhs.denominator;
        int64_t num = lhs.numerator * (lcm / lhs.denominator) - rhs.numerator * (lcm / rhs.denominator);
        return Fraction(num, lcm);
    }

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
        int64_t num = lhs.numerator * rhs.numerator;
        int64_t denom = lhs.denominator * rhs.denominator;
        return Fraction(num, denom);
    }

    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
        int64_t num = lhs.numerator * rhs.denominator;
        int64_t denom = lhs.denominator * rhs.numerator;
        return Fraction(num, denom);
    }

    friend istream& operator>>(istream& is, Fraction& fraction) {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        fraction.simplify();
        return is;
    }

    string toString() const {
        if (denominator == 0) {
            return "Inf";
        }
        string format;
        if (denominator == 1) { // integer (numerator % denominator = 0), including 0 (numerator = 0)
            format += to_string(numerator);
        } else if (abs(numerator) > denominator) { // improper fraction
            format += to_string(numerator / denominator) + " ";
            format += to_string(abs(numerator) % denominator) + "/" + to_string(denominator);
        } else { // proper fraction
            format += to_string(numerator) + "/" + to_string(denominator);
        }
        return numerator < 0 ? "(" + format + ")" : format;
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.toString();
        return os;
    }
};

int main(int argc, char const *argv[]) {

    Fraction a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << "\n";
    cout << a << " - " << b << " = " << a - b << "\n";
    cout << a << " * " << b << " = " << a * b << "\n";
    cout << a << " / " << b << " = " << a / b << "\n";

    return 0;
}
// @pintia code=end
