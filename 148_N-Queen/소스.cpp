#include <string>
#include <vector>
#include <iostream>

using namespace std;

int col[15];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++)
    {
        // �밢���̰ų� ���� ����
        //col[i]�� �ǹ��ϴ� ���� X��ǥ, i�� �ǹ��ϴ°��� Y��ǥ�̹Ƿ� ���̰� �����ϴٸ� �밢���� �ִٰ� �� �� �ִ�.
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
        {
            return false;
        }
    }
    return true;
}

void nqueen(int x)
{
    if (x == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i; // �ش� ��ġ�� ���� ��ġ
            if (check(x)) // ��ȿ�ϴٸ� �������� �� ��ġ, ��ȿ�����ʴٸ� �ٸ� ��ġ�� �� ��ġ ����
                nqueen(x + 1);
        }
    }
}

int solution(int n) {
    
    N = n;
    nqueen(0);
    return total;
}

int main()
{
    int a = solution(4);
    cout << a << endl;
}

