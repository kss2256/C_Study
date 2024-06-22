#include <string>
#include <vector>
#include <stack>

using namespace std;



vector<int> solution(vector<int> numbers) 
{
   

    vector<int> answer(numbers.size(), -1);
    stack<int> stack;
    

	for (int i = numbers.size() - 1; i >= 0; --i)
	{
        while (!stack.empty() && numbers[i] >= numbers[stack.top()])
        {
            stack.pop();
        }

        if(!stack.empty())
            answer[i] = numbers[stack.top()];


        stack.push(i);
	}

   

    return answer;
}


int main()
{
    //[2, 3, 3, 5] = [3, 5, 5, -1]
    //[9, 1, 5, 3, 6, 2] = [-1, 5, 6, 6, -1, -1]

    vector<int> result = solution({ 2, 3, 3, 5 });



    return 0;
}