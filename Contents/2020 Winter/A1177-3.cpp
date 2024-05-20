/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 14:31:06
 *	modified:	2024-05-17 14:56:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s, p;
	cin >> s >> p;
	int i = 0, j = 0;
	int le = 0, ri = 0, minl = INT_MAX;
	while (i < (int)s.size()) {
		if (s[i] == p[j]) {
			++j;
		}
		if (j == (int)p.size()) {
			ri = i;
			--j;
			while (j >= 0) {
				if (s[i] == p[j]) {
					--j;
				}
				--i;
			}
			++i;
			if (ri - i + 1 < minl) {
				le = i;
				minl = ri - le + 1;
			}
			j = 0;
		}
		++i;
	}
	cout << s.substr(le, minl) << "\n";

	return 0;
}