#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "table.h"
#include <string.h>

#define MENU "Меню:\n1. Заполнить таблицу вручную\n2. Заполнить таблицу случайными данными\n3. Очистить таблицу\n4. Отсортировать\n5. Поиск по ключу\n6. Инвертировать таблицу\n7. Перемешать таблицу\n8. Вывести таблицу\n9. Выход\nВыбор: "

int main() {
    int choice, count;
    bool running = true;
    Table table;
    initializeTable(&table);

    char searchKey[MAX_KEY_LENGTH]; // Перемещаем объявление сюда

    while (running) {
        printf(MENU);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Введите количество записей (<= 10): ");
                scanf("%d", &count);
                while (count > 10) {
                    printf("Введено число больше 10. Введите количество записей (<= 10): ");
                    scanf("%d", &count);
                }
                for (int i = 0; i < count; ++i) {
                    Record record;
                    printf("Введите ключ для записи %d: ", i + 1);
                    scanf("%s", record.key);
                    printf("Введите текст для записи %d: ", i + 1);
                    getchar(); // Добавляем getchar() для очистки буфера ввода
                    fgets(record.text, sizeof(record.text), stdin); // Используем fgets() для считывания строки
                    record.text[strcspn(record.text, "\n")] = '\0'; // Убираем символ новой строки, который добавляется fgets()
                    table.elements[table.size++] = record;
                }
                break;
            case 2:
                printf("Введите количество записей (<= 10): ");
                scanf("%d", &count);
                while (count > 10) {
                    printf("Введено число больше 10. Введите количество записей (<= 10): ");
                    scanf("%d", &count);
                }
                for (int i = 0; i < count; ++i) {
                    Record record;
                    sprintf(record.key, "key%d", i);
                    sprintf(record.text, "Случайный текст %d", i);
                    table.elements[table.size++] = record;
                }
                break;
            case 3:
                if (table.size == 0)
                    printf("Таблица уже пуста.\n");
                else {
                    initializeTable(&table);
                    printf("Таблица очищена.\n");
                }
                break;
            case 4:
                tournamentSort(&table);
                printf("Таблица отсортирована.\n");
                break;
            case 5:
                printf("Введите ключ для поиска: ");
                getchar(); // Очистка буфера ввода
                fgets(searchKey, sizeof(searchKey), stdin); // Ввод ключа с пробелами
                searchKey[strcspn(searchKey, "\n")] = '\0'; // Убираем символ новой строки, который добавляется fgets()

                printf("Результаты поиска:\n");
                for (int i = 0; i < table.size; ++i) {
                    if (strstr(table.elements[i].key, searchKey) != NULL) {
                        printf("Запись найдена по индексу %d: %s\n", i, table.elements[i].text);
                    }
                }
                break;
            case 6:
                for (int i = 0; i < table.size / 2; ++i) {
                    Record temp = table.elements[i];
                    table.elements[i] = table.elements[table.size - 1 - i];
                    table.elements[table.size - 1 - i] = temp;
                }
                printf("Таблица инвертирована.\n");
                break;
            case 7:
                for (int i = 0; i < table.size; ++i) {
                    int randomIndex = rand() % table.size;
                    Record temp = table.elements[i];
                    table.elements[i] = table.elements[randomIndex];
                    table.elements[randomIndex] = temp;
                }
                printf("Таблица перемешана.\n");
                break;
            case 8:
                printf("Таблица:\n");
                printTable(&table);
                break;
            case 9:
                running = false;
                break;
            default:
                printf("Неизвестная команда.\n");
        }
    }
    return 0;
}

