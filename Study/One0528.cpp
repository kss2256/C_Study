#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int left, int right)
{
    return left > right;
}

int solution(vector<int> citations)
{
    //3, 0, 6, 1, 5

    //���� ���� ���� 

    //6,5,3,1,0  
    sort(citations.begin(), citations.end(), Compare);


    int hidx = 0;

    //6���� h�� �̻� �ο�� ���� h�� �̻��̰� �������� h�� ���� �ο� ���.

    //  ����� �� ���� {3, 0, 6, 1, 5} 
    //  �� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�.
    //  �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

    // 0�� 1�� �ƴϴ�? 
    //6,5,3,1,0  �ο� ��� ����� 1 2 3 4 5 �� 
    //
    for (int i = 0; i < citations.size(); ++i) 
    {
        if (citations[i] >= i + 1) 
        {
            hidx = i + 1;
        }
        else 
            break;
    }

    return hidx;
}


int main()
{

    int result = solution({ 3, 0, 6, 1, 5 });



    return 0;
}