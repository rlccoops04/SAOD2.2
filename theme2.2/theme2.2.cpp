#include <iostream>
void bubbleSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                exchanges++;
            }
            compares++;
        }
    }
}
void selectionSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp, k;
    for (int i = 0; i < size - 1; i++)
    {
        k = i;
        temp = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < temp)
            {
                k = j;
                temp = arr[j];
                exchanges++;
            }
            compares++;
        }
        arr[k] = arr[i];
        arr[i] = temp;
    }
}
void insertionSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((j >= 0) && (temp < arr[j]))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            exchanges++;
            compares++;
        }
        arr[j + 1] = temp;
        compares++;
    }
}
void ShellSorting(int* arr, int size, int& compares, int& exchanges)
{
    int countsteps = (int)log2(size) - 1;
    int* steps = new int[countsteps];
    int t = countsteps;
    for (int i = 0; t > 0; i++, t--)
    {
        steps[i] = 2 * t - 1;
    }
    int temp, step, j;
    for (int numstep = 0; numstep < countsteps; numstep++)
    {
        step = steps[numstep];
        for (int i = step; i < size; i++)
        {
            temp = arr[i];
            j = i - step;
            while ((j >= 0) && (temp < arr[j]))
            {
                arr[j + step] = arr[j];
                j = j - step;
                compares++;
                exchanges++;
            }
            compares++;
            arr[j + step] = temp;
        }
    }
}
void quickSorting(int* arr, int size, int& compares, int& exchanges, int left, int right)
{
    int i, j, sred, temp;
    i = left;
    j = right;
    sred = arr[(left + right) / 2];
    do
    {
        while (arr[i] < sred)
        {
            i++;
            compares++;
        }
        while (arr[j] > sred)
        {
            j--;
            compares++;
        }
        compares += 2;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
            exchanges++;
        }
    } while (i <= j);
    if (left < j)
    {
        quickSorting(arr, size, compares, exchanges, left, j);
    }
    if (i < right)
    {
        quickSorting(arr, size, compares, exchanges, i, right);
    }
}
void Sito(int* arr, int size, int& compares, int& exchanges, int left, int right)
{
    int i, j, x;
    i = left; j = 2 * left; x = arr[left];
    if ((j < right) && arr[j + 1] > arr[j])
    {
        j++;
    }
    compares++;
    while ((j <= right) && (arr[j] > x))
    {
        compares++;
        arr[i] = arr[j];
        exchanges++;
        i = j;
        j *= 2;
        if ((j < right) && (arr[j + 1] > arr[j]))
        {
            j++;
        }
        compares++;
    }
    compares++;
    arr[i] = x;
    exchanges++;
}

void pyramidSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp, left, right;
    left = (size / 2);
    right = size - 1;
    while (left > 0)
    {
        left--;
        Sito(arr, size, compares, exchanges, left, right);
    }
    while (right > 0)
    {
        temp = arr[0];
        arr[0] = arr[right];
        arr[right] = temp;
        right--;
        Sito(arr, size, compares, exchanges, left, right);
    }
}
void duplicateArray(int* mainarr, int* duplarr, int size)
{
    for (int i = 0; i < size; i++)
    {
        duplarr[i] = mainarr[i];
    }
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int size;
    std::cout << "Введите размер массива (не более 10.000): ";
    std::cin >> size;
    int* MainArray = new int[size];
    int* SortedArr = new int[size];
    for (int i = 0; i < size; i++)
    {
        MainArray[i] = 0 + rand() % 11;
    }
    duplicateArray(MainArray, SortedArr, size);
    bool menu = true;
    int choicemenu, compares, exchanges;
    while (menu)
    {
        compares = 0;
        exchanges = 0;
        std::cout << "1) Сортировка обменом(метод пузырька).\n"
            "2) Сортировка выбором.\n"
            "3) Сортировка вставками.\n"
            "4) Сортировка методом Шелла.\n"
            "5) Быстрая сортировка.\n"
            "6) Пирамидальная сортировка.\n"
            "7) Выход.\nВвод: ";
        std::cin >> choicemenu;
        switch (choicemenu)
        {
        case 1:
            bubbleSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 2:
            selectionSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 3:
            insertionSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 4:
            ShellSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 5:
            quickSorting(SortedArr, size, compares, exchanges, 0, size - 1);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 6:
            pyramidSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        default:
            menu = false;
            break;
        }
        duplicateArray(MainArray, SortedArr, size);
    }
    delete[] MainArray;
    delete[] SortedArr;
}