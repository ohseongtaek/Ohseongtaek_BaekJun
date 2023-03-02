#include <string>
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;

    stack<int> D;
    stack<int> P;

    // ��ü ����� ������ ������ ������ ���ÿ� ���� 
    for (int i = 0; i < deliveries.size(); i++)
    {
        D.push(deliveries[i]);
        P.push(pickups[i]);
    }
    
    // ������ ������� ������ �ֻ����� 0�̸� �ű⸦ �鸮�� �ȵǱ� ������ ����ó���� 
    while (!D.empty() && !D.top())
    {
        D.pop();
    }
    while (!P.empty() && !P.top())
    {
        P.pop();
    }

    cout << D.empty() << endl;
    cout << P.empty() << endl;

    // ��ü �ݺ��� ���� ��� �ϸ鼭 �� while���� �ù����� �����ٰ� �������� �� 1ȸ�� �ݺ����� ������ 
    while (!(D.empty() && P.empty()))
    {
        // �պ����� ����ؾ��ϱ� ������ *2�� �� ����Ұ��̳� �����Ұ��̳� ���� �ָ��ִ°��� ������ϱ� ������ max ���
        answer += max(D.size() * 2, P.size() * 2);

        int maxDCap = 0;
        int maxPCap = 0;

        // ������ ������� �ʰ� ������ ������ �ڽ��� ũ�Ⱑ �ִ� ũ�⺸�� ������� 
        while (D.empty() == false && maxDCap <= cap)
        {
            // �ִ�ũ�⺸�� ���� ��쿡 �ڽ��� �����ְ� �ƴѰ�쿡�� top���� ������ ��ŭ�� ���ش� 
            if (D.top() + maxDCap <= cap)
            {
                maxDCap += D.top();
            }
            else
            {
                D.top() -= (cap - maxDCap);
                break;
            }
            D.pop();
        }

        // ������ ������� �ʰ� ������ ������ �ڽ��� ũ�Ⱑ �ִ� ũ�⺸�� ������� 
        while (P.empty() == false && maxPCap <= cap)
        {
            // �ִ�ũ�⺸�� ���� ��쿡 �ڽ��� �����ְ� �ƴѰ�쿡�� top���� ������ ��ŭ�� ���ش� 
            if (P.top() + maxPCap <= cap)
            {
                maxPCap += P.top();
            }
            else
            {
                P.top() -= (cap - maxPCap);
                break;
            }
            P.pop();
        }
    }
    return answer;
}

int main()
{
    vector<int> c = { 4,2,2,4 };
    vector<int> n = { 5,7,7,4 };
    vector<vector<int>> d = { {1, 0, 3, 1, 2}, {1, 0, 2, 0, 1, 0, 2},{1, 0, 2, 0, 1, 0, 2},{25, 24, 51, 0} };
    vector<vector<int>> p = { {0, 3, 0, 4, 0}, {0, 2, 0, 1, 0, 2, 0},{0, 2, 0, 1, 0, 2, 0},{51, 0, 0, 49} };
    vector<int> dab = { 16,30,30 };

    for (int i = 0; i < d.size(); i++)
    {
        long long re = solution(c[i], n[i], d[i], p[i]);
        if (re == dab[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}