#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    int board[51][51];
    int GiveRecv[51];
    map<string, int> mapFriend;
    
    memset(board, 0, sizeof(board));
    memset(GiveRecv, 0, sizeof(GiveRecv));
    mapFriend.clear();

    // �������� �� �ֱ� 
    for (int i = 0; i < friends.size(); i++)
    {
        mapFriend[friends[i]] = i;
    }

    for (int i = 0; i < gifts.size(); i++)
    {
        int idxEmpty = 0;
        int give = 0;
        int recv = 0;
        string start = "";
        string end = "";
        string strIdx = gifts[i];

        idxEmpty = strIdx.find(' ');
        
        start = strIdx.substr(0, idxEmpty);
        end = strIdx.substr(idxEmpty + 1);

        give = mapFriend[start];
        recv = mapFriend[end];
        
        board[give][recv]++;

        GiveRecv[give]++;
        GiveRecv[recv]--;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        int rtn = 0;
        for (int j = 0; j < friends.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            
            if (board[i][j] > board[j][i])
            {
                rtn++;
            }

            if (board[i][j] == board[j][i])
            {
                if (GiveRecv[i] > GiveRecv[j])
                {
                    rtn++;
                }
            }
        }

        answer = max(answer, rtn);
    }

    return answer;
}

int main()
{
	vector<vector<string>> v1 = { { "muzi", "ryan", "frodo", "neo" }, 
                                  { "joy", "brad", "alessandro", "conan", "david" }, 
                                  { "a", "b", "c" } };

    vector<vector<string>> g1 = { {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"} ,
                                  {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"},
                                  {"a b", "b a", "c a", "a c", "a c", "c a"} };
    vector<int> ans = { 2,4,0 };

    for (int i = 0; i < v1.size(); i++)
    {
        int dab = solution(v1[i], g1[i]);
        if (dab == ans[i])
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
������ ���� ���ϱ� ���� �� īī���� �����ϱ� ����� �̿��� ���� ������ ���� �� �ֽ��ϴ�. 
����� ģ������ �̹� �ޱ��� ������ �ְ���� ����� �������� ���� �޿� ���� ������ ���� ������ �����Ϸ��� �մϴ�.

�� ����� ������ �ְ���� ����� �ִٸ�, �̹� �ޱ��� �� ��� ���̿� �� ���� ������ �� ����� ���� �޿� ������ �ϳ� �޽��ϴ�.
���� ��� A�� B���� ������ 5�� ���, B�� A���� ������ 3�� ��ٸ� ���� �޿� A�� B���� ������ �ϳ� �޽��ϴ�.
�� ����� ������ �ְ���� ����� �ϳ��� ���ų� �ְ���� ���� ���ٸ�, ���� ������ �� ū ����� ���� ������ �� ���� ������� ������ �ϳ� �޽��ϴ�.
���� ������ �̹� �ޱ��� �ڽ��� ģ���鿡�� �� ������ ������ ���� ������ ���� �� ���Դϴ�.
���� ��� A�� ģ���鿡�� �� ������ 3���� ���� ������ 10����� A�� ���� ������ -7�Դϴ�. B�� ģ���鿡�� �� ������ 3���� ���� ������ 2����� B�� ���� ������ 1�Դϴ�. ���� A�� B�� ������ �ְ���� ���� ���ų� ��Ȯ�� ���� ���� ������ �ְ�޾Ҵٸ�, ���� �޿� B�� A���� ������ �ϳ� �޽��ϴ�.
���� �� ����� ���� ������ ���ٸ� ���� �޿� ������ �ְ���� �ʽ��ϴ�.
������ ������ ��Ģ��� ���� �޿� ������ �ְ���� ��, ����� ������ ���� ���� ���� ģ���� ���� ������ ���� �˰� �ͽ��ϴ�.

ģ������ �̸��� ���� 1���� ���ڿ� �迭 friends �̹� �ޱ��� ģ������ �ְ���� ���� ����� ���� 1���� ���ڿ� �迭 gifts�� �Ű������� �־����ϴ�. �̶�, �����޿� ���� ���� ������ �޴� ģ���� ���� ������ ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
2 �� friends�� ���� = ģ������ �� �� 50
friends�� ���Ҵ� ģ���� �̸��� �ǹ��ϴ� ���ĺ� �ҹ��ڷ� �̷���� ���̰� 10 ������ ���ڿ��Դϴ�.
�̸��� ���� ģ���� �����ϴ�.
1 �� gifts�� ���� �� 10,000
gifts�� ���Ҵ� "A B"������ ���ڿ��Դϴ�. A�� ������ �� ģ���� �̸��� B�� ������ ���� ģ���� �̸��� �ǹ��ϸ� ���� �ϳ��� ���е˴ϴ�.
A�� B�� friends�� �����̸� A�� B�� ���� �̸��� ���� �������� �ʽ��ϴ�.

����� ��
friends	gifts	result
{"muzi", "ryan", "frodo", "neo"}	{"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"}	2
{"joy", "brad", "alessandro", "conan", "david"}	{"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"}	4
{"a", "b", "c"}	{"a b", "b a", "c a", "a c", "a c", "c a"}	0
����� �� ����
����� �� #1

�ְ���� ������ ���� ������ ǥ�� ��Ÿ���� ������ �����ϴ�.

���� ��� \ ���� �����	muzi	ryan	frodo	neo
muzi	-	0	2	0
ryan	3	-	0	0
frodo	1	1	-	0
neo	1	0	0	-
�̸�	�� ����	���� ����	���� ����
muzi	2	5	-3
ryan	3	1	2
frodo	2	2	0
neo	1	0	1
muzi�� ������ �� ���� ��� frodo���Լ� ������ �ϳ� �޽��ϴ�.
ryan�� ������ �� ���� ��� muzi���Լ� ������ �ϳ� �ް�, ������ �ְ���� �ʾҴ� neo���� ���� ������ Ŀ ������ �ϳ� �޽��ϴ�.
frodo�� ������ �� ���� ��� ryan���� ������ �ϳ� �޽��ϴ�.
neo�� ������ �� ���� ��� muzi���Լ� ������ �ϳ� �ް�, ������ �ְ���� �ʾҴ� frodo���� ���� ������ Ŀ ������ �ϳ� �޽��ϴ�.

�����޿� ���� ������ ���� �޴� ����� ryan�� neo�̰� 2���� ������ �޽��ϴ�. ���� 2�� return �ؾ� �մϴ�.

����� �� #2

�ְ���� ������ ���� ������ ǥ�� ��Ÿ���� ������ �����ϴ�.

���� ��� \ ���� �����	joy	brad	alessandro	conan	david
joy	-	0	0	0	0
brad	0	-	0	0	0
alessandro	1	1	-	1	1
conan	0	0	0	-	0
david	0	0	1	0	-
�̸�	�� ����	���� ����	���� ����
joy	0	1	-1
brad	0	1	-1
alessandro	4	1	3
conan	0	1	-1
david	1	1	0
alessandro�� ������ �� ���� ��� joy, brad, conan���Լ� ������ 3�� �޽��ϴ�. ������ �ϳ��� �ְ���� david���� ���� ������ Ŀ ������ �ϳ� �޽��ϴ�.
david�� ������ �ְ���� �ʾҴ� joy, brad, conan���� ���� ������ Ŀ ���� �޿� ������ 3�� �޽��ϴ�.
joy, brad, conan�� ������ ���� ���մϴ�.

�����޿� ���� ������ ���� �޴� ����� alessandro�̰� 4���� ������ �޽��ϴ�. ���� 4�� return �ؾ� �մϴ�.

����� �� #3

a�� b, a�� c, b�� c ���̿� ���� ������ �ְ���� ���� ���� �� ����� ���� ������ 0���� ���� ���� �޿� �ƹ��� ������ ���� ���մϴ�. ���� 0�� return �ؾ� �մϴ�.

*/