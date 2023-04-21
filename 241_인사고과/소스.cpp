#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct hinfo 
{
    int at;
    int score;
    int idx;
};

bool comp(hinfo a, hinfo b)
{
    return a.at > b.at;
}

bool comp2(pair<int, int> a, pair<int, int> b) 
{
    if (a.first == b.first)
    {
        return b.second < a.second;
    }
    else
    {
        return a.first > b.first;
    }
}

int solution(vector<vector<int>> scores) 
{
    vector<hinfo> v;
    vector<pair<int, int>> vp;

    for (int i = 0; i < scores.size(); i++)
    {
        hinfo in;
        in.at = scores[i][0];
        in.score = scores[i][1];
        in.idx = i;
        v.push_back(in);
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) 
    {
        bool flag = true; 
        hinfo r = v[i];
        for (int j = 0; j < i; j++) 
        {
            hinfo l = v[j];
            if (l.at > r.at && l.score > r.score) 
            {
                flag = false; 
                break;
            }
        }
        if (!flag)
        {
            continue;
        }

        int hhap = r.at + r.score;
        int hidx = r.idx;
        // �ջ���� ���ؼ� �μ��� �������ִ� ����� push 
        // �̶��� �հ� idx ���� ������ �����ϹǷ� �׷��Ը��־��ֱ� 
        vp.push_back(make_pair(hhap,hidx));
    }

    // ���� ū �������� �������� 
    sort(vp.begin(), vp.end(), comp2);
    
    int answer = 0; 
    int rank = 1;

    for (int i = 0; i < vp.size(); i++) 
    {
        int hsum = vp[i].first; 
        int cnt = 0;
        
        // vp ������ ���� i���� �۰� �λ����� ���� ���� idx �� ���� ���
        // ���� rank �� Ȯ�εǸ� ���� ������ �� ��ŭ rank�� �������°��� ������ �ڵ� 
        while (i < vp.size() && hsum == vp[i].first) 
        {
            if (vp[i].second == 0) 
            {
                answer = rank++; 
                break;
            }
            i++; 
            cnt++;
        }
        // ������ �Ѱ� �� ������i ���̱� 
        i--;

        // �� ���� �հ谡 ������� rank ��� 
        rank += cnt;
        
        if (answer != 0)
        {
            break;
        }
    }
    
    if (answer == 0)
    {
        return -1;
    }
    else
    {
        return answer;
    }
}

int main()
{
    vector<vector<int>> vv = { {2,2},{1,4},{3,2},{3,2},{2,1} };
    int dab = solution(vv);
    if (dab == 4)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << "error" << endl;
    }
}


/*
�� ������� �ٹ� �µ� ������ ���� �� ������ ��ϵǾ� �ִµ� 
���� � ����� �ٸ� ������ ������� �� ������ ��� ���� ��찡 �� ���̶� �ִٸ� �� ����� �μ�Ƽ�긦 ���� ���մϴ�. 
�׷��� ���� ����鿡 ���ؼ��� �� ������ ���� ���� ������ ������ ���� ������ ���� �μ�Ƽ�갡 ���� ���޵˴ϴ�. 
�̶�, �� ������ ���� ������ ������� �������̸�, �������� ����ŭ ���� ������ �ǳ� �ݴϴ�. 
���� ��� ������ ���� ���� ū ����� 2���̶�� 1���� 2���̰� 2�� ���� ���� ������ 3������Դϴ�.

�� ����� �ٹ� �µ� ������ ���� �� ���� ��� scores�� �־����� ��, ��ȣ�� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� ����
1 �� scores�� ���� �� 100,000
scores�� �� ���� �� ����� �ٹ� �µ� ������ ���� �� ������ ��Ÿ���� {a, b} �����Դϴ�.
scores{0}�� ��ȣ�� �����Դϴ�.
0 �� a, b �� 100,000
��ȣ�� �μ�Ƽ�긦 ���� ���ϴ� ��� -1�� return �մϴ�.
����� ��
scores	result
{{2,2},{1,4},{3,2},{3,2},{2,1}}	4
����� �� ����
5 ��° ����� 3 ��° �Ǵ� 4 ��° ������� �ٹ� �µ� ������ ���� �� ������ ��� ���� ������ �μ�Ƽ�긦 ���� �� �����ϴ�. 2 ��° ���, 3 ��° ���, 4 ��° ����� �� ������ ���� 5 ������ �ְ����̹Ƿ� 1 ���Դϴ�. 1 ���� �� ���̹Ƿ� 2 ��� 3 ���� ���� 1 ��° ����� ��ȣ�� �� ������ ���� 4 ������ 4 ���Դϴ�.
*/