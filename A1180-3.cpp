/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 20:25:52
 *	modified:	2024-05-17 20:36:03
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> isprime;

void sieve(int n) {
	isprime.resize(n + 1, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isprime[j] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, maxp;
	cin >> n >> maxp;
	sieve(maxp);
	while (!isprime[maxp]) {
		--maxp;
	}
	if (n == 1) {
		cout << maxp << "\n";
		return 0;
	}
	int maxdif = -1, lastn = -1;
	for (int dif = maxp / (n - 1); dif >= 1; dif--) {
		bool isok = false;
		for (int e = maxp; e > maxp - dif; e--) {
			if (!isprime[e]) {
				continue;
			}
			bool flag = true;
			for (int i = 0; i < n; i++) {
				if (!isprime[e - i * dif]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				isok = true;
				maxdif = dif;
				lastn = e;
				break;
			}
		}
		if (isok) {
			break;
		}
	}
	if (maxdif != -1) {
		for (int i = n - 1; i >= 0; i--) {
			cout << lastn - i * maxdif;
			i > 0 ? cout << " " : cout << "\n";
		}
	} else {
		cout << maxp << "\n";
	}

	return 0;
}