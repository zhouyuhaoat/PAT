
#### 1184 Arrays and Linked Lists

Let's design a data structure $A$ that combines arrays and linked lists as the following:

At the very beginning, an integer array $A_0$​ of length $L_0$​ is initialized for the user. When the user tries to access the ith element $A[i]$, if $0\leq i \lt L_0$​, then $A[i]$ is just $A_0​[i]$. Now our system is supposed to return $h_0 ​+ i \times sizeof(int)$ as the accessed address, where $h_0$​ is the initial address of $A_0$​, and $sizeof(int)$ is the size of the array element, which is simply **int**, taking 4 bytes.

In case there is an overflow of the user's access (that is, $i\geq L_0$​), our system will declare another array $A_1$​ of length $L_1$​. Now $A[i]$ corresponds to $A_1​[j]$ (It's your job to figure out the relationship between $i$ and $j$). If $0\leq j\lt L_1$​, then $h_1 ​+ j \times sizeof(int)$ is returned as the accessed address, where $h_1$​ is the initial address of $A_1$​.

And if there is yet another overflow of the user's access to $A_1​[j]$, our system will declare another array $A_2$​ of length $L_2$​, and so on so forth.

Your job is to implement this data structure and to return the address of any access.

**Input Specification:**

Each input file contains one test case. For each case, the first line gives 2 positive integers $N (\leq 10^4)$ and $K (\leq 10^3)$ which are the number of arrays that can be used, and the number of user queries, respectively.

Then $N$ lines follow, each gives 2 positive integers, which are the initial address $(\leq 10^7)$ and the length $(\leq 100)$ of an array, respectively. The numbers are separated by spaces. It is guaranteed that there is no overlap of the spaces occupied by these arrays.

Finally, $K$ indices of the elements queried by users are given in the last line. Each index is an integer in the range $[0, 2^{20}]$.

**Output Specification:**

For each query, print in a line the accessed address. If the queried index exceeds the range of all the $N$ arrays, output `Illegal Access` instead, and this query must NOT be processed.

Print in the last line the total number of arrays that have been declared for the whole process.

**Sample Input:**

```
6 7
2048 5
128 6
4016 10
1024 7
3072 12
9332 10
2 12 25 50 28 8 39
```

**Sample Output:**

```
2056
4020
1040
Illegal Access
3072
140
3116
5
```

**Hint:**

$A[2]$ is just $A_0​[2]$, so the accessed address is $2048 + 2 \times 4 = 2056$.

In order to access $A[12]$, declaring $A_1$​ is not enough, we need $A_2$​ with initial address $h_2​ = 4016$. Since $A[12] = A_2​[1]$, the accessed address is $4016 + 1 \times 4 = 4020$.

In order to access $A[25]$, we need $A_3$​ with initial address $h_3​ = 1024$. Since $A[25] = A_3​[4]$, the accessed address is $1024 + 4 \times 4 = 1040$.

The access of $A[50]$ exceeds the maximum boundary of all the arrays, and hence an illegal access. There is no extra array declared.

In order to access $A[28]$, we need $A_4$​ with initial address $h_4 ​= 3072$. Since $A[28] = A_4​[0]$, the accessed address is just $3072$.

It is clear to see that $A[8] = A_1​[3]$ and hence the accessed address is $128 + 3 \times 4 = 140$; and $A[39] = A_4​[11]$ so the accessed address is $3072 + 11 \times 4 = 3116$.

All together there are 5 arrays used for the above queries.

#### 1185 Stack of Hats

PATers believe that wearing hats makes them look handsome, so wherever they go, everyone of them would wear a hat. One day they came to a restaurant, a waiter collected their hats and piled them up. But then when they were ready to leave, they had to face a stack of hats as shown by the above figure. So your job is to help them line up so that everyone can pick up his/her hat one by one in order without any trouble.

It is known that every hat has a unique size, which is related to the weight of its owner -- that is, the heavier one wears larger hat.

**Input Specification:**

Each input file contains one test case. For each case, the first line contains a positive number $N (\leq 10^4)$ which is the number of PATers. The next line gives $N$ distinct sizes of the hats, which are positive numbers no more than 105. The sizes correspond to the hats from bottom up on the stack. Finally in the last line, $N$ distinct weights are given, correspond to the hat owners numbered from 1 to $N$. The weights are positive numbers no more than 106. All the numbers in a line are separated by spaces.

**Output Specification:**

For each test case, print in a line the indices of the hat owners in the order of picking up their hats. All the numbers must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

**Sample Input:**

```
10
12 19 13 11 15 18 17 14 16 20
67 90 180 98 87 105 76 88 150 124
```

**Sample Output:**

```
3 4 8 6 10 2 1 5 9 7
```

**Hint:**

The 1st hat has the largest size 20, hence must correspond to the one with the largest weight, which is the 3rd one of weight 180. So No.3 must go first.

The 2nd hat has the 6th smallest size 16, hence corresponds to the 6th smallest weight, which is 98. So No.4 is the next to go.

And so on so forth.

#### 1186 Playground Exploration

A playground is equipped with ball pits and tents connected by tunnels. Kids can crawl through the tunnels to meet their friends at a spot with a tent or a ball pit.

Now let's mark each meeting spot (a tent or a ball pit) by a number. Assume that once a kid starts to explore the playground from any meeting spot, he/she will always choose the next destination with the smallest number, and he/she would never want to visit the same spot twice. Your job is to help the kids to find the best starting spot so they can explore as many spots as they can.

**Input Specification:**

Each input file contains one test case. For each case, the first line gives two positive integers $N (\leq 100)$, the total number of spots, and $M$, the number of tunnels. Then $M$ lines follow, each describes a tunnel by giving the indices of the spots (from 1 to $N$) at the two ends.

**Output Specification:**

Print in a line the best starting spot which leads to the maximum number of spots, and the number of spots a kid can explore. If the solution is not unique, output the one with the smallest index. There must be exactly 1 space between the two numbers, and there must be no extra space at the beginning or the end of the line.

**Sample Input:**

```
8 10
1 2
3 4
5 8
1 4
6 1
3 7
2 4
5 3
2 8
2 5
```

**Sample Output:**

```
6 7
```

**Hint:**

Actually there are two solutions. Kids can either start from 6 and go through 1->2->4->3->5->8, or from 7 to 3->4->1->2->5->8, both can visit 7 spots. Since 6 is a smaller index, we output 6 as the starting spot.

#### 1187 Sorted Cartesian Tree

A **Sorted Cartesian tree** is a tree of (key, priority) pairs. The tree is heap-ordered according to the priority values, and an inorder traversal gives the keys in sorted order. For example, given the pairs { (55, 8), (58, 15), (62, 3), (73, 4), (85, 1), (88, 5), (90, 12), (95, 10), (96, 18), (98, 6) }, the increasing min-heap Cartesian tree is shown by the figure.

Your job is to do level-order traversals on an increasing min-heap Cartesian tree.

**Input Specification:**

Each input file contains one test case. Each case starts from giving a positive integer $N (\leq 30)$, and then $N$ lines follow, each gives a pair in the format `key priority`. All the numbers are in the range of int.

**Output Specification:**

For each test case, print in the first line the level-order traversal key sequence and then in the next line the level-order traversal priority sequence of the min-heap Cartesian tree.

All the numbers in a line must be separated by exactly one space, and there must be no extra space at the beginning or the end of the line.

**Sample Input:**

```
10
88 5
58 15
95 10
62 3
55 8
98 6
85 1
90 12
96 18
73 4
```

**Sample Output:**

```
85 62 88 55 73 98 58 95 90 96
1 3 5 8 4 6 15 10 12 18
```

