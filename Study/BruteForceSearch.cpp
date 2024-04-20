#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    1. ������ �� ������ �˰��ִ�.
    2. ���ΰ� ���κ��� ũ�ų� �ּ��� ���ƾ� �Ѵ�.

    ���� ó��
    ���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
    ����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
    ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.


*/


//1Ʈ ���� ���� �������� �𸣰ڴ�
//vector<int> solution(int brown, int yellow) 
//{
//    //���� ó�� (���μ��� ���ܴ� �ؿ��� �ٲ���)
//    if(brown < 8 || brown > 5000 || yellow < 1 || yellow > 2000000)
//      {
//          cout << "���� ���� ����" << endl;
//      }
// 
//    vector<int> answer;
//    int Sum = brown + yellow;
//
//    //������� ¦���� ���
//    if (yellow % 2 == 0)
//    {
//        int half = yellow / 2;
//        int result = Sum % (half + 2);
//        while (result != 0)
//        {
//            half = half / 2;
//            result = Sum % (half + 2);
//        }
//
//        result = Sum / (half + 2);
//        if (result > half + 2)
//        {
//            answer.push_back(result);
//            answer.push_back(half + 2);
//        }
//        else
//        {
//            answer.push_back(half + 2);
//            answer.push_back(result);
//        }
//    }
//    //������� Ȧ���� ���
//    else
//    {
//        answer.push_back(yellow + 2);
//        answer.push_back(3);
//    }
//
//    return answer;
//}

/*
    1. �� ������ �� = �� ���� ������ �˼� �ִ�.
    2. �ݺ����� ���鼭 �ϳ��� üũ�� �غ���
    3. ���� ���� ������?
    4. ����� �� �������� �ؼ� ������� �����̴� �ϳ��� üũ�ϸ鼭
    ���η� +2 ���η� +2 ���ָ� �Ǵµ� ���⿡ �� �� ������ �˼� �����ϱ�
    5. ���� >= ������ ���� ���;� �ϰ� 
	6. ���γ� ���γ� ���� 3�� �̻��� �Ǿ�� �ϴ� 3���� ���� �ݺ��� ������ �ɵ�    

*/


//2Ʈ
vector<int> solution(int brown, int yellow)
{
	vector<int> result;

	//���� ó�� (���μ��� ���ܴ� �ؿ��� �ٲ���)
	if (brown < 8 || brown > 5000 || yellow < 1 || yellow > 2000000)
	{
		cout << "���� ���� ����" << endl;
	}

	//�ּ� �������� 3���Ͷ� 3���� ����
	int blockTotal = brown + yellow;
	int col = 3;
	int row = 0;

	while (true)
	{
		//������ ���μ��� ���� ���ؼ� ����� ���� ���߸� �ȴ�
		row = blockTotal / col;

		if ((col - 2) * (row - 2) == yellow)
		{
			//���� ���� ���� ó�� ū���� ���η�
			if (col > row)
			{
				result.push_back(col);
				result.push_back(row);
			}
			else
			{
				result.push_back(row);
				result.push_back(col);
			}
			break;
		}

		++col;
	}

	return result;
}



int main() 
{
    
    vector<int> result = solution(10, 2);
    
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }

    return 0;
}