#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <queue>
using namespace std;

vector<vector<int>> answer;
void ost(int n, int one, int two, int three) {
    vector<int> temp = { one,three };
    if (n == 1) {
        answer.push_back(temp);;
    }
    else {
        ost(n - 1, one, three, two); // n-1 ���� 1���� 2�� �̵���Ų��
        answer.push_back(temp);
        ost(n - 1, two, one, three); // n-1 ���� 2���� 3���� �̵���Ų��
    }
}

vector<vector<int>> solution(int n) {
    //����Լ�
    ost(n, 1, 2, 3);
    return answer;
}

int main() {
    int n = 2;
    vector<vector<int>> d = solution(n);

    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d[i].size(); j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}