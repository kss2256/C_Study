#include <string>
#include <vector>

using namespace std;

/*
���� ����
XX���ӿ��� �Ƿε� �ý���(0 �̻��� ������ ǥ���մϴ�)�� ������, ���� �Ƿε��� ����ؼ� ������ Ž���� �� �ֽ��ϴ�. 
�̶�, �� �������� Ž���� �����ϱ� ���� �ʿ��� "�ּ� �ʿ� �Ƿε�"�� ���� Ž���� ������ �� �Ҹ�Ǵ� 
"�Ҹ� �Ƿε�"�� �ֽ��ϴ�. "�ּ� �ʿ� �Ƿε�"�� �ش� ������ Ž���ϱ� ���� ������ �־�� �ϴ� 
�ּ����� �Ƿε��� ��Ÿ����, "�Ҹ� �Ƿε�"�� ������ Ž���� �� �Ҹ�Ǵ� �Ƿε��� ��Ÿ���ϴ�. 
���� ��� "�ּ� �ʿ� �Ƿε�"�� 80, "�Ҹ� �Ƿε�"�� 20�� ������ Ž���ϱ� ���ؼ��� ������ ���� 
���� �Ƿε��� 80 �̻� �̾�� �ϸ�, ������ Ž���� �Ŀ��� �Ƿε� 20�� �Ҹ�˴ϴ�.

�� ���ӿ��� �Ϸ翡 �� ���� Ž���� �� �ִ� ������ ������ �ִµ�, 
�� ������ ���� �� �������� �ִ��� ���� Ž���Ϸ� �մϴ�. ������ ���� �Ƿε� k�� 
�� ������ "�ּ� �ʿ� �Ƿε�", "�Ҹ� �Ƿε�"�� ��� 2���� �迭 dungeons �� �Ű������� �־��� ��, 
������ Ž���Ҽ� �ִ� �ִ� ���� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
k�� 1 �̻� 5,000 ������ �ڿ����Դϴ�.
dungeons�� ����(��) ����(��, ������ ����)�� 1 �̻� 8 �����Դϴ�.
dungeons�� ����(��) ���̴� 2 �Դϴ�.
dungeons�� �� ���� �� ������ ["�ּ� �ʿ� �Ƿε�", "�Ҹ� �Ƿε�"] �Դϴ�.
"�ּ� �ʿ� �Ƿε�"�� �׻� "�Ҹ� �Ƿε�"���� ũ�ų� �����ϴ�.
"�ּ� �ʿ� �Ƿε�"�� "�Ҹ� �Ƿε�"�� 1 �̻� 1,000 ������ �ڿ����Դϴ�.
���� �ٸ� ������ ["�ּ� �ʿ� �Ƿε�", "�Ҹ� �Ƿε�"]�� ���� ���� �� �ֽ��ϴ�.
����� ��
k	dungeons	result
80	[[80,20],[50,40],[30,10]]	3
*/



int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = -1;
    vector<int> result;
    result.resize(dungeons.size());
    int idx = 0, iter = 0, hub = 0;
    int curcount = 0, prevcount= 0;
    int fatigue = 0;


    for (int i = 0; i < dungeons.size(); ++i)
    {
        for (int j = 0; j < dungeons.size() - 1; ++j)
        {
            fatigue = k;
            iter = 0;
            curcount = 0;
            hub = 0;
            do
            {
                idx = i + iter + hub;

                if (iter != 0 && iter == i)
                    ++idx;

                if (idx != 0)
                    idx = idx % dungeons.size();

                if (dungeons[idx][0] <= fatigue)
                {
                    fatigue -= dungeons[idx][1];
                    ++curcount;
                }
                if (j >= 1)
                    hub = 1;

                ++iter;
            } while (iter <= dungeons.size());

            if (curcount > prevcount)
                prevcount = curcount;
        }
        
    }

    answer = prevcount;

    return answer;
}



int main()
{

    int result = solution(80,
        {
        {80, 20},
        {50, 40},
        {30, 10} 
        });




    return 0;
}