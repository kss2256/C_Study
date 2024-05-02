#include <iostream>

//1. �޸𸮹���� ��ͷ� �ؿ��� ������� �ö���� �߰� ��ͷ� ������ ����� ���� ���ϸ� �Ѵ�. 
//2. 

unsigned long long FibonacciCalculator(int _value, unsigned long long* dynamic)
{
    if (_value == 0)
        return 0;
    if (_value == 1)
        return 1;

    if (dynamic[_value] != 0)
        return dynamic[_value];

    dynamic[_value] = FibonacciCalculator(_value - 2, dynamic) + FibonacciCalculator(_value - 1, dynamic);
    return dynamic[_value];
}

//Memoizaition, Top-down(�����) ���
unsigned long long FibonacciTopDown(int _value)
{
    if (_value < 0)
        return 0; 

    unsigned long long* dynamic = new unsigned long long[_value + 1];

    for (int i = 0; i < _value + 1; i++)
    {
        dynamic[i] = 0;
    }

    long long result = FibonacciCalculator(_value, dynamic);

    delete[] dynamic;
    return result;
}


//Tabulation, Bottom-up(�����) ���
unsigned long long FibonacciBottomUp(int _value)
{

    if (_value < 0)
        return 0;

    unsigned long long* arrPint = new unsigned long long[_value + 1];
    arrPint[0] = 0;
    arrPint[1] = 1;

    for (int i = 2; i <= _value; i++)
    {
        arrPint[i] = arrPint[i - 1] + arrPint[i - 2];
    }

    return arrPint[_value];

}


int main()
{

    unsigned long long test = FibonacciTopDown(99);
    unsigned long long test1 = FibonacciBottomUp(99);

    std::cout << test << std::endl;
    std::cout << test1 << std::endl;


    return 0;
}