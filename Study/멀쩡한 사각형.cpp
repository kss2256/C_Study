#include <vector>

using namespace std;


int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w, int h) 
{
    long long answer = 0;

    long long colrow = (long long)w * h; 

    int gcdValue = gcd(w, h); 
   
    answer = colrow - ((long long)w + h - gcdValue);

    return answer;
}


int main()
{

    long long result = solution(8, 12);


    return 0;
}