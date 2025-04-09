/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 22:22:26
 *	modified:	2023-03-31 16:06:44
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805290334011392 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1031 查验身份证
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805290334011392
*/

// @pintia code=start
#include <iostream>

using namespace std;

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int m[11] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};

bool valid(string s) {
    int sum = 0;
    for (int i = 0; i < 17; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
        sum += (s[i] - '0') * w[i];
    }
    int id = s[17] - '0';
    if (s[17] == 'X') {
        id = -1;
    }
    return m[sum % 11] == id;
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!valid(s)) {
            cout << s << "\n";
            flag = false;
        }
    }
    if (flag) {
        cout << "All passed\n";
    }

    return 0;
}
// @pintia code=end
