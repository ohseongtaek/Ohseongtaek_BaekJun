#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = 0;
    int temp_incre = 1;
    int sum = 0;

    while (temp_incre < n) {
        temp = temp_incre;          // ó�� �����ϴ� �� ���ϴ°� 
        sum = temp;
        while (1) {
            
            if (temp >= n) {
                
                if (temp == n) {
                    answer++;
                    break;
                }
                else {
                    break;
                }
            }
            sum++;                 //  2   
            temp = temp + sum;        // �����ϴ� ������ �ϳ��� ���Ѵ� 
        }
        temp_incre++;
        if (temp_incre == n) {
            //cout << "good" << endl;
            answer++;
        }

    }
    return answer;
}

int main() {
    int n = 10;

    cout << solution(n);



}