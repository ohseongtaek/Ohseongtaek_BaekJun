#include <string>
#include <vector>
#include <iostream>
using namespace std;

string Convert(int i, int n) {
    string H[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    int temp;
    string Convert_Return = "";
    while (i / n != 0) {                          //������ȯ
        temp = i % n;
        Convert_Return = H[temp] + Convert_Return;
        i = i / n;
    }

    Convert_Return = H[i % n] + Convert_Return;   //������ �� �����ϴ� �ڵ�

    return Convert_Return;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    int total_number = t * m;                    //�� ������ ���� �̸����Ҽ����� ���� 3�̰� �����ο��� 4���̸� �� 12�ڸ����� ���ڸ� ���س��ƾ��Ѵ�
    string temp = "";
    
    for (int i = 0; i < total_number; i++) {
        temp += Convert(i, n);                   //n�������� i�� ��ȯ �Ѵ� �̸����Ҽ��ڸ� n�������� ��ȯ �� s ���ڿ��� ����
        //cout << temp << endl;
    }


    int p_temp = p - 1;                          // ������ ù��°��� 0���� �����ؾ��ؼ� -1�ϱ�

    for (int i = 0; i < t; i++) {
        answer += temp[p_temp];                  // �迭 �̵����� ���� ������ ���� answer�� ��ġ��
        p_temp += m;                             // �����ο� plus
    }

    return answer;
}

int main() {
    int n = 16;  // ����
    int t = 4;  // �̸����Ҽ����� ��
    int m = 10;  // �����ο�
    int p = 1;  // Ʃ�����

    cout << solution(n, t, m, p) << endl;
}

