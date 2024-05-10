/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 10:47:08
 *	modified:	2023-03-26 11:10:32
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end(), [](string a, string b) {
		return a + b < b + a;
	});
	string r;
	for (auto it : s) {
		r += it;
	}
	while (r.size() > 1 && r[0] == '0') {
		r.erase(0, 1);
	}
	cout << r << "\n";

	return 0;
}