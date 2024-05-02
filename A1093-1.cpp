/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 14:03:16
 *	modified:	2023-03-22 14:19:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	vector<int> cp(s.size());
	int countP = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'A') {
			cp[i] = countP;
		} else if (s[i] == 'P') {
			++countP;
		}
	}
	vector<int> ct(s.size());
	int countT = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'A') {
			ct[i] = countT;
		} else if (s[i] == 'T') {
			++countT;
		}
	}
	long result = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		result += cp[i] * ct[i];
	}
	cout << result % 1000000007 << "\n";

	return 0;
}