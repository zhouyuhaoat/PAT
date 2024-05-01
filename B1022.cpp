/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:41:17
 *	modified:	2023-03-22 11:51:21
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

	int a, b, d;
	cin >> a >> b >> d;
	int c = a + b;
	stack<int> r;
	do {
		r.emplace(c % d);
		c /= d;
	} while (c != 0);
	while (!r.empty()) {
		cout << r.top();
		r.pop();
	}
	cout << "\n";

	return 0;
}