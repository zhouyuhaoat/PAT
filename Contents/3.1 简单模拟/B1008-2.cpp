/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 13:57:00
 *	modified:	2024-04-27 14:00:00
 *	item:		Programming Ability Test
 *	site:		Harbin
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	m %= n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.begin() + n - m);
	reverse(a.begin() + n - m, a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}