/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 13:58:24
 *	modified:	2023-03-25 14:10:39
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct per {
	string name;
	int age, worth;
};

int main(int argc, char const *argv[]) {

	int n, k;
	cin >> n >> k;
	vector<per> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].age >> p[i].worth;
	}
	sort(p.begin(), p.end(), [](per a, per b) -> bool {
		if (a.worth != b.worth) {
			return a.worth > b.worth;
		} else if (a.age != b.age) {
			return a.age < b.age;
		} else {
			return a.name < b.name;
		}
	});
	for (int i = 0; i < k; i++) {
		int m, amin, amax;
		cin >> m >> amin >> amax;
		cout << "Case #" << i + 1 << ":\n";
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (p[j].age >= amin && p[j].age <= amax) {
				cout << p[j].name << " " << p[j].age << " " << p[j].worth << "\n";
				if (++count == m) {
					break;
				}
			}
		}
		if (count == 0) {
			cout << "None\n";
		}
	}

	return 0;
}