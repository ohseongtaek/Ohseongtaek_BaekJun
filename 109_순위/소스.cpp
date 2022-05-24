#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

//�÷��̵� �ͼ� �˰���

int humun[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    memset(humun, 0, sizeof(humun));

    //�ºΰ� ������������ 1�� init
    for (int i = 0; i < results.size(); i++) {
        humun[results[i][0]][results[i][1]] = 1;
    }

    //a->b , b->c , a->c �� ���� ���ذ��赵�� ���ؼ� 1�� set
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (humun[j][i] == 1 && humun[i][k] == 1) {
                    humun[j][k] = 1;
                    //cout << "j ? " << j << " k ? " << k << endl;
                }
            }
        }
    }

    //����� -1 ��ŭ ������ ������ Ȯ���� ��
    for (int i = 1; i <= n; i++) {
        int humun_count = 0;
        for (int j = 1; j <= n; j++) {
            //4 2 2 4 �̷� ���� ���� �ȵǱ� ������ ���� �ϳ��� 1�̸� set
            humun_count += (humun[i][j] + humun[j][i]);
        }
        if (humun_count == n - 1) {
            answer++;
        }
    }

    return answer;
}


int main() {
    int n = 5;
    vector<vector<int>> g = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
    cout << solution(n, g) << endl;
}