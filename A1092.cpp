/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 21:23:07
 *	modified:	2023-03-25 21:29:49
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

	string a, b;
	cin >> a >> b;
	int count = 0;
	string c = a;
	for (int i = 0; i < (int)b.size(); i++) {
		size_t j = a.find(b[i]);
		if (j != string::npos) {
			a.erase(j, 1);
		} else {
			++count;
		}
	}
	if (count == 0) {
		cout << "Yes " << c.size() - b.size() << "\n";
	} else {
		cout << "No " << count << "\n";
	}

	return 0;
}