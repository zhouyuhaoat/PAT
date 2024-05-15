/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 13:53:09
 *	modified:	2023-04-04 12:57:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string d;
	int n;
	cin >> d >> n;
	for (int q = 0; q < n - 1; q++) {
		string s;
		for (int i = 0; i < (int)d.size(); i++) {
			int j = i, cnt = 0;
			while (d[j] == d[i] && j++ < (int)d.size()) {
				++cnt;
			}
			i = j - 1;
			s += d[i] + to_string(cnt);
		}
		d = s;
	}
	cout << d << "\n";

	return 0;
}