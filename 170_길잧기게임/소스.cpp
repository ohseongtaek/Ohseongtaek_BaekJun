#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TREE
{
    int iNodeCnt;
    int x;
    int y;
    TREE* left;     // ���� ����� ���� �ڽ� ���� 
    TREE* right;    // ���� ����� ������ �ڽ� ���� 
};

bool compare(TREE a, TREE b)
{
    if (a.y >= b.y)
    {
        if (a.y == b.y)
        {
            if (a.x < b.x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void makeTree(TREE* rootNode, TREE* childNode)
{
    // x ��ǥ �������� ���� ������ ä��� 
    // ���� ä��� 
    if (rootNode->x > childNode->x)
    {
        // ���� ��尡 ����ִ� ���  �ֱ� 
        if (rootNode->left == NULL)
        {
            rootNode->left = childNode;
            return;
        }
        // �ƴ� ��� ���ʿ� �ִ� ��尡 ��Ʈ��尡 �Ǹ� ���� ����� 
        makeTree(rootNode->left, childNode);
    }

    // ������ ä��� 
    else
    {
        // ������ ��尡 ����ִ� ��� �׳� �ֱ� 
        if (rootNode->right == NULL)
        {
            rootNode->right = childNode;
            return;
        }
        // �ƴ� ��� ������ �� �ִ� ��忡�ٰ� �ֱ� 
        makeTree(rootNode->right, childNode);
    }
}

void preorder(TREE* rootNode, vector<int>& pre)
{
    // ��尡 ���� ���� ����
    if (rootNode == NULL)
    {
        return;
    }
    else
    {
        pre.push_back(rootNode->iNodeCnt);
        // ��ͷ� ���ʲ� ������ ���� Ž���� �����ʲ� Ž�� 
        preorder(rootNode->left, pre);
        preorder(rootNode->right, pre);

    }
}

void postorder(TREE* rootNode, vector<int>& post)
{
    // ��尡 ���� ���� ����
    if (rootNode == NULL)
    {
        return;
    }
    else
    {
        // ��ͷ� ���ʲ� ������ ���� Ž���� �����ʲ� Ž�� 
        postorder(rootNode->left, post);
        postorder(rootNode->right, post);
        post.push_back(rootNode->iNodeCnt);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    // ���� ���� 
    vector<TREE> vecTree;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        TREE tr;
        tr.x = nodeinfo[i][0];
        tr.y = nodeinfo[i][1];
        tr.iNodeCnt = i + 1;
        tr.left = NULL;
        tr.right = NULL;
        vecTree.push_back(tr);
    }

    // ���� (y��ǥ ���� ū�� ��Ʈ��� , x��ǥ ������ ���ʳ�� �̷���)
    sort(vecTree.begin(), vecTree.end(), compare);

    // Tree �� ���� ������ ��� ä���ֱ� 
    TREE* rootNode = &vecTree[0];
    for (int i = 1; i < vecTree.size(); i++)
    {
        makeTree(rootNode, &vecTree[i]);
    }


    // ������ȸ 
    vector<int> pre;
    preorder(rootNode, pre);

    // ������ȸ 
    vector<int> post;
    postorder(rootNode, post);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main()
{
    vector<vector<int>> v = { {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} };
    vector<vector<int>> ans = { {7, 4, 6, 9, 1, 8, 5, 2, 3}, {9, 6, 5, 8, 1, 4, 3, 2, 7} };
    vector<vector<int>> dab;

    dab = solution(v);

    for (int i = 0; i < dab.size(); i++)
    {
        for (int j = 0; j < dab[i].size(); j++)
        {
            cout << dab[i][j] << " ";
        }
        cout << endl;
    }
}

/*

��濡 ���� īī�� ����� ���� ����Ʈ���� �����ϴ� ������ ��ǥ�� ��� �迭 nodeinfo�� �Ű������� �־��� ��,
����� ������ ����Ʈ���� ���� ��ȸ, ���� ��ȸ�� ����� 2���� �迭�� ������� ��� return �ϵ��� solution �Լ��� �ϼ�����.

���ѻ���
nodeinfo�� ����Ʈ���� �����ϴ� �� ����� ��ǥ�� 1�� ������ ������� ����ִ� 2���� �迭�̴�.
nodeinfo�� ���̴� 1 �̻� 10, 000 �����̴�.
nodeinfo{i} �� i + 1�� ����� ��ǥ�̸�, {x�� ��ǥ, y�� ��ǥ} ������ ����ִ�.
��� ����� ��ǥ ���� 0 �̻� 100, 000 ������ �����̴�.
Ʈ���� ���̰� 1, 000 ������ ��츸 �Է����� �־�����.
��� ����� ��ǥ�� ������ �־��� ��Ģ�� ������, �߸��� ��� ��ġ�� �־����� ���� ����.



*/