#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dp[201][201];

// ���� https://source-sc.tistory.com/24

int Cal_math(int n, vector<vector<int>> matrix) {
    int a, b;
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            a = j;
            b = j + i;
            if (a == b) {
                dp[a][b] = 0;
            }
            else {
                dp[a][b] = 987654321;
                for (k = a; k < b; k++) {
                    dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
                }
            }
        }
    }
    return dp[0][n - 1];
}

int solution(vector<vector<int>> matrix_sizes) 
{
    int answer = 0;

    answer = Cal_math(matrix_sizes.size(), matrix_sizes);

    return answer;
}

int main()
{
    vector<vector<int>> mat = { {5, 3},{3, 10},{10, 6} };
    int dab = 270;

    int ans = solution(mat);
    if (dab == ans)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << ans << endl;
    }
}


/*
����� ������ 3�̻� 200������ �ڿ����Դϴ�.
�� ����� ��� ���� ũ��� 200������ �ڿ��� �Դϴ�.
����� �� �� ���� ����� �Է����� �־����� �ʽ��ϴ�.
*/