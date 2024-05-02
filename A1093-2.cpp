/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 19:00:00
 *	modified:	2024-04-28 19:30:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string s;
	cin >> s;
	int countT = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'T') {
			++countT;
		}
	}
	int countP = 0, res = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		switch (s[i]) {
		case 'P':
			++countP;
			break;
		case 'A':
			res += countP * countT;
			res %= 1000000007;
			break;
		case 'T':
			--countT;
			break;
		}
	}
	cout << res << "\n";

	return 0;
}