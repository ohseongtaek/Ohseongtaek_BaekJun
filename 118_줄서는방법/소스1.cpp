#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <queue>
using namespace std;


long long factorial(int a) {

    if (a == 1) {
        return 1;
    }
    else {
        return a * factorial(a - 1);
    }
}


vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> temp_arr;
    long long first_number_slice, now_idx;


    for (int i = 1; i <= n; i++) {
        temp_arr.push_back(i);
    }

    while (1) {
        if (n == 0) {
            break;
        }
        // �ش� �ڵ�� �� ���ڸ� ���ڿ� ���� ���ü��ִ� ����� ���� ��� ���� 4�� �϶� �� 6���� �̰� ��Ÿ�� �ڵ�
        first_number_slice = factorial(n) / n;

        // ���� �ε��� ���� ��Ÿ���� �ڵ�
        // k-1 �� n=4 k=6 �� ��쿡 k ���� ����������� ������ -1 �� ���ش�.
        now_idx = int((k - 1) / first_number_slice);

        // ���� �ε��� ���� answer ���Ϳ� Ǫ��
        answer.push_back(temp_arr[now_idx]);

        // ����� �ε����� �����Ѵ� �ٽô� ���� ���� �� �̱� ������
        temp_arr.erase(temp_arr.begin() + now_idx);

        // �迭�� �پ����Ƿ� �ٽ� �ڸ��� ����Ǽ��� ã�ƾ��Ѵ� ���� n--
        n--;

        // �ڸ��� ���� �����ɶ����� k ��° ���� ������ ����ȴ�
        // ex : 4 5 ���� ó�� 1�� �����Ǹ� 6������ �̱���� ������ �ι�°���ڰ� �����Ǹ� 2���� ����� ���ۿ� ���� �̶� k =5 �̸� ������ ����Ƿ� ���� ������ ������.
        k %= first_number_slice;

        // ������ �迭�� �ֱ� ���ؼ� �ִ� ����ó�� !!!(�������� ���Ѱ� 30�� �ҿ�)!!!
        if (k == 0) {
            k = first_number_slice;
        }
    }
    return answer;
}

int main() {
    int n = 4;
    int k = 5;
    vector<int> a = solution(n, k);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
    return 0;
}