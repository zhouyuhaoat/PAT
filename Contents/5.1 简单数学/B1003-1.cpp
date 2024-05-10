/*
 *	author:		zhouyuhao
 *	created:	2023-04-10 21:51:01
 *	modified:	2023-04-10 22:17:14
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		string s;
		cin >> s;
		bool flag = true;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T') {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
			continue;
		}
		int ip = -1;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'P') {
				ip = i;
				break;
			}
		}
		int it = -1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 'T') {
				it = i;
				break;
			}
		}
		for (int i = ip + 1; i < it; i++) {
			if (s[i] == 'P' || s[i] == 'T') {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
			continue;
		}
		int la = ip, ma = it - ip - 1, ra = s.size() - it - 1;
		if (ra == la * ma && it - ip > 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}