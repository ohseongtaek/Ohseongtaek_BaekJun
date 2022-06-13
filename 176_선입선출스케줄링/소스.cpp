#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �߰��ð��� �������� �۾� ������ �ھ��� ������ ������ 
int Work(int time_mid, vector<int> cores)
{
    // �ð��� 0�ΰ�� ��� �ھ �۾��� �����ϴ�.
    if (time_mid == 0)
    {
        return cores.size();
    }
    else
    {
        int Cnt = cores.size();

        // �߰� �ð����� �� �ھ ó���Ҽ� �ִ� �۾����� �ջ���
        for (int i = 0; i < cores.size(); i++)
        {
            Cnt += time_mid / cores[i];
        }
        return Cnt;
    }
}

int solution(int n, vector<int> cores) 
{
    int answer = 0;
    
    // �Ķ��Ʈ�� ��ġ (�̺�Ž��)

    int time_min = 0;
    int time_max = cores[0] * n;
    int time_item = 0;
    int time_work = 0;

    while (time_min <= time_max)
    {
        int time_mid = (time_min + time_max) / 2;
        int count = Work(time_mid, cores);

        // �۾��� ���� n ���� ũ�� ���ŷ���
        if (count >= n)
        {
            time_max = time_mid - 1;
            time_item = time_mid;
            time_work = count;
        }
        else
        {
            time_min = time_mid + 1;
        }
    }

	// ó���� �۾����� n�� ���� ����
	time_work -= n;

	for (int i = cores.size() - 1; i >= 0; i--)
	{
		// �ð��� �۾��� ó���ϴ� core 
		if (time_item % cores[i] == 0)
		{
			if (time_work == 0)
			{
				answer = i + 1;
				break;
			}
			time_work--;
		}
	}
    
    return answer;
}


int main()
{
    int n = 6;
    vector<int> c = { 1,2,3 };

    int dab = solution(n, c);

    if (dab == 2)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}