#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
���ε��� ���� ����� 1�� �̻� 50,000�� �����Դϴ�.
�� ����� �����Դ� 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ �׻� ������� ������ �� �ִ񰪺��� 
ũ�� �־����Ƿ� ������� ������ �� ���� ���� �����ϴ�.
*/


/*
    1. ���� ���� �����ϱ�.
    2. �� ����� ������ ���� �������� ���� �ϱ�.
    3. 



*/



int solution(vector<int> people, int limit)
{
    int result = 0;
    const int Min = 40;
    const int Max = 240;

    //���� �������� ����
    sort(people.begin(), people.end());

    //���� ó�� 
    for (size_t i = 0; i < people.size(); i++)
    {
        //������ 40 ���� 240 �̻� , ����Ʈ ���Ժ��� ���ſ�� ����
        if (people[i] < Min || people[i] > Max || Max < limit)
        {
            cout << "���� ���� ����" << endl;
        }
    }
        

    for (size_t i = 0; i < people.size();)
    {
        //���� �����ִ� �ּҰ� + �ִ밪�� limit���� ū ���  �ִ밪 Ż��
        if (people[i] + people[people.size() - 1] > limit)
        {
            ++result;
            people.pop_back();
        }
        //���� limit ���� �۾������
        else
        {
            //Ȥ�� �θ� ������ ��쿡�� �¿�� ����          
            if (i + 1 == people.size() - 1)
                return ++result;

            //�ּҰ� + �ִ밪 �¿��� ������
            ++i;
            people.pop_back();
            ++result;
        }
    }

    return result;
}


int main()
{

    vector<int> PeopleWeights;
    PeopleWeights.push_back(70);
    PeopleWeights.push_back(50);
    PeopleWeights.push_back(80);
    PeopleWeights.push_back(50);
    
    
   int test =  solution(PeopleWeights, 100);
    
   std::cout << test;
    
    

    return 0;
}


