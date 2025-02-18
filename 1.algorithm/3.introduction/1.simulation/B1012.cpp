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
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<float> a(5);
    vector<bool> flag(5);
    float symbol = 1;
    int c4 = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        switch (num % 5) {
            case 0:
                if (num % 2 == 0) {
                    a[0] += num;
                    flag[0] = true;
                }
                break;
            case 1:
                a[1] += symbol * num;
                symbol = -symbol;
                flag[1] = true;
                break;
            case 2:
                ++a[2];
                flag[2] = true;
                break;
            case 3:
                a[3] += num;
                ++c4;
                flag[3] = true;
                break;
            case 4:
                if (num > a[4]) {
                    a[4] = num;
                    flag[4] = true;
                }
                break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (!flag[i]) {
            cout << "N";
        } else {
            if (i != 3) {
                cout << (int)a[i];
            } else {
                cout << fixed << setprecision(1) << a[3] / c4;
            }
        }
        if (i < 4) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }

    return 0;
}
// @pintia code=end