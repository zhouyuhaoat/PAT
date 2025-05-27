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

int main(int argc, char const *argv[]) {

    int size, n, m;
    cin >> size >> n >> m;
    while (!isPrime(size)) { // adjust the size
        size++;
    }
    vector<int> hashTable(size);
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if (hashTable[key % size] == 0) { // 0: empty
            hashTable[key % size] = key;
        } else { // !0: occupied -> collision
            bool inserted = false;
            for (int j = 1; j <= size; j++) { // quadratic probing (with positive increment only)
                int hashKey = (key % size + j * j) % size;
                if (hashTable[hashKey] == 0) {
                    hashTable[hashKey] = key;
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                cout << key << " cannot be inserted.\n";
            }
        }
    }
    int cnt = 0; // search time
    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        cnt++;
        if (hashTable[key % size] != key && hashTable[key % size] != 0) { // collision
            for (int j = 1; j <= size; j++) {
                cnt++;
                int hashKey = (key % size + j * j) % size; // quadratic probing
                if (hashTable[hashKey] == key || hashTable[hashKey] == 0) {
                    break;
                }
            }
        }
    }
    cout << fixed << setprecision(1) << (double)cnt / m << "\n";

    return 0;
}
// @pintia code=end
