#include <iostream>

using namespace std;


#include "structures.h"
#include "constants.h"
#include "file_reader.h"
#include "filter.h"
#include "sort.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №9. Телефонные разговоры\n";
    cout << "Автор: Орех Игорь\n";
    cout << "Группа: 23ПИ1д\n";
    tell_subscribe* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size); 

        printArray(subscriptions, size);

        int n, nn;     
        cout << "\nВыберите сортировку:\n";
        cout << "1)Пирамидальная сортировка (Heap sort)\n2)Быстрая сортировка(Quick sort)\n";

        cin >> nn;

        cout << "\nВыберите критерий сортировки:\n";
        cout << "1)По убыванию продолжительности разговора\n2)По возрастанию номера телефона, а в рамках одного номера по убыванию стоимости разговора\n";

        cin >> n;

        bool (*check_arr)(tell_subscribe * el1, tell_subscribe * el2);
        switch (n) {
        case 1:
            check_arr = _by_duration_desc;
            break;
        case 2:
            check_arr = _by_phone_asc_and_cost_desc;
            break;
        default:
            check_arr = _by_duration_desc;
        }

        switch (nn) {
        case 1:
            heapSort(subscriptions, size, *check_arr);
            break;
        case 2:
            qsort(subscriptions, 0, size, *check_arr);
            break;
        }

        printArray(subscriptions, size);

        cout << "\nВыберите функцию для фильтрации:\n";
        cout << "1)Вывести все телефонные разговоры на мобильные телефоны.\n2)Вывести все телефонные разговоры в ноябре 2021 года.\n";
        cin >> n;

        switch (n) {
        case 1:
        {
            bool (*check)(tell_subscribe * element) = areMobile;
            int result_size;
            tell_subscribe** out = filter(subscriptions, size, check, result_size);
            printArray(out, result_size);
            break;
        }
        case 2:
        {
            bool (*check)(tell_subscribe * element) = isNovember2021;
            int result_size;
            tell_subscribe** out = filter(subscriptions, size, check, result_size);
            printArray(out, result_size);
            break;
        }
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
