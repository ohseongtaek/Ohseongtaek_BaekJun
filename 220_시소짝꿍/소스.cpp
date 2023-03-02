#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(vector<int> weights) 
{
    long long answer = 0;

    //������ ���� 100 ~ 1000 
    vector<long long> v(1001, 0);

    //���� ���� ������ �����԰� �ִ°��� �ϳ��� üũ���ֱ� 
    for (int i = 0; i < weights.size(); i++)
    {
        v[weights[i]]++;
    }

    // ���� �����Կ� 2:3 3:4 2:4  �� ���� ���� ��� ����ؼ� �־��ֱ� ��, 1000 �� �ִ��̹Ƿ� 1000�� ������ ���ٰ� �����ϰ� ���� ���� 
    for (int i = 0; i < weights.size(); i++)
    {
        long long calWeights = 0;

        if (weights[i] % 2 == 0)
        {
            // 2:3 �ΰ�� ����� ���Ϳ� �ִ� ���� �־��ش� 0�ϼ����ְ� �ƴҼ������� 
            calWeights = (weights[i] / 2) * 3;
            if (calWeights <= 1000)
            {
                answer += v[calWeights];
            }
        }
        if (weights[i] % 3 == 0)
        {
            // 3:4 �ΰ�� ����� ���Ϳ� �ִ� ���� �־��ش� 0�ϼ����ְ� �ƴҼ������� 
            calWeights = (weights[i] / 3) * 4;
            if (calWeights <= 1000)
            {
                answer += v[calWeights];
            }
        }
        // 2:4 �ΰ�� ����� ���Ϳ� �ִ� ���� �־��ش� 0�ϼ����ְ� �ƴҼ������� 
		calWeights = weights[i] * 2;
		if (calWeights <= 1000)
		{
			answer += v[calWeights];
		}
    }

    // 100 ~ 1000�����Ա��� ����ؼ� ���� �������ΰ�� �����Ǽ��� ��� ����Ǽ��� �����ش�
    for (int i = 100; i <= 1000; i++)
    {
        if (v[i] >= 2)
        {
            answer += (long long)(v[i] * (v[i] - 1)) / 2;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> v = { {100,180,360,100,270} };
    long long test = solution(v[0]);

    if (test == 4)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }

}