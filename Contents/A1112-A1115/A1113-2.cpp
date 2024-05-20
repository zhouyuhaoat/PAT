/*
 *	author:		zhouyuhao
 *	created:	2023-04-14 10:16:08
 *	modified:	2023-04-14 10:22:51
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<int> d(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		sum += d[i];
	}
	nth_element(d.begin(), d.begin() + n / 2, d.end());
	int suml = 0;
	for (int i = 0; i < n / 2; i++) {
		suml += d[i];
	}
	cout << n % 2 << " " << sum - 2 * suml << "\n";

	return 0;
}