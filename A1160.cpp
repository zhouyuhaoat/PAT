/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 19:28:28
 *	modified:	2023-04-05 21:55:49
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <cmath>
#include <iostream>

using namespace std;

bool isprime(int n) {
	if (n <= 2) {
		return false;
	}
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int getsum(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		int k, m;
		cin >> k >> m;
		cout << "Case " << q + 1 << "\n";
		bool flag = false;
		for (int i = 3; i < m; i++) {
			if (isprime(gcd(m, i))) {
				if ((m - i + 1) % 9 == 0) {
					int rc = (m - i + 1) / 9;
					string suffix = string(rc, '9');
					int lc = k - rc;
					int sum = m - rc * 9;
					if (sum >= 1 && sum <= lc * 9) {
						int lj = pow(10, lc - 1), rj = lj * 10 - 1;
						for (int j = lj; j <= rj; j++) {
							if (getsum(j) == sum && j % 10 != 9) {
								cout << i << " " << j << suffix << "\n";
								flag = true;
							}
						}
					}
				}
			}
		}
		if (!flag) {
			cout << "No Solution\n";
		}
	}

	return 0;
}