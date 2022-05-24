#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;

    if (clothes.size() != 0) {
        answer++;                                           // ���� ���� 1���� �ִٸ� answer++���ش� ���߿� ���� ���� 
    }
  
    for (int i = 0; i < clothes.size(); i++) {
        m[clothes[i][1]]++;                                 // map�� Ű�� ������ ++
    }
    
    map<string, int>::iterator iter;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer = answer * (iter->second + 1);               // ����
    }
    answer--;                                               // ���� ���� �ʴ°�� ������ 

    return answer;
}


int main() {
    vector<vector<string>> clo = { {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    int dab;
    dab = solution(clo);
    cout << dab << endl;
}