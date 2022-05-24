

// ���� �߻� �ڵ� ! set�� ����ϸ� ���� Ǯ������!

/*
#include <string>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    // 0 ���� ���� 
    // D => down
    // U => Up
    // C => delete
    // Z => restore

    // n ��ŭ 0���� �ʱ�ȭ�� ����Ʈ ���� 
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(false, i));
    }

    // ������ ���� ��� ���� ���� 
    vector<pair<int,int>> delete_v;

    // �ʱ� ���� index �� true �� ���� 
    v[k].first = true;

    // ���� ���õ� �� �˱� ���� ���� 
    int nCurrentSelect = k;

    // ������� �ε��� 
    vector<int> v_idx;
    

    for (int i = 0; i < cmd.size(); i++)
    {
        string logic = cmd[i];
        if (logic.size() > 1)
        {
            size_t idx = logic.find(" ");
            int number = stoi(logic.substr(idx, logic.size()));

            // ���õ� ��ġ�� ����Ǿ� ���� ��ġ false�� ���� 
            v[nCurrentSelect].first = false;

            if (logic[0] == 'D')
            {
                nCurrentSelect += number;
            }
            else if (logic[0] == 'U')
            {
                nCurrentSelect -= number;
            }

            // ���Ӱ� ����� ��ġ ����
            v[nCurrentSelect].first = true;
        }
        // C�� ��� 
        else if(logic[0] == 'C')
        {
            //���� �ε��� ���� �� �ٷ� �Ʒ����� �ö���鼭 ������ 
            //(���� �� �ؿ� ���� ������ ��� �ٷ� ���� ���� ���õ�)
            if (nCurrentSelect == v.size() - 1)
            {
                v[nCurrentSelect].first = false;
                delete_v.push_back(make_pair(false,v[nCurrentSelect].second));
                v.erase(v.begin() + nCurrentSelect);
                v[nCurrentSelect - 1].first = true;
                nCurrentSelect -= 1;
                v_idx.push_back(nCurrentSelect + 1);
            }
            // �Ϲ����� ��� 
            else
            {
                v[nCurrentSelect].first = false;
                delete_v.push_back(make_pair(false, v[nCurrentSelect].second));
                v.erase(v.begin() + nCurrentSelect);
                v[nCurrentSelect].first = true;
                v_idx.push_back(nCurrentSelect);
            }
        }
        // Z�� ��� 
        else if (logic[0] == 'Z')
        {
            // ���� ���õ� �ຸ�� �Ʒ��� �ִ� ���� �����ϴ� ��쿡�� ���� �ε��� true ���� false �� ���� ���� +1�� �� ���� true�� �����ؾ��� 
            int test = delete_v.size() - 1;
            int idx = v_idx[v_idx.size() - 1];
            if (nCurrentSelect >= delete_v[delete_v.size() - 1].second)
            {
                v[nCurrentSelect].first = false;
                v.insert(v.begin() + idx,make_pair(false, delete_v[test].second));
                nCurrentSelect++;
                v[nCurrentSelect].first = true;
            }
            else
            {
                v.insert(v.begin() + idx, make_pair(false, delete_v[test].second));
            }
            delete_v.pop_back();
            v_idx.pop_back();
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < delete_v.size(); j++)
        {
            if (delete_v[j].second == i)
            {
                answer += "X";
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }
        answer += "O";
    }

    return answer;
}

int main()
{
    vector<int> n = { 8,8 };
    vector<int> k = { 2,2 };
    vector<vector<string>> cmd = { { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" } , {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"} };
    
    vector<string> dablist = { "OOOOXOOO","OOXOXOOO" };
    vector<string> dab;
    for (int i = 0; i < n.size(); i++)
    {
        dab.push_back(solution(n[i], k[i], cmd[i]));
    }

    for (int i = 0; i < dab.size(); i++)
    {
        if (dab[i] == dablist[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
            cout << dab[i] << endl;
            cout << dablist[i] << endl;
        }
    }
    return 0;
}

*/

// ȿ���� �׽�Ʈ ��� ����...

/*
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

string solution(int n, int k, vector<string> cmd) 
{
    string answer(n, 'X');
    set<int> table;
    stack<int> Delete_stack;

    // �⺻�� �Է� 
    for (int i = 0; i < n; i++)
    {
        table.insert(i);
    }

    // ���� ��ġ ���� 
    auto nCurrentSelect = table.find(k);
    
    for (int i = 0; i < cmd.size(); i++)
    {
        string str = cmd[i];

        if (str[0] == 'U' || str[0] == 'D')
        {
            size_t idx = str.find(" ");
            int number = stoi(str.substr(idx, str.size()));
            if (str[0] == 'U')
            {
                while (number--)
                {
                    nCurrentSelect = prev(nCurrentSelect);
                }
            }
            else
            {
                while (number--)
                {
                    nCurrentSelect = next(nCurrentSelect);
                }
            }
        }
        else if (str[0] == 'C')
        {
            Delete_stack.push(*nCurrentSelect);
            nCurrentSelect = table.erase(nCurrentSelect);
            if (nCurrentSelect == table.end())
            {
                nCurrentSelect = prev(nCurrentSelect);
            }
        }
        else if (str[0] == 'Z')
        {
            table.insert(Delete_stack.top());
            Delete_stack.pop();
        }
    }
    
    for (int i : table)
    {
        answer[i] = 'O';
    }

    return answer;

}
*/



// https://yabmoons.tistory.com/686 => �幮�� �ڵ� ���� �� ���ο��� (2022.02.15 ~ 2022.04.26) ȿ�����׽�Ʈ ������ �Ф�

#include <string>
#include <vector>
#include <iostream>
#include <stack>


using namespace std;

struct NODE
{
    int Data;
    NODE* Prev;
    NODE* Next;
    NODE(int D)
    {
        Data = D;
        Prev = NULL;
        Next = NULL;
    }
};

struct LINKEDLIST
{
    NODE* Head;
    NODE* Tail;

    LINKEDLIST() : Head(NULL), Tail(NULL) {}
    void Insert(int _Data);
    NODE* Erase(NODE* Node);
    void Restore(NODE* Node);
};

void LINKEDLIST::Insert(int _Data)
{
    if (Head == NULL)
    {
        NODE* NewNode = new NODE(_Data);
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        NODE* NewNode = new NODE(_Data);
        NewNode->Prev = Tail;
        Tail->Next = NewNode;
        Tail = Tail->Next;
    }
}

NODE* LINKEDLIST::Erase(NODE* Node)
{
    if (Node == Head)
    {
        Head = Node->Next;
        Node->Next->Prev = NULL;
        return Node->Next;
    }
    else if (Node == Tail)
    {
        Tail = Node->Prev;
        Node->Prev->Next = NULL;
        return Node->Prev;
    }
    else
    {
        Node->Prev->Next = Node->Next;
        Node->Next->Prev = Node->Prev;
        return Node->Next;
    }
}

void LINKEDLIST::Restore(NODE* Node)
{
    if (Node->Prev == NULL)
    {
        Head = Node;
        Node->Next->Prev = Node;
    }
    else if (Node->Next == NULL)
    {
        Tail = Node;
        Node->Prev->Next = Node;
    }
    else
    {
        Node->Prev->Next = Node;
        Node->Next->Prev = Node;
    }
}

stack<NODE*> Delete;
LINKEDLIST* List;

void Make_LinkedList(int N)
{
    List = new LINKEDLIST();
    for (int i = 0; i < N; i++) List->Insert(i);
}

string Solve(int N, int K, vector<string> Cmd)
{
    NODE* Iter = List->Head;
    for (int i = 0; i < K; i++) Iter = Iter->Next;

    for (int i = 0; i < Cmd.size(); i++)
    {
        string Str = Cmd[i];
        if (Str[0] == 'U')
        {
            string SX = Str.substr(2);
            int X = stoi(SX);
            for (int i = 0; i < X; i++) Iter = Iter->Prev;
        }
        else if (Str[0] == 'D')
        {
            string SX = Str.substr(2);
            int X = stoi(SX);
            for (int i = 0; i < X; i++) Iter = Iter->Next;
        }
        else if (Str[0] == 'C')
        {
            Delete.push(Iter);
            Iter = List->Erase(Iter);
        }
        else
        {
            NODE* Z = Delete.top();
            Delete.pop();
            List->Restore(Z);
        }
    }

    string Result = "";
    for (int i = 0; i < N; i++) Result += 'O';
    while (Delete.empty() == false)
    {
        NODE* Temp = Delete.top();
        Delete.pop();

        int Idx = Temp->Data;
        Result[Idx] = 'X';
    }
    return Result;
}

string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    Make_LinkedList(n);
    answer = Solve(n, k, cmd);
    return answer;
}


int main()
{
    vector<int> n = { 8,8 };
    vector<int> k = { 2,2 };
    vector<vector<string>> cmd = { { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" } , {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"} };

    vector<string> dablist = { "OOOOXOOO","OOXOXOOO" };
    vector<string> dab;
    for (int i = 0; i < n.size(); i++)
    {
        dab.push_back(solution(n[i], k[i], cmd[i]));
    }

    for (int i = 0; i < dab.size(); i++)
    {
        if (dab[i] == dablist[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
            cout << dab[i] << endl;
            cout << dablist[i] << endl;
        }
    }
    return 0;
}
//ó�� ǥ�� �� ������ ��Ÿ���� ���� n, 
//ó���� ���õ� ���� ��ġ�� ��Ÿ���� ���� k, 
//������ ��ɾ���� ��� ���ڿ� �迭 cmd�� �Ű������� �־��� ��, 
//��� ��ɾ ������ �� ǥ�� ���¿� ó�� �־��� ǥ�� ���¸� ���Ͽ� �������� ���� ���� O, 
//������ ���� X�� ǥ���Ͽ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ����ּ���.