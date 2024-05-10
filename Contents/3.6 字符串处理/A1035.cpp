/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 20:07:58
 *	modified:	2023-03-23 20:29:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<vector<string>> s(n);
	vector<bool> f(n, false);
	int cnt = 0;
	map<char, char> m = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		bool flag = false;
		for (int j = 0; j < (int)b.size(); j++) {
			if (m.find(b[j]) != m.end()) {
				b[j] = m[b[j]];
				flag = true;
			}
		}
		s[i].emplace_back(a);
		s[i].emplace_back(b);
		if (flag) {
			f[i] = true;
			cnt++;
		}
	}
	if (cnt != 0) {
		cout << cnt << "\n";
		for (int i = 0; i < n; i++) {
			if (f[i]) {
				cout << s[i][0] << " " << s[i][1] << "\n";
			}
		}
	} else {
		if (s.size() == 1) {
			cout << "There is 1 account and no account is modified\n";
		} else {
			cout << "There are " << s.size() << " accounts and no account is modified\n";
		}
	}

	return 0;
}