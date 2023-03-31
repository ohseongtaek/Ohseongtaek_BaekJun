#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;

    int rangeY = park.size();
    int rangeX = park[0].size();

    int currentX = 0;
    int currentY = 0;

    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                currentX = i;
                currentY = j;
            }
        }
    }

    vector<pair<char, int>> vp;

    for (int i = 0; i < routes.size(); i++)
    {
        char szDir = routes[i][0];
        int nCnt = routes[i][2] - '0';

        int tempX = currentX;
        int tempY = currentY;

        bool flag = true;
        bool ForCase = true;

        /*
           N : �������� �־��� ĭ��ŭ �̵��մϴ�.
           S : �������� �־��� ĭ��ŭ �̵��մϴ�.
           W : �������� �־��� ĭ��ŭ �̵��մϴ�.
           E : �������� �־��� ĭ��ŭ �̵��մϴ�.
       */
        if (szDir == 'N')
        {
            currentX = currentX - nCnt;
            ForCase = false;
        }
        else if (szDir == 'S')
        {
            currentX = currentX + nCnt;
            ForCase = true;
        }
        else if (szDir == 'W')
        {
            currentY = currentY - nCnt;
            ForCase = false;
        }
        else if (szDir == 'E')
        {
            currentY = currentY + nCnt;
            ForCase = true;
        }

        if (currentX < 0 || currentX >= rangeY || currentY < 0 || currentY >= rangeX)
        {
            currentX = tempX;
            currentY = tempY;
            continue;
        }

        if (ForCase == true)
        {
            for (int x = tempX; x <= currentX; x++)
            {
                for (int y = tempY; y <= currentY; y++)
                {
                    if (park[x][y] == 'X')
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == false)
                {
                    break;
                }
            }
        }
        else
        {
            for (int x = currentX; x <= tempX; x++)
            {
                for (int y = currentY; y <= tempY; y++)
                {
                    if (park[x][y] == 'X')
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == false)
                {
                    break;
                }
            }
        }

        if (flag == false)
        {
            currentX = tempX;
            currentY = tempY;
            continue;
        }

    }
    answer.push_back(currentX);
    answer.push_back(currentY);
    return answer;
}

int main()
{
    vector<vector<string>> p = { {  "SOO",
                                    "OOO",
                                    "OOO" },

                                    {"SOO",
                                     "OXX",
                                     "OOO"},

                                    {"OSO",
                                     "OOO",
                                     "OXO",
                                     "OOO" },
    {"SOO","OOO","OOO"},
    {"SOO","OXX","OOO"},
    {"OSO","OOO","OXO","OOO"},

    {"OSO","OOO","OOO","OOO"},
    {"OSO","OOO","OOO","OOO"},
    {"OSO","OOO","OOO","OOO"},
    {"OSO","OOO","OOO","OOO"},

    {"XXX","XSX","XXX"},
    {"XXX","XSX","XXX"},
    {"XXX","XSX","XXX"},
    {"XXX","XSX","XXX"},

    {"SOXOO","OOOOO","OOOOO", "OOOOO", "OOOOO"},
    {"SOOOX","OOOOO","OOOOO", "OOOOO", "OOOOO"},
    {"XOOOS","OOOOO","OOOOO", "OOOOO", "OOOOO"},
    {"OOXOS","OOOOO","OOOOO", "OOOOO", "OOOOO"},
    {"SOOOO","OOOOO","XOOOO", "OOOOO", "OOOOO"},
    {"SOOOO","OOOOO","OOOOO", "OOOOO", "XOOOO"},
    {"OOOOO","OOOOO","XOOOO", "OOOOO", "SOOOO"},
    {"XOOOO","OOOOO","OOOOO", "OOOOO", "SOOOO"},
    
    };

    vector<vector<string>> r = { {"E 2", "S 2", "W 1"}, {"E 2", "S 2", "W 1"}, {"E 2", "S 3", "W 1"},
    
    {"E 2","S 2","W 1"},
    {"E 2","S 2","W 1"},
    {"E 2","S 3","W 1"},

    {"W 2"},
    {"N 2"},
    {"S 5"},
    {"E 5"},
           
    {"E 1"},
    {"W 1"},
    {"S 1"},
    {"N 1"},
           
    {"E 3"},
    {"E 3"},
    {"W 3"},
    {"W 3"},
    {"S 3"},
    {"S 3"},
    {"N 3"},
    {"N 3"},
    
    };
    vector<vector<int>> va = { { 2, 1 }, {0, 1}, {0, 0},
    {2,1},
    {0,1},
    {0,0},
         
    {0,1},
    {0,1},
    {0,1},
    {0,1},
         
    {1,1},
    {1,1},
    {1,1},
    {1,1},

    {0, 0},
    {0, 3},
    {0, 1},
    {0, 4},
    {0, 0},
    {3, 0},
    {4, 0},
    {1, 0}
    
    };

    for (int i = 0; i < va.size(); i++)
    {
        vector<int> dab = solution(p[i], r[i]);

        bool flag = false;
        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != va[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << " error " << i << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }

}


/*
�����ٴϴ� ���� 'O', ��ֹ��� 'X'�� ��Ÿ�� ���簢�� ���� ����� �������� �κ� �������� ��å�� �Ϸ��մϴ�. ��å�� �κ� �������� �̸� �Էµ� ��ɿ� ���� �����ϸ�, ����� ������ ���� �������� �־����ϴ�.

{"���� �Ÿ�", "���� �Ÿ�" �� }
���� ��� "E 5"�� �κ� �������� ���� ��ġ���� �������� 5ĭ �̵��ߴٴ� �ǹ��Դϴ�. �κ� �������� ����� �����ϱ� ���� ���� �� ������ ���� Ȯ���մϴ�.

�־��� �������� �̵��� �� ������ ������� Ȯ���մϴ�.
�־��� �������� �̵� �� ��ֹ��� �������� Ȯ���մϴ�.
�� �� ������ ��� �ϳ��� �ش�ȴٸ�, �κ� �������� �ش� ����� �����ϰ� ���� ����� �����մϴ�.
������ ���� ���̰� W, ���� ���̰� H��� �� ��, ������ ���� ����� ��ǥ�� (0, 0), ���� �ϴ��� ��ǥ�� (H - 1, W - 1) �Դϴ�.

image

������ ��Ÿ���� ���ڿ� �迭 park, �κ� �������� ������ ����� ��� ���ڿ� �迭 routes�� �Ű������� �־��� ��, �κ� �������� ��� ����� ���� �� ���� ��ġ�� {���� ���� ��ǥ, ���� ���� ��ǥ} ������ �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
3 �� park�� ���� �� 50
3 �� park{i}�� ���� �� 50
park{i}�� ���� ���ڵ�� �̷���� ������ ���������� �ϳ��� �־����ϴ�.
S : ���� ����
O : �̵� ������ ���
X : ��ֹ�
park�� ���簢�� ����Դϴ�.
1 �� routes�� ���� �� 50
routes�� �� ���Ҵ� �κ� �������� ������ ��ɾ ��Ÿ���ϴ�.
�κ� �������� routes�� ù ��° ���Һ��� ������� ����� �����մϴ�.
routes�� ���Ҵ� "op n"�� ���� ������ �̷���� ������, op�� �̵��� ����, n�� �̵��� ĭ�� ���� �ǹ��մϴ�.
op�� ���� �� ������ �ϳ��� �̷���� �ֽ��ϴ�.
N : �������� �־��� ĭ��ŭ �̵��մϴ�.
S : �������� �־��� ĭ��ŭ �̵��մϴ�.
W : �������� �־��� ĭ��ŭ �̵��մϴ�.
E : �������� �־��� ĭ��ŭ �̵��մϴ�.
1 �� n �� 9
����� ��

����� �� ����
����� �� #1

�Էµ� ��ɴ�� �������� 2ĭ, �������� 2ĭ, �������� 1ĭ �̵��ϸ� {0,0} -> {0,2} -> {2,2} -> {2,1}�� �˴ϴ�.

����� �� #2

�Էµ� ��ɴ�ζ�� �������� 2ĭ, �������� 2ĭ, �������� 1ĭ �̵��ؾ������� �������� 2ĭ �̵��� �� ��ֹ��� �ִ� ĭ�� ������ ������ �ش� ����� ������ ��ɵ鸸 �����ϴ�. ��������δ� {0,0} -> {0,2} -> {0,1}�� �˴ϴ�.

����� �� #3

ó�� �Էµ� ����� ������ ������ �ǰ� �� ��°�� �Էµ� ��� ���� ��ֹ��� �������� �ǹǷ� �� �Է��� ������ �� ��° ��ɸ� �����Ƿ� ����� ������ �����ϴ�. {0,1} -> {0,0}
*/