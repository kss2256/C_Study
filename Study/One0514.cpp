#include <vector>
#include <string>
#include <sstream>

using namespace std;


/*
���� ����
JadenCase�� ��� �ܾ��� ù ���ڰ� �빮���̰�, �� ���� ���ĺ��� �ҹ����� ���ڿ��Դϴ�. 
��, ù ���ڰ� ���ĺ��� �ƴ� ������ �̾����� ���ĺ��� �ҹ��ڷ� ���� �˴ϴ�. (ù ��° ����� �� ����)
���ڿ� s�� �־����� ��, s�� JadenCase�� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
s�� ���� 1 �̻� 200 ������ ���ڿ��Դϴ�.
s�� ���ĺ��� ����, ���鹮��(" ")�� �̷���� �ֽ��ϴ�.
���ڴ� �ܾ��� ù ���ڷθ� ���ɴϴ�.
���ڷθ� �̷���� �ܾ�� �����ϴ�.
���鹮�ڰ� �����ؼ� ���� �� �ֽ��ϴ�.

����� ��

        s	                            return
"3people unFollowed me"	        "3people Unfollowed Me"
"for the last week"	            "For The Last Week"

*/


//�빮�ڷ� ��ȯ 
int mytoupper(int s)
{
    //�ҹ��� �����ְ� �빮�� �����ֱ�
    if ((s >= 'a') && (s <= 'z'))
    {
        s = s - 'a' + 'A';
    }

    return s;
}

//�ҹ��ڷ� ��ȯ
int mytolower(int s)
{
    //�빮�� �����ְ� �ҹ��� �����ֱ�
    if ((s >= 'A') && (s <= 'Z'))
    {
        s = s - 'A' + 'a';
    }

    return s;

}


string solution(string s)
{
    string answer = "";

    bool cheak = false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (i == 0)
        {
            s[i] = mytoupper(s[i]);
		}
        else
		s[i] = mytolower(s[i]);

		if (cheak)
		{
			s[i] = mytoupper(s[i]);
			cheak = false;
		}

        if (s[i] == ' ')
        {
            cheak = true;
        }
    }
   
    return s;
}


int main()
{
    string result = solution("3people unFollowed me");
  


	return 0;
}