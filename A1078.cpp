/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:07:49
 *	modified:	2023-04-11 15:18:25
 *	item:		Programming Ability Test
 *	site:		Shahu
 */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {

	int msize, n;
	cin >> msize >> n;
	while (!isprime(msize)) {
		++msize;
	}
	vector<int> d(msize);
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (d[v % msize] == 0) {
			d[v % msize] = v;
			cout << v % msize;
		} else {
			bool flag = false;
			for (int j = 1; j <= msize; j++) {
				if (d[(v % msize + j * j) % msize] == 0) {
					d[(v % msize + j * j) % msize] = v;
					cout << (v % msize + j * j) % msize;
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "-";
			}
		}
		if (i < n - 1) {
			cout << " ";
		} else {
			cout << "\n";
		}
	}

	return 0;
}