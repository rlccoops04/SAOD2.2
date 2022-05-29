#include <iostream>
void bubbleSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
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
void insertionSorting(int* arr, int size, int& compares, int& exchanges)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while ((++compares) && j >= 0 && arr[i] < arr[j])
        {
            j -= 1;
        }
        if (j + 1 != i)
        {
            int temp = arr[i];
            int l = i - 1;
            while (l >= j + 1)
            {
                arr[l + 1] = arr[l]; l--;
                exchanges++;
            }
            arr[j + 1] = temp;
            exchanges++;
        }
    }
    exchanges = exchanges / 3;
}
void selectionSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp = 0;
    int k = 0;
    for (int i = 0; i < size - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < size; j++)
        {
            compares++;
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        if (i != k)
        {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            exchanges++;
        }
    }
}
void ShellSorting(int* arr, int size, int& compares, int& exchanges)
{
    int count = round(log2(size) - 1);
    int* steps = new int[count];
    int t = count;
    for (int i = 0; t > 0; i++, t--)
    {
        steps[i] = 2 * t - 1;
    }
    int temp, step, j, l;
    for (int numstep = 0; numstep < count; numstep++)
    {
        step = steps[numstep];
        for (int i = step; i < size; i++)
        {
            j = i - step;
            while ((++compares) && (j >= 0) && (arr[i]< arr[j]))
            {
                j = j - step;
            }
            if (j + step != i)
            {
                temp = arr[i];
                l = i - step;
                exchanges++;
                while (l >= j + step)
                {
                    arr[l + step] = arr[l];
                    l -= step;
                    exchanges++;
                }
                arr[j + step] = temp;
                exchanges++;
            }
        }
    }
    exchanges = exchanges / 3;
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
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
            exchanges += 3;
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
void Sito(int* arr, int& compares, int& exchanges, int left, int right)
{
    int i, j, x;
    i = left; j = 2 * left; x = arr[left];
    exchanges++;
    compares++;
    if ((j < right) && arr[j + 1] > arr[j])
    {
        j++;
    }
    while ((j <= right) && (arr[j] > x))
    {
        compares++;
        arr[i] = arr[j];
        exchanges++;
        compares++;
        i = j;
        j *= 2;
        if ((j < right) && (arr[j + 1] > arr[j]))
        {
            j++;
        }
    }
    arr[i] = x;
    exchanges++;
}

void pyramidSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp, left, right;
    left = (size / 2) + 2;
    right = size - 1;
    while (left > 0)
    {
        left--;
        Sito(arr, compares, exchanges, left, right);
    }
    while (right > 0)
    {
        temp = arr[0];
        arr[0] = arr[right];
        arr[right] = temp;
        exchanges += 3;
        right--;
        Sito(arr, compares, exchanges, left, right);
    }
    exchanges = exchanges / 3;
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
        MainArray[i] = 0 + rand() % size;
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
            exchanges = exchanges / 3;
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