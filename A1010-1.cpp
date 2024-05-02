/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 10:58:14
 *	modified:	2023-03-31 19:16:35
 *	item:		Programming Ability Test
 *	site:		Yuting
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
	ll high = max(low, num);
	ll ans = -1;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		ll temp = trans(n2, mid);
		if (temp > num || temp < 0) {
			high = mid - 1;
		} else if (temp < num) {
			low = mid + 1;
		} else {
			ans = mid;
			break;
		}
	}
	if (ans != -1) {
		cout << ans << "\n";
	} else {
		cout << "Impossible\n";
	}

	return 0;
}