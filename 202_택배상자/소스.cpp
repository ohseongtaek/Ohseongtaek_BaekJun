#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) 
{
	int answer = 0;
	int index = 0;
	vector<int> save1;
	save1.push_back(10000001);

	for (int i = 1; i < order.size() + 1; i++) 
	{
		if (order[index] == i) 
		{
			index += 1;
		}
		else if (order[index] == save1.back()) 
		{
			save1.pop_back();
			index += 1;
			i -= 1;
		}
		else 
		{
			save1.push_back(i);
		}
	}

	while (save1.size() != 1) 
	{
		if (save1.back() == order[index]) 
		{
			index += 1;
			save1.pop_back();
		}
		else 
		{
			break;
		}
	}
	return index;
}

/* 시간초과 코드 
int solution(vector<int> order) 
{
	int answer = 0;
	bool flag = false;
	stack<int> belt;
	stack<int> belt_sub;

	for (int i = order.size(); i > 0; i--)
	{
		belt.push(i);
	}

	while (flag == false)
	{
		
		int want = order[0];
		int BeltNum = 0;
		int BeltSubNum = 0;
		
		if (!belt.empty())
		{
			BeltNum = belt.top();
		}

		if (!belt_sub.empty())
		{
			BeltSubNum = belt_sub.top();
		}

		if (want == BeltNum)
		{
			belt.pop();
			answer++;
			order.erase(order.begin());
		}
		else if (want == BeltSubNum)
		{
			belt_sub.pop();
			answer++;
			order.erase(order.begin());
		}
		else
		{
			if (want < BeltNum)
			{
				flag = true;
			}
			else
			{
				belt_sub.push(BeltNum);
				belt.pop();
			}
		}

		if (order.size() == 0 || (true == belt.empty() && true == belt_sub.empty()))
		{
			flag = true;
		}
	}
	return answer;
}
*/
int main()
{
	vector<vector<int>> number = { {4, 3, 1, 2, 5}	, {5, 4, 3, 2, 1} , {2, 1, 4, 3, 6, 5, 8, 7, 10, 9}, {1,2,3,4,5} };
	vector<int> result = { 2, 5, 10, 5 };

	for (int i = 0; i < result.size(); i++)
	{
		int k = solution(number[i]);
		if (k == result[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error = " << k << ", wnat = " << result[i] << endl;
		}
	}
}

/*
영재는 택배상자를 트럭에 싣는 일을 합니다. 
영재가 실어야 하는 택배상자는 크기가 모두 같으며 
1번 상자부터 n번 상자까지 번호가 증가하는 순서대로 컨테이너 벨트에 일렬로 놓여 영재에게 전달됩니다.

컨테이너 벨트는 한 방향으로만 진행이 가능해서 벨트에 놓인 순서대로(1번 상자부터) 상자를 내릴 수 있습니다. 

하지만 컨테이너 벨트에 놓인 순서대로 택배상자를 내려 바로 트럭에 싣게 되면 택배 기사님이 배달하는 순서와 택배상자가 실려 있는 순서가 맞지 않아 배달에 차질이 생깁니다. 
따라서 택배 기사님이 미리 알려준 순서에 맞게 영재가 택배상자를 실어야 합니다.

만약 컨테이너 벨트의 맨 앞에 놓인 상자가 현재 트럭에 실어야 하는 순서가 아니라면 
그 상자를 트럭에 실을 순서가 될 때까지 잠시 다른 곳에 보관해야 합니다. 
하지만 고객의 물건을 함부로 땅에 둘 수 없어 보조 컨테이너 벨트를 추가로 설치하였습니다. 
보조 컨테이너 벨트는 앞 뒤로 이동이 가능하지만 입구 외에 다른 면이 막혀 있어서 맨 앞의 상자만 뺄 수 있습니다
(즉, 가장 마지막에 보조 컨테이너 벨트에 보관한 상자부터 꺼내게 됩니다).
보조 컨테이너 벨트를 이용해도 기사님이 원하는 순서대로 상자를 싣지 못 한다면, 
더 이상 상자를 싣지 않습니다.

예를 들어, 영재가 5개의 상자를 실어야 하며, 
택배 기사님이 알려준 순서가 기존의 컨테이너 벨트에 네 번째, 세 번째, 첫 번째, 두 번째, 다섯 번째 놓인 택배상자 순서인 경우, 
영재는 우선 첫 번째, 두 번째, 세 번째 상자를 보조 컨테이너 벨트에 보관합니다. 
그 후 네 번째 상자를 트럭에 싣고 보조 컨테이너 벨트에서 세 번째 상자 빼서 트럭에싣습니다. 
다음으로 첫 번째 상자를 실어야 하지만 보조 컨테이너 벨트에서는 두 번째 상자를, 기존의 컨테이너 벨트에는 다섯 번째 상자를 꺼낼 수 있기 때문에 더이상의 상자는 실을 수 없습니다. 
따라서 트럭에는 2개의 상자만 실리게 됩니다.

모든 상자를 보조 컨테이너 벨트에 모두 넣고, 역순으로 하나씩 빼서 트럭에 싣습니다.
*/