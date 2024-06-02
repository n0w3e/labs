# Отчет по лабораторной работе № 26
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Степанов Никита Евгеньевич

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Абстрактные типы данных. Рекурсия.
2. **Цель работы**: Составить и отладить модуль определений и реализаций для абстрактного типа данных(стек, очереди, списка или дека)
3. **Задание**: 1-3
4. **Идея, метод, алгоритм решения задачи**: Использовать быструю сортировку Хоара для сортировки стека, а затем инвертировать порядок элементов стека для получения возрастающей сортировки.
5. **Сценарий выполнения работы**: 
    - Создать структуру *Stack* и определить функции для работы с ним в заголовочном файле
    - Реализовать функции структуры стека, включая алгоритмы быстрой сортировки Хоара (*partition* и *quickSort*)
    - Создать главный файл, где будет проведено тестирование функций структуры стека
    - Проверить результаты сортировки и отсутствие утечек памяти с помощью *Valgrind*
6. **Протокол**: -
7. **Замечания автора** -
8. **Выводы**: Изучение структур данных, таких как стек, и алгоритмов сортировки, включая быструю сортировку Хоара, дало мне понимание их роли в программировании. Разработка этой программы стала интересным опытом изучения рекурсии и работы с динамической памятью в языке Си. Кроме того, я овладел организацией кода, разбиением его на модули и применением принципов модульного программирования. Этот опыт поможет мне создавать более структурированный и поддерживаемый код в будущих проектах.