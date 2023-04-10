#include <string>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    for (int i = 0; i < balls.size(); i++)
    {
        int tx = balls[i][0];
        int ty = balls[i][1];
        int total = INT_MAX;

        if (startX != tx || startY <= ty)
        {
            total = min(total, (int)(pow(startX - tx, 2) + pow(startY + ty, 2)));
        }
        if (startX >= tx || startY != ty)
        {
            total = min(total, (int)(pow(startX - 2 * m + tx, 2) + pow(startY - ty, 2)));
        }
        if (startX != tx || startY >= ty)
        {
            total = min(total, (int)(pow(startX - tx, 2) + pow(startY - 2 * n + ty, 2)));
        }
        if (startX <= tx || startY != ty)
        {
            total = min(total, (int)(pow(startX + tx, 2) + pow(startY - ty, 2)));
        }
        answer.push_back(total);
    }

    return answer;
}

int main()
{
    int m = 10;
    int n = 10;
    int sx = 3;
    int sy = 7;
    vector<vector<int>> vv = { {7, 7}, { 2, 7 }, { 7, 3 } };
    vector<int> v = { 52, 37, 116 };

    vector<int> dab = solution(m, n, sx, sy, vv);
    bool falg = false;
    for (int i = 0; i < dab.size(); i++)
    {
        if (dab[i] != v[i])
        {
            falg = true;
            break;
        }
    }

    if (falg == true)
    {
        cout << "error " << endl;
    }
    else
    {
        cout << " good " << endl;
    }
}
/*
리스트에는 머쓱이가 맞춰야 하는 공들의 위치가 담겨있습니다.
머쓱이는 리스트에 담긴 각 위치에 순서대로 공을 놓아가며 "원쿠션" 연습을 하면 됩니다.
이때, 머쓱이는 항상 같은 위치에 공을 놓고 쳐서 리스트에 담긴 위치에 놓인 공을 맞춥니다.

머쓱이와 달리 최근 취미로 알고리즘 문제를 풀기 시작한 당신은, 머쓱이가 친 공이 각각의 목표로한 공에 맞을 때까지
최소 얼마의 거리를 굴러가야 하는지가 궁금해졌습니다.

당구대의 가로 길이 m,
세로 길이 n과
머쓱이가 쳐야 하는 공이 놓인 위치 좌표를 나타내는 두 정수 startX, startY,
그리고 매 회마다 목표로 해야하는 공들의 위치 좌표를 나타내는 정수 쌍들이 들어있는 2차원 정수배열 balls가 주어집니다.
"원쿠션" 연습을 위해 머쓱이가 공을 적어도 벽에 한 번은 맞춘 후 목표 공에 맞힌다고 할 때, 각 회마다 머쓱이가 친 공이 굴러간 거리의 최솟값의 제곱을 배열에 담아
return 하도록 solution 함수를 완성해 주세요.

단, 머쓱이가 친 공이 벽에 부딪힐 때 진행 방향은 항상 입사각과 반사각이 동일하며,
만약 꼭짓점에 부딪힐 경우 진입 방향의 반대방향으로 공이 진행됩니다.
공의 크기는 무시하며, 두 공의 좌표가 정확히 일치하는 경우에만 두 공이 서로 맞았다고 판단합니다.
공이 목표 공에 맞기 전에 멈추는 경우는 없으며, 목표 공에 맞으면 바로 멈춘다고 가정합니다.

제한사항
3 ≤ m, n ≤ 1,000
0 < startX < m
0 < startY < n
2 ≤ balls의 길이 ≤ 1,000
balls의 원소는 {a, b} 형태입니다.
a, b는 머쓱이가 맞춰야 할 공이 놓인 좌표를 의미합니다.
0 < a < m, 0 < b < n
(a, b) = ( startX, startY )인 입력은 들어오지 않습니다.
입출력 예

입출력 예 설명
입출력 예 #1

첫 번째 예시의 첫번째 공에 대한 그림은 다음과 같습니다.

당구대의 좌측 하단 좌표가 (0, 0) 입니다.

점 A는 머쓱이가 칠 공이 놓인 위치입니다.

점 A → 점{0} : 점선을 따라 이동하면 거리의 제곱이 52로 최소가 됩니다.

같은 예시의 두 번째 공에 대한 그림은 다음과 같습니다.
ball1.png

점 A → 점{1} : 점선을 따라 이동하면 거리의 제곱이 37로 최소가 됩니다.

점 A에 놓인 공을 왼쪽 방향으로 x축과 수평이 되도록 보내면 벽에 맞고 점 {1}에 닿아 이동 거리가 더 짧아보이지만, A가 벽으로 이동하는 경로에 점 {1}이 있으므로, 벽에 맞기전에 공에 먼저 맞게 됩니다.
같은 예시의 세 번째 공에 대한 그림은 다음과 같습니다.
ball2.png

점 A → 점{2} : 점선을 따라 이동하면 거리의 제곱이 116으로 최소가 됩니다.

따라서 {52, 37, 116}을 return 합니다.

※ 공지 - 2023년 3월 20일 문제 난이도가 Lv. 1 → Lv. 2로 변경되었습니다.

*/