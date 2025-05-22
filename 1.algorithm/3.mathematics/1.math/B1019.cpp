/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 14:22:28
 *	modified:	2023-03-27 10:16:29
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805302786899968 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1019 数字黑洞
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805302786899968
*/

// @pintia code=start
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string n;
    cin >> n;
    n.insert(0, 4 - n.size(), '0'); // padding with zeros
    do {
        string min = n, max = n;
        sort(min.begin(), min.end());
        sort(max.rbegin(), max.rend());
        n = to_string(stoi(max) - stoi(min));
        n.insert(0, 4 - n.size(), '0');
        cout << max << " - " << min << " = " << n << "\n";
    } while (n != "6174" && n != "0000");

    return 0;
}
// @pintia code=end
