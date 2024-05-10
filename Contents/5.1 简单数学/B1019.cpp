/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 14:22:28
 *	modified:	2023-03-27 10:16:29
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string n;
	cin >> n;
	n.insert(0, 4 - n.size(), '0');
	do {
		string min = n, max = n;
		sort(min.begin(), min.end());
		sort(max.rbegin(), max.rend());
		n = to_string(stoi(max) - stoi(min));
		n.insert(0, 4 - n.size(), '0');
		cout << max << " - " << min << " = " << n << "\n";
	} while (n != "6174" && n != "0000");

	return 0;
}