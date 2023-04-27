#include <string>
#include <iostream>
#include <vector>

using namespace std;

int DP[100001][2];

typedef enum
{
    BASIC_CASE_0 = 0,
    BASIC_CASE_1,
    BASIC_CASE_2,
    BASIC_CASE_3,
    DP_CASE
}CAL_CASE;

int GetCase(int num)
{
    if (num == 50 || num <= 20)
    {
        DP[num][0] = 1;
        DP[num][1] = 1;
        return BASIC_CASE_0;
    }
    else if ((num <= 60 && num % 3 == 0) || (num <= 40 && num % 2 == 0))
    {
        DP[num][0] = 1;
        DP[num][1] = 0;
        return BASIC_CASE_1;
    }
    else if ((num > 50 && num <= 70) || (num < 70 && num < 40))
    {
        DP[num][0] = 2;
        DP[num][1] = 2;
        return BASIC_CASE_2;
    }
    else if (num < 70)
    {
        DP[num][0] = 2;
        DP[num][1] = 1;
        return BASIC_CASE_3;
    }
    else
    {
        return DP_CASE;
    }
}

void CalcDP(int target)
{
    if (DP[target - 60][0] == DP[target - 50][0])
    {
        DP[target][0] = DP[target - 50][0] + 1;
        DP[target][1] = max(DP[target - 60][1], DP[target - 50][1] + 1);
    }
    else if (DP[target - 60][0] < DP[target - 50][0])
    {
        DP[target][0] = DP[target - 60][0] + 1;
        DP[target][1] = DP[target - 60][1];
    }
    else
    {
        DP[target][0] = DP[target - 50][0] + 1;
        DP[target][1] = DP[target - 50][1] + 1;
    }
}

vector<int> solution(int target) 
{
    vector<int> answer;

    for (int i = 1; i <= target; i++)
    {
        if (DP_CASE == GetCase(i))
        {
            CalcDP(i);
        }
    }

    answer.push_back(DP[target][0]);
    answer.push_back(DP[target][1]);

    return answer;
}

int main()
{
    vector<int> t = { 21,58 };
    vector<vector<int>> an = { {1,0},{2,2} };

    for (int i = 0; i < t.size(); i++)
    {
        vector<int> dab = solution(t[i]);

        bool flag = false;

        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != an[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << " error " << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
}

/*
���α׷��ӽ� ��Ʈ ��ȸ������ �ų⸶�� ���ο� Ư�� ������ ��Ʈ ��ȸ�� �����մϴ�. �̹� ��ȸ�� ���� "ī��Ʈ �ٿ�"���� "���ο�" ���� ���� ���Դϴ�.
"ī��Ʈ �ٿ�"�� ������ ���۵Ǹ� �������� ������ ��������, ��Ʈ�� �����鼭 ������ ��Ƽ� ��Ȯ�� 0������ ����� �����Դϴ�. ��, ���� �������� ū ������ �����ϸ� ����Ʈ�� �Ǹ� �ǰ� �մϴ�.

���� �׸��� ��Ʈ �����Դϴ�.
�׸�.png

��Ʈ ���ῡ�� 1 ���� 20 ������ ���� �ϳ��� �ְ� �� ������ "�̱�", "����", "Ʈ����" ĭ�� �ֽ��ϴ�. "�̱�"�� ������ �ش� ����ŭ ������ ��� "����"�� ������ �ش� ���� �� �踸ŭ ������ ��� "Ʈ����"�� ������ �ش� ���� �� �踸ŭ ������ ����ϴ�. ������� "��"�� "�ƿ��� ��"�� �ִµ� "ī��Ʈ �ٿ�" ���ӿ����� ���� ���� 50���� ����ϴ�.

��ȸ�� ��ʸ�Ʈ�� ����Ǹ� �� ���ӿ��� �� ������ �����ϰ� �˴ϴ�. ������ �� ������ ����� �� ���� ������ ���� ������� ����˴ϴ�. ���� ���� 0���� ���� ������ �¸��ϴµ� ���� �� ������ ���� ���忡 0���� ����� �� ���� �� "�̱�" �Ǵ� "��"�� �� ���� ���� ������ �¸��ϸ� �׸����� ���ٸ� ������ ������ �¸��մϴ�.

��Ʈ �Ƿ¿� �ڽ� �ִ� ��ȣ�� �� ��ȸ�� �����ϱ�� �Ͽ����ϴ�. �ּ����� ��Ʈ�� 0���� ����� �� ���� �߿��ϰ�, �׷��� ����� ���������� �ִٸ� "�̱�" �Ǵ� "��"�� �ִ��� ���� ������ ����� �����ؾ� �մϴ�.

��ǥ ���� target�� �Ű������� �־����� �� �ּ��� ��� ���� ��Ʈ ���� �� ���� "�̱�" �Ǵ� "��"�� ���� Ƚ��(��)�� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
1 �� target �� 100,000
����� ��
target	result
21	[1,0]
58	[2,2]
����� �� ����
����� �� #1
7 Ʈ���÷� 21���� ���� �� �ֽ��ϴ�.

����� �� #2
�� + 8 �̱۷� 58���� ���� �� �ֽ��ϴ�.
*/