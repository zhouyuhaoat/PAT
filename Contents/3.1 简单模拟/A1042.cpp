/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 17:32:07
 *	modified:	2023-03-22 18:50:23
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

	int k;
	cin >> k;
	int n = 55;
	vector<int> order(n);
	for (int i = 1; i < n; i++) {
		cin >> order[i];
	}
	vector<int> result(n);
	iota(result.begin(), result.end(), 0);
	for (int i = 0; i < k; i++) {
		vector<int> temp = result;
		for (int j = 1; j < n; j++) {
			result[order[j]] = temp[j];
		}
	}
	char card[5] = {'S', 'H', 'C', 'D', 'J'};
	for (int i = 1; i < n; i++) {
		cout << card[(result[i] - 1) / 13];
		if (result[i] % 13 == 0) {
			cout << 13;
		} else {
			cout << result[i] % 13;
		}
		if (i < n - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}