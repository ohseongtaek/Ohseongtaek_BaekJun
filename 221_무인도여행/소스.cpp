#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;

    // �湮�ߴ��� Ȯ���ϱ� 
    bool visit[101][101];
    pair<int, int> m[4] = { {-1,0},{1,0},{0,-1},{0,1} };

    memset(visit, false, sizeof(visit));
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'X' || visit[i][j] == true)
            {
                continue;
            }
            else
            {
                queue<pair<int, int>> qp;
                qp.push(make_pair(i, j));
                visit[i][j] = true;

                int value = maps[i][j] - '0';

                while (qp.empty() == false)
                {
                    auto pfront = qp.front();
                    qp.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nextX = pfront.first + m[k].first;
                        int nextY = pfront.second + m[k].second;

                        if (nextX <0 || nextX >= maps.size())
                        {
                            continue;
                        }

                        if (nextY <0 || nextY >= maps[0].size())
                        {
                            continue;
                        }

                        if (maps[nextX][nextY] == 'X')
                        {
                            continue;
                        }

                        if (visit[nextX][nextY] == true)
                        {
                            continue;
                        }

                        visit[nextX][nextY] = true;
                        value += maps[nextX][nextY] - '0';

                        qp.push(make_pair(nextX, nextY));
                    }
                }

                answer.push_back(value);
            }
        }
    }

    sort(answer.begin(),answer.end());

    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }

    return answer;
}

int main()
{
    vector<vector<string>> vv = { { "X591X",
                                    "X1X5X",
                                    "X231X", 
                                    "1XXX1" },

                                    {"XXX", 
                                     "XXX", 
                                     "XXX"} };

    vector<vector<int>> an = { {1, 1, 27}, { -1 } };

    for (int i = 0; i < vv.size(); i++)
    {
        vector<int> k = solution(vv[i]);

        bool flag = true;

        for (int j = 0; j < k.size(); j++)
        {
            if (k[j] != an[i][j])
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            cout << "good " << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}


/*
���� ����
�޸��� ������ �¾� ���ε��� ������ ���� ���� ������ ���� �ֽ��ϴ�. 
�������� �ٴٿ� ���ε��鿡 ���� ������ ǥ�õ� �ֽ��ϴ�. 
������ 1 x 1ũ���� �簢����� �̷���� ���簢�� ���� �����̸�, 
������ �� ĭ���� 'X' �Ǵ� 1���� 9 ������ �ڿ����� �����ֽ��ϴ�. 
������ 'X'�� �ٴٸ� ��Ÿ����, ���ڴ� ���ε��� ��Ÿ���ϴ�. �̶�, ��, ��, ��, ��� ����Ǵ� ������ �ϳ��� ���ε��� �̷�ϴ�. 
������ �� ĭ�� ���� ���ڴ� �ķ��� ��Ÿ���µ�, ��, ��, ��, ��� ����Ǵ� ĭ�� ���� ���ڸ� ��� ���� ���� �ش� ���ε����� �ִ� ��ĥ���� �ӹ� �� �ִ����� ��Ÿ���ϴ�. 
� ������ � ���� �� ���� �޸��� �켱 �� ������ �ִ� ��ĥ�� �ӹ� �� �ִ��� �˾ƺ� �� ��� ���� �����Ϸ� �մϴ�.

������ ��Ÿ���� ���ڿ� �迭 maps�� �Ű������� �־��� ��, 
�� ������ �ִ� ��ĥ�� �ӹ��� �� �ִ��� �迭�� ������������ ��� return �ϴ� solution �Լ��� �ϼ����ּ���. ���� ���� �� �ִ� ���ε��� ���ٸ� -1�� �迭�� ��� return ���ּ���.

���ѻ���
3 �� maps�� ���� �� 100
3 �� maps{i}�� ���� �� 100
maps{i}�� 'X' �Ǵ� 1 �� 9 ������ �ڿ����� �̷���� ���ڿ��Դϴ�.
������ ���簢�� �����Դϴ�.
����� ��
maps	result

����� �� ����
����� �� #1

�� ���ڿ��� ������ ���� ������ ��Ÿ���ϴ�.

image1

����� ������ ���� ��ġ�� ������ ������

image2

�̸� ������������ �����ϸ� {1, 1, 27}�� �˴ϴ�.

����� �� #2

�� ���ڿ��� ������ ���� ������ ��Ÿ���ϴ�.

image3

���� �������� �ʱ� ������ -1�� �迭�� ��� ��ȯ�մϴ�.
*/