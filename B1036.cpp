/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:29:56
 *	modified:	2023-03-22 11:40:26
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	char c;
	cin >> n >> c;
	int col = n, row = n / 2.0 + 0.5;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j == 0 || j == col - 1 || i == 0 || i == row - 1) {
				cout << c;
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}