/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 13:27:55
 *	modified:	2023-03-27 14:14:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805377432928256 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1089 Insert or Merge
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805377432928256
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        i < (int)v.size() - 1 ? cout << " " : cout << "\n";
    }
}

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<int> init(n), part(n), temp(n);
    for (int i = 0; i < n; i++) {
        cin >> init[i];
        temp[i] = init[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> part[i];
    }
    for (int i = 2; i <= n; i++) {
        sort(init.begin(), init.begin() + i);
        if (init == part) {
            cout << "Insertion Sort\n";
            sort(init.begin(), init.begin() + i + 1);
            print(init);
            return 0;
        }
    }
    init = temp; // reset
    int g = 2; // group size of merge sort
    while (g <= n) {
        for (int i = 0; i <= n / g; i++) {
            sort(init.begin() + i * g, init.begin() + min(n, (i + 1) * g));
        }
        g *= 2;
        if (init == part) {
            cout << "Merge Sort\n";
            for (int i = 0; i <= n / g; i++) {
                sort(init.begin() + i * g, init.begin() + min(n, (i + 1) * g));
            }
            print(init);
            break;
        }
    }

    return 0;
}
// @pintia code=end
