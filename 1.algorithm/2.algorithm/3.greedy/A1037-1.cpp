/*
 *	author:		zhouyuhao
 *	created:	2023-03-25 22:49:55
 *	modified:	2023-03-26 12:53:14
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805451374313472 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1037 Magic Coupon
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805451374313472
*/

// @pintia code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n1;
    cin >> n1;
    vector<int> coupon(n1);
    for (int i = 0; i < n1; i++) {
        cin >> coupon[i];
    }
    int n2;
    cin >> n2;
    vector<int> product(n2);
    for (int i = 0; i < n2; i++) {
        cin >> product[i];
    }
    /*
        pair two arrays to get the maximum sum of products (multiply) of two elements
        - each element in the first array can be paired with at most one element in the second array
    */
    int profit = 0;
    sort(coupon.begin(), coupon.end());
    sort(product.begin(), product.end());
    for (int i = 0; i < n1 && i < n2; i++) { // from left to right
        if (coupon[i] < 0 && product[i] < 0) { // both negative
            profit += coupon[i] * product[i];
        } else {
            break;
        }
    }
    for (int i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) { // from right to left
        if (coupon[i] > 0 && product[j] > 0) { // both positive
            profit += coupon[i] * product[j];
        } else {
            break;
        }
    }
    cout << profit << "\n";

    return 0;
}
// @pintia code=end
