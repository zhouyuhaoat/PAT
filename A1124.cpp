/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 02:45:36
 *	modified:	2023-04-03 02:54:28
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {

	int m, n, st;
	cin >> m >> n >> st;
	int cnt = 0;
	bool nowin = true;
	map<string, bool> iswin;
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		if (i >= st && !iswin[s]) {
			if (cnt % n == 0) {
				cout << s << "\n";
				nowin = false;
				iswin[s] = true;
			}
			++cnt;
		}
	}
	if (nowin) {
		cout << "Keep going...\n";
	}

	return 0;
}