#include <string>
#include <iostream>
#include <vector>

using namespace std;

// ���� ����Ʈ : https://prgms.tistory.com/108 (���� �ڵ� ç���� �ؼ� ����Ʈ)


//�� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ����(query(0, dx))
//�� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ����(query(1, dx))
//�� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ����(query(2, dx))
//�� ��ȣ�� �����ϴ� �������� dxĭ �̵��ϴ� ����(query(3, dx))

enum DIRECTION
{
    COL_DOWN = 0,   // �� ��ȣ�� ����
    COL_UP,         // �� ��ȣ�� ����
    ROW_DOWN,       // �� ��ȣ�� ����
    ROW_UP          // �� ��ȣ�� ����
};


long long solution(int n, int m, int x, int y, vector<vector<int>> queries) 
{
    long long answer = -1;

    // �� �ʱ�ȭ (��� ���� ���� �и��ؼ� ����)
    long long pos_Arr[4] = { x,x,y,y };

    // ���� ���� ���� 
    for (int i = queries.size() - 1; i >= 0; i--)
    {
        // ����ȣ ���� 
        if (queries[i][0] == COL_DOWN)
        {
            if (pos_Arr[2] > 0)
            {
                if (queries[i][1] > m - 1 - pos_Arr[2])
                {
                    return 0;
                }
                if (pos_Arr[2] + queries[i][1] >= m)
                {
                    pos_Arr[2] = m - 1;
                }
                else
                {
                    pos_Arr[2] = pos_Arr[2] + queries[i][1];
                }
            }
            if (pos_Arr[3] + queries[i][1] >= m)
            {
                pos_Arr[3] = m - 1;
            }
            else
            {
                pos_Arr[3] = pos_Arr[3] + queries[i][1];
            }
        }
        // ����ȣ ���� 
        else if (queries[i][0] == COL_UP)
        {
            if (pos_Arr[3] < m - 1)
            {
                if (queries[i][1] > pos_Arr[3])
                {
                    return 0;
                }
                if (pos_Arr[3] - queries[i][1] < 0)
                {
                    pos_Arr[3] = 0;
                }
                else
                {
                    pos_Arr[3] = pos_Arr[3] - queries[i][1];
                }
            }
            if (pos_Arr[2] - queries[i][1] < 0)
            {
                pos_Arr[2] = 0;
            }
            else
            {
                pos_Arr[2] = pos_Arr[2] - queries[i][1];
            }
        }
        // ���ȣ ����
        else if (queries[i][0] == ROW_DOWN)
        {
            if (pos_Arr[0] > 0)
            {
                if (queries[i][1] > n - 1 - pos_Arr[0])
                {
                    return 0;
                }
                if (pos_Arr[0] + queries[i][1] >= n)
                {
                    pos_Arr[0] = n - 1;
                }
                else
                {
                    pos_Arr[0] = pos_Arr[0] + queries[i][1];
                }
            }
            if (pos_Arr[1] + queries[i][1] >= n)
            {
                pos_Arr[1] = n - 1;
            }
            else
            {
                pos_Arr[1] = pos_Arr[1] + queries[i][1];
            }
        }
        // ���ȣ ���� 
        else if (queries[i][0] == ROW_UP)
        {
            if (pos_Arr[1] < n - 1)
            {
                if (queries[i][1] > pos_Arr[1])
                {
                    return 0;
                }
                if (pos_Arr[1] - queries[i][1] < 0)
                {
                    pos_Arr[1] = 0;
                }
                else
                {
                    pos_Arr[1] = pos_Arr[1] - queries[i][1];
                }
            }
            if (pos_Arr[0] - queries[i][1] < 0)
            {
                pos_Arr[0] = 0;
            }
            else
            {
                pos_Arr[0] = pos_Arr[0] - queries[i][1];
            }
        }
    }

    answer = (pos_Arr[1] - pos_Arr[0] + 1) * (pos_Arr[3] - pos_Arr[2] + 1);
    return answer;
}

int main()
{
    vector<int> n = { 2,2 };
    vector<int> m = { 2,5 };
    vector<int> x = { 0,0, };
    vector<int> y = { 0,1 };

    vector<vector<vector<int>>> q = { {{2, 1}, {0, 1}, {1, 1}, {0, 1}, {2, 1}}, { {3, 1}, {2, 2}, {1, 1}, {2, 3}, {0, 1}, {2, 1}} };
    
    vector<int> answer = { 4,2 };

    for (int i = 0; i < q.size(); i++)
    {
        long long test = solution(n[i], m[i], x[i], y[i], q[i]);
        if (test == answer[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << test << ", [want] = " << answer[i] << endl;
        }
    }
        
    
}