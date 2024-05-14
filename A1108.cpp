/*
 *	author:		zhouyuhao
 *	created:	2023-04-01 19:46:31
 *	modified:	2023-04-01 20:09:12
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iomanip>
#include <iostream>

using namespace std;

bool islaw(string s) {
	string t = s;
	size_t p = s.find('.');
	if (p != string::npos) {
		s.erase(p, 1);
	}
	if (s[0] == '-') {
		s.erase(0, 1);
	}
	for (auto it : s) {
		if (!isdigit(it)) {
			return false;
		}
	}
	double n = stod(t);
	if (n < -1000 || n > 1000) {
		return false;
	}
	if (p != string::npos && t.size() - p > 3) {
		return false;
	}
	return true;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (!islaw(s)) {
			cout << "ERROR: " << s << " is not a legal number\n";
		} else {
			++cnt;
			sum += stod(s);
		}
	}
	if (cnt == 0) {
		cout << "The average of 0 numbers is Undefined\n";
	} else if (cnt == 1) {
		cout << "The average of " << cnt << " number is " << fixed << setprecision(2) << sum / cnt << "\n";
	} else {
		cout << "The average of " << cnt << " numbers is " << fixed << setprecision(2) << sum / cnt << "\n";
	}

	return 0;
}