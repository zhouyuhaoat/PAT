/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 13:17:00
 *	modified:	2024-05-04 13:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	getline(cin, s);
	map<string, int> count;
	string t;
	int cnt = -1;
	for (int i = 0; i < (int)s.size(); i++) {
		if (isalnum(s[i])) {
			t += tolower(s[i]);
		}
		if (!isalnum(s[i]) || i == (int)s.size() - 1) {
			if (!t.empty() && ++count[t] > cnt) {
				cnt = count[t];
			}
			t = "";
		}
	}
	for (auto it : count) {
		if (it.second == cnt) {
			cout << it.first << " " << cnt << "\n";
			break;
		}
	}

	return 0;
}