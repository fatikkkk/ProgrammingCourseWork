#include <iostream>
#include <Windows.h>

using namespace std;

const int N1 = 6;
const int N2 = 8;
const int N3 = 10;
const int kComboSort = 1.247;

void fillZero(int* matrix, int N)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i = 0;
}

void print(int* matrix, int N)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
    {
        cout << ' ';
        if (*i < 100)
            cout << ' ';
        if (*i < 10)
            cout << ' ';
        cout << *i << ' ';
        if ((i - matrix) % N == (N - 1))
            cout << '\n';
        else
            cout << ' ';
    }
}

void printBlocks(int* matrix, int N)
{
    int* endMatrix = matrix + N * N - 1;
    int* middleMatrix = matrix + (N * N / 2) - 1;
    for (int* i = matrix; i <= endMatrix; i++)
    {
        cout << ' ';
        if (*i < 100)
            cout << ' ';
        if (*i < 10)
            cout << ' ';
        cout << *i << ' ';
        if (i == middleMatrix)
        {
            cout << '\n';
            for (int j = 0; j < (N / 2) - 1; j++)
                cout << "------";
            cout << "-----|";
            for (int j = 0; j < (N / 2) - 1; j++)
                cout << "------";
            cout << "-----\n";
        }
        else if ((i - matrix) % N == (N - 1))
            cout << '\n';
        else if ((i - matrix) % N == (N / 2) - 1)
            cout << '|';
        else
            cout << ' ';
    }
}

void newMatrix(int* matrix, int N)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i = rand() % (N * N) + 1;
}

void fillSpiralMatrix(int* matrix, int N)
{
    fillZero(matrix, N);
    print(matrix, N);
    Sleep(100);
    for (int param = 0; param < N / 2; param++)
    {
        int* p1 = matrix + param * (N + 1);
        int* p2 = matrix + (param + 1) * (N - 1);
        int* p3 = matrix + N * N - 1 - param * (N + 1);
        int* p4 = matrix + N * (N - 1) - param * (N - 1);
        for (int* i = p1; i < p2; i++)
        {
            *i = rand() % (N * N) + 1;
            system("cls");
            print(matrix, N);
            Sleep(100);
        }
        for (int* i = p2; i < p3; i += N)
        {
            *i = rand() % (N * N) + 1;
            system("cls");
            print(matrix, N);
            Sleep(100);
        }
        for (int* i = p3; i > p4; i--)
        {
            *i = rand() % (N * N) + 1;
            system("cls");
            print(matrix, N);
            Sleep(100);
        }
        for (int* i = p4; i > p1; i -= N)
        {
            *i = rand() % (N * N) + 1;
            system("cls");
            print(matrix, N);
            Sleep(100);
        }
    }
}

void fillSnakeMatrix(int* matrix, int N)
{
    fillZero(matrix, N);
    print(matrix, N);
    Sleep(100);
    for (int param = 0; param < N / 2; param++)
    {
        int* p1 = matrix + param * 2;
        int* p2 = matrix + N * (N - 1) + param * 2;
        for (int* i = p1; i <= p2; i += N)
        {
            *i = rand() % (N * N) + 1;
            system("cls");
            print(matrix, N);
            Sleep(100);
        }
        for (int* i = p2 + 1; i >= p1 + 1; i -= N)
        {
            *i = rand() % (N * N) + 1;
            system("cls");
            print(matrix, N);
            Sleep(100);
        }
    }
}

void changeSnake(int* matrix, int N)
{
    for (int param = 0; param < (N * N / 4); param++)
    {
        int* p1 = matrix + (param * 2 / N) * N + (param % (N / 2));
        int* p2 = p1 + (N / 2);
        int* p3 = p2 + (N / 2) * N;
        int* p4 = p3 - (N / 2);
        int temp = *p1;
        int temp2 = *p3;
        *p1 = *p4;
        *p3 = *p2;
        *p2 = temp;
        *p4 = temp2;
    }
    cout << "\n\n";
    printBlocks(matrix, N);
}

void changeCross(int* matrix, int N)
{
    for (int param = 0; param < (N * N / 4); param++)
    {
        int* p1 = matrix + (param * 2 / N) * N + (param % (N / 2));
        int* p2 = p1 + (N / 2);
        int* p3 = p2 + (N / 2) * N;
        int* p4 = p3 - (N / 2);
        swap(*p1, *p3);
        swap(*p2, *p4);
    }
    cout << "\n\n";
    printBlocks(matrix, N);
}

void changeVertical(int* matrix, int N)
{
    for (int param = 0; param < (N * N / 4); param++)
    {
        int* p1 = matrix + (param * 2 / N) * N + (param % (N / 2));
        int* p2 = p1 + (N / 2);
        int* p3 = p2 + (N / 2) * N;
        int* p4 = p3 - (N / 2);
        swap(*p1, *p4);
        swap(*p2, *p3);
    }
    cout << "\n\n";
    printBlocks(matrix, N);
}

void changeHorizontal(int* matrix, int N)
{
    for (int param = 0; param < (N * N / 4); param++)
    {
        int* p1 = matrix + (param * 2 / N) * N + (param % (N / 2));
        int* p2 = p1 + (N / 2);
        int* p3 = p2 + (N / 2) * N;
        int* p4 = p3 - (N / 2);
        swap(*p1, *p2);
        swap(*p3, *p4);
    }
    cout << "\n\n";
    printBlocks(matrix, N);
}

void bubbleSort(int* arr, int countElements)
{
    int* f_endArray = arr + countElements - 1;
    for (int* f_i = arr; f_i < f_endArray; f_i++)
    {
        for (int* f_j = arr; f_j < (f_endArray - (f_i - arr)); f_j++)
        {
            if (*(f_j) > *(f_j + 1))
                swap(*(f_j + 1), *f_j);
        }
    }
}

void insertSort(int* arr, int countElements)
{
    int* f_endArray = arr + countElements;
    for (int* f_i = arr + 1; f_i < f_endArray; f_i++)
    {
        int elem = *f_i, pos = f_i - arr;
        for (int* f_j = f_i - 1; f_j >= arr && *f_j > elem; f_j--)
        {
            *(f_j + 1) = *f_j;
            pos--;
        }
        *(arr + pos) = elem;
    }
}

void shakerSort(int* arr, int countElements)
{
    int* first = arr, * last = arr + countElements - 1;
    while (first < last)
    {
        for (int* f_i = first; f_i < last; f_i++)
        {
            if (*f_i > *(f_i + 1))
                swap(*f_i, *(f_i + 1));
        }
        last--;
        for (int* f_i = last; f_i > first; f_i--)
        {
            if (*(f_i - 1) > *f_i)
                swap(*f_i, *(f_i - 1));
        }
        first++;
    }
}

void combSort(int* arr, int temp, int countElements)
{
    int* f_endArray = arr + countElements - 1;
    while (temp >= 1)
    {
        for (int* f_i = arr; f_i + temp <= f_endArray; f_i++)
        {
            if (*f_i > *(f_i + temp))
                swap(*f_i, *(f_i + temp));
        }
        temp /= kComboSort;
    }
}

void quickSort(int* arr, int* begin, int* end)
{
    int* first = begin, * last = end;
    int middle = *(first + ((last - first) / 2));
    while (first < last)
    {
        while (*first < middle)
            first++;
        while (*last > middle)
            last--;
        if (first <= last)
        {
            swap(*first, *last);
            first++;
            last--;
        }
    }
    if (begin < last)
        quickSort(arr, begin, last);
    if (first < end)
        quickSort(arr, first, end);
}

void add(int* matrix, int N, int actNumber)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i += actNumber;
}

void sub(int* matrix, int N, int actNumber)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i -= actNumber;
}

void mult(int* matrix, int N, int actNumber)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i *= actNumber;
}

void div(int* matrix, int N, int actNumber)
{
    int* endMatrix = matrix + N * N - 1;
    for (int* i = matrix; i <= endMatrix; i++)
        *i /= actNumber;
}


void sort(int* sArr, int N)
{
    int punktSort;
    cout << "\nWhich sort do you want to use? Choose the number\n"
        << "1 - Bubble Sort\n"
        << "2 - Shaker Sort\n"
        << "3 - Comb Sort\n"
        << "4 - Insert Sort\n"
        << "5 - Quick Sort\n"
        << "0 - Exit in menu\n\n";
    cin >> punktSort;
    cout << '\n';
    switch (punktSort)
    {
    case 1:
        bubbleSort(sArr, N * N);
        print(sArr, N);
        break;
    case 2:
        shakerSort(sArr, N * N);
        print(sArr, N);
        break;
    case 3:
        combSort(sArr, N * N - 1, N * N);
        print(sArr, N);
        break;
    case 4:
        insertSort(sArr, N * N);
        print(sArr, N);
        break;
    case 5:
        quickSort(sArr, sArr, sArr + N * N - 1);
        print(sArr, N);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.";
        system("Pause");
        sort(sArr, N);
        break;
    }
}

void action(int* aArr, int N)
{
    int punktAction, actNumber;
    cout << "\nInput the number\n";
    cin >> actNumber;
    cout << "\nWhich action do you want to use? Choose the number\n"
        << "1 - Addition\n"
        << "2 - Subtraction\n"
        << "3 - Multiplication\n"
        << "4 - Division\n"
        << "0 - Exit in menu\n\n";
    cin >> punktAction;
    cout << '\n';
    switch (punktAction)
    {
    case 1:
        add(aArr, N, actNumber);
        print(aArr, N);
        break;
    case 2:
        sub(aArr, N, actNumber);
        print(aArr, N);
        break;
    case 3:
        mult(aArr, N, actNumber);
        print(aArr, N);
        break;
    case 4:
        div(aArr, N, actNumber);
        print(aArr, N);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.";
        system("Pause");
        action(aArr, N);
        break;
    }
}

void menu(int* mArr, int* mVArr, int N)
{
    int itemMenu;
    cout << "What operation you want to perform? Enter a number from 1 to 8:\n"
        << "1 - Fill matrix with spiral method\n"
        << "2 - Fill matrix with snake method\n"
        << "3 - Change matrix blocks sequentially\n"
        << "4 - Change matrix blocks crosswise.\n"
        << "5 - Change matrix blocks vertical\n"
        << "6 - Change matrix blocks horizontal\n"
        << "7 - Sort matrix\n"
        << "8 - Make an action with matrix\n"
        << "0 - Exit\n\n";
    cin >> itemMenu;
    switch (itemMenu)
    {
    case 1:
        system("cls");
        fillSpiralMatrix(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 2:
        system("cls");
        fillSnakeMatrix(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 3:
        system("cls");
        newMatrix(mArr, N);
        printBlocks(mArr, N);
        changeSnake(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 4:
        system("cls");
        newMatrix(mArr, N);
        printBlocks(mArr, N);
        changeCross(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 5:
        system("cls");
        newMatrix(mArr, N);
        printBlocks(mArr, N);
        changeVertical(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 6:
        system("cls");
        newMatrix(mArr, N);
        printBlocks(mArr, N);
        changeHorizontal(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 7:
        system("cls");
        newMatrix(mArr, N);
        print(mArr, N);
        sort(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    case 8:
        system("cls");
        newMatrix(mArr, N);
        print(mArr, N);
        action(mArr, N);
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;

    case 0:
        //exit(1);
        break;
    default:
        cout << "Error! Repeat, please.";
        system("Pause");
        system("cls");
        menu(mArr, mVArr, N);
        break;
    }
}

void mainThird()
{
    srand(time(NULL));
    int numberUser;

    int matrix1[N1][N1], matrix2[N2][N2], matrix3[N3][N3];
    int* m1 = *matrix1, * m2 = *matrix2, * m3 = *matrix3;
    
    int matrixV1[N1][N1], matrixV2[N2][N2], matrixV3[N3][N3];
    int* mV1 = *matrixV1, * mV2 = *matrixV2, * mV3 = *matrixV3;
    
    cout << "Input size of matrix.\n";
    cin >> numberUser;
    switch (numberUser)
    {
    case 6:
        system("cls");
        menu(m1, mV1, N1);
        break;
    case 8:
        system("cls");
        menu(m2, mV2, N2);
        break;
    case 10:
        system("cls");
        menu(m3, mV3, N3);
        break;
    default:
        cout << "Error! Repeat, please.\n";
        system("Pause");
        system("cls");
        mainThird();
        break;
    }
}