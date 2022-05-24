#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 1000000007
int solution(int n, vector<int> money) {

    int answer = 0;
    int DP[100001];
    //0������ ����� �ִ� ����� ���� ������ 1��
    DP[0] = 1;

    /*  DP �迭�� �������� �ջ��ϱ�
      �Ʒ��� ���� �������� DP �� ���´�.
      �� ������ DP[0] ������ �ʿ� X
      * �κ��� �� ���ڰ� �߰��� �κ� �� 2�� * ���ִ°��� money[1] = 2�̱� ������ �ٷ� ���� ���� �߰��ȴ�.
      * ���� �κ��� �� ���� ���� ���� �߰��� ����ŭ ���� ���� �� ���Ŀ� ���� ���Ѱ� (T) ǥ�õȰ�
      1(T) 1    1(T) 1    1    1 -> money[0]
      1    1    2(*) 2    3    3 -> money[1]
      1    1    2    3(*) 4    5 -> money[2]
      1    1    2    3    5(*) 6 -> money[3]
    */
    for (int i = 0; i < money.size(); i++) {
        for (int j = money[i]; j <= n; j++) {
            DP[j] += DP[j - money[i]] % MOD;

        }
        /* Test Code
         for(int j=0; j<=n; j++){
             cout <<DP[j] <<" " ;
         }
         cout << endl;
        */
    }

    /* Test Code
    for(int i=0; i<n; i++){
        cout << DP[i] << " ";
    }
    */

    answer = DP[n];
    return answer;
}

int main() {
    int n = 5;
    vector<int> m = { 1,2,3,4 };
    int d = solution(n, m);
    cout << d << endl;
}