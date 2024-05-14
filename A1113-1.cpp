/*
 *	author:		zhouyuhao
 *	created:	2023-04-02 09:54:07
 *	modified:	2023-04-02 10:20:46
 *	item:		Programming Ability Test
 *	site:		Yuting
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
	sort(d.begin(), d.end());
	int suml = 0;
	for (int i = 0; i <= n / 2 - 1; i++) {
		suml += d[i];
	}
	cout << n % 2 << " " << sum - 2 * suml << "\n";

	return 0;
}