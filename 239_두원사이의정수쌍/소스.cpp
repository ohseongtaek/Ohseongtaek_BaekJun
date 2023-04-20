
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll CalFun(ll tY, ll r, int dir) {

    long long answer = 0;
    long long start = 1;
    long long end = r;
    long long mid = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (mid * mid > tY)
        {
            end = mid - 1;
        }
        else if (mid * mid < tY)
        {
            start = mid + 1;
            answer = mid;
        }
        else if (mid * mid == tY)
        {
            if (dir == 1)
            {
                return mid - 1;
            }
            return mid;
        }
    }
    return answer;
}

long long solution(int r1, int r2)
{
    long long answer = 0;
    ll tY = 0;

    ll r = r2;
    for (ll i = 0; i < r2; i++)
    {
        tY = r * r - i * i;
        answer += CalFun(tY, r, 2);
    }

    r = r1;
    for (ll i = 0; i < r1; i++)
    {
        tY = r * r - i * i;
        answer -= CalFun(tY, r, 1);
    }

    //��и��� ������ 4�� ��������.
    answer *= 4;

    return answer;
}

int main()
{
    /*
    2, 4, 40
    9, 20, 1008
    10, 20, 952
    999999, 1000000, 6281440
    */

    vector<int> r = { 2,2,9,10,999999 };
    vector<int> r2 = { 3,4,20,20,1000000 };
    vector<int> d = { 20, 40,1008,952,6281440 };

    //int r = 2;
    //int r2 = 3;

    for (int i = 0; i < r.size(); i++)
    {
        long long dab = solution(r[i], r2[i]);

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
x��� y������ �̷���� 2���� ���� ��ǥ�迡 �߽��� ������ ���� �ٸ� ũ���� ���� �� �� �־����ϴ�.
�������� ��Ÿ���� �� ���� r1, r2�� �Ű������� �־��� ��,
�� �� ������ ������ x��ǥ�� y��ǥ�� ��� ������ ���� ������ return�ϵ��� solution �Լ��� �ϼ����ּ���.

�� �� �� ���� ���� �����Ͽ� ���ϴ�.

���� ����
1 �� r1 < r2 �� 1,000,000
����� ��
r1	r2	result
2	3	20
*/