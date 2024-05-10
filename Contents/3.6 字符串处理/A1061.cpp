/*
 *	author:		zhouyuhao
 *	created:	2023-03-23 17:08:58
 *	modified:	2023-03-23 17:37:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string w[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = min(a.size(), b.size());
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
			cout << w[a[i] - 'A'] << " ";
			flag = i;
			break;
		}
	}
	for (int i = flag + 1; i < n; i++) {
		if (a[i] == b[i]) {
			if (isdigit(a[i])) {
				cout << setfill('0') << setw(2) << a[i] << ":";
				break;
			} else if (a[i] >= 'A' && a[i] <= 'N') {
				cout << a[i] - 'A' + 10 << ":";
				break;
			}
		}
	}
	int m = min(c.size(), d.size());
	for (int i = 0; i < m; i++) {
		if (c[i] == d[i] && isalpha(c[i])) {
			cout << setfill('0') << setw(2) << i << "\n";
			break;
		}
	}

	return 0;
}