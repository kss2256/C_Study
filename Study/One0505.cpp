#include<string>
#include <iostream>
#include <stack>

using namespace std;

/*
��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' 
���ڷ� ������ �Ѵٴ� ���Դϴ�. ���� ���
"()()" �Ǵ� "(())()" �� �ùٸ� ��ȣ�Դϴ�.
")()(" �Ǵ� "(()(" �� �ùٸ��� ���� ��ȣ�Դϴ�.
'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��,
���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, 
�ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

"()()"	true
"(())()"	true
")()("	false
"(()("	false
 
*/



bool solution(string s)
{
    bool answer = true;
    

    std::stack<char> stack;

    for (char i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!stack.empty() && stack.top() == '(')
                stack.pop();
            else
                return false;

        }
    }


    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return stack.empty();
}


int main()
{

    bool test = solution("()()");
    //bool test = solution(")()(");



    return 0;
}