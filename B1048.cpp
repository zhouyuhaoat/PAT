/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 18:58:44
 *	modified:	2023-03-23 19:25:11
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() > b.size()) {
		b.append(a.size() - b.size(), '0');
	} else {
		a.append(b.size() - a.size(), '0');
	}
	map<int, char> m = {{10, 'J'}, {11, 'Q'}, {12, 'K'}};
	for (int i = 0; i < (int)b.size(); i++) {
		int ai = a[i] - '0';
		int bi = b[i] - '0';
		if (i % 2 == 0) {
			int ci = (ai + bi) % 13;
			if (ci > 9) {
				b[i] = m[ci];
			} else {
				b[i] = ci + '0';
			}
		} else {
			int ci = bi - ai;
			if (ci < 0) {
				ci += 10;
			}
			b[i] = ci + '0';
		}
	}
	reverse(b.begin(), b.end());
	cout << b << "\n";

	return 0;
}