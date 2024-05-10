/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 16:30:41
 *	modified:	2023-03-27 10:12:49
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct stu {
	string name, id;
	int grade;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	vector<stu> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].id >> s[i].grade;
	}
	int g1, g2;
	cin >> g1 >> g2;
	sort(s.begin(), s.end(), [](stu a, stu b) -> bool {
		return a.grade >= b.grade;
	});
	int count = 0;
	for (auto it : s) {
		if (it.grade >= g1 && it.grade <= g2) {
			cout << it.name << " " << it.id << "\n";
			++count;
		}
	}
	if (count == 0) {
		cout << "NONE\n";
	}

	return 0;
}