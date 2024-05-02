/*
 *	author:		zhouyuhao
 *	created:	2023-03-26 20:57:47
 *	modified:	2023-03-26 21:06:55
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int i = 0, j = n - 1;
	while (i < n && j > i) {
		if (d[i] + d[j] > m) {
			j--;
		} else if (d[i] + d[j] < m) {
			i++;
		} else {
			cout << d[i] << " " << d[j] << "\n";
			return 0;
		}
	}
	cout << "No Solution\n";

	return 0;
}