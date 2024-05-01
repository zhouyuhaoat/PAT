/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:42:45
 *	modified:	2023-03-31 16:20:52
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

struct peo {
	string name;
	int y, m, d;
};

bool islaw(peo a) {
	if (a.y > 1814 && a.y < 2014) {
		return true;
	} else if (a.y == 1814) {
		if (a.m > 9 || (a.m == 9 && a.d >= 6)) {
			return true;
		}
	} else if (a.y == 2014) {
		if (a.m < 9 || (a.m == 9 && a.d <= 6)) {
			return true;
		}
	}
	return false;
}

bool younger(peo a, peo b) {
	if (a.y != b.y) {
		return a.y > b.y;
	} else if (a.m != b.m) {
		return a.m > b.m;
	} else {
		return a.d > b.d;
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	peo o = {"", 2014, 9, 7}, y = {"", 1814, 9, 5};
	int count = 0;
	for (int i = 0; i < n; i++) {
		peo temp;
		cin >> temp.name;
		int unused __attribute__((unused));
		unused = scanf("%d/%d/%d", &temp.y, &temp.m, &temp.d);
		if (islaw(temp)) {
			count++;
			if (younger(temp, y)) {
				y = temp;
			}
			if (!younger(temp, o)) {
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