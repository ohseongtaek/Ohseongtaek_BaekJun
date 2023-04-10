#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;
   
    map<int, string> m2;
    map<string, int> m;
    map<int, string>::iterator iter2 = m2.begin();
    map<string, int>::iterator iter = m.begin();

    for (int i = 0; i < players.size(); i++)
    {
        m.insert(make_pair(players[i], i));
        m2.insert(make_pair(i, players[i]));
    }
    
    for (int i = 0; i < callings.size(); i++)
    {
        // �߿��� 
        iter = m.find(callings[i]);
        int temp = iter->second;
        
        // �ڷΰ����
        iter2 = m2.find(temp-1);

        // �� map ����
        m[iter->first] = temp - 1;
        m[iter2->second] = temp;

        m2[temp] = iter2->second;
        m2[temp - 1] = iter->first;
        
    }
 

    for (iter2 = m2.begin(); iter2 != m2.end(); iter2++)
    {
        answer.push_back(iter2->second);
    }
    return answer;
}

int main()
{
    vector<vector<string>> p = { {"mumu", "soe", "poe", "kai", "mine"} };
    vector<vector<string>> c = { {"kai", "kai", "mine", "mine"} };
    vector<string> d = solution(p[0], c[0]);
    vector<string> dab = { "mumu", "kai", "mine", "soe", "poe" };

    bool flag = true;
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] != dab[i])
        {
            flag = false;
            break;
        }
    }

    if (flag == true)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " eroor " << endl;
    }

}
/*
�ῡ���� �ų� �޸��� ���ְ� �����ϴ�. 
�ؼ������� �������� �ڱ� �ٷ� ���� ������ �߿��� �� �߿��� ������ �̸��� �θ��ϴ�. 
���� ��� 1����� 3����� "mumu", "soe", "poe" �������� ������� �޸��� ���� ��, 
�ؼ����� "soe"������ �ҷ��ٸ� 2���� "soe" ������ 1���� "mumu" ������ �߿��ߴٴ� ���Դϴ�. 
�� "soe" ������ 1��, "mumu" ������ 2������ �ٲ�ϴ�.

�������� �̸��� 1����� ���� ��� ������� ��� ���ڿ� �迭 players�� �ؼ����� �θ� �̸��� ���� ���ڿ� �迭 callings�� �Ű������� �־��� ��, 
���ְ� ������ �� �������� �̸��� 1����� ��� ������� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
5 �� players�� ���� �� 50,000
players{i}�� i��° ������ �̸��� �ǹ��մϴ�.
players�� ���ҵ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
players���� �ߺ��� ���� �� ���� �ʽ��ϴ�.
3 �� players{i}�� ���� �� 10
2 �� callings�� ���� �� 1,000,000
callings�� players�� ���ҵ�θ� �̷���� �ֽ��ϴ�.
���� ������ 1���� ������ �̸��� �Ҹ��� �ʽ��ϴ�.
����� ��
players	callings	result
		
����� �� ����
����� �� #1

4���� "kai" ������ 2�� �߿��Ͽ� 2���� �ǰ� �ռ� 3��, 2���� "poe", "soe" ������ 4��, 3���� �˴ϴ�. 5���� "mine" ������ 2�� �߿��Ͽ� 4��, 3���� "poe", "soe" ������ 5��, 4���� �ǰ� ���ְ� �����ϴ�. 1����� �迭�� ������ {"mumu", "kai", "mine", "soe", "poe"}�� �˴ϴ�.
*/