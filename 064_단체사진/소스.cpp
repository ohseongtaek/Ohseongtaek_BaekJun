#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<char> first = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };    // ĳ���� �̸��� 
int dist_temp[26];

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    do {
        for (int i = 0; i < first.size(); i++) {
            dist_temp[first[i] - 'A'] = i;              // �Ÿ� ���ϱ� ���� �迭 ���� �� �� �־��� 
        }
        bool Switch_Case_Temp = true;

        for (int j = 0; j < data.size(); j++) {
            int first_number = data[j][0] - 'A';
            int second_number = data[j][2] - 'A';

            int Distance = abs(dist_temp[first_number] - dist_temp[second_number]) - 1;     // �Ÿ��� ���ϴ� �� A�� C���̿� ���� ���ϴ� ���̱� ������ -1������ �����ָ� A�� C������ �Ÿ��� 2�� ���� C�� �����ؼ� 

            char Sic = data[j][3];
            int result = data[j][4] - '0';
            switch (Sic) {                      // ������ ������ �� 3�� = < > �� ���� 
            case '=': 
                if (Distance != result) {
                    Switch_Case_Temp = false;
                }
                break;

            case '>' :
                if (Distance <= result) {
                    Switch_Case_Temp = false;
                }
                break;

            case '<' :
                if (Distance >= result) {
                    Switch_Case_Temp = false;
                }
                break;

            default:
                cout << "Not UserCase" << '\n';
            }

            if (!Switch_Case_Temp) {           // ù��° ���ǿ��� �̹� �����Ѱ��̸� �ٷ� break �� Ż��
                break;
            }

        }
        if (Switch_Case_Temp) {
            answer++;
        }
    } while (next_permutation(first.begin(), first.end()));     // �迭�� ���� ����Ǽ��� �����ϴ� ���ø� 

    return answer;
}

int main() {
    int dab;
    int n = 2;
    vector<string> dat = { "N~F=0", "R~T>2" };
                          //012 3 4 
    dab = solution(n, dat);

    cout << dab;

    return 0;
}
