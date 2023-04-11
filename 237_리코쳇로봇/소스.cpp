#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(vector<string>& b, int Garo, int Sero, int i, int j)
{
    // �湮 
    vector<vector<int>> visit(Garo, vector<int>(Sero));

    // ���� �� 
    vector<vector<int>> depth(Garo, vector<int>(Sero, 100000));

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visit[i][j] = 1;
    depth[i][j] = 0;

    while (q.empty() == false)
    {
        int currGaro = q.front().first;
        int currSero = q.front().second;

        q.pop();

        // �����¿� �̵� 
        for (int i = 0; i < 4; i++)
        {
            int nextGaro = currGaro;
            int nextSero = currSero;

            while (true)
            {
                nextGaro += dy[i];
                nextSero += dx[i];
                if (nextGaro < 0 || nextGaro >= Garo || nextSero < 0 || nextSero >= Sero) 
                {
                    nextGaro -= dy[i];
                    nextSero -= dx[i];
                    break;
                }
                if (b[nextGaro][nextSero] == 'D')
                {
                    nextGaro -= dy[i];
                    nextSero -= dx[i];
                    break;
                }
            }

            if (visit[nextGaro][nextSero] == true)
            {
                continue;
            }
            else
            {
                visit[nextGaro][nextSero] = 1;
                depth[nextGaro][nextSero] = min(depth[nextGaro][nextSero], depth[currGaro][currSero] + 1);
                q.push(make_pair(nextGaro, nextSero));
            }
        }
    }
    for (int i = 0; i < depth.size(); i++)
    {
        for (int j = 0; j < depth[i].size(); j++)
        {
            if (b[i][j] == 'G')
            {
                if (depth[i][j] == 100000)
                {
                    return -1;
                }
                return depth[i][j];
            }
        }
    }
    return 0;
}


int solution(vector<string> board) 
{
    int answer = 0;
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                int nAnswer = BFS(board, board.size(), board[i].size(), i, j);
                answer = nAnswer;
                break;
            }
        }

        if (answer != 0)
        {
            break;
        }
    }


    return answer;
}

int main()
{
    vector<vector<string>> v = { {  "...D..R", 
                                    ".D.G...", 
                                    "....D.D", 
                                    "D....D.", 
                                    "..D...."},

                                    {   ".D.R", 
                                        "....", 
                                        ".G..", 
                                        "...D"} };
    
    vector<int> d = { 7,-1 };

    for (int i = 0; i < v.size(); i++)
    {
        int dab = solution(v[i]);

        if (dab == d[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
        }
    }
}

/*
������ �κ��̶�� ��������� �ֽ��ϴ�.

�� ��������� ���ڸ�� ������ ������ ���� �����̴� ��������, ���� ��ġ���� ��ǥ ��ġ���� �ּ� �� ������ ������ �� �ִ��� ���ϴ� �����Դϴ�.

�� ���ӿ��� ���� �������� ��, ��, ��, �� 4���� �� �ϳ��� �����ؼ� ������ ���� ��ֹ��̳� �� ���� �ε��� ������ �̲����� �̵��ϴ� ���� �� ���� �̵����� Ĩ�ϴ�.

������ ����������� ��Ÿ�� �����Դϴ�.

...D..R
.D.G...
....D.D
D....D.
..D....
���⼭ "."�� �� ������,
"R"�� �κ��� ó�� ��ġ��, 
"D"�� ��ֹ��� ��ġ��, 
"G"�� ��ǥ������ ��Ÿ���ϴ�.
�� ���ÿ����� "R" ��ġ���� �Ʒ�, ����, ��, ����, �Ʒ�, ������, �� ������ �����̸� 7�� ���� "G" ��ġ�� ���� �� �� ������, �̰��� �ּ� ������ �� �ϳ��Դϴ�.

�������� ���¸� ��Ÿ���� ���ڿ� �迭 board�� �־����� ��, ���� ��ǥ��ġ�� �����ϴµ� �ּ� �� �� �̵��ؾ� �ϴ��� return �ϴ� solution�Լ��� �ϼ��ϼ���. ���� ��ǥ��ġ�� ������ �� ���ٸ� -1�� return ���ּ���.

���� ����
3 �� board�� ���� �� 100
3 �� board�� ������ ���� �� 100
board�� ������ ���̴� ��� �����մϴ�.
���ڿ��� ".", "D", "R", "G"�θ� �����Ǿ� ������ ���� �� ����, ��ֹ�, �κ��� ó�� ��ġ, ��ǥ ������ ��Ÿ���ϴ�.
"R"�� "G"�� �� ���� �����մϴ�.
����� ��
board	result

����� �� ����
����� �� #1

���� ������ ���ÿ� �����ϴ�.
����� �� #2

.D.R
....
.G..
...D
"R" ��ġ�� �ִ� ���� ��� �������� "G" �� ���޽�ų �� �����ϴ�.
���� -1�� return �մϴ�.
*/