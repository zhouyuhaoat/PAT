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
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int msize, n, m;
    cin >> msize >> n >> m;
    while (!isprime(msize)) { // adjust the size
        ++msize;
    }
    vector<int> ht(msize); // 0: empty
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if (ht[key % msize] == 0) {
            ht[key % msize] = key;
        } else { // collision
            bool isins = false;
            for (int j = 1; j <= msize; j++) { // quadratic probing
                int hk = (key % msize + (int)pow(j, 2)) % msize;
                if (ht[hk] == 0) {
                    ht[hk] = key;
                    isins = true;
                    break;
                }
            }
            if (!isins) {
                cout << key << " cannot be inserted.\n";
            }
        }
    }
    int cnt = 0; // search time
    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        ++cnt;
        if (ht[key % msize] != key && ht[key % msize] != 0) { // collision
            for (int j = 1; j <= msize; j++) {
                ++cnt;
                int hk = (key % msize + (int)pow(j, 2)) % msize; // quadratic probing
                if (ht[hk] == key || ht[hk] == 0) {
                    break;
                }
            }
        }
    }
    cout << fixed << setprecision(1) << (double)cnt / m << "\n";

    return 0;
}
// @pintia code=end