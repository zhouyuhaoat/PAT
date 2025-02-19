/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 10:58:14
 *	modified:	2023-03-31 19:16:35
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805507225665536 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1010 Radix
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805507225665536
*/

// @pintia code=start
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

ll binary(string s, ll num) {
    char ch = *max_element(s.begin(), s.end());
    ll low = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1;
    ll high = max(low, num);
    ll ans = -1;
    while (low <= high) {
        ll mid = (low + high) >> 1;
        ll temp = trans(s, mid);
        if (temp > num || temp < 0) {
            high = mid - 1;
        } else if (temp < num) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {

    string n1, n2;
    ll tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) {
        swap(n1, n2);
    }
    ll num = trans(n1, radix);
    ll ans = binary(n2, num);
    if (ans != -1) {
        cout << ans << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
// @pintia code=end