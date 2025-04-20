/*
 *	author:		zhouyuhao
 *	created:	2023-04-04 14:26:03
 *	modified:	2023-04-04 15:08:41
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805343236767744 compiler=GXX
    ProblemSet: Average Search Time - PAT (Advanced Level) Practice
    Title: 1145 Hashing
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343236767744
*/

// @pintia code=start
#include <iomanip>
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

bool insert(vector<int>& ht, int key, int msize) {
    for (int i = 0; i <= msize; i++) {
        int hk = (key % msize + i * i) % msize;
        if (ht[hk] == 0) {
            ht[hk] = key;
            return true;
        }
    }
    return false;
}

int count(vector<int>& ht, int key, int msize) {
    int cnt = 0;
    for (int i = 0; i <= msize; i++) {
        cnt++;
        int hk = (key % msize + i * i) % msize;
        if (ht[hk] == key || ht[hk] == 0) {
            return cnt;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {

    int msize, n, m;
    cin >> msize >> n >> m;
    while (!isPrime(msize)) {
        msize++;
    }
    vector<int> ht(msize);
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if (!insert(ht, key, msize)) {
            cout << key << " cannot be inserted.\n";
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        cnt += count(ht, key, msize);
    }
    cout << fixed << setprecision(1) << (double)cnt / m << "\n";

    return 0;
}
// @pintia code=end
