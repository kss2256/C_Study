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

    //내림 차순 정렬 

    //6,5,3,1,0  
    sort(citations.begin(), citations.end(), Compare);


    int hidx = 0;

    //6편중 h번 이상 인용된 논문이 h편 이상이고 나머지는 h번 이하 인용 됬다.

    //  입출력 예 설명 {3, 0, 6, 1, 5} 
    //  이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다.
    //  그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

    // 0과 1은 아니다? 
    //6,5,3,1,0  인용 등수 만들고 1 2 3 4 5 등 
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