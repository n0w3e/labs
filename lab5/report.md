# Отчет по лабораторной работе № 5
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Степанов Никита Евгеньевич

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Программирование машин Тьюринга
2. **Цель работы**: Запрограммировать задачу на Машине Тьюринга.
3. **Заданиe**: №6 Генерация двух чисел из чётных и нечетных разрядов двоичного числа.
4. **Идея, метод, алгоритм решения задачи**: Сначала копируем числа из нечетных разрядов, потом переходим в начало и копируем числа из четных разрядов.
5. **Сценарий выполнения работы**: 
	1. Перемещаемся до конца влево, пока не встретим самый левый пробел, идем вправо на 1. 
        2. Пропускаем цифру и переходим к следующей.
        3. Заменяем цифру на пробел, запоминаем и перемещаем через всё число.
        4. Находим пробел идем направо, если там ничего нет, то заменяем его на цифру которую запомнили, если есть, то проходим через все число, находим пробел и заменяем его на цифру которую запомнили.
        5. Идем обратно и ищем 2-ой пробел.
        6. Заменяем пробел на цифру которую уже поставили.
        7. Повторяем шаги 2 - 6 до тех пор, пока последний символ изначального числа не будет пробелом.
        8. Если последний символ - пробел, то возвращаемся к первому пробелу и начинаем генерацию второго числа.
        9. Берем первую цифру, заменяем на пробел, запоминаем, проходим через изначальное число, потом через первое число сгенерированное из четных разрядов.
        10. Если нашелся пробел, то идем направо, если там ничего нет, то заменяем пробел на цифру которую запомнили, если есть, то проходим через все число, находим пробел и заменяем его на цифру которую запомнили.
        11. Возвращаемся обратно и ищем 3-ий пробел.
        12. Заменяем пробел на цифру, пропускаем цифру и повторяем шаги.
        13. Если сгенерировались 2 числа, идем к концу первого числа и делаем проверку на ведущие нули.
        14. Если они есть, то заменяем их на пробелы и смещаем числа влево.

	| Входные данные  | Выходные данные |
	|-----------------|-----------------|
	| 1010101001101   |  10 1111011     |
	| 1110110111      |  10111 11101    |

7. **Протокол**: [Код программы](https://github.com/n0w3e/labs/blob/main/lab3/laba_final.txt)
8. **Замечания автора** -
9. **Выводы**: При написании программы на Машине Тьюринга можно сделать вывод о том, как она будет работать и какие результаты она будет давать. Например, можно сказать, что программа будет выполняться за конечное число шагов или что она будет останавливаться при выполнении определенного условия. 
