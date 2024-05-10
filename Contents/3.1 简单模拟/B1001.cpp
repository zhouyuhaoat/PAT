/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:08:18
 *	modified:	2023-03-22 11:11:50
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int count = 0;
	while (n != 1) {
		if (n % 2 != 0) {
			n = 3 * n + 1;
		}
		n = n >> 1;
		++count;
	}
	cout << count << "\n";

	return 0;
}