/*
 *	author:		zhouyuhao
 *	created:	2023-04-11 15:07:49
 *	modified:	2023-04-11 15:18:25
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    @pintia psid=994805342720868352 pid=994805389634158592 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1078 Hashing
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805389634158592
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void insert(int v, int size, vector<int>& d) {
    for (int i = 0; i < size; i++) {
        int id = (v + i * i) % size;
        if (d[id] == 0) {
            d[id] = v;
            cout << id % size;
            return;
        }
    }
    cout << "-";
}

int main(int argc, char const *argv[]) {

    int msize, n;
    cin >> msize >> n;
    while (!isPrime(msize)) {
        msize++;
    }
    vector<int> d(msize);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        insert(v, msize, d);
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
