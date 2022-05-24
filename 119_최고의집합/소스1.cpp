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



vector<int> solution(int n, int s) {
    vector<int> answer;

    // ���� �м�
    // ���� �ִ밪�� ���ڳ����� ���̰� ���� �������
    // ex ) n=127 s=3 �ϰ�� 42 42 43 �� �ְ��� �����̴�
    // �̷� ���� ������ �Ϸ��� n/3 = 42 �̰� �������� 1�̴�
    // �������� 2��� �����ʿ��� 2���� +1�ϰ� ���Ͱ��� ��쿡�� �������� 1�̱� ������ �� ������ ���� +1���Ѵ�.
    // ������� ��� -1 ����

    if (n > s) {
        answer.push_back(-1);
    }
    else {
        int value = s / n;
        int percent = s % n;

        // value �� �� idx Ǫ��
        for (int i = 0; i < n; i++) {
            answer.push_back(value);
        }

        /* temp code
        for(int i=0; i<answer.size(); i++){
            cout << answer[i] << endl;
        }
        */

        for (int i = 0; i < percent; i++) {
            answer[i]++;
        }

        sort(answer.begin(), answer.end());
    }
    return answer;
}

int main() {
    int n = 3;
    int k = 128;
    vector<int> a = solution(n, k);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }

    return 0;
}