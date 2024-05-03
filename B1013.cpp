/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 22:38:14
 *	modified:	2023-04-10 22:38:18
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e6;

vector<int> p;
vector<bool> isprime(maxn, true);
void sieve() {
	for (int i = 2; i < maxn; i++) {
		if (isprime[i]) {
			p.emplace_back(i);
			for (int j = 2 * i; j < maxn; j += i) {
				isprime[j] = false;
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	sieve();
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n - m + 1; i++) {
		cout << p[m - 1 + i];
		if ((i + 1) % 10 == 0) {
			cout << "\n";
		} else {
			if (i < n - m) {
				cout << " ";
			} else {
				cout << "\n";
			}
		}
	}

	return 0;
}