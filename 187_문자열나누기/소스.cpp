#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) 
{
	int answer = 0;
	
	bool start = true;
	int firstCnt = 0;
	int secondCnt = 0;
	string slice_str = "";
	vector<string> vec_slice;

	for (int i = 0; i < s.size(); i++)
	{
		// ���ο� ���ڿ� �����Ҷ� 
		if (start == true)
		{
			slice_str += s[i];
			firstCnt++;
			start = false;
		}
		else
		{
			// ù��° �ε����� ������� 
			if (slice_str[0] == s[i])
			{
				slice_str += s[i];
				firstCnt++;
			}
			// ù��° �ε����� �ٸ���� 
			else
			{
				slice_str += s[i];
				secondCnt++;
			}

			if (firstCnt == secondCnt)
			{
				vec_slice.push_back(slice_str);
				slice_str = "";
				firstCnt = 0;
				secondCnt = 0;
				start = true;
			}
		}

		// ������ �����ΰ�� 
		if (i == s.size() - 1)
		{
			if (slice_str != "")
			{
				vec_slice.push_back(slice_str);
			}
		}

	}

	answer = vec_slice.size();
	
	return answer;
}

int main()
{
	vector<string> test = { "baaa","banana","abracadabra","aaabbaccccabba","a"};

	for (int i = 0; i < test.size(); i++)
	{
		int dab = solution(test[i]);
		printf("answer = %d\n", dab);
	}
	
	return 0;
}

