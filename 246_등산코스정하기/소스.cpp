#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

#define MAX_RANGE 50001

int Pointer[MAX_RANGE];
int intensity[MAX_RANGE];

vector<vector<pair<int, int>>> vp(MAX_RANGE);
    
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    vector<int> answer;
    
    int minintensity = INT_MAX;
    int summit = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        intensity[i] = INT_MAX;
    }

    for (int i = 0; i < summits.size(); i++)
    {
        Pointer[summits[i]] = 2;
    }

    for (int i = 0; i < paths.size(); i++)
    {
        vp[paths[i][0]].push_back(make_pair(paths[i][2],paths[i][1]));
        vp[paths[i][1]].push_back(make_pair(paths[i][2],paths[i][0]));
    }

    priority_queue<pair<int, int>> pqp;

    for (int i = 0; i < gates.size(); i++)
    {
        intensity[gates[i]] = -1;
        pqp.push(make_pair(0, gates[i]));
    }
    

    while (!pqp.empty()) 
    {
        pair<int, int> p;
        p.first = pqp.top().first;
        p.second = pqp.top().second;
        pqp.pop();
        
        if (p.first > minintensity)
        {
            continue;
        }

        if (Pointer[p.second] == 2) 
        {
            if (p.first < minintensity) 
            {
                minintensity = p.first;
                summit = p.second;
            }
            else if (p.first == minintensity && p.second < summit) 
            {
                summit = p.second;
            }

            continue;
        }

        
        for (int i = 0; i < vp[p.second].size(); i++)
        {
            if (intensity[vp[p.second][i].second] > max(p.first, vp[p.second][i].first))
            {
                intensity[vp[p.second][i].second] = max(p.first, vp[p.second][i].first);

                pqp.push({ intensity[vp[p.second][i].second], vp[p.second][i].second });
            }
        }
    }

    answer.push_back(summit);
    answer.push_back(minintensity);

    return answer;
}

int main()
{
    vector<int> n = { 6,7,7,5 };
    vector<vector<vector<int>>> paths = {{ {1, 2, 3}, { 2, 3, 5 }, { 2, 4, 2 }, { 2, 5, 4 }, { 3, 4, 4 }, { 4, 5, 3 }, { 4, 6, 1 }, { 5, 6, 1 }},
                                         { {1, 4, 4}, { 1, 6, 1 }, { 1, 7, 3 }, { 2, 5, 2 }, { 3, 7, 4 }, { 5, 6, 6 }},
                                         { {1, 2, 5}, { 1, 4, 1 }, { 2, 3, 1 }, { 2, 6, 7 }, { 4, 5, 1 }, { 5, 6, 1 }, { 6, 7, 1 }},
                                         { {1, 3, 10}, { 1, 4, 20 }, { 2, 3, 4 }, { 2, 4, 6 }, { 3, 5, 20 }, { 4, 5, 6 }}};
    vector<vector<int>> gates = {{1, 3},
                                 {1},
                                 {3, 7},
                                 {1, 2}};
    vector<vector<int>> summits = { {5},
                                    {2, 3, 4},
                                    {1, 5},
                                    {5}};
    vector<vector<int>> dab = { {5, 3},
                                {3, 4},
                                {5, 1},
                                {5, 6}};

    for (int i = 0; i < n.size(); i++)
    {
        vector<int> ans = solution(n[i], paths[i], gates[i], summits[i]);

        bool flag = false;
        for (int j = 0; j < dab[i].size(); j++)
        {
            if (dab[i][j] != ans[j])
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
XX���� n���� �������� �̷���� �ֽ��ϴ�. 
�� ������ 1���� n���� ��ȣ�� �پ�������, ���Ա�, ����, Ȥ�� ����츮�Դϴ�. 
�� ������ ����� ������ ������ ���η� ����Ǿ� ������, ���� �ٸ� ������ �̵��� �� �� ���θ� �̿��ؾ� �մϴ�. 
�̶�, ���κ��� �̵��ϴµ� ���� �ð��� �ҿ�˴ϴ�.

����ڽ��� �湮�� ���� ��ȣ���� ������� �����Ͽ� ǥ���� �� �ֽ��ϴ�.
���� ��� 1-2-3-2-1 ���� ǥ���ϴ� ����ڽ��� 1���������� ����Ͽ� 2��, 3��, 2��, 1�� ������ ������� �湮�Ѵٴ� ���Դϴ�.
����ڽ��� ���� �̵��ϴ� �� ���� Ȥ�� ����츮�� �湮�� ������ �޽��� ���� �� ������, �޽� ���� �̵��ؾ� �ϴ� �ð� �� ���� �� �ð��� �ش� ����ڽ��� intensity��� �θ���� �մϴ�.

����� XX���� ���Ա� �� �� ������ ����Ͽ� ����츮 �� �� ���� �湮�� �� �ٽ� ������ ���Ա��� ���ƿ��� ����ڽ��� ���Ϸ��� �մϴ�. 
�ٽ� ����, ����ڽ����� ���Ա��� ó���� ���� �� ����, ����츮�� �� ���� ���ԵǾ�� �մϴ�.
����� �̷��� ��Ģ�� ��Ű�鼭 intenssity�� �ּҰ� �ǵ��� ����ڽ��� ���Ϸ��� �մϴ�.

�� �׸����� ���� ���� ���ڴ� ������ ��ȣ�� ��Ÿ����, 1, 3�� ������ ���Ա�, 5�� ������ ����츮�� �ֽ��ϴ�. 
�� ������ ���θ� ��Ÿ����, �� ���п� ���� ���� �̵� �ð��� ��Ÿ���ϴ�. 
���� ��� 1�� �������� 2�� �������� �̵��� ���� 3�ð��� �ҿ�˴ϴ�.
���� ���ÿ��� 1-2-5-4-3 �� ���� ����ڽ��� ó�� ����� ������ ���Ա��� ���ƿ��� �ʱ� ������ �߸��� ����ڽ��Դϴ�. 
���� 1-2-5-6-4-3-2-1 �� ���� ����ڽ��� �ڽ��� ó���� �� �ܿ� 3�� ���Ա��� �湮�ϱ� ������ �߸��� ����ڽ��Դϴ�.

�̶�, �޽� ���� �̵��ؾ� �ϴ� �ð� �� ���� �� �ð��� 5�ð��Դϴ�. ���� �� ����ڽ��� intensity�� 5�Դϴ�.
����ڽ��� 1-2-4-5-6-4-2-1 �� ���� ������ ���� �̵���θ� �׸����� ��Ÿ���� �Ʒ��� �����ϴ�.
�̶�, �޽� ���� �̵��ؾ� �ϴ� �ð� �� ���� �� �ð��� 3�ð��Դϴ�. 
���� �� ����ڽ��� intensity�� 3�̸�, �� ���� intensity�� ���� ����ڽ��� �����ϴ�.

XX���� ���� �� n, 
�� ������ ������ ���� 2���� ���� �迭 paths, 
���Ա����� ��ȣ�� ��� ���� �迭 gates, 
����츮���� ��ȣ�� ��� ���� �迭 summits�� �Ű������� �־����ϴ�. 

�̶�, intensity�� �ּҰ� �Ǵ� ����ڽ��� ���Ե� 
����츮 ��ȣ�� intensity�� �ּڰ�
�� ���ʴ�� ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���. 
intensity�� �ּҰ� �Ǵ� ����ڽ��� ���� ����� 
���� ����츮�� ��ȣ�� ���� ���� ����ڽ��� �����մϴ�.

���ѻ���
2 �� n �� 50,000
n - 1 �� paths�� ���� �� 200,000
paths�� ���Ҵ� {i, j, w} �����Դϴ�.
i�� ������ j�� ������ �����ϴ� ���ΰ� �ִٴ� ���Դϴ�.
w�� �� ���� ���̸� �̵��ϴ� �� �ɸ��� �ð��Դϴ�.
1 �� i < j �� n
1 �� w �� 10,000,000
���� �ٸ� �� ������ ���� �����ϴ� ���δ� �ִ� 1���Դϴ�.
1 �� gates�� ���� �� n
1 �� gates�� ���� �� n
gates�� ���Ҵ� �ش� ������ ���Ա����� ��Ÿ���ϴ�.
1 �� summits�� ���� �� n
1 �� summits�� ���� �� n
summits�� ���Ҵ� �ش� ������ ����츮���� ��Ÿ���ϴ�.
���Ա��̸鼭 ���ÿ� ����츮�� ������ �����ϴ�.
gates�� summits�� �������� ���� ������ ��� �����Դϴ�.
������ �� ���� ���̿� �̵� ������ ��ΰ� �׻� �����մϴ�.
return �ϴ� �迭�� {����츮�� ��ȣ, intensity�� �ּڰ�} �������� �մϴ�.
����� ��
n	paths	gates	summits	result

*/