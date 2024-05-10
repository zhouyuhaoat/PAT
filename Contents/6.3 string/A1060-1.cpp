/*
 *	author:		zhouyuhao
 *	created:	2024-05-04 09:17:00
 *	modified:	2024-05-04 09:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

string trans(string s, int n) {
	while (s[0] == '0' && s.size() > 1 && s[1] != '.') {
		s.erase(0, 1);
	}
	int dot = -1, nonZero = -1;
	for (int i = 0; i < (int)s.size() && (dot == -1 || nonZero == -1); i++) {
		if (s[i] == '.') {
			dot = i;
		} else if (nonZero == -1 && s[i] != '0') {
			nonZero = i;
		}
	}
	string num;
	int e = 0;
	if (nonZero != -1) {
		if (nonZero == 0) {
			if (dot != -1) {
				s.erase(dot, 1);
				e = dot;
			} else {
				e = s.size();
			}
		} else {
			e = dot - nonZero + 1;
		}
		num = s.substr(nonZero, n);
	}
	if ((int)num.size() < n) {
		num.append(n - num.size(), '0');
	}
	return "0." + num + "*10^" + to_string(e);
}

int main(int argc, char const *argv[]) {

	int n;
	string a, b;
	cin >> n >> a >> b;
	string sa = trans(a, n), sb = trans(b, n);
	if (sa == sb) {
		cout << "YES " << sa << "\n";
	} else {
		cout << "NO " << sa << " " << sb << "\n";
	}

	return 0;
}