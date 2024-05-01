/*
 *	author:		zhouyuhao
 *	created:	2024-05-01 16:10:00
 *	modified:	2024-05-01 16:10:10
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <iostream>

using namespace std;

struct peo {
	string name;
	int y, m, d;
};

bool younger(peo a, peo b, bool flag) {
	if (a.y != b.y) {
		return a.y > b.y;
	} else if (a.m != b.m) {
		return a.m > b.m;
	} else if (a.d != b.d) {
		return a.d > b.d;
	}
	return flag;
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	peo o = {"", 2014, 9, 7}, y = {"", 1814, 9, 5};
	peo l = y, r = o;
	int count = 0;
	for (int i = 0; i < n; i++) {
		peo temp;
		cin >> temp.name;
		int unused __attribute__((unused));
		unused = scanf("%d/%d/%d", &temp.y, &temp.m, &temp.d);
		if (younger(temp, l, false) && !younger(temp, r, true)) {
			count++;
			if (younger(temp, y, false)) {
				y = temp;
			}
			if (!younger(temp, o, true)) {
				o = temp;
			}
		}
	}
	if (count != 0) {
		cout << count << " " << o.name << " " << y.name << "\n";
	} else {
		cout << count << "\n";
	}

	return 0;
}