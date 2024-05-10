/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 13:09:11
 *	modified:	2023-03-25 13:53:59
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, idx;
	cin >> n >> idx;
	vector<vector<string>> s(n, vector<string>(3));
	for (int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}
	sort(s.begin(), s.end(), [idx](vector<string> a, vector<string> b) -> bool {
		switch (idx) {
		case 2:
			if (a[1] != b[1]) {
				return a[1] < b[1];
			}
		default:
			return a[0] < b[0];
		case 3:
			return stoi(a[2]) < stoi(b[2]);
		}
	});
	for (auto it : s) {
		cout << it[0] << " " << it[1] << " " << it[2] << "\n";
	}

	return 0;
}