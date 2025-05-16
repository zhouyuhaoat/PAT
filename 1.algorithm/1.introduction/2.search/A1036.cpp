/*
 *	author:		zhouyuhao
 *	created:	2023-03-22 20:51:31
 *	modified:	2023-03-22 21:03:07
 *	item:		Programming Ability Test
 *	site:		Yuting
 */

/*
    @pintia psid=994805342720868352 pid=994805453203030016 compiler=GXX
    ProblemSet: PAT (Advanced Level) Practice
    Title: 1036 Boys vs Girls
    https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805453203030016
*/

// @pintia code=start
#include <iostream>

using namespace std;

struct Student {
    int grade;
    string name, id;
    char gender;
};

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    Student boyLo = {101}, girlHi = {-1}; // lowest of boys, highest of girls
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.name >> s.gender >> s.id >> s.grade;
        if (s.gender == 'M' && s.grade < boyLo.grade) {
            boyLo = s;
        } else if (s.gender == 'F' && s.grade > girlHi.grade) {
            girlHi = s;
        }
    }
    girlHi.grade == -1 ? cout << "Absent\n" : cout << girlHi.name << " " << girlHi.id << "\n";
    boyLo.grade == 101 ? cout << "Absent\n" : cout << boyLo.name << " " << boyLo.id << "\n";
    boyLo.grade == 101 || girlHi.grade == -1 ? cout << "NA\n" : cout << girlHi.grade - boyLo.grade << "\n";

    return 0;
}
// @pintia code=end
