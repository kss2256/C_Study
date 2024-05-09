#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


/*
���� ����
0�� 1�� �̷���� � ���ڿ� x�� ���� ���� ��ȯ�� ������ ���� �����մϴ�.

x�� ��� 0�� �����մϴ�.
x�� ���̸� c��� �ϸ�, x�� "c�� 2�������� ǥ���� ���ڿ�"�� �ٲߴϴ�.
���� ���, x = "0111010"�̶��, x�� ���� ��ȯ�� ���ϸ� x = "0111010" -> "1111" -> "100" �� �˴ϴ�.

0�� 1�� �̷���� ���ڿ� s�� �Ű������� �־����ϴ�. 
s�� "1"�� �� ������ ����ؼ� s�� ���� ��ȯ�� ������ ��, 
���� ��ȯ�� Ƚ���� ��ȯ �������� ���ŵ� ��� 0�� ������ ���� �迭�� ��� 
return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
s�� ���̴� 1 �̻� 150,000 �����Դϴ�.
s���� '1'�� �ּ� �ϳ� �̻� ���ԵǾ� �ֽ��ϴ�.

����� ��
s	                result
"110010101001"	    [3,8]
"01110"	            [3,3]
"1111111"	        [4,1]

*/

//

vector<int> solution(string s) 
{
    vector<int> answer;
    int zero = 0, one = 0, Cheak = 0; //Cheak�� �ݺ� Ƚ���� ������ ����, zero�� �ݺ��ϸ鼭 ���� �� 0�� ����
    vector<int> result;               //result�� 2�� ��ȯ ���� ��� ������Ʈ              
   
    
    while (result.size() != 1)
    {
        result.clear();
        ++Cheak;
        //1ȸ��
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
                ++one;
            else
                ++zero;
        }

        //1�� ������ ���ؼ� �� ���� 2����ȯ �ؼ� result�� ������Ʈ
        while (one > 1)
        {
            result.push_back(one % 2);
            one /= 2;
        }
        result.push_back(one);  //�������� 0 Ȥ�� 1�� �ǰ� �� ���� �־��ְ�

        reverse(result.begin(), result.end());  //�Ųٷ� ������ �ٲ��ش�.
        one = 0;
        s.clear();                              //s ����ְ� ������ ���� ������
        for (int j = 0; j < result.size(); j++)
        {
            s += to_string(result[j]);
        }
        
    }

	answer = { Cheak , zero };


    return answer;
}


int main()
{

    vector<int> result = solution("110010101001");
    //vector<int> result = solution("0111010");




    return 0;
}