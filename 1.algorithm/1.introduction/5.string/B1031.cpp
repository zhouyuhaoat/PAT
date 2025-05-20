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

const int ID = 18, MOD = 11;
int weight[ID - 1] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
string digit = "10X98765432"; // check digit

bool valid(string s) {
    int sum = 0; // check sum
    for (int i = 0; i < ID - 1; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
        sum += (s[i] - '0') * weight[i];
    }
    return s[ID - 1] == digit[sum % MOD]; // check
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    bool allValid = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!valid(s)) {
            cout << s << "\n";
            allValid = false;
        }
    }
    if (allValid) {
        cout << "All passed\n";
    }

    return 0;
}
// @pintia code=end
