#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    int str_size = s.size();

    int answer = str_size;

    for (int i = 1; i <= (str_size / 2); i++) {
        string result;
        string Diff_temp = s.substr(0, i);
        int count = 1;                      // �⺻������ ���� 1���� ������ 1�̱⶧���� �ʱ�ȭ

        for (int j = i; j <= str_size; j = j + i) { //������ < �� �������� count �س����� �߰��� �������� <= �̰��ؾ��� 
            if (Diff_temp == s.substr(j, i)) {
                count++;
            }
            else {
                if (count == 1) {
                    result = result + Diff_temp;
                }
                else {
                    result = result + to_string(count) + Diff_temp;
                }
                Diff_temp = s.substr(j, i);
                count = 1;
            }
        }

        result = result + s.substr((str_size / i) * i);     // ���ڿ� 9���̰� 2���� �ڸ��� 1���� �ȵ��� ������ �װ��� ������ 
        answer = min(answer, (int)result.length());
    }
    return answer;
}