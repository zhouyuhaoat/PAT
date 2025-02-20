/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 16:18:57
 *	modified:	2023-03-27 19:56:45
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
  @pintia psid=994805342720868352 pid=994805413520719872 compiler=GXX
  ProblemSet: PAT (Advanced Level) Practice
  Title: 1060 Are They Equal
  https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805413520719872
*/

// @pintia code=start
#include <iostream>

using namespace std;

string erase0(string s) {
    while (s[0] == '0' && s.size() > 1 && s[1] != '.') {
        s.erase(0, 1);
    }
    return s;
}

string erasep(string s) {
    size_t p = s.find('.');
    if (p != string::npos) {
        s.erase(p, 1);
    }
    return s;
}

bool iszero(string s) {
    s = erasep(s);
    if (stoi(s) == 0) {
        return true;
    }
    return false;
}

string chop(string s, int n) {
    s = erasep(s), s = erase0(s);
    // first erase the point, then erase leading zeros
    // since there may be zeros after the point
    if ((int)s.size() < n) {
        s.append(n - s.size(), '0');
    }
    return s.substr(0, n);
}

int magnitude(string s) {
    s = erase0(s);
    int e = 0;
    if (s[0] != '0') { // nonZero + ...
        size_t dot = s.find('.');
        dot != string::npos ? e = dot : e = s.size();
    } else if (!iszero(s)) { // 0. + zero + nonZero + ...
        size_t nonZero = s.find_first_not_of('0', 2);
        e = -(nonZero - 2);
    }
    return e;
}

string trans(string s, int n) {
    return "0." + chop(s, n) + "*10^" + to_string(magnitude(s));
}

int main(int argc, char const *argv[]) {

    int n;
    string a, b;
    cin >> n >> a >> b;
    string sa = trans(a, n), sb = trans(b, n);
    if (sa == sb) {
        cout << "YES " << sa << "\n";
    } else {
        cout << "NO " << sa << " " << sb << "\n";
    }

    return 0;
}
// @pintia code=end