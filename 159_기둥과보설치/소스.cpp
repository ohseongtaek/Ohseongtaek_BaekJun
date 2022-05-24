#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

// x , y , ��պ� , ��ġ�̼�ġ 
int visit[101][101][2];
int board_size;

bool Check_range(int x, int y)
{
    if (x <0 || y<0 || x>board_size || y>board_size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool func_install(int x, int y, bool st)
{
    // ���
    if (st == 0)
    {
        // �ٴڿ� ��ġ�ϴ� ��� ������ ��ġ �� �迭 �� �߰� 
        if (y == 0)
        {
           return true;
        }
        // �ٴ��� �ƴ� ���� ��ġ�ϴ� ��� �� �Ǵ� ����� �ִ��� Ȯ���ؾ��� 
        else
        {
            // ���������� ���� ���� �ִ� ��� 
            if (visit[x][y][1] == true)
            {
                return true;
            }

            // �ٷ� �Ʒ��� ����� �ִ� ��� 
            if (visit[x][y - 1][0] == true && Check_range(x,y-1))
            {
                return true;
            }

            // �Ʒ��� ���� �ִ� ��� 
            else if (visit[x - 1][y][1] == true && Check_range(x-1,y))
            {
                return true;
            }
        }
    }
    // ��
    else
    {
        // ���� ��ġ�Ϸ��� ���� ���ʿ� ����� �ְų� or �� �� ���� �ְų� ���� �ϳ��� !
        // ���ʿ� ����� �ִ� ��� (����)
        if (visit[x][y - 1][0] == true && Check_range(x,y-1))
        {
            return true;
        }
        // ���ʿ� ����� �ִ� ��� (������)
        else if (visit[x + 1][y - 1][0] == true && Check_range(x+1,y-1))
        {
            return true; 
        }
        // ���ʿ� ���� �ִ� ��� 
        else if (Check_range(x-1,y) && visit[x-1][y][1] == true && Check_range(x+1,y) &&visit[x+1][y][1] == true)
        {
            return true;
        }
    }
    return false;
}

bool func_uninstall()
{
    // ��ü ���忡 ���ؼ� �ϳ��� �����غ��� Ȯ���غ��� -> ó���� ���� ��ǥ�� ������ ������ �� ���� �����ϱ⿡�� ��ü ���̽� Ȯ���� �ʿ��ϴٴ°��� ���� Why?
    for (int i = 0; i <= board_size; i++)
    {
        for (int j = 0; j <= board_size; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                // �� �Ǵ� ����� �����Ҷ� 
                if (visit[i][j][k] == true)
                {
                    // ���� �� ���Ŀ� 
                    visit[i][j][k] = false;

                    // ��ġ�� �������� Ȯ��!
                    if (false == func_install(i, j, k))
                    {
                        //�Ұ����� ��� 
                        visit[i][j][k] = true;
                        return false;
                    }
                    
                    visit[i][j][k] = true;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    // 0 ���� ��ü �迭 �ʱ�ȭ 
    memset(visit, 0, sizeof(visit));

    // n : ������ ũ�� 
    board_size = n;
    // build_frame : �迭 �׸�
    // 0 => x��ǥ 
    // 1 => y��ǥ 
    // 2 => ��հ� �� (0:���,1:��)
    // 3 => ��ġ���� (0:����, 1:��ġ)

    // ����� ���� �׾ƿø� 
    // ���� ���������� ������ (������ ������ ����̰ų�, ���� ��� ���� �ִ� ��쿡 ������)
    
    for (int i = 0; i < build_frame.size(); i++)
    {
        int pos_x = build_frame[i][0];
        int pos_y = build_frame[i][1];
        int structor = build_frame[i][2];
        int install = build_frame[i][3];

        // ��ġ�ϴ� ������ ��� 
        if (install == 1)
        {
            if (true == func_install(pos_x, pos_y, structor))
            {
                // ��ġ �����ϰ� ����϶� 
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                // ��ġ �����ϰ� ���϶� 
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
        // �����ϴ� ������ ��� 
        else
        {
            // �ϴ� �� ���� 
            if (structor == 0)
            {
                visit[pos_x][pos_y][0] = false;
            }
            else
            {
                visit[pos_x][pos_y][1] = false;
            }
            // ������ �Ұ����̸� ���� 
            if (false == func_uninstall())
            {
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                vector<int> v;
                if (visit[i][j][k] == true)
                {
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    answer.push_back(v);
                }
            }
        }
    }

    return answer;
}
int main() {
    int n = 5;
    vector<vector<int>> v = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    vector<vector<int>> v2 = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> a;
    a = solution(n, v);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

/*
���� ���� ����
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

// x , y , ��պ� , ��ġ�̼�ġ
int visit[101][101][2];
int board_size;

bool Check_range(int x, int y)
{
    if (x <0 || y<0 || x>board_size || y>board_size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool func_install(int x, int y, bool st)
{
    // ���
    if (st == 0)
    {
        // �ٴڿ� ��ġ�ϴ� ��� ������ ��ġ �� �迭 �� �߰�
        if (y == 0)
        {
           return true;
        }
        // �ٴ��� �ƴ� ���� ��ġ�ϴ� ��� �� �Ǵ� ����� �ִ��� Ȯ���ؾ���
        else
        {
            // �ٷ� �Ʒ��� ����� �ִ� ���
            if (visit[x][y - 1][0] == true && Check_range(x,y-1))
            {
                return true;
            }
            // �Ʒ��� ���� �ִ� ���
            else if (visit[x - 1][y][1] == true && Check_range(x-1,y))
            {
                return true;
            }
        }
    }
    // ��
    else
    {
        // ���� ��ġ�Ϸ��� ���� ���ʿ� ����� �ְų� or �� �� ���� �ְų� ���� �ϳ��� !
        // ���ʿ� ����� �ִ� ��� (����)
        if (visit[x][y - 1][0] == true && Check_range(x,y-1))
        {
            return true;
        }
        // ���ʿ� ����� �ִ� ��� (������)
        else if (visit[x + 1][y - 1][0] == true && Check_range(x+1,y-1))
        {
            return true;
        }
        // ���ʿ� ���� �ִ� ���
        else if (Check_range(x-1,y) && visit[x-1][y][1] == true && Check_range(x+1,y) &&visit[x+1][y][1] == true)
        {
            return true;
        }
    }
    return false;
}

bool func_uninstall(int x, int y, bool st)
{
    // ��� ����
    if (st == 0)
    {
        // �����Ϸ��� ������� ����� �ִ� ���
        if (visit[x][y + 1][0] == true && Check_range(x,y+1))
        {
            // ����� ������ �� ���� ���� �Ѱ��� �ִ°�� ���� ����
            if ((visit[x - 1][y + 1][1] == true && Check_range(x-1,y+1)) || (visit[x][y + 1][1] == true && Check_range(x,y+1)))
            {
                return true;
            }
        }
        // �����Ϸ��� ������� ����� ���� ���
        else
        {
            // ���� �ִ� ���
            if ((visit[x - 1][y + 1][1] == true && Check_range(x-1,y+1)) || (visit[x][y + 1][1] == true && Check_range(x,y+1)))
            {
                return true;
            }
            // �ƹ��͵� ���� ��� ���� �Ұ�
            else
            {
                return false;
            }
        }
    }
    // �� ����
    else
    {
        bool left = false;
        bool right = false;
        // ���� ���� ��� �ִ��� Ȯ��
        if((visit[x][y-1][0] == true && Check_range(x,y-1))|| (visit[x-1][y-1][0] == true && Check_range(x-1,y-1)))
        {
            left = true;
        }
        // ������ ���� ����� �ִ��� Ȯ���ϱ�
        if ((visit[x + 1][y - 1][0] == true && Check_range(x+1,y-1)) || visit[x + 2][y - 1][0] == true && Check_range(x+2,y-1))
        {
            right = true;
        }

        // ����
        if (left == true && right == true)
        {
            return true;
        }
        // �� ����
        else
        {
            return false;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    // 0 ���� ��ü �迭 �ʱ�ȭ
    memset(visit, 0, sizeof(visit));

    // n : ������ ũ��
    board_size = n;
    // build_frame : �迭 �׸�
    // 0 => x��ǥ
    // 1 => y��ǥ
    // 2 => ��հ� �� (0:���,1:��)
    // 3 => ��ġ���� (0:����, 1:��ġ)

    // ����� ���� �׾ƿø�
    // ���� ���������� ������ (������ ������ ����̰ų�, ���� ��� ���� �ִ� ��쿡 ������)

    for (int i = 0; i < build_frame.size(); i++)
    {
        int pos_x = build_frame[i][0];
        int pos_y = build_frame[i][1];
        int structor = build_frame[i][2];
        int install = build_frame[i][3];

        // ��ġ�ϴ� ������ ���
        if (install == 1)
        {
            if (true == func_install(pos_x, pos_y, structor))
            {
                // ��ġ �����ϰ� ����϶�
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                // ��ġ �����ϰ� ���϶�
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
        // �����ϴ� ������ ���
        else
        {
            // �ϴ� �� ����
            if (structor == 0)
            {
                visit[pos_x][pos_y][0] = false;
            }
            else
            {
                visit[pos_x][pos_y][1] = false;
            }
            // ������ �Ұ����̸� ����
            if (false == func_uninstall(pos_x, pos_y, structor))
            {
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                vector<int> v;
                if (visit[i][j][k] == true)
                {
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    answer.push_back(v);
                }
            }
        }
    }

    return answer;
}
int main() {
    int n = 5;
    vector<vector<int>> v = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    vector<vector<int>> v2 = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> a;
    a = solution(n, v);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


*/