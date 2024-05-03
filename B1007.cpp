/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 22:17:26
 *	modified:	2023-04-10 22:23:36
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
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (isprime(i) && isprime(i - 2)) {
			++cnt;
		}
	}
	cout << cnt << "\n";

	return 0;
}