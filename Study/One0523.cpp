#include <string>
#include <vector>

using namespace std;



/*
���� ����
� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
number�� 2�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
����� ��

number	        k	return
"1924"	        2	"94"            4 - 2   = 2     3
"1231234"	    3	"3234"          7 - 3   = 4     4
"1231234"	    2	"32341"         7 - 2   = 5     3
"4177252841"	4	"775841"       10 - 4   = 6     5
*/

string solution(string number, int k)
{
    string answer = "";
    vector<int> result;
    //diff = �ڸ���
    int diff = number.length() - k;
    //2���� �迭 
    int diff2 = number.length() - (k - 1);

    for (int i = 0; i < number.length(); ++i)
    {
        result.push_back(number[i] - '0');
    }

    //�ڸ��� ��ŭ �ݺ��� ����
    for (int i = 0; i <= number.length() - diff; ++i)
    {
      for(int j = 0 ; j < )



    }




    return answer;
}



int main()
{

    string result = solution("1924", 2);


    return 0;
}