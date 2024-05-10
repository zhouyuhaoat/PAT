/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 19:37:50
 *	modified:	2023-03-22 19:41:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

struct stu {
	string name, id;
	int grade;
};

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	stu h, l;
	h.grade = -1;
	l.grade = 101;
	for (int i = 0; i < n; i++) {
		stu temp;
		cin >> temp.name >> temp.id >> temp.grade;
		if (temp.grade > h.grade) {
			h = temp;
		}
		if (temp.grade < l.grade) {
			l = temp;
		}
	}
	cout << h.name << " " << h.id << "\n";
	cout << l.name << " " << l.id << "\n";

	return 0;
}