/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 18:30:00
 *	modified:	2024-04-27 18:35:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <cmath>
#include <iostream>

using namespace std;

void print(int n, char ch) {
	for (int i = 0; i < n; i++) {
		cout << ch;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	char ch;
	cin >> n >> ch;
	int col = (int)sqrt(2 * (n + 1)) - 1;
	if (col % 2 == 0) {
		--col;
	}
	int row = (col + 1) >> 1;
	for (int i = 0; i < row; i++) {
		print(i, ' '), print(col, ch);
		col -= 2;
		cout << "\n";
	}
	col += 2;
	for (int i = row - 2; i >= 0; i--) {
		col += 2;
		print(i, ' '), print(col, ch);
		cout << "\n";
	}
	cout << n - (col + 1) * row + 1 << "\n";

	return 0;
}