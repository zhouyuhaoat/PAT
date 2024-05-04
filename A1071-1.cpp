/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 22:33:18
 *	modified:	2023-03-26 23:18:02
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	getline(cin, s);
	for (int i = 0; i < (int)s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	map<string, int> count;
	int i = 0, j = 0, cnt = -1;
	while (i < (int)s.size() && j < (int)s.size()) {
		if (isalnum(s[i])) {
			j = i;
			while (j < (int)s.size() && isalnum(s[j])) {
				++j;
			}
			string w = s.substr(i, j - i);
			if (++count[w] > cnt) {
				cnt = count[w];
			}
			i = j;
		} else {
			++i;
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