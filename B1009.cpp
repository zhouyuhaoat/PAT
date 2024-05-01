/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 11:51:38
 *	modified:	2023-03-22 11:55:15
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {

	stack<string> s;
	string w;
	while (cin >> w) {
		s.emplace(w);
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
		if (!s.empty()) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}