#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(vector<string>& b, int Garo, int Sero, int i, int j)
{
    // 방문 
    vector<vector<int>> visit(Garo, vector<int>(Sero));

    // 깊이 값 
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

        // 상하좌우 이동 
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
리코쳇 로봇이라는 보드게임이 있습니다.

이 보드게임은 격자모양 게임판 위에서 말을 움직이는 게임으로, 시작 위치에서 목표 위치까지 최소 몇 번만에 도달할 수 있는지 말하는 게임입니다.

이 게임에서 말의 움직임은 상, 하, 좌, 우 4방향 중 하나를 선택해서 게임판 위의 장애물이나 맨 끝에 부딪힐 때까지 미끄러져 이동하는 것을 한 번의 이동으로 칩니다.

다음은 보드게임판을 나타낸 예시입니다.

...D..R
.D.G...
....D.D
D....D.
..D....
여기서 "."은 빈 공간을,
"R"은 로봇의 처음 위치를, 
"D"는 장애물의 위치를, 
"G"는 목표지점을 나타냅니다.
위 예시에서는 "R" 위치에서 아래, 왼쪽, 위, 왼쪽, 아래, 오른쪽, 위 순서로 움직이면 7번 만에 "G" 위치에 멈춰 설 수 있으며, 이것이 최소 움직임 중 하나입니다.

게임판의 상태를 나타내는 문자열 배열 board가 주어졌을 때, 말이 목표위치에 도달하는데 최소 몇 번 이동해야 하는지 return 하는 solution함수를 완성하세요. 만약 목표위치에 도달할 수 없다면 -1을 return 해주세요.

제한 사항
3 ≤ board의 길이 ≤ 100
3 ≤ board의 원소의 길이 ≤ 100
board의 원소의 길이는 모두 동일합니다.
문자열은 ".", "D", "R", "G"로만 구성되어 있으며 각각 빈 공간, 장애물, 로봇의 처음 위치, 목표 지점을 나타냅니다.
"R"과 "G"는 한 번씩 등장합니다.
입출력 예
board	result

입출력 예 설명
입출력 예 #1

문제 설명의 예시와 같습니다.
입출력 예 #2

.D.R
....
.G..
...D
"R" 위치에 있는 말을 어떻게 움직여도 "G" 에 도달시킬 수 없습니다.
따라서 -1을 return 합니다.
*/