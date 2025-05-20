/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 16:39:26
 *	modified:	2023-03-22 16:56:43
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805311146147840 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1012 数字分类
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805311146147840
*/

// @pintia code=start
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    int sum[5] = {0}, cnt[5] = {0};
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        switch (num % 5) {
            case 0: // even
                if (num % 2 == 0) {
                    sum[0] += num, cnt[0]++;
                }
                break;
            case 1: // alternating sum
                if (cnt[1] % 2 == 0) {
                    sum[1] += num, cnt[1]++;
                } else {
                    sum[1] -= num, cnt[1]++;
                }
                break;
            case 2: // count
                sum[2]++, cnt[2]++;
                break;
            case 3: // average
                sum[3] += num, cnt[3]++;
                break;
            case 4: // max
                if (num > sum[4]) {
                    sum[4] = num, cnt[4]++;
                }
                break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (cnt[i] == 0) {
            cout << "N";
        } else {
            if (i != 3) {
                cout << sum[i];
            } else {
                cout << fixed << setprecision(1) << sum[3] * 1.0 / cnt[3];
            }
        }
        i < 4 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
