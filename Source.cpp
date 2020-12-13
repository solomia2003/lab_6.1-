#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* t, const int n, const int min, const int max, int i)
{
    if (i == n) {
        return;
    }
    t[i] = min + rand() % (max - min + 1);
    create(t, n, min, max, i + 1);
}

void modify(int* t, const int n, int i)
{
    if (i == n) 
    {
        return;
    }
    if ((t[i] > 0 && i % 4 != 0)) 
    {
        t[i] = 0;
    }
    modify(t, n, i + 1);
}


void print(int* t, const int n, int i)
{
    if (i == n) 
    {
        cout << endl;
        return;
    }
    cout << " " << t[i] << "; ";
    print(t, n, i + 1);
}

int sum(int* t, const int n, int i)
{
    if (i == n) 
    {
        return 0;
    }
    if ((t[i] > 0 && i % 4 != 0)) 
    {
        return sum(t, n, i + 1) + t[i];
    }
    return sum(t, n, i + 1);
}

int count(int* t, const int n, int i)
{
    if (i == n) 
    {
        return 0;
    }
    if ((t[i] > 0 && i % 4 != 0)) 
    {
        return count(t, n, i + 1) + 1;
    }
    return count(t, n, i + 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    const int n = 21;
    int t[n];
    int min = -14;
    int max = 7;
    create(t, n, min, max, 0);
    cout << "Масив із рандомних чисел:";
    print(t, n, 0);
    cout << "Сума елементів масиву: " << sum(t, n, 0) << endl;
    cout << "Кількість елементів масиву: " << count(t, n, 0) << endl;
    cout << "Модифікований масив: ";
    modify(t, n, 0);
    print(t, n, 0);
}
