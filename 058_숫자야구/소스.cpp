#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ���� : 0�� ������ ��� �ڸ��� ��ġ�� �ʴ´�.


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for (int i = 123; i <= 987; i++) {
        int B = i / 100;            //100���ڸ�
        int S = (i / 10) % 10;      //10���ڸ�
        int I = i % 10;             //1���ڸ�
        
        if (B == 0 || S == 0 || I == 0) {       // ���� �ϳ��� 0�̸� 
            continue;
        }
        if (B == S || B == I || S == I) {       // ���� �������� ������ 
            continue;
        }

        for (int j = 0; j < baseball.size(); j++) {     // �ݺ��Ѵ� ���� for������ ���ڰ� ������ �� �Է°� ���������� ��� answer++
            int Strike = 0;
            int Ball = 0;
            int baseball_temp = baseball[j][0];
            int baseball_temp_B = baseball_temp / 100;          // �Է��� ���� �����ڸ� 
            int baseball_temp_S = (baseball_temp / 10) % 10;    // �Է��� ���� �����ڸ�  
            int baseball_temp_I = baseball_temp % 10;           // �Է��� ���� �����ڸ� 

            if (baseball_temp_B == 0 || baseball_temp_S == 0 || baseball_temp_I == 0) {
                break;
            }

            if (B == baseball_temp_B) Strike++;
            if (S == baseball_temp_S) Strike++;
            if (I == baseball_temp_I) Strike++;

            if (baseball[j][1] != Strike) {
                break;
            }

            if (B == baseball_temp_S || B == baseball_temp_I) Ball++;
            if (S == baseball_temp_B || S == baseball_temp_I) Ball++;
            if (I == baseball_temp_B || I == baseball_temp_S) Ball++;
            if (baseball[j][2] != Ball) {
                break;
            }
            
            if (j == baseball.size() - 1) answer++;         //  �Է��� ����ŭ ���� ������ ��� �����Ҷ� answer ++ �� �Ǵ°�

        }

    }
    return answer;
}

int main() {
    vector<vector<int>> v = { {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1} };
    int dab;
    dab = solution(v);
    cout << dab;
}