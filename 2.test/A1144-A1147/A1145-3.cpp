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

int find(vector<int>& hashTable, int key, int size, int& cnt) {
    cnt = 0;
    for (int i = 0; i <= size; i++) {
        cnt++;
        int hashKey = (key % size + i * i) % size;
        if (hashTable[hashKey] == 0 || hashTable[hashKey] == key) {
            // judge whether the position is empty firstly
            return hashKey;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {

    int size, n, m;
    cin >> size >> n >> m;
    while (!isPrime(size)) {
        size++;
    }
    vector<int> hashTable(size);
    for (int i = 0; i < n; i++) {
        int key, cnt;
        cin >> key;
        int hashKey = find(hashTable, key, size, cnt);
        if (hashKey == -1) {
            cout << key << " cannot be inserted.\n";
        } else {
            hashTable[hashKey] = key;
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int key, cnt;
        cin >> key;
        find(hashTable, key, size, cnt);
        sum += cnt;
    }
    cout << fixed << setprecision(1) << (double)sum / m << "\n";

    return 0;
}
// @pintia code=end
