/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 20:39:06
 *	modified:	2023-04-14 20:42:25
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s, p;
	cin >> s >> p;
	int minl = INT_MAX;
	string ans;
	for (int i = 0; i <= (int)s.size(); i++) {
		if (s[i] == p[0]) {
			int k = 0;
			for (int j = i; j < (int)s.size(); j++) {
				if (s[j] == p[k]) {
					++k;
					if (k == (int)p.size() && j - i + 1 < minl) {
						minl = j - i + 1;
						ans = s.substr(i, minl);
					}
				}
			}
		}
	}
	cout << ans << "\n";

	return 0;
}