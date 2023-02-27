#include <string>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

#define NOT_VISIT -1

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size(), NOT_VISIT);
    stack<pair<int, int>> sp;

    for (int i = 0; i < numbers.size(); i++)
    {
        while (true)
        {
            if (sp.empty() == true)
            {
                break;
            }
            else
            {
                auto spTop = sp.top();

                if (spTop.first >= numbers[i])
                {
                    break;
                }
                else
                {
                    answer[spTop.second] = numbers[i];
                    sp.pop();
                }
            }
        }
        sp.push(make_pair(numbers[i], i));
    }

    return answer;
}

int main()
{
    vector<vector<int>> vv = { {2, 3, 3, 5}, {9, 1, 5, 3, 6, 2} };
    vector<vector<int>> an = { {3, 5, 5, -1},{-1, 5, 6, 6, -1, -1} };

    for (int i = 0; i < vv.size(); i++)
    {
        vector<int> r = solution(vv[i]);

        bool flag = false;
        for (int j = 0; j < r.size(); j++)
        {
            if (r[j] != an[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "good" << endl;
        }
    }
}

/*
������ �̷���� �迭 numbers�� �ֽ��ϴ�. �迭 �� �� ���ҵ鿡 ���� �ڽź��� �ڿ� �ִ� ���� �߿��� �ڽź��� ũ�鼭 ���� ������ �ִ� ���� �� ū����� �մϴ�.
���� �迭 numbers�� �Ű������� �־��� ��, ��� ���ҿ� ���� �� ū������ ���ʷ� ���� �迭�� return �ϵ��� solution �Լ��� �ϼ����ּ���. ��, �� ū���� �������� �ʴ� ���Ҵ� -1�� ����ϴ�.

���ѻ���
4 �� numbers�� ���� �� 1,000,000
1 �� numbers{i} �� 1,000,000
����� ��
numbers	result
	
����� �� ����
����� �� #1
2�� �� ū���� 3�Դϴ�. ù ��° 3�� �� ū���� 5�Դϴ�. �� ��° 3 ���� ���������Դϴ�. 5�� �� ū���� �����Ƿ� -1�Դϴ�. �� ������ ���ʴ�� �迭�� ������ {3, 5, 5, -1}�� �˴ϴ�.

����� �� #2
9�� �� ū���� �����Ƿ� -1�Դϴ�. 1�� �� ū���� 5�̸�, 5�� 3�� �� ū���� 6�Դϴ�. 6�� 2�� �� ū���� �����Ƿ� -1�Դϴ�. �� ������ ���ʴ�� �迭�� ������ {-1, 5, 6, 6, -1, -1}�� �˴ϴ�.
*/