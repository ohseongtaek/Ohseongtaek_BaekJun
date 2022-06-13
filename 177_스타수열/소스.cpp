#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// ��Ÿ�����̶� ? 
// => x(�κм���)�� ���̰� 2�̻�
// => �� �κм����� �������� ���Ұ� 1�� �̻��̴� => ex) {0,1} {0,3} => 0�� �κм����� ������!
// => �� �κм����� ���� ������ �ȵ� => ex) {1,1} => �κм����� ���� ����!


int solution(vector<int> a) 
{
    int answer = -1;
    
    // Ư�� ���ڰ� �����ϴ� Ƚ���� ī��Ʈ�ϱ� ���� ���� 
    vector<int> NumberCnt(a.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)
    {
        NumberCnt[a[i]]++;
    }

    // ������ �Ǵ� ��Ÿ������ �迭�� for������ �ݺ� !
    for (int i = 0; i < NumberCnt.size(); i++)
    {
        // �Ķ���Ϳ� ������ ���Ϳ� �������� �ʴ� ������ ��� 
        if (NumberCnt[i] == 0)
        {
            continue;
        }
        // ������ ������ ��Ÿ������ ����µ� ���� ���� ���� Ƚ�� ���� ���� ��쿡�� ��� ��ü�� �� �ʿ䰡 ����!
        // ex ) 1�� �̿��� 1,2 1,3 1,4 �� ����� 2�� ���������� 2�� �� 2���ۿ� �ȳ��� ��쿡�� Ž���� �� �ʿ䰡 ����!
        if (NumberCnt[i] <= answer)
        {
            continue;
        }

        int res = 0;

        for (int j = 0; j < a.size() - 1; j++)
        {
            // �������� ���� i �� ���� ���� �ε����� �����ε����� ���� ��쿡�� ��Ÿ������ �� �� ���� ������ continue;
            if (a[j] != i && a[j + 1] != i)
            {
                continue;
            }
            // �������� ���� i �� ���� ���� �ε����� ������ ��쿡 �������� ���õ� ���ؿ� �������� ���ϹǷ�  continue;
            if (a[j] == a[j + 1])
            {
                continue;
            }

            // ���� 2������ �ƴѰ�� ��Ÿ������ ������ �ø��� �ε����� 2���� Ž���ϱ� ������ j++ �� ���ش�.
            res++;
            j++;
        }

        answer = max(answer, res);
    }

    // ��Ÿ������ ���̴� 2��� ������ !
    return answer * 2;
}

int main() {

    vector<vector<int>> v = { {0} , {5, 2, 3, 3, 5, 3} ,{ 0,3,3,0,7,2,0,2,2,0 } };
    vector<int> dab = { 0,4,8 };


    for (int i = 0; i < v.size(); i++)
    {
        int a = solution(v[i]);
        if (dab[i] == a)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << a << ", want = " << dab[i] << endl;
        }
    }

}