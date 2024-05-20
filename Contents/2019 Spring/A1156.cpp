/*
 *	author:		zhouyuhao
 *	created:	2023-04-05 09:39:36
 *	modified:	2023-04-05 09:51:29
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <cmath>
#include <iostream>

using namespace std;

bool isprime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	if (isprime(n) && (isprime(n - 6) || isprime(n + 6))) {
		if (isprime(n - 6)) {
			cout << "Yes\n" << n - 6 << "\n";
		} else {
			cout << "Yes\n" << n + 6 << "\n";
		}
	} else {
		while (!(isprime(n) && (isprime(n - 6) || isprime(n + 6)))) {
			++n;
		}
		cout << "No\n" << n << "\n";
	}

	return 0;
}