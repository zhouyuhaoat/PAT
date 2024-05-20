/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 15:13:36
 *	modified:	2023-04-14 15:22:57
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int ans = 0, minad = INT_MAX;
	int f = 1, g = 0;
	while (g < 2 * n) {
		g += f;
		f = g - f;
		if (abs(g - n) < minad) {
			minad = abs(g - n);
			ans = g;
		}
	}
	cout << ans << "\n";

	return 0;
}