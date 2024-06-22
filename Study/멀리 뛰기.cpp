#include <string>
#include <vector>

using namespace std;


/*
    1의 최대 개수 = n개
    2의 최대 개수 = n / 2 개
    n % 2가 0 이면 마지막은 한번만


    n = 5
    

*/


//long long solution(int n) 
//{
//    long long answer = 0;
//
//    int number2 = n / 2;
//    int sum = 0;
//    if (n % 2 == 0)
//    {
//        number2 -= 1;
//        sum = 1;
//    }
//    
//    for (int i = 1; i < number2 + 1; ++i)
//    {
//        sum += n - i;
//    }
//
//    answer = sum + 1;
//    return answer;
//}



long long solution(int n) 
{
    long long answer = 0;

    if (n == 1) return 1;
    if (n == 2) return 2;

    std::vector<int> result(n + 1, 0);
    result[1] = 1;
    result[2] = 2;

    for (int i = 3; i <= n; ++i) 
    {
        result[i] = (result[i - 1] + result[i - 2]) % 1234567;
    }

    return result[n];


}

//int comb(int n, int k) 
//{
//    if (k > n) 
//        return 0;
//
//    if (k == 0 || k == n) 
//        return 1;
//
//    k = std::min(k, n - k);  
//
//    long long c = 1;
//    for (int i = 0; i < k; ++i) 
//    {
//        c = c * (n - i) / (i + 1);
//    }
//
//    return c % 1234567;
//}
//
//long long solution(int n) 
//{
//    long long answer = 0;
//
//   
//    for (int two = 0; two <= n / 2; ++two)
//    {
//        answer = (answer + comb(n - two, two)) % 1234567;
//    }
//
//    return answer;
//}



int main()
{
    long long result = solution(3);





    return 0;
}