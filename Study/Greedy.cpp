#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 
크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.
*/


/*
    1. 무게 제한 설정하기.
    2. 각 사람을 몸무게 별로 오름차순 정렬 하기.
    3. 최소 + 최대가 리밋을 넘기면 최대만 보내기
    2명씩만 태울수 있음.
*/



int solution(vector<int> people, int limit)
{
    int result = 0;
    const int Min = 40;
    const int Max = 240;

    int MinPeople = 0;
    int MaxPeople = people.size() - 1;

    //오름 차순으로 정렬
    sort(people.begin(), people.end());

    //예외 처리 
    for (size_t i = 0; i < MaxPeople; i++)
    {
        //몸무게 40 이하 240 이상 , 리미트 무게보다 무거우면 오류
        if (people[i] < Min || people[i] > Max || Max < limit)
        {
            cout << "무게 설정 오류" << endl;
        }
    }
        

    for (; MinPeople <= MaxPeople;)
    {
        //만약 남아있는 최소값 + 최대값이 limit보다 큰 경우  최대값 탈출
        if (people[MinPeople] + people[MaxPeople] > limit)
        {
            ++result;
            --MaxPeople;
        }
        //만약 limit 보다 작았을경우
        else
        {
            //혹시 두명 남았을 경우에는 태우고 종료          
            if (MinPeople + 1 == MaxPeople)
                return ++result;

            //최소값 + 최대값 태워서 보내기
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


