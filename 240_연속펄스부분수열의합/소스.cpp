#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(vector<int> sequence)
{
	long long answer = 0;

	vector<ll> PP(sequence.size() + 1);
	vector<ll> PM(sequence.size() + 1);

	for (int i = sequence.size() - 1; i >= 0; i--)
	{
		ll MLeft = -sequence[i];
		ll MRight = -sequence[i] + PP[i + 1];
		ll PLeft = sequence[i];
		ll PRight = sequence[i] + PM[i + 1];

		PM[i] = max(MLeft,MRight);
		PP[i] = max(PLeft,PRight);
		answer = max(answer, max(PM[i], PP[i]));
	}
	return answer;
}

int main()
{
    vector<int> v = { 2, 3, -6, 1, 3, -1, 2, 4 };
    int dab = solution(v);
    if (dab == 10)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}


/*
� ������ ���� �κ� ������ ���� ������ �޽� ������ �� ���ҳ��� ���Ͽ� ���� �޽� �κ� ������ ����� �մϴ�. 
�޽� �����̶� {1, -1, 1, -1 ��} �Ǵ� {-1, 1, -1, 1 ��} �� ���� 1 �Ǵ� -1�� �����ϸ鼭 1�� -1�� ������ ������ �����Դϴ�.

���� ��� ���� {2, 3, -6, 1, 3, -1, 2, 4}�� ���� �κ� ���� {3, -6, 1}�� �޽� ���� {1, -1, 1}�� ���ϸ� ���� �޽� �κм����� {3, 6, 1}�� �˴ϴ�. 
�� �ٸ� ���÷� ���� �κ� ���� {3, -1, 2, 4}�� �޽� ���� {-1, 1, -1, 1}�� ���ϸ� ���� �޽� �κм����� {-3, -1, -2, 4}�� �˴ϴ�.
���� ���� sequence�� �Ű������� �־��� ��, ���� �޽� �κ� ������ �� �� ���� ū ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� ����
1 �� sequence�� ���� �� 500,000
-100,000 �� sequence�� ���� �� 100,000
sequence�� ���Ҵ� �����Դϴ�.
����� ��
sequence	result
{2, 3, -6, 1, 3, -1, 2, 4}	10
����� �� ����
�־��� ������ ���� �κ� ���� {3, -6, 1}�� �޽� ���� {1, -1, 1}�� ���Ͽ� ���� �޽� �κ� ���� {3, 6, 1}�� ���� �� �ְ� �� ���� 10���μ� ���� Ů�ϴ�.
*/
