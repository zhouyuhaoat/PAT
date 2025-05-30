/*
 *	author:		zhouyuhao
 *	created:	2023-04-13 17:45:05
 *	modified:	2023-04-13 17:52:56
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
        cin >> person[i].enter >> person[i].exit; // time <=> string
    }
    // greedy: activity selection, interval scheduling
    sort(person.begin(), person.end(), [](Person a, Person b) {
        if (a.exit != b.exit) {
            return a.exit < b.exit; // end time: as earlier as possible
        } else {
            return a.enter > b.enter; // start time: for shorter time duration
        }
    });
    int cnt = 1;
    string lastExit = person[0].exit;
    for (int i = 1; i < n; i++) {
        if (person[i].enter >= lastExit) { // not overlap: enter after last exit
            cnt++;
            lastExit = person[i].exit;
        }
    }
    cout << cnt << "\n";

    return 0;
}
