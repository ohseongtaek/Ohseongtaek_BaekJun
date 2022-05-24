#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(string expression) {     // 100-200*300-500+20
    long long answer = 0;                   // 100  200  300 500 20
    vector<long long> number;               //  -    *    -   +
    vector<char> real_booho;
    vector<char> facto_booho = { '+' , '-' , '*' };

    string num = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            number.push_back(stoi(num));
            num = "";
            real_booho.push_back(expression[i]);
        }
        else {
            num = num + expression[i];
        }
    }
    number.push_back(stoi(num));
    sort(facto_booho.begin(), facto_booho.end());

    for (int i = 0; i < number.size(); i++) {
        cout << number[i] << endl;
    }

    do {
        vector<long long> temp = number;
        vector<char> booho = real_booho;
        for (int i = 0; i < facto_booho.size(); i++) {

            for (int j = 0; j < booho.size(); j++) {

                if (facto_booho[i] == booho[j]) {

                    if (booho[j] == '*') {
                        temp[j] = temp[j] * temp[j + 1];
                    }
                    else if (booho[j] == '+') {
                        temp[j] = temp[j] + temp[j + 1];
                    }
                    else if (booho[j] == '-') {
                        temp[j] = temp[j] - temp[j + 1];
                    }
                    temp.erase(temp.begin() + j + 1);       // �ڿ� ���� ����
                    booho.erase(booho.begin() + j);         // �� �ڸ� ����������
                    j--;                                    // j�ٿ������ ������ ������ ���������� index�� ���� ���ŵǱ⶧��
                }
            }
        }
        answer = max(answer, abs(temp[0]));
    } while (next_permutation(facto_booho.begin(), facto_booho.end()));

    return answer;
}