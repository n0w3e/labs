# Отчет по лабораторной работе № 6
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Степанов Никита Евгеньевич

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Констурирование диаграмм Тьюринга.
2. **Цель работы**: Реализовать задачу в диаграмме Тьюринга.
3. **Заданиe**: №20 - Вычисление двоичного логического сдвига первого числа вправо на число разрядов, равное второму.
4. **Идея, метод, алгоритм решения задачи**: Сначала копируем 2 числа направо. Уменьшаем второе число на 1 и делаем сдвиг левого числа на 1.
5. **Сценарий выполнения работы**:  
	1. Копируем два числа.
	2. Переходим в конец второго числа.
	3. Вычитаем из второго числа 1 переходим к первому числу и постепенно сдвигаем каждую цифру направо.
    4. После того как дошли до начала первого числа, заменяем первую цифру на 0
    5. Повторяем шаги 2-4 до тех пор, пока второе число не будет полностью состоять из нулей.
    6. Если второе число полностью состоит из нулей, стираем их и завершаем программу.

    |  Входные данные | Выходные данные |
    |-----------------|-----------------|
    |    111011 101   |       000001    |
    |  11101011 100   |     00001110    |
    |      110  1     |          011    |

6. **Протокол**: [Программа](https://github.com/n0w3e/labs/blob/main/lab4/MyProject.jdtp)
7. **Замечания автора** -
8. **Выводы**: Диаграмма Тьюринга позволяет решать сложные задачи и моделировать различные вычисления. Она является важным инструментом для разработки алгоритмов и решения различных задач.