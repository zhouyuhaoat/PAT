/*
 *	author:		zhouyuhao
 *	created:	2024-05-02 19:29:46
 *	modified:	2024-05-02 19:41:46
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	m %= n;
	if (m != 0) {
		int g = gcd(n, m);
		for (int i = n - m; i < n - m + g; i++) {
			int now = i;
			do {
				int next = (now - m + n) % n;
				if (next != i) {
					swap(d[now], d[next]);
				}
				now = next;
			} while (now != i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << d[i];
		if (i < n - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}