/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 15:32:00
 *	modified:	2024-04-27 15:35:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	string dl = "1814/09/05", dr = "2014/09/07";
	pair<string, string> o = {"", dr}, y = {"", dl};
	int count = 0;
	for (int i = 0; i < n; i++) {
		pair<string, string> t;
		cin >> t.first >> t.second;
		if (t.second > dl && t.second < dr) {
			count++;
			if (t.second > y.second) {
				y = t;
			}
			if (t.second < o.second) {
				o = t;
			}
		}
	}
	if (count != 0) {
		cout << count << " " << o.first << " " << y.first << "\n";
	} else {
		cout << count << "\n";
	}

	return 0;
}