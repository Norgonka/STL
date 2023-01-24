#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void FillVector(vector<int> &vc)
{
    int a;

    cout << "Input integer. Input 0 or anything else to quit out of cycle." << endl;
    while (true)
    {
        cin >> a;
        if (!a) break;

        vc.emplace_back(a);
    }
}

void Foo(int a)
{
    if (10 <= a && a <= 40)
    {
        cout << a << " is in range of 10 to 40." << endl;
    }
}

void Bar(int a)
{
    if (a % 2 == 0)
    {
        cout << a << " is even" << endl;
    }
}

void DoWork(vector<int>& vc, vector<function<void(int)>> fVector)
{
    for (auto it : vc)
    {
        for (auto fit : fVector)
        {
            fit(it);
        }
    }
}

int main()
{
    vector<int> vc;
    
    FillVector(vc);

    vector<function<void(int)>> fVector;

    fVector.emplace_back(Foo);
    fVector.emplace_back(Bar);

    DoWork(vc, fVector);
}