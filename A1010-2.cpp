/*
 *	author:		zhouyuhao
 *	created:	2024-04-28 18:16:00
 *	modified:	2024-04-28 18:26:00
 *	item:		Programming Ability Test
 *	site:		914, Harbin
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll trans(string s, ll b) {
	ll sum = 0, w = 1;
	for (ll i = s.size() - 1; i >= 0; i--) {
		if (isdigit(s[i])) {
			sum += (s[i] - '0') * w;
		} else {
			sum += (s[i] - 'a' + 10) * w;
		}
		w *= b;
	}
	return sum;
}

int main(int argc, char const *argv[]) {

	string n1, n2;
	ll tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2) {
		swap(n1, n2);
	}
	ll num = trans(n1, radix);
	char ch = *max_element(n2.begin(), n2.end());
	ll low = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1;
	ll high = max(low, num) + 1;
	while (low + 1 < high) {
		ll mid = (low + high) >> 1;
		ll temp = trans(n2, mid);
		if (temp > num || temp < 0) {
			high = mid;
		} else {
			low = mid;
		}
	}
	if (num == trans(n2, low)) {
		cout << low << "\n";
	} else {
		cout << "Impossible\n";
	}

	return 0;
}