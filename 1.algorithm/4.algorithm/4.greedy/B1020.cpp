/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 13:43:19
 *	modified:	2023-03-22 13:55:31
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805260223102976 pid=994805301562163200 compiler=GXX
    ProblemSet: PAT (Basic Level) Practice （中文）
    Title: 1020 月饼
    https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805301562163200
*/

// @pintia code=start
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct cake {
    double stock, sale, price;
    // price per unit = sale / stock
};

int main(int argc, char const *argv[]) {

    int n;
    double demand;
    cin >> n >> demand;
    vector<cake> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i].stock;
    }
    for (int i = 0; i < n; i++) {
        cin >> list[i].sale;
        list[i].price = list[i].sale / list[i].stock;
    }
    sort(list.begin(), list.end(), [](cake a, cake b) {
        return a.price > b.price; // higher price per unit first
    });
    double profit = 0;
    for (int i = 0; i < n; i++) {
        if (demand > list[i].stock) { // not enough stock
            profit += list[i].sale;
            demand -= list[i].stock;
        } else { // enough stock
            profit += demand * list[i].price;
            break;
        }
    }
    cout << fixed << setprecision(2) << profit << "\n";

    return 0;
}
// @pintia code=end
