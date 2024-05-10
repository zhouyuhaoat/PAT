/*
 *	author:		zhouyuhao
 *	created:	2024-04-29 10:01:00
 *	modified:	2024-04-29 10:10:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	int now = 0, next = 0, sum = 0;
	cin >> next;
	while (cin >> next) {
		if (next > now) {
			sum += (next - now) * 6;
		} else {
			sum += (now - next) * 4;
		}
		sum += 5;
		now = next;
	}
	cout << sum << "\n";

	return 0;
}