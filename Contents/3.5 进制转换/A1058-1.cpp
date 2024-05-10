/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:01:41
 *	modified:	2023-03-31 15:56:16
 *	item:		Programming Ability Test
 *	site:		Yuting
 */
#include <iostream>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {

	ll a, b, c;
	int unused __attribute__((unused));
	unused = scanf("%lld.%lld.%lld", &a, &b, &c);
	ll s1 = a * 17 * 29 + b * 29 + c;
	unused = scanf("%lld.%lld.%lld", &a, &b, &c);
	ll s2 = a * 17 * 29 + b * 29 + c;
	ll sum = s1 + s2;
	cout << sum / 29 / 17 << "." << sum / 29 % 17 << "." << sum % 29 << "\n";

	return 0;
}