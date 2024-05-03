/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 09:51:59
 *	modified:	2023-04-11 10:02:04
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	long double sum = 0;
	for (int i = 0; i < n; i++) {
		long double v;
		cin >> v;
		sum += v * (i + 1) * (n - i);
	}
	cout << fixed << setprecision(2) << sum << "\n";

	return 0;
}