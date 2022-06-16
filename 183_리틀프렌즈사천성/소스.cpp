#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct BFS_INFO
{
    int x;
    int y;
    int dir;
    int cnt;
};

bool BFS(int x, int y, int x1, int y1, vector<string>& board, int m, int n)
{
    int dx[] = { 1,0,-1,0 };
    int dy[] = { 0,1,0,-1 };

    queue<BFS_INFO> q;

    q.push({ x,y,-1,0 });

    while (q.empty() == false)
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_dir = q.front().dir;
        int current_change_dir_cnt = q.front().cnt;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            // �ڷ� ���ٸ� continue -> �ּڰ��� �� �� ���� ������ 
            if (current_dir != -1 && abs(current_dir - i) == 2)
            {
                continue;
            }
            
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            int next_change_dir_cnt = 0;

            // ������ �ٸ��ٸ� Ʋ��� �ϱ� ������ 
            if ((current_dir == i || current_dir == -1))
            {
                next_change_dir_cnt = current_change_dir_cnt;
            }
            else
            {
                next_change_dir_cnt = current_change_dir_cnt + 1;
            }

            if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n)
            {
                if (next_change_dir_cnt <= 1)
                {
                    // �����ΰ�� �ٷ� continue;
                    if (board[next_x][next_y] == '*')
                    {
                        continue;
                    }
                    // �Ϲ� ����ִ� ����� ��� �ش� ��ġ���� BFS ���ƾ��ؼ� queue Ǫ�� 
                    else if (board[next_x][next_y] == '.')
                    {
                        q.push({ next_x,next_y,i,next_change_dir_cnt });
                    }
                    else
                    {
                        // ¦�� ã�� ��� 
                        if (next_x == x1 && next_y == y1)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

string solution(int m, int n, vector<string> board) 
{
    string answer = "";

    // A ~ Z => 26�� �� ���� �ʱ�ȭ 26���� Ÿ�Ͽ� �� ��ǥ���� ������ (������� �����ؾ��ϱ� ������ A~Z ���� ������)
    // A ~ Z ( vp[A][0] , vp[A][1] ) 
    vector<vector<pair<int, int>>> vp(26, vector<pair<int, int>>());

    // ���Ÿ� �ؾ��� ���� 
    int RemoveTile = 0;

    // loop ���鼭 ã�ƾ� �ϴ��� Ȯ���ϴ� ���� 
    bool find_flag = true;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Board ���� Ÿ���� ��� 
            if ('A' <= board[i][j] && board[i][j] <= 'Z')
            {
                vp[int(board[i][j]) - int('A')].push_back(make_pair(i, j));
                RemoveTile++;
            }
        }
    }

    while (find_flag)
    {
        // �ϴ� false�� �ʱ�ȭ 
        find_flag = false;

        // A ~ Z ���� �˻�
        for (int i = 0; i < vp.size(); i++)
        {
            //���� 2���� ���� �� �ִٸ�(�����ؾ��� Ÿ��) ��� ����Ǽ��� �̿��ؼ� �˻��Ѵ�.
            if (vp[i].size() > 1)
            {
                if (BFS(vp[i][0].first, vp[i][0].second, vp[i][1].first, vp[i][1].second, board, m, n))
                {
                    // ¦�� ã�� ��쿡�� �ش� Ÿ���� ��� ��������� ���������� 
                    board[vp[i][0].first][vp[i][0].second] = '.';
                    board[vp[i][1].first][vp[i][1].second] = '.';

                    // ���Ϳ��� �ش� ���� ���������� 
                    vp[i].clear();

                    // ��ü �����ؾ��� Ÿ���� 2�� Ÿ���� ���� 
                    RemoveTile -= 2;

                    answer += char(i + int('A'));
                    find_flag = true;
                    break;
                }
            }
        }
    }

    if (RemoveTile != 0)
    {
        answer = "IMPOSSIBLE";
    }

    return answer;
}

// * -> ���� 
// . -> ��ĭ 

int main()
{
    vector<int> m = { 3,2,4,2 };
    vector<int> n = { 3,4,4,2 };

    vector<vector<string>> b = { {"DBA", "C*A", "CDB"} ,{"NRYN", "ARYA"} ,{".ZI.", "M.**", "MZU.", ".IU."} ,{"AB", "BA"} };

    vector<string> dab = { "ABCD","RYAN","MUZI","IMPOSSIBLE" };

    for (int i = 0; i < dab.size(); i++)
    {
        string answer = solution(m[i], n[i], b[i]);

        if(answer == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << ", want = " << dab[i] << endl;
        }
    }
    return 0;
}
