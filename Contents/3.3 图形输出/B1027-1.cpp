/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 21:04:17
 *	modified:	2023-03-22 21:16:40
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
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
	int count = n;
	--count;
	int row = 1, col = 1;
	while (count >= 2 * (col + 2)) {
		col += 2;
		count -= 2 * col;
		++row;
	}
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
	cout << count << "\n";

	return 0;
}