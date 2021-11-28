#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
struct Student
{
    char name[255];
    char surname[255];
    int course;
    int year;
    int marks[6];
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int rez = 1;
    int n;
    Student* group = NULL;
    group = new Student[1000];
    while (rez != 0)
    {
        cout << "Меню: \n";
        cout << "0. Выход\n";
        cout << "1. Ввести данные\n";
        cout << "2. Вывод таблицы студентов\n";
        cout << "3. Вывод фамилий, оценок, курса студентов, имена которых начинаются с буквы 'А'\n";
        cout << "4. Добавить нового студента\n";
        cout << "5. Изменить данные\n";
        cout << "6. Удалить данные\n";
        cout << "7. Сортировка\n";
        cout << "8. Загрузка базы данных из текстового файла\n";
        cout << "9. Загрузка базы данных из бинарного файла\n";
        cout << "10. Выгрузка базы данных в текстовый файл\n";
        cout << "11. Перевод содержимого текстового файла в бинарный\n";
        cout << "Выберите действие: ";
        cin >> rez;

        if (rez == 0) exit;	

        if (rez == 1)
        {
            int year, course;
            cout << "Введите количество студентов: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Введите фамилию: ";
                cin >> group[i].surname;
                cout << "Введите имя: ";
                cin >> group[i].name;
                cout << "Введите курс: ";
                do
                {
                    cin >> course;
                    if ((course < 1) || (course > 9))
                        cout << "Введите однозначное число\n";
                } while ((course < 1) || (course > 9));
                group[i].course = course;
                cout << "Введите год поступления: ";
                do
                {
                    cin >> year;
                    if ((year < 1000) || (year > 9999))
                        cout << "Введите четырёхзначное число \n";
                } while ((year < 1000) || (year > 9999));
                group[i].year = year;
                cout << "Введите шесть оценок:\n";
                for (int j = 0; j < 6; j++)
                {
                    cout << "Введите " << j + 1 << " оценку:";
                    cin >> group[i].marks[j];
                }
            }
        }

        if (rez == 2)
        {
            if (group)
            {
                cout << "+---+---------------------+---------------------+----+----+---------+---------+---------+---------+---------+---------+\n";
                cout << "| № |       Фамилия       |         Имя         |Год |Курс|Предмет 1|Предмет 2|Предмет 3|Предмет 4|Предмет 5|Предмет 6|\n";
                cout << "+---+---------------------+---------------------+----+----+---------+---------+---------+---------+---------+---------+\n";
                for (int i = 0; i < n; i++)
                {
                    cout << left << "|" << setw(3) << (i + 1) << "|";
                    cout << left << setw(21) << group[i].surname << "|";
                    cout << left << setw(21) << group[i].name << "|";
                    cout << left << setw(3) << group[i].year << "|";
                    cout << left << setw(4) << group[i].course << "|";
                    for (int j = 0; j < 6; j++)
                    {
                        cout << setw(9) << group[i].marks[j] << "|";
                    }
                    cout << "\n";
                    cout << "+---+---------------------+---------------------+----+----+---------+---------+---------+---------+---------+---------+\n";
                }
            }
            else cout << "Отсутствуют данные для вывода\n";
        }

        if (rez == 3)
        {
            if (group)
            {
                for (int i = 0; i < n; i++)
                {
                    if (group[i].name[0] == 'А')
                    {
                        cout << "Данные " << i + 1 << "-го студента\n";
                        cout << "Фамилия: ";
                        cout << group[i].surname << "\n";
                        cout << "Курс: ";
                        cout << group[i].course << "\n";
                        cout << "Оценки:\n";
                        for (int j = 0; j < 6; j++)
                        {
                            cout << group[i].marks[j] << " ";
                        }
                        cout << "\n";
                    }
                }
            }
            else cout << "Отсутствуют данные для вывода\n";
        }
        if (rez == 4)
        {
            n++;
            int year, course;
                cout << "Введите фамилию: ";
                cin >> group[n-1].surname;
                cout << "Введите имя: ";
                cin >> group[n-1].name;
                cout << "Введите курс: ";
                do
                {
                    cin >> course;
                    if ((course < 1) || (course > 9))
                        cout << "Введите однозначное число!\n";
                } while ((course < 1) || (course > 9));
                group[n-1].course = course;
                cout << "Введите год поступления: ";
                do
                {
                    cin >> year;
                    if ((year < 1000) || (year > 9999))
                        cout << "Введите четырёхзначное число! \n";
                } while ((year < 1000) || (year > 9999));
                group[n-1].year = year;
                cout << "Введите шесть оценок:\n";
                for (int j = 0; j < 6; j++)
                {
                    cout << "Введите " << j + 1 << " оценку:";
                    cin >> group[n-1].marks[j];
                }
        }
        if (rez == 5)
        {
            int z, v = 1;
            cout << "Введите № студента\n";
            cin >> z;
            while (v != 0)
            {
                cout << "0. Выход\n";
                cout << "1. Изменить фамилию\n";
                cout << "2. Изменить имя\n";
                cout << "3. Изменить курс\n";
                cout << "4. Изменить год поступления\n";
                cout << "5. Изменить оценки\n";
                cin >> v;
                if (v == 0) exit;
                if (v == 1)
                {
                    cout << "Введите новую фамилию: ";
                    cin >> group[z - 1].surname;
                }
                if (v == 2)
                {
                    cout << "Введите новое имя: ";
                    cin >> group[z - 1].name;
                }
                if (v == 3)
                {
                    int course;
                    cout << "Введите новый курс: ";
                    do
                    {
                        cin >> course;
                        if ((course < 1) || (course > 9))
                            cout << "Введите однозначное число!\n";
                    } while ((course < 1) || (course > 9));
                    group[z - 1].course = course;
                }
                if (v == 4)
                {
                    int year;
                    cout << "Введите новый год поступления: ";
                    do
                    {
                        cin >> year;
                        if ((year < 1000) || (year > 9999))
                            cout << "Введите четырёхзначное число!\n";
                    } while ((year < 1000) || (year > 9999));
                    group[z - 1].year = year;
                }
                if (v == 5)
                {
                    cout << "Введите новые оценки:\n";
                    for (int j = 0; j < 6; j++)
                    {
                        cout << "Введите " << j + 1 << " оценку:";
                        cin >> group[z - 1].marks[j];
                    }
                }
            }
        }
        if (rez == 6)
        {
            int w;
            cout << "Введите № студента:\n";
            cin >> w;
            if (n != 1)
            {
                for (int i = w - 1; i < n; i++)
                    group[i] = group[i + 1];
                n--;
            }
            else group = NULL;
        }
        if (rez == 7)
        {
            int v2 = 1;
            Student d;
            while (v2 != 0)
            {
                cout << "0. Выход\n";
                cout << "1. Сортировать по фамилии\n";
                cout << "2. Сортировать по имени\n";
                cout << "3. Сортировать по году поступления\n";
                cout << "4. Сортировать по курсу\n";
                cout << "5. Сортировать по всем параметрам\n";
                cin >> v2;
                if (v2 == 0) exit;

                if (v2 == 1)
                {
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n - i - 1; j++)
                            if (group[j].surname[0] > group[j + 1].surname[0])
                            {
                                d = group[j];
                                group[j] = group[j + 1];
                                group[j + 1] = d;
                            }
                }
                if (v2 == 2)
                {
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n - i - 1; j++)
                            if (group[j].name[0] > group[j + 1].name[0])
                            {
                                d = group[j];
                                group[j] = group[j + 1];
                                group[j + 1] = d;
                            }
                }
                if (v2 == 3)
                {
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n - i - 1; j++)
                            if (group[j].year > group[j + 1].year)
                            {
                                d = group[j];
                                group[j] = group[j + 1];
                                group[j + 1] = d;
                            }
                }
                if (v2 == 4)
                {
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n - i - 1; j++)
                            if (group[j].course > group[j + 1].course)
                            {
                                d = group[j];
                                group[j] = group[j + 1];
                                group[j + 1] = d;
                            }
                }
                if (v2 == 5)
                {
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n - i - 1; j++)
                            if ((group[j].name > group[j + 1].name) && (group[j].surname > group[j + 1].surname) && (group[j].course > group[j + 1].course) && (group[j].year > group[j + 1].year))
                            {
                                d = group[j];
                                group[j] = group[j + 1];
                                group[j + 1] = d;
                            }
                }
            }
        }
    }

    delete[] group;		
    system("pause");
}
