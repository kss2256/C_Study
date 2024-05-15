#include <string>
#include <vector>

using namespace std;

/*
���� ����
���� ��ų�̶� � ��ų�� ���� ���� ���� ����� �ϴ� ��ų�� ���մϴ�.

���� ��� ���� ��ų ������ ����ũ �� ����Ʈ�� ��Ʈ �� ����϶�, 
����� ������ ���� ����Ʈ�� ��Ʈ�� ����� �ϰ�, ����Ʈ�� ��Ʈ�� ������ ���� ����ũ�� ����� �մϴ�.

�� ������ ���� �ٸ� ��ų(���� ��)�� ������ ������� ��� �� �ֽ��ϴ�. 
���� ����ũ �� ���� �� ����Ʈ�� ��Ʈ �� ����� ���� ��ųƮ���� ����������, 
��� �� ����ũ�� ����Ʈ�� ��Ʈ �� ����ũ �� ���� �� ����� ���� ��ųƮ���� �Ұ����մϴ�.

���� ��ų ���� skill�� �������� ���� ��ųƮ��1�� ���� �迭 skill_trees�� �Ű������� �־��� ��, 
������ ��ųƮ�� ������ return �ϴ� solution �Լ��� �ۼ����ּ���.

���� ����
��ų�� ���ĺ� �빮�ڷ� ǥ���ϸ�, ��� ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
��ų ������ ��ųƮ���� ���ڿ��� ǥ���մϴ�.
���� ���, C �� B �� D ��� "CBD"�� ǥ���մϴ�
���� ��ų ���� skill�� ���̴� 1 �̻� 26 �����̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
skill_trees�� ���� 1 �̻� 20 ������ �迭�Դϴ�.
skill_trees�� ���Ҵ� ��ų�� ��Ÿ���� ���ڿ��Դϴ�.
skill_trees�� ���Ҵ� ���̰� 2 �̻� 26 ������ ���ڿ��̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.

����� ��
skill	skill_trees	                            return
"CBD"	["BACDE", "CBADF", "AECB", "BDA"]	    2


����� �� ����
"BACDE": B ��ų�� ���� ���� C ��ų�� ���� ����� �մϴ�. �Ұ����� ��ųƮ���ϴ�.
"CBADF": ������ ��ųƮ���Դϴ�.
"AECB": ������ ��ųƮ���Դϴ�.
"BDA": B ��ų�� ���� ���� C ��ų�� ���� ����� �մϴ�. �Ұ����� ��ųƮ���Դϴ�.

*/


// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
// skill_trees_len�� �迭 skill_trees�� �����Դϴ�.


/*

1.1. skill( order ) ���� �� ����
�� ������ �ùٸ� ������ ������ ���� �ʽ��ϴ�. �����ϰ� �����մϴ�.
��Ģ : CBD �� ��
tree [ 'BACDE', 'CBADF', 'AECB', 'BDA' ] =>
tree [ 'BCD', 'CBD', 'CB', 'BD' ]

1.2. ������ ������ CBD ���� ���� �ε��� ���� �����մϴ�.
[ [ 1, 0, 2 ], [ 0, 1, 2 ], [ 0, 1 ], [ 1, 2 ] ]

1.3. ������ �ε��� ���� 0���� ���������� �����Ǿ�� �ùٸ� ���Դϴ�.
isRightOrder : [ false, true, true, false ] => 2

*/


//skill "CBD", ["BACDE", "CBADF", "AECB", "BDA"]

int solution(string skill, vector<string> skill_trees) 
{
    int answer = skill_trees.size();

    vector<vector<int>> result(skill_trees.size());

    for (int i = 0; i < skill_trees.size(); ++i)
    {
        for (int j = 0; j < skill_trees[i].size(); ++j)
        {
            for (int k = 0; k < skill.size(); ++k)
            {
                if (skill_trees[i][j] == skill[k])
                {
                    result[i].push_back(k);
                    break;
                }

            }
            
        }
    }

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            if (result[i][j] != j)
            {
                --answer;
                break;
            }
        }
    }
    return answer;
}


int main()
{
    

    int result = solution("CBD", {"BACDE", "CBADF", "AECB", "BDA" });



    return 0;
}