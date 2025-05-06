#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"

using namespace std;

/// <summary> Структура города. </summary>
struct City
{
    string name;
    string region;
    int population;

    bool operator==(const City& other) const
    {
        return name == other.name &&
            region == other.region &&
            population == other.population;
    }
};

/// <summary> Ввод данных города с консоли. </summary>
City InputCity()
{
    City city;
    cout << "Название города: ";
    getline(cin, city.name);  

    cout << "Регион: ";
    getline(cin, city.region);

    cout << "Население: ";
    cin >> city.population;
   

    return city;
}

/// <summary> Вывод одного города. </summary>
void PrintCity(const City& city)
{
    cout << "Город: " << city.name
        << " | Регион: " << city.region
        << " | Население: " << city.population << endl;
}

/// <summary> Показать все города. </summary>
void ShowAllCities(const List<City>& cities)
{
    if (cities.count() == 0)
    {
        cout << "Список городов пуст." << endl;
        return;
    }

    for (int i = 0; i < cities.count(); ++i)
        PrintCity(cities[i]);
}

/// <summary> Меню. </summary>
void ShowMenu()
{
    cout << endl;
    cout << "+------------------------+" << endl;
    cout << "|         М Е Н Ю        |" << endl;
    cout << "+------------------------+" << endl;
    cout << "| 1. Добавить город      |" << endl;
    cout << "| 2. Вставить по индексу |" << endl;
    cout << "| 3. Удалить по индексу  |" << endl;
    cout << "| 4. Показать все города |" << endl;
    cout << "| 5. Кол-во городов      |" << endl;
    cout << "| 6. Вхождения по имени  |" << endl;
    cout << "| 7. Удалить по региону  |" << endl;
    cout << "| 8. Сорт. по регионам   |" << endl;
    cout << "| 9. Очистить список     |" << endl;
    cout << "| 0. Выход               |" << endl;
    cout << "+------------------------+" << endl;
    cout << "Выбор: ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List<City> cities;

    while (true)
    {
        ShowMenu();

        int option;
        cin >> option;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // важно!

        switch (option)
        {
        case 1:
            cities.add(InputCity());
            break;

        case 2:
        {
            int index;
            cout << "Индекс: ";
            cin >> index;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            try {
                cities.insert(index, InputCity());
            }
            catch (const exception& ex) {
                cout << "Ошибка: " << ex.what() << endl;
            }
            break;
        }

        case 3:
        {
            int index;
            cout << "Индекс для удаления: ";
            cin >> index;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            try {
                cities.removeAt(index);
                cout << "Удалено." << endl;
            }
            catch (const exception& ex) {
                cout << "Ошибка: " << ex.what() << endl;
            }
            break;
        }

        case 4:
            ShowAllCities(cities);
            break;

        case 5:
            cout << "Текущее количество городов: " << cities.count() << endl;
            break;

        case 6:
        {
            string name;
            cout << "Введите название города: ";
            getline(cin, name);
            int count = 0;
            for (int i = 0; i < cities.count(); ++i)
                if (cities[i].name == name)
                    ++count;
            cout << "Вхождений с названием \"" << name << "\": " << count << endl;
            break;
        }

        case 7:
        {
            string region;
            cout << "Введите регион: ";
            getline(cin, region);
            for (int i = 0; i < cities.count(); )
            {
                if (cities[i].region == region)
                    cities.removeAt(i);
                else
                    ++i;
            }
            cout << "Удалены все города из региона: " << region << endl;
            break;
        }

        case 8:
        {
            const int MAX = 100;
            string regions[MAX];
            int populations[MAX];
            int regionCount = 0;

            for (int i = 0; i < cities.count(); ++i)
            {
                const string& currentRegion = cities[i].region;
                int j = 0;
                for (; j < regionCount; ++j)
                {
                    if (regions[j] == currentRegion)
                    {
                        populations[j] += cities[i].population;
                        break;
                    }
                }
                if (j == regionCount && regionCount < MAX)
                {
                    regions[regionCount] = currentRegion;
                    populations[regionCount] = cities[i].population;
                    ++regionCount;
                }
            }

            for (int i = 0; i < regionCount - 1; ++i)
            {
                for (int j = 0; j < regionCount - i - 1; ++j)
                {
                    if (populations[j] < populations[j + 1])
                    {
                        swap(populations[j], populations[j + 1]);
                        swap(regions[j], regions[j + 1]);
                    }
                }
            }

            cout << "Регионы по убыванию численности:" << endl;
            for (int i = 0; i < regionCount; ++i)
                cout << regions[i] << " — " << populations[i] << endl;
            break;
        }

        case 9:
            cities.clear();
            cout << "Список очищен." << endl;
            break;

        case 0:
            cout << "Выход..." << endl;
            return 0;

        default:
            cout << "Неверный выбор!" << endl;
        }
    }
}
