#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
#define remove_rn "\n"

struct WebPage {
    int idx;            // �ε���
    int basic;          // �⺻���� 
    int externel_link;  // �������������� �ٸ� �������� ��ũ�� �� 
    vector<int> link_page_idx;  // �ش��������� ��ũ�� �ɸ� �������� �ε���
    int matching;       // ������ 
    string url;         // ���������� url
    WebPage()
    {
        idx = 0;
        basic = 0;
        externel_link = 0;
        link_page_idx.clear();
        matching = 0;
        url = "";
    }
};

vector<WebPage> v;

void Find_currentURL(string page, WebPage& st_page, int idx, string word)
{
    // �ε��� �ֱ�
    st_page.idx = idx;
    
    // ���� URL �ֱ� 
    string tmp_page = page;
    tmp_page = tmp_page.substr(tmp_page.find("content=") + 9);
    tmp_page = tmp_page.substr(0, tmp_page.find("\""));
    st_page.url = tmp_page;

    // �˻��� ����Ƚ�� �ֱ� 
    // ��� ���� �ҹ��ڷ� ���� 
    int count = 0;
    for (int i = 0; i < page.size(); i++)
    {
        if (isalpha(page[i]))
        {
            page[i] = tolower(page[i]);
        }
    }
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }

    tmp_page = page;
    size_t find_idx;
    int word_size = word.size();
    while ((find_idx = tmp_page.find(word)) != string::npos)
    {
        // �� �� 
        if (isalpha(tmp_page[find_idx - 1]) || isalpha(tmp_page[find_idx + word_size]))
        {
            tmp_page = tmp_page.substr(find_idx + 1);
            continue;
        }
        count++;
        tmp_page = tmp_page.substr(find_idx + 1);
    }
    st_page.basic = count;
}

void Find_struct(string page, string word, WebPage &st_page, int idx)
{
    // ���� 
    int url_idx = 0;
    // ���ڿ� ���� 
    string tmp_page = "";

    // �ܺη� ������ ��ũ 
    int count = 0;
    tmp_page = page;
    while(tmp_page.find("a href=") != string::npos)
    {
        count++;
        tmp_page = tmp_page.substr(tmp_page.find("a href=") + 8);
    }
    // ã�� ī��Ʈ��ŭ ���� �ֱ� 
    st_page.externel_link = count;

    // �ܺ� URL Vector�� �ֱ� 
    int loop = count - 1;
    for (int i = loop; i >= 0; i--)
    {
        int wlop = i;
        tmp_page = page;
        while (wlop--)
        {
            tmp_page = tmp_page.substr(tmp_page.find("a href=") + 8);
        }
        tmp_page = tmp_page.substr(tmp_page.find("a href=") + 8);
        tmp_page = tmp_page.substr(0, tmp_page.find("\""));
        
        // �������� ���Ϳ� �ش� �ܺη� ���� ��ũ�� �ּҸ� �ش� ������ ī���ͷ� �����ϱ�
        for (int k = 0; k < v.size(); k++)
        {
            if (tmp_page == v[k].url)
            {
                v[k].link_page_idx.push_back(idx);
            }
        }
    }

}

int solution(string word, vector<string> pages) {
    int answer = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        // ��� ���� �����ϱ� 
        size_t found;
        while((found = pages[i].find(remove_rn)) != string::npos )
        {
            pages[i].erase(found, 1);
        }

        WebPage st_page;

        Find_currentURL(pages[i], st_page, i, word);
        v.push_back(st_page);
    }

    // ����ü ���� �����ϱ� 
    for (int i = 0; i < pages.size(); i++)
    {
        Find_struct(pages[i], word, v[i], i);
    }

    // ��� ���� 
    double result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        double sum = 0;
        double other_sum = 0;
        for (int j = 0; j < v[i].link_page_idx.size(); j++)
        {
            int externel_idx = v[i].link_page_idx[j];
            other_sum += (double)v[externel_idx].basic / (double)v[externel_idx].externel_link;
        }
        sum = other_sum + v[i].basic;
        if (result < sum)
        {
            result = sum;
            answer = i;
        }
    }
    return answer;
}
*/

struct PAGE
{
    int Idx;
    int Basic_Point;
    vector<string> Out_Link_List;
    double Link_Point;
    double Match_Point;
};

string Word;
map<string, int> Page_Num;
vector<PAGE> Page;

bool Cmp(PAGE A, PAGE B)
{
    if (A.Match_Point >= B.Match_Point)
    {
        if (A.Match_Point == B.Match_Point)
        {
            if (A.Idx < B.Idx)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

string To_Upper(string Str)
{
    transform(Str.begin(), Str.end(), Str.begin(), ::toupper);
    return Str;
}

string Find_URL(string Str)
{
    string Target = "<META PROPERTY=\"OG:URL\" CONTENT=\"HTTPS://";
    int Idx = Str.find(Target); Idx += Target.length();
    string URL = "";
    while (Str[Idx] != '\"') URL += Str[Idx++];
    return URL;
}

int Find_Word(string Str)
{
    string Target1 = "<BODY>";
    string Target2 = "/<BODY>";
    int Idx1 = Str.find(Target1); Idx1 += Target1.length();
    int Idx2 = Str.find(Target2);
    Str = Str.substr(Idx1, Idx2 - Idx1);

    string Cur = "";
    int Cnt = 0;
    for (int i = 0; i < Str.length(); i++)
    {
        if (isalpha(Str[i]) == 0)
        {
            if (Cur == Word) Cnt++;
            Cur = "";
        }
        else Cur += Str[i];
    }
    return Cnt;
}

vector<string> Find_Out_Link(string Str)
{
    vector<string> Result;
    string Target = "<A HREF=\"HTTPS://";
    int Idx = Str.find(Target);
    while (Idx != -1)
    {
        Idx += Target.length();
        string Cur = "";
        while (Str[Idx] != '\"') Cur += Str[Idx++];
        Result.push_back(Cur);
        Str = Str.substr(Idx);
        Idx = Str.find(Target);
    }
    return Result;
}

void Calculate_Link_Point()
{
    for (int i = 0; i < Page.size(); i++)
    {
        vector<string> V = Page[i].Out_Link_List;
        int Size = V.size();
        for (int j = 0; j < V.size(); j++)
        {
            string Str = V[j];
            if (Page_Num[Str] == 0) continue;
            int Target_Idx = Page_Num[Str] - 1;
            Page[Target_Idx].Link_Point += ((double)Page[i].Basic_Point / (double)Size);
        }
    }
    for (int i = 0; i < Page.size(); i++)
    {
        Page[i].Match_Point = (double)Page[i].Basic_Point + (double)Page[i].Link_Point;
    }
    sort(Page.begin(), Page.end(), Cmp);
}

void Function(vector<string> V)
{
    for (int i = 0; i < V.size(); i++)
    {
        string Str = To_Upper(V[i]);
        string URL = Find_URL(Str);
        Page_Num[URL] = i + 1;
        int BP = Find_Word(Str);
        vector<string> Out_Link = Find_Out_Link(Str);
        Page.push_back({ i, BP, Out_Link, 0.0, 0.0 });
    }
    Calculate_Link_Point();
}

int solution(string word, vector<string> pages) 
{
    int answer = 0;
    Word = To_Upper(word);
    Function(pages);
    answer = Page[0].Idx;
    return answer;
}

int main()
{
    string word = "Muzi";
    vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apea0muzi0muzi0ch&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};
    cout << solution(word, pages) << endl;
    return 0;
}

// ��ǥ : �˻�� ���� �� �´� ���������� �����ֱ� ���� �Ʒ��� ���� ��Ģ���� �˻�� ���� ���������� ��Ī������ ��� �ϴ� �� (�ְ� ������ ������)
// �䱸���� 
// �������� = �⺻����,�ܺθ�ũ��,��ũ����,��Ī����
// �⺻���� : �������� �ؽ�Ʈ �� �˻�� �����ϴ� Ƚ�� (��ҹ��� ����)
// �ܺθ�ũ�� : ������������ �ٸ� �ܺ� �������� ����� ��ũ�� ���� 
// ��ũ���� : �ش� ���������� ��ũ�� �ɸ� �ٸ� ���������� �⺻���� / �ܺθ�ũ���� ���� 
// ��Ī���� : �⺻���� + ��ũ���� 

// �Ķ���� : word(�˻���) pages(��������)

// ���ѻ��� : 
// pages�� ������ html ������ (1 <= pages.size() <= 20)
// ���ڿ��� 1 <= pages[i].size() <= 1500
// <meta property="og:url" content="https://careers.kakao.com/index" /> �� URL�� https://careers.kakao.com/index �� 
// �ܺ� ��ũ�� <a href="https://careers.kakao.com/index">�� �����̸� URL�� https://careers.kakao.com/index �� 
// ��� url�� https:// �θ� �����Ѵ�
// �ܾ�� ������ ��ġ�ϴ� ��쿡�� �⺻ ������ �ݿ�
// �ܾ�� ���ĺ��� ������ �ٸ� ��� ���ڷ� ����
// ������� �˻�� "aba" �� ��, "abab abababa"�� �ܾ� ������ ��ġ�ϴ°� ������, �⺻ ������ 0��
// ���� �˻�� "aba" ���, "aba@aba aba"�� �ܾ� ������ ������ ��ġ
// ������ ��Ī������ ���� ���������� ���� ����� ���� index ��ȣ�� ���� ���� �͸� ����
// 