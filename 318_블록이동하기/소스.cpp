#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

// �ִ� 100x100 ������ �� ���� ���� �迭 
bool visit[101][101][4];

// ���� ��ġ 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


// ������ ����Ǵ°� 
int ChangeDir(int Dir)
{
    if (Dir == 0)
        return 1;
    else if (Dir == 1)
        return 0;
    else if (Dir == 2)
        return 3;
    else if (Dir == 3)
        return 2;
}


// BFS ���� Queue ��� �� �ִܰŸ� Ȯ�� 
int solution(vector<vector<int>> board) {
    int answer = 0;
    
    // ��ġ ������ ����ü 
    struct POS
    {
        int x, y, dir, cnt;
        // Dir = 0,1,2,3 (��������)
    };

    // ��ü ���� 
    int range_N = board.size();

    // BFS Create Queue
    queue<POS> q;
    // �����ʿ� �ִ� ���� ���������� �ϰ� 
    q.push({ 0,1,1,0 });
    // 0,0 �� ������ �ٸ� �ϳ��� ������ �湮�Ѱ����� üũ 
    visit[0][0][0] = true;
    // 0,1 �� ������ �ٸ� �ϳ��� ������ �湮�Ѱ����� üũ 
    visit[0][1][1] = true;

    // ť�� ��� ������� ���� �ݺ� 
    while (q.empty() == 0)
    {
        // pos_x pos_y �������� ����� ��ǥ 
        int pos_x = q.front().x;
        int pos_y = q.front().y;
        int pos_dir = q.front().dir;
        int pos_cnt = q.front().cnt;

        // pos_xx pos_yy ���������� �� ��ǥ 
        int pos_xx = pos_x + dx[pos_dir];
        int pos_yy = pos_y + dy[pos_dir];

        // ť �ϳ� ���� 
        q.pop();

        // ��ġ�� �ϳ��� ������ �Ѿ ��� 
        if ((pos_x == range_N - 1 && pos_y == range_N - 1) || (pos_xx == range_N - 1 && pos_yy == range_N - 1))
        {
            return pos_cnt;
        }

        // �������� ������ �� ��ü Ž�� 
        for (int i = 0; i < 4; i++)
        {
            if (pos_dir == i)
            {
                int pos_change_x = pos_xx + dx[i];
                int pos_change_y = pos_yy + dy[i];
                if (pos_change_x >= 0 && pos_change_y >= 0 && pos_change_x < range_N && pos_change_y < range_N)
                {
                    if (board[pos_change_x][pos_change_y] == 0 && visit[pos_change_x][pos_change_y][ChangeDir(pos_dir)] == false && visit[pos_xx][pos_yy][pos_dir] == false)
                    {
                        visit[pos_x][pos_y][ChangeDir(pos_dir)] = true;
                        visit[pos_xx][pos_yy][pos_dir] = true;
                        q.push({pos_xx,pos_yy,pos_dir,pos_cnt+1});
                    }
                }
            }
            else if (ChangeDir(pos_dir) == i)
            {
                int pos_change_x = pos_x + dx[i];
                int pos_change_y = pos_y + dy[i];
                if (pos_change_x >= 0 && pos_change_y >= 0 && pos_change_x < range_N && pos_change_y < range_N)
                {
                    if (board[pos_change_x][pos_change_y] == 0 && visit[pos_change_x][pos_change_y][pos_dir] == false && visit[pos_x][pos_y][ChangeDir(pos_dir)] == false)
                    {
                        visit[pos_change_x][pos_change_y][pos_dir] = true;
                        visit[pos_x][pos_y][ChangeDir(pos_dir)] = true;
                        q.push({ pos_change_x,pos_change_y,pos_dir,pos_cnt + 1 });
                    }
                }
            }
            else
            {
                int pos_change_x = pos_x + dx[i];
                int pos_change_y = pos_y + dy[i];
                int pos_change_xx = pos_xx + dx[i];
                int pos_change_yy = pos_yy + dy[i];
                if (pos_change_x >= 0 && pos_change_y >= 0 && pos_change_x < range_N && pos_change_y < range_N && pos_change_xx >= 0 && pos_change_yy >= 0 && pos_change_xx < range_N && pos_change_yy < range_N)
                {
                    if (board[pos_change_x][pos_change_y] == 0 && board[pos_change_xx][pos_change_yy] == 0)
                    {
                        if (visit[pos_change_x][pos_change_y][pos_dir] == false && visit[pos_change_xx][pos_change_yy][ChangeDir(pos_dir)] == false)
                        {
                            visit[pos_change_x][pos_change_y][pos_dir] = true;
                            visit[pos_change_xx][pos_change_yy][ChangeDir(pos_dir)] = true;
                            q.push({ pos_change_x,pos_change_y,pos_dir,pos_cnt + 1 });
                        }
                    }
                }
            }
        }

        // ���� Ȥ�� ������ ��� 
        if (pos_dir == 0 || pos_dir == 1)
        {
            //����
            int temp_x = pos_x - 1;
            int temp_xx = pos_xx - 1;
            if (temp_x >= 0 && temp_xx >= 0 && temp_x < range_N && temp_xx < range_N)
            {
                // �� �� �ִ� ��� 
                if (board[temp_x][pos_y] == 0 && board[temp_xx][pos_yy] == 0)
                {
                    if (visit[pos_x][pos_y][3] == false && visit[temp_x][pos_y][2] == false)
                    {
                        visit[pos_x][pos_y][3] = true;
                        visit[temp_x][pos_y][2] = true;
                        q.push({ pos_x,pos_y,3,pos_cnt + 1 });
                    }
                    if (visit[temp_xx][pos_yy][2] == false && visit[pos_xx][pos_yy][3] == false)
                    {
                        visit[temp_xx][pos_yy][2] = true;
                        visit[pos_xx][pos_yy][3] = true;
                        q.push({ temp_xx,pos_yy,2,pos_cnt + 1 });
                    }
                }
            }
            //����
            temp_x = pos_x + 1;
            temp_xx = pos_xx + 1;
            if (temp_x >= 0 && temp_xx >= 0 && temp_x < range_N && temp_xx < range_N)
            {
                if (board[temp_x][pos_y] == 0 && board[temp_xx][pos_yy] == 0)
                {
                    if (visit[pos_x][pos_y][2] == false && visit[temp_x][pos_y][3] == false)
                    {
                        visit[pos_x][pos_y][2] = true;
                        visit[temp_x][pos_y][3] = true;
                        q.push({ pos_x, pos_y, 2, pos_cnt + 1 });
                    }

                    if (visit[temp_xx][pos_yy][3] == false && visit[pos_xx][pos_yy][2] == false)
                    {
                        visit[temp_xx][pos_yy][3] = true;
                        visit[pos_xx][pos_yy][2] = true;
                        q.push({ temp_xx, pos_yy, 3, pos_cnt + 1 });
                    }
                }
            }
        }
        // �� Ȥ�� ���ΰ�� 
        else
        {
            int temp_y = pos_y - 1;
            int temp_yy = pos_yy - 1;
            if (temp_y >= 0 && temp_yy >= 0 && temp_y < range_N && temp_yy < range_N)
            {
                if (board[pos_x][temp_y] == 0 && board[pos_xx][temp_yy] == 0)
                {
                    if (visit[pos_x][pos_y][1] == false && visit[pos_x][temp_y][0] == false)
                    {
                        visit[pos_x][pos_y][1] = true;
                        visit[pos_x][temp_y][0] = true;
                        q.push({ pos_x, pos_y, 1, pos_cnt + 1 });
                    }

                    if (visit[pos_xx][pos_yy][1] == false && visit[pos_xx][temp_yy][0] == false)
                    {
                        visit[pos_xx][pos_yy][1] = true;
                        visit[pos_xx][temp_yy][0] = true;
                        q.push({ pos_xx, temp_yy, 0, pos_cnt + 1 });
                    }
                }
            }

            temp_y = pos_y + 1;
            temp_yy = pos_yy + 1;
            if (temp_y >= 0 && temp_yy >= 0 && temp_y < range_N && temp_yy < range_N)
            {
                if (board[pos_x][temp_y] == 0 && board[pos_xx][temp_yy] == 0)
                {
                    if (visit[pos_x][pos_y][0] == false && visit[pos_x][temp_y][1] == false)
                    {
                        visit[pos_x][pos_y][0] = true;
                        visit[pos_x][temp_y][1] = true;
                        q.push({ pos_x, pos_y, 0, pos_cnt + 1 });
                    }

                    if (visit[pos_xx][pos_yy][0] == false && visit[pos_xx][temp_yy][1] == false)
                    {
                        visit[pos_xx][pos_yy][0] = true;
                        visit[pos_xx][temp_yy][1] = true;
                        q.push({ pos_xx, temp_yy, 1, pos_cnt + 1 });
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>>  vb = { {0, 0, 0, 1, 1}, { 0, 0, 0, 1, 0 }, { 0, 1, 0, 1, 1 }, { 1, 1, 0, 0, 1 }, { 0, 0, 0, 0, 0 } };
    cout << solution(vb) << endl;
}

