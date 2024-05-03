/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:19:04
 *	modified:	2023-04-11 20:00:52
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int f = 1, l = 0;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		int t = 1;
		for (int j = i; j <= (int)sqrt(n); j++) {
			t *= j;
			if (n % t != 0) {
				break;
			}
			if (j - i + 1 > l) {
				l = j - i + 1;
				f = i;
			}
		}
	}
	if (l == 0) {
		cout << f << "\n" << n << "\n";
	} else {
		cout << l << "\n";
		for (int i = 0; i < l; i++) {
			cout << f + i;
			if (i < l - 1) {
				cout << "*";
			} else {
				cout << "\n";
			}
		}
	}

	return 0;
}