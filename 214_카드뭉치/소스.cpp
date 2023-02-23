#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";
    int idxC1 = 0;
    int idxC2 = 0;

    answer = "Yes";

    for (int i = 0; i < goal.size(); i++)
    {
        string word = goal[i];

        if (word == cards1[idxC1])
        {
            idxC1++;
            continue;
        }

        if (word == cards2[idxC2])
        {
            idxC2++;
            continue;
        }

        answer = "No";

        break;
    }
    return answer;
}

int main()
{
    vector<vector<string>> c1 = { {"i", "drink", "water"}, {"i", "water", "drink"} };
    vector<vector<string>> c2 = { {"want", "to"},{"want", "to"} };
    vector<vector<string>> goal = { {"i", "want", "to", "drink", "water"} ,{"i", "want", "to", "drink", "water"} };
    vector<string> answer = { "YES","NO" };

    for (int i = 0; i < c1.size(); i++)
    {
        string dab = solution(c1[i], c2[i], goal[i]);

        if (dab == answer[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}


/*
���ϴ� ī�� ��ġ���� ī�带 ������� �� �徿 ����մϴ�.

�� �� ����� ī��� �ٽ� ����� �� �����ϴ�.

ī�带 ������� �ʰ� ���� ī��� �Ѿ �� �����ϴ�.

������ �־��� ī�� ��ġ�� �ܾ� ������ �ٲ� �� �����ϴ�.

���� ��� ù ��° ī�� ��ġ�� ������� {"i", "drink", "water"}, �� ��° ī�� ��ġ�� ������� {"want", "to"}�� �������� �� {"i", "want", "to", "drink", "water"} ������ �ܾ� �迭�� ������� �Ѵٸ�
ù ��° ī�� ��ġ���� "i"�� ����� �� �� ��° ī�� ��ġ���� "want"�� "to"�� ����ϰ� ù ��° ī�并ġ�� "drink"�� "water"�� ���ʴ�� ����ϸ� ���ϴ� ������ �ܾ� �迭�� ���� �� �ֽ��ϴ�.

���ڿ��� �̷���� �迭 cards1, cards2�� ���ϴ� �ܾ� �迭 goal�� �Ű������� �־��� ��, cards1�� cards2�� ���� �ܾ��� goal�� ���� �ִٸ� "Yes"��, ���� �� ���ٸ� "No"�� return�ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� cards1�� ����, cards2�� ���� �� 10
1 �� cards1{i}�� ����, cards2{i}�� ���� �� 10
cards1�� cards2���� ���� �ٸ� �ܾ �����մϴ�.
2 �� goal�� ���� �� cards1�� ���� + cards2�� ����
1 �� goal{i}�� ���� �� 10
goal�� ���Ҵ� cards1�� cards2�� ���ҵ�θ� �̷���� �ֽ��ϴ�.
cards1, cards2, goal�� ���ڿ����� ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
����� ��
cards1	cards2	goal	result
{"i", "drink", "water"}	{"want", "to"}	{"i", "want", "to", "drink", "water"}	"Yes"
{"i", "water", "drink"}	{"want", "to"}	{"i", "want", "to", "drink", "water"}	"No"
����� �� ����
����� �� #1

������ �����ϴ�.

����� �� #2

cards1���� "i"�� ����ϰ� cards2���� "want"�� "to"�� ����Ͽ� "i want to"������ ���� �� ������ "water"�� "drink"���� ���� ���Ǿ�� �ϱ� ������ �ش� ������ �ϼ���ų �� �����ϴ�. ���� "No"�� ��ȯ�մϴ�.

*/