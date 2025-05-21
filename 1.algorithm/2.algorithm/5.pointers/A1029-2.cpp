/*
 *	author:		zhouyuhao
 *	created:	2023-03-27 14:14:43
 *	modified:	2023-03-27 14:59:42
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805466364755968 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1029 Median
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805466364755968
*/

// @pintia code=start
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n1;
    cin >> n1;
    vector<long long> seq1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> seq1[i];
    }
    int n2;
    cin >> n2;
    vector<long long> seq2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> seq2[i];
    }
    int res = 0, i = 0, j = 0, k = 0, median = (n1 + n2 + 1) / 2 - 1; // median = (size + 1) / 2 - 1
    while (i < n1 && j < n2 && k <= median) { // k = i + j
        res = seq1[i] < seq2[j] ? seq1[i++] : seq2[j++];
        k++;
    }
    if (i < n1 && k <= median) { // while -> index operation
        res = seq1[i + median - k];
    } else if (j < n2 && k <= median) {
        res = seq2[j + median - k];
    }
    cout << res << "\n";

    return 0;
}
// @pintia code=end
