#include <string>
#include <vector>
#include <algorithm>

using namespace std;



/*
���� ����
��ȭ�� ���������� ���� ��Ȯ�߽��ϴ�. ��ȭ�� ��Ȯ�� �� �� 'k'���� ��� ���� �ϳ��� ��� �Ǹ��Ϸ��� �մϴ�. 
�׷��� ��Ȯ�� ���� ũ�Ⱑ �������� �ʾ� ���⿡ ���� �ʴٰ� ������ ��ȭ�� ���� ũ�⺰�� �з����� �� 
���� �ٸ� ������ ���� �ּ�ȭ�ϰ� �ͽ��ϴ�.

���� ���, ��ȭ�� ��Ȯ�� �� 8���� ũ�Ⱑ [1, 3, 2, 5, 4, 5, 2, 3] �̶�� �սô�. 
��ȭ�� �� 6���� �Ǹ��ϰ� �ʹٸ�, ũ�Ⱑ 1, 4�� ���� ������ ���� ���� ���� ���ڿ� ������, 
���� ũ���� ������ 2, 3, 5�� �� 3������ �Ǹ� �̶��� ���� �ٸ� ������ �ּ��� ���Դϴ�.

��ȭ�� �� ���ڿ� �������� ���� ���� k�� ���� ũ�⸦ ���� �迭 tangerine�� �Ű������� �־����ϴ�. 
��ȭ�� �� k���� �� �� ũ�Ⱑ ���� �ٸ� ������ ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
1 �� k �� tangerine�� ���� �� 100,000
1 �� tangerine�� ���� �� 10,000,000

����� ��
k			tangerine					result
6	[1, 3, 2, 5, 4, 5, 2, 3]				3
4	[1, 3, 2, 5, 4, 5, 2, 3]				2
2	[1, 1, 1, 1, 2, 2, 2, 3]				1

*/

bool Compare(int a, int b)
{
    return a > b;
}


int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    int count = 1;
    vector<int> result;
    //[1, 3, 2, 5, 4, 5, 2, 3] �Էµ� ��



    //5,5,4,3,3,2,2,1 ���� �������� ����
    sort(tangerine.begin(), tangerine.end(), Compare);


    //2,1,2,2,1 �ߺ��� �� ���� üũ �ϱ�
    for (int i = 1; i < tangerine.size(); ++i)
    {
        if (tangerine[i] == tangerine[i - 1])
        {
            ++count;
        }
        else
        {
            result.push_back(count);
            count = 1;
        }
    }
    result.push_back(count);



    //2,1,2,2,1 
    //2,2,2,1,1 ������������ ����
    sort(result.begin(), result.end(), Compare);


    //k��ŭ �� ���ְ� ���� �������� Ȯ��
    for (int i = 0; i < result.size(); i++)
    {
        k -= result[i];
        ++answer;

        if (k <= 0)
        {
            break;
        }
    }


    return answer;
}


int main()
{

    int result = solution(6, { 1,3,2,5,4,5,2,3 });




    return 0;
}