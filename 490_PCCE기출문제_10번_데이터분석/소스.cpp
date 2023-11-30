#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string StrSort_by = "";
bool sortComp(int a, int b)
{
    if (a < b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool comp(vector<int> a, vector<int> b)
{
    //"code", "date", "maximum", "remain"
    if (StrSort_by == "code")
    {
        if (a[0] < b[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(StrSort_by == "date")
    {
        if (a[1] < b[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(StrSort_by == "maximum")
    {
        if (a[2] < b[2])
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
        if (a[3] < b[3])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;
    vector<vector<int>> vtemp;
    bool bRtn = false;
    StrSort_by = sort_by;

    for (int i = 0; i < data.size(); i++)
    {
        if (ext == "code")
        {
            bRtn = sortComp(data[i][0], val_ext);
        }
        else if (ext == "date")
        {
            bRtn = sortComp(data[i][1], val_ext);
        }
        else if (ext == "maximum")
        {
            bRtn = sortComp(data[i][2], val_ext);
        }
        else if (ext == "remain")
        {
            bRtn = sortComp(data[i][3], val_ext);
        }

        if (bRtn == true)
        {
            vtemp.push_back(data[i]);
        }
    }

    sort(vtemp.begin(), vtemp.end(), comp);

    //"code", "date", "maximum", "remain"
    answer = vtemp;
    return answer;
}

int main()
{
    vector<vector<int>> v = { {1, 20300104, 100, 80}, { 2, 20300804, 847, 37 }, { 3, 20300401, 10, 8 } };
    string ext = "date";
    int val_ext = 20300501;
    string sor = "remain";
    
    vector<vector<int>> vv = solution(v, ext, val_ext, sor);

    printf("%d", vv[0][0]);
    //{ {3, 20300401, 10, 8}, { 1,20300104,100,80 }}
}

/*
AI �����Ͼ��� �����̴� �����͸� �м��ϴ� �۾��� �����ϰ� �ֽ��ϴ�. 
{"�ڵ� ��ȣ(code)", "������(date)", "�ִ� ����(maximum)", "���� ����(remain)"}

code	date	    maximum	remain
1	    20300104	100	    80
2	    20300804	847	    37
3	    20300401	10	    8

�־��� ������ �� "�������� 20300501 ������ ���ǵ��� ���� ������ ���� ����"�� �����ؾ� �Ѵٸ� ���ǿ� �°� ������ �����ʹ� ������ �����ϴ�.

data = {{3,20300401,10,8},{1,20300104,100,80}}
������ �����͵��� ��� ������ ���� ����Ʈ data�� � ������ �������� �����͸� �̾Ƴ����� �ǹ��ϴ� ���ڿ� ext, �̾Ƴ� ������ ���ذ��� ��Ÿ���� ���� val_ext, ������ ������ ������ �Ǵ� ���ڿ� sort_by�� �־����ϴ�.

data���� ext ���� val_ext���� ���� �����͸� ���� ��, sort_by�� �ش��ϴ� ���� �������� ������������ �����Ͽ� return �ϵ��� solution �Լ��� �ϼ��� �ּ���. ��, ������ �����ϴ� �����ʹ� �׻� �� �� �̻� �����մϴ�.

���ѻ���
1 �� data�� ���� �� 500
data{i}�� ���Ҵ� {�ڵ� ��ȣ(code), ������(date), �ִ� ����(maximum), ���� ����(remain)} �����Դϴ�.
1 �� �ڵ� ��ȣ�� 100,000
20000101 �� �����ϡ� 29991231
data{i}{1}�� yyyymmdd ������ ���� ������, �ùٸ� ��¥�� �־����ϴ�. (yyyy : ����, mm : ��, dd : ��)
1 �� �ִ� ������ 10,000
1 �� ���� ������ �ִ� ����
ext�� sort_by�� ���� ���� �� �� ������ �����ϴ�.
"code", "date", "maximum", "remain"
������� �ڵ� ��ȣ, ������, �ִ� ����, ���� ������ �ǹ��մϴ�.
val_ext�� ext�� ���� �ùٸ� ������ ���ڷ� �־����ϴ�.
���� ���ؿ� �ش��ϴ� ���� ���� ���� ���� �����ϴ�.
����� ��
data	ext	val_ext	sort_by	result
{{1, 20300104, 100, 80}, {2, 20300804, 847, 37}, {3, 20300401, 10, 8}}	"date"	20300501	"remain"	{{3,20300401,10,8},{1,20300104,100,80}}
����� �� ����
����� �� #1

������ ����� �����մϴ�.
cpp�� �����ϴ� ��� ����Ʈ�� �迭�� ������ �ǹ��̴� Ǯ�̿� �������ּ���.
ex) ��ȣ�� ��� ���� ����Ʈ numbers�� �־����ϴ�. => ��ȣ�� ��� ���� �迭 numbers�� �־����ϴ�.
java�� �����ϴ� ��� ����Ʈ�� �迭, �Լ��� �޼ҵ�� ������ �ǹ��̴� Ǯ�̿� �������ּ���.
ex) solution �Լ��� �ùٸ��� �۵��ϵ��� �� ���� ������ �ּ���. => solution �޼ҵ尡 �ùٸ��� �۵��ϵ��� �� ���� ������ �ּ���.
*/