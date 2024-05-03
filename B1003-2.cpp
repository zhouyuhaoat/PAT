/*
 *	author:		zhouyuhao
 *	created:	2024-04-29 10:01:00
 *	modified:	2024-04-29 10:10:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		string s;
		cin >> s;
		map<char, int> cnt;
		int ip = -1, it = -1;
		for (int i = 0; i < (int)s.size(); i++) {
			++cnt[s[i]];
			if (s[i] == 'P') {
				ip = i;
			} else if (s[i] == 'T') {
				it = i;
			}
		}
		if (cnt['P'] == 1 && cnt['A'] != 0 && cnt['T'] == 1 && cnt.size() == 3) {
			int la = ip, ma = it - ip - 1, ra = s.size() - it - 1;
			if (it - ip > 1 && la * ma == ra) {
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}

	return 0;
}