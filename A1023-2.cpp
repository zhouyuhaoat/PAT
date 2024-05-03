/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:27:24
 *	modified:	2023-04-11 15:36:40
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string n1;
	cin >> n1;
	string n2;
	int carry = 0;
	for (int i = n1.size() - 1; i >= 0; i--) {
		int sum = (n1[i] - '0') * 2 + carry;
		n2 = to_string(sum % 10) + n2;
		carry = sum / 10;
	}
	if (carry != 0) {
		n2 = to_string(carry) + n2;
	}
	string n3 = n2;
	sort(n1.begin(), n1.end());
	sort(n3.begin(), n3.end());
	if (n1 == n3) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	cout << n2 << "\n";

	return 0;
}