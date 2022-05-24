#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 19960614;

    vector<vector<int>> vWire(n + 1);

    // �� ��忡 ����� ���� �ֱ� 
    for (int i = 0; i < wires.size(); i++)
    {
        vWire[wires[i][0]].push_back(wires[i][1]);
        vWire[wires[i][1]].push_back(wires[i][0]);
    }

    // �ϳ��� ����� 
    for (int i = 0; i < wires.size(); i++)
    {
        int Result = 0;

        // ��忡 1���� ����� ��� (��ü���� 2�� ���� ���̰� ����)
        if (vWire[wires[i][0]].size() == 1 || vWire[wires[i][1]].size() == 1)
        {
            Result = n - 2;
        }
        // ��ü �湮 Queue �� �̿��� BFS
        else
        {
            bool visit[101] = { 0, };
            queue<int> Q;
            Q.push(wires[i][0]);

            // �⺻ �Է°��� True �� �ʱ�ȭ
            visit[wires[i][0]] = true;
            visit[wires[i][1]] = true;
            Result++;

            while (!Q.empty())
            {
                for (int j = 0; j < vWire[Q.front()].size(); j++)
                {
                    // �湮���� ���� ����� ��� 
                    if (visit[vWire[Q.front()][j]] == false)
                    {
                        Q.push(vWire[Q.front()][j]);
                        visit[vWire[Q.front()][j]] = true;
                        Result++;
                    }
                }
                Q.pop();
            }
            cout << Result << endl;
            Result = abs(n - Result*2);
        }
        answer = min(answer, Result);
    }

    return answer;
}

int main()
{
    int n = 7;
    vector<vector<int>> v = { {1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7} };
    //{ {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    //{ {1, 2}, {2, 3}, {3, 4} };       
    //{ {1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7} };
    int dab = solution(n, v);
    cout << "A = " << dab << endl;
}

//  n	wires	result
//  9 {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} 3
//  4 {{1, 2}, {2, 3}, {3, 4}} 0
//  7 {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}} 1