# Отчет по лабораторной работе № 7
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Степанов Никита Евгеньевич

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Программирование в алгоритмической модели Маркова.
2. **Цель работы**: Реализовать задачу с помощью алгоритмов Маркова.
3. **Заданиe**: №17 Составить алгоритм вычисления поразрядной конъюкции исходных чисел.
4. **Идея, метод, алгоритм решения задачи**: Сравнение последних цифр первого и второго числа.
5. **Сценарий выполнения работы**:  
    (1) Проходим по первому числу, смотрим последнюю цифру, запоминаем и затираем.
    (2) Проходим по второму числу, сравниваем цифру, которую запомнили, с последней из второго числа, далее ставим соответствующую цифру через пробел.
    (3) Повторяем шаги 1-2 до тех пор, пока не закончится одно из чисел.
    (4) После того как закончилось одно из чисел, заменяем оставшиеся цифры другого числа на 0.
    (5) Убираем лишние пробелы и завершаем программу.

    | Входные данные      | Выходные данные |
    |---------------------|-----------------|
    | 1110101&111         | 0000101         |
    | 1111&11             | 0011            |
    | 00&0                | 00               |


6. **Протокол**: [Правила](https://github.com/n0w3e/labs/blob/main/lab5/rules.txt)
7. **Замечания автора** -
8. **Выводы**: Данная лабораторная работа показалась для меня познавательной и интересной. Алгоритмы Маркова помогли развить мышление, улучшить навыки разработки программного кода, оптимизации алгоритмов и научили правильно строить цепочку процессов исполнения программы.
