#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    vector<int> answer;

    map<string, int> m;

    for (int i = 0; i < name.size(); i++)
    {
        m.insert(make_pair(name[i], yearning[i]));
    }

    for (int i = 0; i < photo.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < photo[i].size(); j++)
        {
            int value = 0;
            value = m[photo[i][j]];
            if (value != 0)
            {
                sum += value;
            }
        }

        answer.push_back(sum);
    }


    return answer;
}

int main()
{
    vector<vector<string>> name = { {"may", "kein", "kain", "radi"}, {"kali", "mari", "don"}, { "may", "kein", "kain", "radi" } };
    vector<vector<int>> ye = { {5, 10, 1, 3},{11, 1, 55},{ 5, 10, 1, 3 } };
    vector<vector<vector<string>>> p = { { {"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"} },
                                         { {"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"} },
                                         { {"may"}, {"kein", "deny", "may"}, {"kon", "coni"} } };
    vector<vector<int>> d = { { 19, 15, 6 }, { 67, 0, 55 }, { 5, 15, 0 } };

    for (int i = 0; i < d.size(); i++)
    {
        vector<int> dab = solution(name[i], ye[i], p[i]);

        bool flag = false;

        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != d[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
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
�������� ���� �߾￡ ���� �ִ� ��� �������� �߾� ������ �ű���� �մϴ�.
���� �ӿ� ������ �ι��� �׸��� ������ ��� �ջ��� ���� �ش� ������ �߾� ������ �˴ϴ�.

���� ��� ���� �� �ι��� �̸���{"may", "kein", "kain"}�̰� 
�� �ι��� �׸��� ������{5��, 10��, 1��}�� �� �ش� ������ �߾� ������ 16(5 + 10 + 1)���� �˴ϴ�.

�ٸ� ���� �� �ι��� �̸���{"kali", "mari", "don", "tony"}�̰�{"kali", "mari", "don"}�� �׸��� ������ ����{11��, 1��, 55��}}�̰�, 

"tony"�� �׸��� ������ ���� ��, �� ������ �߾� ������ 3���� �׸��� ������ ���� 67(11 + 1 + 55)���Դϴ�.

�׸����ϴ� ����� �̸��� ���� ���ڿ� �迭 name, 
�� ����� �׸��� ������ ���� ���� �迭 yearning, 
�� ������ ���� �ι��� �̸��� ���� ������ ���ڿ� �迭 photo�� �Ű������� �־��� ��, 
�������� �߾� ������ photo�� �־��� ������� �迭�� ��� return�ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
3 �� name�� ���� = yearning�� ���̡� 100
3 �� name�� ������ ���� �� 7
name�� ���ҵ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
name���� �ߺ��� ���� ���� �ʽ��ϴ�.
1 �� yearning{i} �� 100
yearning{i}�� i��° ����� �׸��� �����Դϴ�.
3 �� photo�� ���� �� 100
1 �� photo{i}�� ���� �� 100
3 �� photo{i}�� ����(���ڿ�)�� ���� �� 7
photo{i}�� ���ҵ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
photo{i}�� ���ҵ��� �ߺ��� ���� ���� �ʽ��ϴ�.
����� ��
name	yearning	photo	result
{"may", "kein", "kain", "radi"},     {5, 10, 1, 3},   {{"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}},  {19, 15, 6},
{"kali", "mari", "don"},            {11, 1, 55},     {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}},                         {67, 0, 55},
{"may", "kein", "kain", "radi"}     {5, 10, 1, 3}   {{"may"}, {"kein", "deny", "may"}, {"kon", "coni"}}                                                  {5, 15, 0}
����� �� ����
����� �� #1

ù ��° ���� �� "may", "kein", "kain", "radi"�� �׸��� ������ ��ġ�� 19(5 + 10 + 1 + 3)�� �Դϴ�.�� ��° ���� �� �׸����ϴ� ������� "may"�� "kein"�� �׸��� ������ ��ġ�� 15(5 + 10)���Դϴ�.�� ��° ������ ��� "kain"�� "may"�� �׸����ϹǷ� ���� �׸��� ������ ���� 6(1 + 5)���� ������ �߾� �����Դϴ�.����{19, 15, 6}�� ��ȯ�մϴ�.

����� �� #2

ù ��° ���� �� �׸����ϴ� ������� "kali", "mari", "don"�� �׸��� ������ ��ġ�� 67(11 + 1 + 55)���Դϴ�.�� ��° ���� �ӿ� �׸����ϴ� �ι��� �����Ƿ� 0���Դϴ�.�� ��° ���� �� �׸����ϴ� ����� "don"�� �����Ƿ� 55���Դϴ�.����{67, 0, 55}�� ��ȯ�մϴ�.

����� �� #3

���� ����
*/