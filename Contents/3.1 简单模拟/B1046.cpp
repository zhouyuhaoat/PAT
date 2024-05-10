/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:23:39
 *	modified:	2023-03-22 16:28:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int ca = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		int a, aa, b, bb;
		cin >> a >> aa >> b >> bb;
		int c = a + b;
		if (aa == c && bb != c) {
			++cb;
		} else if (aa != c && bb == c) {
			++ca;
		}
	}
	cout << ca << " " << cb << "\n";

	return 0;
}