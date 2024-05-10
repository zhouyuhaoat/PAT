/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 14:56:32
 *	modified:	2023-04-11 15:07:22
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <cmath>
#include <iostream>
#include <vector>

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
	while (n > 0) {
		int d;
		cin >> d;
		if (isprime(n)) {
			vector<int> t;
			while (n != 0) {
				t.emplace_back(n % d);
				n /= d;
			}
			int sum = 0, b = 1;
			for (int i = t.size() - 1; i >= 0; i--) {
				sum += t[i] * b;
				b *= d;
			}
			if (isprime(sum)) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			cout << "No\n";
		}
		cin >> n;
	}

	return 0;
}