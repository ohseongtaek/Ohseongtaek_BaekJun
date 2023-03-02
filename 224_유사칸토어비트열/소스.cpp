#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) 
{
    int answer = 0;

    // �����ƴ� 5�� ����ΰ� �����ؾ��� 11011 �� 00000 �̱� ������ 
    for (long long i = l; i <= r; i++) 
    {
        int flag = 1;

        // ������ 3�ΰ�쿡 11011 ���� 0 �κ��̶� ������ �����ȼ� 
        if (i % 5 == 3) 
        {
            continue;
        }

        long long temp = i;
        long long result;
        
        while (1) 
        {
            if (temp % 5 == 0) 
            {
                temp = temp / 5;
            }
            else 
            {
                temp = (temp / 5) + 1;
            }

            if (temp % 5 == 3) 
            {
                flag = 0;
                break;
            }      
            else if (temp <= 5) 
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1) answer++;
    }

    return answer;
}

int main()
{
    int n = 2;
    int l = 53;
    int r = 53;
    int re = 8;

    if (re == solution(n, l, r))
    {
        cout << " good " <<endl;
    }
    else
    {
        cout << " error"<< endl;
    }
}