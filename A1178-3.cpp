/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 16:55:06
 *	modified:	2024-05-17 16:59:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	string r;
	cin >> n >> r;
	getchar();
	map<string, string> p;
	p[r] = r;
	map<int, string> level;
	level[0] = r;
	for (int i = 1; i < n; i++) {
		string s;
		getline(cin, s);
		int l = 0;
		while (isspace(s[l])) {
			++l;
		}
		s = s.substr(l);
		p[s] = level[l - 1];
		level[l] = s;
	}
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		string s;
		cin >> s;
		if (p.find(s) == p.end()) {
			cout << "Error: " << s << " is not found.\n";
		} else {
			string ans;
			while (s != r) {
				ans = "->" + s + ans;
				s = p[s];
			}
			cout << r << ans << "\n";
		}
	}

	return 0;
}