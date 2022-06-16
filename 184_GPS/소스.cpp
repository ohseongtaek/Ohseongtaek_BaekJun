#include <vector>
#include <iostream>

using namespace std;

// n => ������ ���� 
// m => ������ ����
// edge_list => ����� ���� ���� 
// k => �ð��� ���� �������� ���� ������ �� ���� 
// gps_log => �ӹ����� ������ ���� 
// �ùٸ� ��η� �����ϴ� ���� �Ұ����� ��� -1�� ����

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) 
{
    int answer = -1;

    // ������ ���Ϳ� DP �� ���� �ʱ�ȭ 
    vector<vector<int>> edge(n + 1);
    vector<vector<int>> DP(k, vector<int>(n + 1, 2e9));

    // �� �������� ���� 
    for (int i = 0; i < edge_list.size(); i++)
    {
        edge[edge_list[i][0]].push_back(edge_list[i][1]);
        edge[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    // 0��°���� gps_log[0] ���� ���µ� ������ Ƚ�� 0 => ó���� ��ġ�Ѱ��� ������ ������ ���� ������ 0���� �ʱ�ȭ ��Ŵ 
    DP[0][gps_log[0]] = 0;

    // �ð��� ���� ������ ������ �˾ƾ� �ϱ� ������ ���� ū for������ ���� 
    for (int time = 1; time < k; time++)
    {
        for (int pos = 1; pos <= n; pos++)
        {
            // ������ ����Ǿ� ���� �ʴ� ��� �׳� continue
            if (DP[time - 1][pos] == 2e9)
            {
                continue;
            }

            // ������ ����� ũ�⸸ŭ �ݺ� ����
            for (int idx = 0; idx < edge[pos].size(); idx++)
            {
                int next_pos = edge[pos][idx];
                int changed = 0;

                // �������� ������ �����ϵ��� �����ϱ� 
                if (gps_log[time] != next_pos)
                {
                    changed++;
                }

                // ���� ���� ������ ���� �������� ���� DP�� �־ ����� 
                DP[time][next_pos] = min(DP[time][next_pos], DP[time - 1][pos] + changed);
            }
        }
    }

    // ������������ ������ 2e9 ���� �۴ٸ� ������ ������ ������ �� ���� 
    if (DP[k - 1][gps_log[k - 1]] < 2e9)
    {
        answer = DP[k - 1][gps_log[k - 1]];
    }

    return answer;
}

int main()
{
    vector<int> n = { 7,7 };
    vector<int> m = { 10,10 };
    vector<vector<vector<int>>> el = { {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}} ,
                                       {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}} };
    vector<int> k = { 6,6 };
    vector<vector<int>> gl = { {1, 2, 3, 3, 6, 7} , 
                               {1, 2, 4, 6, 5, 7} };

    vector<int> dab = { 1, 0 };

    for (int i = 0; i < dab.size(); i++)
    {
        int answer = solution(n[i], m[i], el[i], k[i], gl[i]);

        if (answer == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << " , want = " << dab[i] << endl;
        }
    }

    return 0;
}
