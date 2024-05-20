/*
 *	author:		zhouyuhao
 *	created:	2024-05-17 15:44:06
 *	modified:	2024-05-17 15:45:17
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s, p;
	cin >> s >> p;
	int sta = 0, minl = 10001;
	for (int i = 0; i <= (int)s.size() - (int)p.size(); i++) {
		if (s[i] == p[0]) {
			int k = 0;
			for (int j = i; j < (int)s.size(); j++) {
				if (j - i + 1 >= minl) {
					break;
				}
				if (s[j] == p[k]) {
					k++;
					if (k == (int)p.size() && j - i + 1 < minl) {
						sta = i;
						minl = j - i + 1;
					}
				}
			}
		}
	}
	cout << s.substr(sta, minl) << "\n";

	return 0;
}