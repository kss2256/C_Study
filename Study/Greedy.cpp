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
    3. �ּ� + �ִ밡 ������ �ѱ�� �ִ븸 ������
    2���� �¿�� ����.
*/



int solution(vector<int> people, int limit)
{
    int result = 0;
    const int Min = 40;
    const int Max = 240;

    int MinPeople = 0;
    int MaxPeople = people.size() - 1;

    //���� �������� ����
    sort(people.begin(), people.end());

    //���� ó�� 
    for (size_t i = 0; i < MaxPeople; i++)
    {
        //������ 40 ���� 240 �̻� , ����Ʈ ���Ժ��� ���ſ�� ����
        if (people[i] < Min || people[i] > Max || Max < limit)
        {
            cout << "���� ���� ����" << endl;
        }
    }
        

    for (; MinPeople <= MaxPeople;)
    {
        //���� �����ִ� �ּҰ� + �ִ밪�� limit���� ū ���  �ִ밪 Ż��
        if (people[MinPeople] + people[MaxPeople] > limit)
        {
            ++result;
            --MaxPeople;
        }
        //���� limit ���� �۾������
        else
        {
            //Ȥ�� �θ� ������ ��쿡�� �¿�� ����          
            if (MinPeople + 1 == MaxPeople)
                return ++result;

            //�ּҰ� + �ִ밪 �¿��� ������
            ++MinPeople;
            --MaxPeople;
            ++result;
        }
    }
   
    return result;
}


int main()
{

    vector<int> PeopleWeights;
    PeopleWeights.push_back(70);
    PeopleWeights.push_back(80);
    PeopleWeights.push_back(50);
    
    
   int test =  solution(PeopleWeights, 100);
    
   std::cout << test;
    
   //std::string tets = "Hellow \"feuhs\"! ";
   std::string tets = R"(Hellow "feuhs" !)";


   std::cout << tets;

    return 0;
}


