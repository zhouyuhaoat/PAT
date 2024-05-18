/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 20:37:52
 *	modified:	2024-05-17 20:41:03
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> notprime;

void sieve(int n) {
	notprime.resize(n + 1);
	notprime[0] = notprime[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!notprime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				notprime[j] = 1;
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, maxp;
	cin >> n >> maxp;
	sieve(maxp);
	while (notprime[maxp]) {
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
			if (notprime[e]) {
				continue;
			}
			bool flag = true;
			for (int i = 0; i < n; i++) {
				if (notprime[e - i * dif]) {
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