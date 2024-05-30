#include <iostream>
#include<string>
#include <stack>

using namespace std;



//int solution(string s)
//{
//    int answer = 0;
//    queue<char> q;
//
//
//    for (char i = 0; i < s.size();)
//    {
//        if (s[i] == s[i + 1])
//        {
//            s.erase(i, 2);
//            i = 0;
//        }
//        else
//            ++i;
//
//        if (s.empty())
//            return 1;
//    }
//    
//    
//    return answer;
//}


int solution(string s)
{
   
    stack<char> stack;
    
   

    for (int i = 0; i < s.size(); ++i)
    {
        if (!stack.empty() && stack.top() == s[i])
        {
            stack.pop();
        }
        else
        {
            stack.push(s[i]);
        }


    }



    return stack.empty();
}



int main()
{

    int result = solution("baabaa");


    return 0;
}