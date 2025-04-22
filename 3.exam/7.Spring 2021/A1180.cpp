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

vector<bool> isPrime;

void sieve(int n) { // Sieve of Eratosthenes
    isPrime.resize(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) { // multiples
                isPrime[j] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    int n, maxP; // maximum prime
    cin >> n >> maxP;
    sieve(maxP);
    while (!isPrime[maxP]) {
        maxP--;
    }
    if (n == 1) {
        cout << maxP << "\n";
        return 0;
    }
    int maxDif = -1, lastP = -1; // dif: difference; p: prime
    for (int dif = maxP / (n - 1); dif >= 1; dif--) {
        bool ok = false; // flag to check if a valid sequence is found
        for (int e = maxP; e > maxP - dif; e--) { // end of the sequence
            if (!isPrime[e]) continue;
            bool flag = true; // flag to check if all elements are prime
            for (int i = 0; i < n; i++) {
                if (!isPrime[e - i * dif]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ok = true;
                maxDif = dif, lastP = e;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    if (maxDif != -1) {
        for (int i = n - 1; i >= 0; i--) {
            cout << lastP - i * maxDif;
            i > 0 ? cout << " " : cout << "\n";
        }
    } else {
        cout << maxP << "\n";
    }

    return 0;
}
