/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:20:40
 *	modified:	2023-04-13 17:44:58
 *	item:		Programming Ability Test
 *	site:		Shahu
 */

/*
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1181 Lab Access Scheduling
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Person {
    string enter, exit;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<Person> person(n);
    for (int i = 0; i < n; i++) {
        cin >> person[i].enter >> person[i].exit;
    }
    sort(person.begin(), person.end(), [](Person a, Person b) {
        if (a.enter != b.enter) {
            return a.enter > b.enter; // start time: as later as possible
        } else {
            return a.exit < b.exit; // end time: for shorter time duration
        }
    });
    int cnt = 1;
    string lastEnter = person[0].enter;
    for (int i = 1; i < n; i++) {
        if (person[i].exit <= lastEnter) { // not overlap: exit before last enter
            cnt++;
            lastEnter = person[i].enter;
        }
    }
    cout << cnt << "\n";

    return 0;
}
