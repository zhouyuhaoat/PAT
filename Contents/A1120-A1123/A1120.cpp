/*
 *	author:		zhouyuhao
 *	created:	2023-04-03 01:51:08
 *	modified:	2023-04-03 01:55:56
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <set>

using namespace std;

int trans(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	set<int> ans;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		ans.emplace(trans(num));
	}
	int size = ans.size();
	cout << size << "\n";
	for (auto it : ans) {
		cout << it;
		--size > 0 ? cout << " " : cout << "\n";
	}

	return 0;
}