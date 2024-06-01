#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


bool Compare(int left, int right) 
{
    return left < right;
}

string solution(string s) 
{    
    string answer = "";
  
    stringstream stream(s);
    string str;
    vector<int> result;

    

    while (stream >> str)
    {
        result.push_back(stoi(str));
    }

    sort(result.begin(), result.end(), Compare);
  
    int begin = result.front();
    int end = result.back();
    answer = to_string(begin) + " " + to_string(end);

    return answer;
}


int main()
{

    string result = solution("1 2 3 4");

    return 0;
}