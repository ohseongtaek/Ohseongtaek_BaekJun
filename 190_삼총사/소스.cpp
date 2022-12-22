#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) 
{
	int answer = 0;

	for (int i = 0; i < number.size() - 2; i++)
	{
		for (int j = i+1; j < number.size() - 1; j++)
		{
			for (int k = j+1; k < number.size(); k++)
			{
				if (number[i] + number[j] + number[k] == 0)
				{
					answer++;
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> v = { {-2, 3, 0, 2, -5}, {-3, -2, -1, 0, 1, 2, 3}, {-1, 1, -1, 1} };
	for (int i = 0; i < v.size(); i++)
	{
		cout << solution(v[i]) << endl;
	}
}