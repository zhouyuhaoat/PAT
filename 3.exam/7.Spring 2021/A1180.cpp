/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:07:48
 *	modified:	2023-04-13 22:12:05
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1180 Arithmetic Progression of Primes
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> isprime;

void sieve(int n) { // Sieve of Eratosthenes
    isprime.resize(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j <= n; j += i) { // multiples
                isprime[j] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, maxp; // maximum prime
    cin >> n >> maxp;
    sieve(maxp);
    while (!isprime[maxp]) {
        maxp--;
    }
    if (n == 1) {
        cout << maxp << "\n";
        return 0;
    }
    int maxdif = -1, lastp = -1; // dif: difference; p: prime
    for (int dif = maxp / (n - 1); dif >= 1; dif--) {
        bool isok = false; // flag to check if a valid sequence is found
        for (int e = maxp; e > maxp - dif; e--) { // end of the sequence
            if (!isprime[e]) continue;
            bool flag = true; // flag to check if all elements are prime
            for (int i = 0; i < n; i++) {
                if (!isprime[e - i * dif]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                isok = true;
                maxdif = dif, lastp = e;
                break;
            }
        }
        if (isok) break;
    }
    if (maxdif != -1) {
        for (int i = n - 1; i >= 0; i--) {
            cout << lastp - i * maxdif;
            i > 0 ? cout << " " : cout << "\n";
        }
    } else {
        cout << maxp << "\n";
    }

    return 0;
}