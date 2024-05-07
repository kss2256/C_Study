#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
문제 설명
호텔을 운영 중인 코니는 최소한의 객실만을 사용하여 예약 손님들을 받으려고 합니다.
한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소를 하고 다음 손님들이 사용할 수 있습니다.
예약 시각이 문자열 형태로 담긴 2차원 배열 book_time이 매개변수로 주어질 때, 
코니에게 필요한 최소 객실의 수를 return 하는 solution 함수를 완성해주세요.

제한사항
1 ≤ book_time의 길이 ≤ 1,000
book_time[i]는 ["HH:MM", "HH:MM"]의 형태로 이루어진 배열입니다
[대실 시작 시각, 대실 종료 시각] 형태입니다.
시각은 HH:MM 형태로 24시간 표기법을 따르며, "00:00" 부터 "23:59" 까지로 주어집니다.
예약 시각이 자정을 넘어가는 경우는 없습니다.
시작 시각은 항상 종료 시각보다 빠릅니다.

입출력 예
book_time	result
[["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]	3
[["09:10", "10:10"], ["10:20", "12:20"]]	1
[["10:20", "12:30"], ["10:20", "12:30"], ["10:20", "12:30"]]	3
*/

//{ "15:00", "17:00" }
//{ "16:40", "18:20" }
//{ "14:20", "15:20" }
//{ "14:10", "19:20" }
//{ "18:20", "21:20" }

//std::istringstream 은 정수나 부동소수점 문자열을 파싱할때 사용 한다. #include <sstream>
//stio

bool compare(const vector<int>& a, const vector<int>& b) 
{
    if (a[0] != b[0]) 
        return a[0] < b[0]; // 시작 시간을 기준
    else
        return a[1] < b[1]; // 시작 시간이 같은 경우 종료 시간을 기준
}

int solution(vector<vector<string>> book_time) 
{

    int answer = 0;
    vector<vector<int>> temp;
    vector<bool> visit(book_time.size(), false);
    temp.resize(book_time.size());

    //std::istringstream 을 사용해서 문자열 파싱? 이라는걸 함.. 
    // timeToint 변수에 이미 15   :    20   이런식으로 분류가 되어있을것임. 
    //정수나 부동소수점 이 아닌 다른 문자열 _ 도 되고 공백도 되고? 암튼 다른거를 만나면 따로 분류하는듯함
    for (int i = 0; i < book_time.size(); ++i) 
    {
        for (int j = 0; j < book_time[i].size(); ++j) 
        {
            //15::00   15 _ 00 
            istringstream timeToint(book_time[i][j]);
            int hour, minute;
            char dumi;
            timeToint >> hour >> dumi >> minute;
            temp[i].push_back(hour * 60 + minute);
        }
    }

    // 오름 차순으로 정렬
    sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < temp.size(); ++i) 
    {
        if (visit[i] == true)
            continue;

        int endTime = temp[i][1];
        for (int j = i + 1; j < temp.size(); ++j)
        {
            if (visit[j] == true)
                continue;

            // 다음 예약의 시작 시간이 현재 예약의 종료 시간보다 늦다면 같은 객실을 사용 해도됨
            if (temp[j][0] >= endTime + 10)
            {
                //이미 들른방체크해주고 마지막 투숙객의 퇴실 시간을 업데이트
                endTime = temp[j][1]; 
                visit[j] = true; 
            }
        }
        ++answer;
    }

    return answer;
}

int main()
{
	int result = solution
	({	
		{ "15:00", "17:00" },
		{ "16:40", "18:20" },
		{ "14:20", "15:20" },
		{ "14:10", "19:20" },
		{ "18:20", "21:20" }
	});

	//int result = solution
	//({	
	//	{ "09:10", "10:10" },
	//	{ "10:20", "12:20" },	
	//});

	//int result = solution
	//({
	//	{ "10:20", "12:30" },
	//	{ "10:20", "12:30" },
	//	{ "10:20", "12:30" },
	//	});

    return 0;
}