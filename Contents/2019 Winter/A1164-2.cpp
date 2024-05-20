/*
 *	author:		zhouyuhao
 *	created:	2024-05-16 21:40:52
 *	modified:	2024-05-16 22:00:13
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	vector<vector<string>> l(26, vector<string>(7));
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> l[i][j];
		}
	}
	string t;
	getchar();
	getline(cin, t);
	vector<string> w;
	for (int i = 0; i < (int)t.size(); i++) {
		int j = i;
		while (!isupper(t[j]) && j < (int)t.size()) {
			++j;
		}
		i = j;
		while (isupper(t[j]) && j < (int)t.size()) {
			++j;
		}
		if (i != j) {
			w.emplace_back(t.substr(i, j - i));
		}
		i = j - 1;
	}
	for (int i = 0; i < (int)w.size(); i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < (int)w[i].size(); k++) {
				cout << l[w[i][k] - 'A'][j];
				k < (int)w[i].size() - 1 ? cout << " " : cout << "\n";
			}
		}
		if (i < (int)w.size() - 1) {
			cout << "\n";
		}
	}

	return 0;
}