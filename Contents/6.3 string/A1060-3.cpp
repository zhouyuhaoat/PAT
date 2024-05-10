/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 16:18:57
 *	modified:	2023-03-27 19:56:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

string erase0(string s) {
	while (s[0] == '0' && s.size() > 1 && s[1] != '.') {
		s.erase(0, 1);
	}
	return s;
}

string erasep(string s) {
	size_t p = s.find('.');
	if (p != string::npos) {
		s.erase(p, 1);
	}
	return s;
}

bool iszero(string s) {
	s = erasep(s);
	if (stoi(s) == 0) {
		return true;
	}
	return false;
}

string substr(string s, int n) {
	s = erasep(s);
	s = erase0(s);
	if ((int)s.size() < n) {
		s.append(n - s.size(), '0');
	}
	return s.substr(0, n);
}

int magnitude(string s) {
	s = erase0(s);
	int count = 0;
	if (s[0] != '0') {
		for (int i = 0; i < (int)s.size() && s[i] != '.'; i++) {
			++count;
		}
	} else if (!iszero(s)) {
		for (int i = 2; i < (int)s.size() && s[i] == '0'; i++) {
			--count;
		}
	}
	return count;
}

int main(int argc, char const *argv[]) {

	int n;
	string s[2];
	cin >> n >> s[0] >> s[1];
	int m[2];
	string subs[2];
	for (int i = 0; i < 2; i++) {
		m[i] = magnitude(s[i]);
		subs[i] = substr(s[i], n);
	}
	bool flag = false;
	if (m[0] == m[1] && subs[0] == subs[1]) {
		flag = true;
	}
	if (flag) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	for (int i = 0; i < 2; i++) {
		cout << " 0." << subs[i] << "*10^" << m[i];
		if (flag && i == 0) {
			break;
		}
	}
	cout << "\n";

	return 0;
}