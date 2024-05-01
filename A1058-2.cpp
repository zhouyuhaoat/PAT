/*
 *	author:		zhouyuhao
 *	created:	2024-04-27 15:55:00
 *	modified:	2024-04-27 15:59:00
 *	item:		Programming Ability Test
 *	site:		226, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int a1, a2, a3;
	int unused __attribute__((unused));
	unused = scanf("%d.%d.%d", &a1, &a2, &a3);
	int b1, b2, b3;
	unused = scanf("%d.%d.%d", &b1, &b2, &b3);
	int c1, c2, c3;
	c3 = a3 + b3;
	c2 = a2 + b2 + c3 / 29, c3 %= 29;
	c1 = a1 + b1 + c2 / 17, c2 %= 17;
	cout << c1 << "." << c2 << "." << c3 << "\n";

	return 0;
}