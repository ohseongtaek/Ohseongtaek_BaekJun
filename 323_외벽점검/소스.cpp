#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// min ���� ã�°��̶� 8�� �ִ밪�̹Ƿ� 9�� ���� 
int answer = 9;

// dist �ִ�� = 8
bool Choice[8];

// ������� ���� ���� 
vector<int> V;

bool Cmp(int A, int B)
{
    if (A > B)
    {
        return true;
    }
    return false;
}

vector<int> Next_Vector(vector<int> w_temp, int start, int n)
{
    for (int j = 1; j < w_temp.size(); j++)
    {
        w_temp[j - 1] = w_temp[j];
    }
    w_temp[w_temp.size() - 1] = start + n;

    return w_temp;
}

void Need_person(vector<int> Weak, vector<int> Dist, int N)
{
    // �ܺ� ��� �κ��� ���������� �ؾ��ϴ��� ��Ȯ���� �ʱ⶧���� for������ �ݺ��ϱ� 
    for (int i = 0; i < Weak.size(); i++)
    {
        int idx = 0;
        int Cnt;
        bool Flag = false;

        for (int j = 0; 
            // j�� ������� ��ü �������� �۰�
            // answer �� ������ �ּڰ����� �ϳ� �� ũ�� ���´ٸ� ��� ��ü�� �ʿ��� ���� 
            // flag �� false �� ���� ���� ������ �ο���� �ܺ������� ��ģ��쿡�� ū for���� ���鼭 �������� �缳���Ѵ�.
            (j < V.size()) && (j + 1 < answer) && (Flag == false); 
            j++)
        {
            int End = Weak[idx] + Dist[V[j]];
            while (End >= Weak[idx])
            {
                idx++;
                if (idx == Weak.size())
                {
                    Cnt = j + 1;
                    Flag = true;
                    break;
                }
            }
        }
        if (Flag == true)
        {
            answer = min(answer, Cnt);
        }
     
        int Start = Weak[0];
        Weak = Next_Vector(Weak, Start, N);
    }
}

void ALL_CASE(int Cnt, vector<int> Weak, vector<int> Dist, int N)
{
    if (Cnt == Dist.size())
    {
        // �ο��� �� ä��������쿡�� Ư���ο��� �ʿ��ϴ� ��찡 ��������� ������ ���� �ش� ���� üũ�ϱ� ���� �Լ�ó�� 
        Need_person(Weak, Dist, N);
        return;
    }

    for (int i = 0; i < Dist.size(); i++)
    {
        // ���õ� ����̶�� ��� 
        if (Choice[i] == true)
        {
            continue;
        }
        // �ƴ϶�� ������ ���� 
        Choice[i] = true;
        // ���õ� ��� ���Ϳ� �߰� 
        V.push_back(i);
        // ��ͷ� �߰� �ϱ� 
        ALL_CASE(Cnt + 1, Weak, Dist, N);
        V.pop_back();
        Choice[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    // �̵��Ҽ��ִ� �Ÿ��� ���� ������������ ����    
    sort(dist.begin(), dist.end(), Cmp);

    // �� ����� ó���Ҽ� �ִ��� ��ü ���� �ݺ�
    vector<int> w_temp = weak;
    for (int i = 0; i < w_temp.size(); i++)
    {
        int start = w_temp[0];
        int end = w_temp[w_temp.size() - 1];
        // ���� ���� ������ ���� ���̰� ���� �Ÿ��� ���� �̵��Ҽ��ִ� ��� 1���� ��쿡 ���� 1
        if (end - start <= dist[0])
        {
            return 1;
        }

        // �ƴѰ�� �迭�� �ϳ��� �о��� ex) 1,2,3 -> 2,3,1
        w_temp = Next_Vector(w_temp,start,n);
    }

    // dist �� ����� ��������� ���Խ�Ű���Ŀ� ���� ����� �޶��� ������ ���� 
    ALL_CASE(0, weak, dist, n);

    if (answer == 9)
    {
        return -1;
    }
    return answer;
}

int main()
{
    int n = 12;
    vector<vector<int>> weak = { {1,5,6,10},{1,3,4,9,10} };
    vector<vector<int>> dist = { {1,2,3,4},{3,5,7} };

    for (int i = 0; i < weak.size(); i++)
    {
        cout << i << " = " << solution(n, weak[i], dist[i]) << endl;
    }
}