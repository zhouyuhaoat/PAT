/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 19:59:19
 *	modified:	2023-03-23 20:07:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string n;
	cin >> n;
	int s = 0;
	for (auto i : n) {
		s += i - '0';
	}
	string r = to_string(s);
	string w[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (int i = 0; i < (int)r.size(); i++) {
		cout << w[(r[i] - '0')];
		if (i < (int)r.size() - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}