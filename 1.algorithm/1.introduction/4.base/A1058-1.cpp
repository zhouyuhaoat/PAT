/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:01:41
 *	modified:	2023-03-31 15:56:16
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805416519647232 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1058 A+B in Hogwarts
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805416519647232
*/

// @pintia code=start
#include <iostream>

using namespace std;

using ll = long long;

int main(int argc, char const *argv[]) {

    ll a, b, c; // Galleon, Sickle, Knut
    scanf("%lld.%lld.%lld", &a, &b, &c);
    ll s1 = a * 17 * 29 + b * 29 + c;
    scanf("%lld.%lld.%lld", &a, &b, &c);
    ll s2 = a * 17 * 29 + b * 29 + c;
    ll sum = s1 + s2;
    cout << sum / 29 / 17 << "." << sum / 29 % 17 << "." << sum % 29 << "\n";

    return 0;
}
// @pintia code=end
