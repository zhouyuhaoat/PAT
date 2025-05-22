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

int main(int argc, char const *argv[]) {

    int size, n;
    cin >> size >> n;
    while (!isPrime(size)) { // adjust the size
        size++;
    }
    vector<int> hashTable(size);
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if (hashTable[key % size] == 0) { // 0: empty
            hashTable[key % size] = key;
            cout << key % size;
        } else { // !0: occupied -> collision
            bool inserted = false;
            for (int j = 1; j <= size; j++) { // quadratic probing (with positive increments only)
                int hashKey = (key % size + j * j) % size;
                if (hashTable[hashKey] == 0) {
                    hashTable[hashKey] = key;
                    cout << hashKey;
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                cout << "-";
            }
        }
        i < n - 1 ? cout << " " : cout << "\n";
    }

    return 0;
}
// @pintia code=end
