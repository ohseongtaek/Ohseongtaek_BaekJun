#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> numbers) 
{
    sort(numbers.begin(), numbers.end()); // �������� ����
    int n = numbers.size();
    int max_product = numbers[n - 1] * numbers[n - 2]; // ���� ū �� ���� ��
    int min_product = numbers[0] * numbers[1]; // ���� ���� �� ���� ��
    return max(max_product, min_product);
}

int main()
{
    solution({ 1, 2, -3, 4, -5 });
}