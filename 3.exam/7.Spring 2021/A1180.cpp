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

vector<bool> sieve(int n) { // Sieve of Eratosthenes
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) { // multiples
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main(int argc, char const *argv[]) {

    int n, maxPrime;
    cin >> n >> maxPrime;
    vector<bool> isPrime = sieve(maxPrime);
    while (!isPrime[maxPrime]) {
        maxPrime--;
    }
    if (n == 1) {
        cout << maxPrime << "\n";
        return 0;
    }
    int maxDiff = -1, lastPrime = -1; // diff: difference
    for (int diff = maxPrime / (n - 1); diff >= 1; diff--) {
        bool ok = false; // flag to check if a valid sequence is found
        for (int end = maxPrime; end > maxPrime - diff; end--) { // end of the sequence
            if (!isPrime[end]) continue;
            bool flag = true; // flag to check if all elements are prime
            for (int i = 0; i < n; i++) {
                if (!isPrime[end - i * diff]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ok = true;
                maxDiff = diff, lastPrime = end;
                break;
            }
        }
        if (ok) break;
    }
    if (maxDiff != -1) {
        for (int i = n - 1; i >= 0; i--) {
            cout << lastPrime - i * maxDiff;
            i > 0 ? cout << " " : cout << "\n";
        }
    } else {
        cout << maxPrime << "\n";
    }

    return 0;
}
