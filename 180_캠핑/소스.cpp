#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> data) 
{
    int answer = 0;

    // ���� 
    sort(data.begin(), data.end());
    
    // ù��° ���⸦ �����ϴ� for�� 
    for (int i = 0; i < n; i++)
    {
        int x = data[i][0];
        int y = data[i][1];


        // �ι�° ���⸦ �����ϴ� for�� 
        for (int j = i + 1; j < n; j++)
        {
            int x2 = data[j][0];
            int y2 = data[j][1];

            // ũ�Ⱑ 0�� �Ǵ��� Ȯ���ϴ� ���� 
            if (x == x2 || y == y2)
            {
                continue;
            }

            // ù��° ������� �ι�° ������� �ݺ��ϸ鼭 �ȿ� ���Ⱑ �ִ��� Ȯ���ϴ� for��
            bool falg = false;
            for (int k = i + 1; k < j; k++)
            {
                int xIN = data[k][0];
                int yIN = data[k][1];
                
                if ((x < xIN && xIN < x2) && (min(y, y2) < yIN && yIN < max(y, y2)))
                {
                    falg = true;
                    break;
                }
            }

            if (falg == false)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> v = { {0, 0},{1, 1},{0, 2},{2, 0} };
    
    int dab = solution(n, v);

    if (dab == 3)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}