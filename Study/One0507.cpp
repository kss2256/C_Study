#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
���� ����
ȣ���� � ���� �ڴϴ� �ּ����� ���Ǹ��� ����Ͽ� ���� �մԵ��� �������� �մϴ�.
�� �� ����� ������ ��� �ð��� �������� 10�а� û�Ҹ� �ϰ� ���� �մԵ��� ����� �� �ֽ��ϴ�.
���� �ð��� ���ڿ� ���·� ��� 2���� �迭 book_time�� �Ű������� �־��� ��, 
�ڴϿ��� �ʿ��� �ּ� ������ ���� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� book_time�� ���� �� 1,000
book_time[i]�� ["HH:MM", "HH:MM"]�� ���·� �̷���� �迭�Դϴ�
[��� ���� �ð�, ��� ���� �ð�] �����Դϴ�.
�ð��� HH:MM ���·� 24�ð� ǥ����� ������, "00:00" ���� "23:59" ������ �־����ϴ�.
���� �ð��� ������ �Ѿ�� ���� �����ϴ�.
���� �ð��� �׻� ���� �ð����� �����ϴ�.

����� ��
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

//std::istringstream �� ������ �ε��Ҽ��� ���ڿ��� �Ľ��Ҷ� ��� �Ѵ�. #include <sstream>
//stio

bool compare(const vector<int>& a, const vector<int>& b) 
{
    if (a[0] != b[0]) 
        return a[0] < b[0]; // ���� �ð��� ����
    else
        return a[1] < b[1]; // ���� �ð��� ���� ��� ���� �ð��� ����
}

int solution(vector<vector<string>> book_time) 
{

    int answer = 0;
    vector<vector<int>> temp;
    vector<bool> visit(book_time.size(), false);
    temp.resize(book_time.size());

    //std::istringstream �� ����ؼ� ���ڿ� �Ľ�? �̶�°� ��.. 
    // timeToint ������ �̹� 15   :    20   �̷������� �з��� �Ǿ���������. 
    //������ �ε��Ҽ��� �� �ƴ� �ٸ� ���ڿ� _ �� �ǰ� ���鵵 �ǰ�? ��ư �ٸ��Ÿ� ������ ���� �з��ϴµ���
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

    // ���� �������� ����
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

            // ���� ������ ���� �ð��� ���� ������ ���� �ð����� �ʴٸ� ���� ������ ��� �ص���
            if (temp[j][0] >= endTime + 10)
            {
                //�̹� �鸥��üũ���ְ� ������ �������� ��� �ð��� ������Ʈ
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