/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 20:31:57
 *	modified:	2023-03-27 10:12:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	getchar();
	vector<string> s(n);
	int l = INT_MAX;
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
		reverse(s[i].begin(), s[i].end());
		l = min(l, (int)s[i].size());
	}
	string r;
	for (int i = 0; i < l; i++) {
		bool flag = true;
		for (int j = 1; j < n; j++) {
			if (s[j][i] != s[0][i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			r += s[0][i];
		} else {
			break;
		}
	}
	reverse(r.begin(), r.end());
	if (!r.empty()) {
		cout << r << "\n";
	} else {
		cout << "nai\n";
	}

	return 0;
}