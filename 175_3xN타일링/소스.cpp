#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long DP[5001] = { 0, };

int solution(int n) 
{
    int answer = 0;

    //n �� Ȧ���� ��� ����� 2 x 1 Ÿ�Ϸ� ��θ� ä��� ���� !
    if (n % 2 == 1)
    {
        return answer;
    }

    // ¦���ΰ�쿡�� ä��� ���� 
    DP[0] = 1;
    DP[2] = 3;

    // ��ȭ�� ���� ! 
    // f(x) = f(x-2) * f(2) + f(x-4) * 2 + f(x-6) * 2 .... + f(2) * 2 + 2

    for (int i = 4; i <= n; i += 2)
    {
        DP[i] = DP[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            DP[i] = DP[i] + DP[j] * 2;
        }
        DP[i] = DP[i] % 1000000007;
    }

    answer = (int)DP[n];
    return answer;
}

int main()
{
    int n = 6;
    int result = 11;

    int dab = solution(n);
    if (dab == result)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}