#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void refunc(int first, int num, vector<vector<int>>& computers, vector<bool>& flag) {
    // �ϴ� ������ ������ �ش� ��ġ�� true�� ���� �̰� �����ϸ� �ش� ��Ʈ��ũ�� ���� �뿪�̶� �Ǵ��� �����Ǵ°�  
    flag[first] = true;

    // ���� �Ѿ�� ���� ���� ������ ���Ҹ� ��� 
    for (int i = 0; i < num; i++) {
        if (computers[first][i] && !flag[i]) {
            cout << "refunc i ? " << i << endl;
            refunc(i, num, computers, flag);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    //n �� ũ�⸦ ���� bool �� ���� ���� 
    vector<bool> flag(n, false);

    // for�� n��ŭ �ݺ��� ���� flag�� ���� false �̸� ����Լ� ���� �� answer ++ 
    // ���⼭ ����Լ��� flag���� ������ ���� ��Ʈ��ũ �뿪�� ����� �߿��� ���� 
    for (int i = 0; i < n; i++) {
        if (flag[i] == false) {
            refunc(i, n, computers, flag);
            answer++;
        }
    }

    return answer;
}

int main() {
    int num = 3;
    vector<vector<int>> vv = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    cout << solution(num, vv) << endl;;
}