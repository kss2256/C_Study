#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//1Â÷
//char* solution(int numbers[], size_t numbers_len)
//{
//
//    vector<int> array;
//
//    std::string name;
//
//    
//    for (int i = 0; i < numbers_len; i++)
//    {
//        while (numbers[i] != 0)
//        {
//            array.push_back(numbers[i] % 10);
//            numbers[i] /= 10;
//        }
//    }
//    
//    sort(array.begin(), array.end());
//
//
//    for (int i = (int)array.size() - 1; i >= 0; i--)
//    {
//        name += to_string(array[i]);
//    }
//
//    char* answer = (char*)malloc(name.size() + 1);
//    if (answer != 0)
//    {
//    strcpy_s(answer, name.size() + 1, name.c_str());
//    }
//
//
//    return answer;
//}


string solution(vector<int> numbers)
{

    vector<int> array;

    std::string name;


    for (int i = 0; i < numbers.size(); i++)
    {
        while (numbers[i] != 0)
        {
            array.push_back(numbers[i] % 10);
            numbers[i] /= 10;
        }
    }

    sort(array.begin(), array.end());


    for (int i = (int)array.size() - 1; i >= 0; i--)
    {
        name += to_string(array[i]);
    }

   


    return name;
}



int main()
{
    char* pchar = nullptr;
    std::vector<int> array = { 6, 10, 2 };
    std::string test;

    test = solution(array);


    std::cout << test;
    
   

   


   


    return 0;
}


