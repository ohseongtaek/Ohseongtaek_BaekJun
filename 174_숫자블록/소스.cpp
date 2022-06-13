#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getMaxDivision(int n)
{
    // ��Ʈ !
    int num = sqrt(n);

    // �ִ� ����� get
    for (int i = 2; i <= num; i++) 
    {
        // 10000000 => �̹� ��Ƴ��� ������ �ִ����� �̰��� ������ �ȵ�!
        if (n % i == 0 && n / i <= 10000000)
        {
            return n / i;
        }
    }
    return 1;
}

vector<int> solution(long long begin, long long end) 
{
    vector<int> answer;

    // �� �ε����� ���� �Ҽ����� �ƴϸ� �ִ� ������� �������� �ȴ�.
    for (int i = begin; i <= end; i++) 
    {
        answer.push_back(getMaxDivision(i));
    }
    
    
    if (begin == 1)
    {
        answer[0] = 0;
    }

    return answer;
}


int main()
{
    long long b = 1;
    long long e = 10;

    vector<int> answer = { 0, 1, 1, 2, 1, 3, 1, 4, 3, 5 };
    vector<int> dab = solution(b, e);

    bool flag = false;
    for (int i = 0; i < dab.size(); i++)
    {
        if (answer[i] != dab[i])
        {
            cout << " error " << endl;
            flag = true;
            break;
        }
    }

    if (flag == false)
    {
        cout << " good " << endl;
    }
    return 0;
}