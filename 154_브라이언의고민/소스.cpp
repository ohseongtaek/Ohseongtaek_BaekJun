#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
������ ���ǿ� ����, ���ԵǴ� ��ȣ�� �� 26����(���ĺ� �ҹ����� ��)�̸� ������ �� ������ ����� �� �ֽ��ϴ�. 
��, �� ���ĺ��� ������ ��ġ�� ���� � �ܾ � ��Ģ���� ����Ǿ����� �� �� �ֽ��ϴ�.

��ȣ�� ������ 1�� Ȥ�� 3�� �̻��� ���, �� ��ȣ�� ��Ģ 1�� ���� �߰��� ��ȣ���� �� �� �ֽ��ϴ�. 
��ȣ�� ������ 2���̸鼭 ���̿� �� ����(�빮��)�� ���� 2�� �̻��� ���, �� ��ȣ�� ��Ģ 2�� ���� �߰��� ��ȣ���� �� �� �ֽ��ϴ�. 

��ȣ�� ������ 2���̸鼭 ���̿� �� ������ ���� 1���� ���� ��Ģ 1 Ȥ�� ��Ģ 2�� ��� ����� �� �ִµ�, 
�� ��쿡�� ������ ������ ���ܸ� �����ϰ�� ��Ģ 2�� ����� ��ȣ�� ������ �� �ֽ��ϴ�. 
a A b B b C a ��, �ٸ� ��ȣ�� ���� �ȿ� �ִ� ����Դϴ�.

��, �� ��ȣ ���� ������ ����, 
��ȣ�� ������ 2���� �ƴ� ��� ��Ģ 1, 
2���� ��� ��Ģ 2(������ ������ ��� ����)�� ����� ��ȣ�� �����ϰ� 
�׿� �°� ��Ģ�� �ùٸ��� ����Ǿ������� �Ǵ��ϸ� �˴ϴ�.
*/

string solution(string sentence) {
    string answer = "";
    const string invalid = "invalid";
    vector<string> words;
    vector<bool> checked(26);
    bool first_rule = false;
    bool second_rule = false;
    char char_rule1 = NULL;
    char char_rule2 = NULL;
    string word = "";

    for (int i = 0; i < sentence.length(); ++i) {
        // ��Ģ 1+2�� ��� 
        if (first_rule && second_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];
                // ������ �ҹ��ڷ� ���� ������ 
                if (i + 1 == sentence.length())
                    return invalid;
                // �빮�ڰ� ���޾� ���ü��� ���� 
                else if (isupper(sentence[i + 1]))
                    return invalid;
                // ��Ģ 2�� Ư�����ڷ� �������� 
                else if (char_rule1 != sentence[i + 1] && char_rule2 != sentence[i + 1])
                    return invalid;
            }
            // ���� ���ڰ� �ҹ����ΰ�� 
            if (islower(sentence[i])) {
                // ���� ���ڰ� ��Ģ2�� Ư�������ΰ�� 
                if (char_rule2 == sentence[i]) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;

                    second_rule = false;
                    checked[char_rule2 - 'a'] = true;
                    char_rule2 = NULL;

                    words.push_back(word);
                    word = "";

                    continue;
                }
                // ������ �Ѿ�ų� �ٸ� �ܾ ���� �����ΰ�� 
                if (i + 1 == sentence.length())
                    return "invalid";
                else if (islower(sentence[i + 1]))
                    return "invalid";
            }
        }
        // ��Ģ 1�� ��� 
        else if (first_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];
                // �ܾ ������� 
                if (i + 1 == sentence.length()) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
                // �ܾ ������ ���� ���ڰ� �빮���ΰ�� 
                else if (isupper(sentence[i + 1])) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
                // �ܾ ������ �������ڰ� �ҹ����ε� ���� ����ϴ� Ư������ ��Ģ�� �ƴѰ�� 
                else if (char_rule1 != sentence[i + 1]) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
            }
            // ��Ģ�� ��߳���� 
            if (islower(sentence[i])) {
                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]))
                    return invalid;
            }
        }
        // ��Ģ2�� ��� 
        else if (second_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];
                // �ش� �ҹ��ڷ� ������ �ϱ� ������ ����ó�� 
                if (i + 1 == sentence.length())
                    return invalid;
                // ���� ���ڰ� �ҹ����̸�, ��Ģ 2�� Ư�����ڰ� �ƴ� ���ο� Ư�������ΰ�� (��Ģ 1+2 �� ���)
                else if (islower(sentence[i + 1]) && char_rule2 != sentence[i + 1]) {
                    if (char_rule2 == sentence[i - 1]) {
                        if (checked[sentence[i + 1] - 'a'])
                            return invalid;
                        first_rule = true;
                        char_rule1 = sentence[i + 1];
                    }
                    else
                        return invalid;
                }
            }
            // ���� ���ڰ� �ҹ����ΰ�� ����Ǵ� ��ƾ���� ���� �߰� 
            if (islower(sentence[i])) {
                second_rule = false;
                checked[char_rule2 - 'a'] = true;
                char_rule2 = NULL;
                words.push_back(word);
                word = "";
            }
        }
        // ���ο� �ܾ��� ������ ��� 
        else {
            if (isupper(sentence[i])) {
                word += sentence[i];
                first_rule = true;

                // ������ ������ ��� 
                if (i + 1 == sentence.length()) {
                    first_rule = false;
                    words.push_back(word);
                    word = "";
                }

                // ��Ģ1�� ���� ���� ���ο� ���ڰ� �ٽ� ��Ģ 1�� ��� 
                else if (isupper(sentence[i + 1])) {
                    first_rule = false;
                    words.push_back(word);
                    word = "";
                }

                // �������ڰ� �ҹ��ڶ�� ��Ģ�� �ǰ� ��� ���ԵǴ��� Ȯ���ϴ� ���� 
                else if (islower(sentence[i + 1])) {
                    
                    // �̹� ���� �ҹ������� Ȯ���ϱ� 
                    if (checked[sentence[i + 1] - 'a'])
                        return invalid;

                    char_rule1 = sentence[i + 1];

                    // �ҹ��ڰ� ��� ���Դ��� Ȯ���ϴ� ���� 
                    vector<int> pos;
                    for (int j = i + 1; j < sentence.length(); ++j)
                        if (sentence[j] == char_rule1)
                            pos.push_back(j);

                    // ��Ģ 2�ΰ�� aAAAa 1���� ���� ������ ���� 
                    if (pos.size() == 1)
                        continue;
                    // ��Ģ 1�ΰ�� 3�� �̻� 
                    else if (pos.size() >= 3) {
                        bool flag = true;
                        for (int j = 1; j < pos.size(); ++j) {
                            // �ε��� ���̸� ��Ÿ���� ���ǹ�
                            if (pos[i + 1] - pos[i] != 2) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            continue;
                    }
                    // ��Ģ 2 OR ��Ģ1+2 �� ��� 
                    else {
                        first_rule = false;
                        char_rule1 = NULL;
                        words.push_back(word);
                        word = "";
                    }
                }
            }
            if (islower(sentence[i])) {
                if (checked[sentence[i] - 'a'])
                    return invalid;
                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]))
                    return invalid;
                second_rule = true;
                char_rule2 = sentence[i];
            }
        }
    }

    for (int i = 0; i < words.size(); ++i)
    {
        answer += (words[i] + " ");
        //cout << answer << endl;
    }
        
    answer.pop_back();
    return answer;
}

int main()
{
    vector<string> sen = { "HaEaLaLaO bWORLDb" ,"SpIpGpOpNpG JqOqA" ,"AxAxAxA oBoBoB" };

    /*
    "HELLO WORLD"
    "SIGONG JOA"
    "invalid"
    */
    string dab = solution(sen[1]);
    cout << dab << endl;
       	
}