---
title: Спецификация и верификация реалистичного примера кода
---

Цель задания - отработать навыки разработки кода на языке Си с повышенными требованиями к качеству кода. В рамках разработки используются такие техники, как статический и динамический анализ кода, модульное тестирование, формальная спецификация, дедуктивная верификация. Требуется реализовать небольшой программный модуль на языке Си согласно варианту задания и доказать отсутствие в нем ошибок времени исполнения и доказать выполнение функциональных требований. Задание состоит из нескольких этапов. На первом этапе пишется реализация модуля. На втором этапе применяется статический и динамический анализ кода, а также модульное тестирование. На третьем этапе формально записываются функциональные требования. На последних этапах используется дедуктивная верификация.

## Типы данных и варианты задания (файл maptypes.h)

Исходный код заголовочного файла: [maptypes.h](maptypes.h).

Вам дано определение структуры данных `Map` для хранения отображений
элементов типа `Key` в элементы типа `Value` (ассоциативный массив).
Структура может хранить лишь единственное отображение для конкретного
ключа. Отображение представляется типом `Item`. Его поле `existent` может
быть истиной (то есть равняться единице) или ложью (то есть равняться нулю).

```c
typedef struct {
    int a;
    int b;
} Key;

typedef struct {
    int c;
    int d;
} Value;

typedef struct {
    Key key __attribute__((noembed));
    Value value;
    int existent;
} Item;

typedef struct {
    Item *items;
    int capacity;
    int count;
} Map;
```

Поле `items` структуры `Map` представляет собой массив длины `capacity`. Поле
`count` этой структуры определяет, сколько элементов данного массива
имеет поле `existent` установленным в истину (единицу). При работе со
структурой учитываются те и только те записи массива `items`,
которые имеют булево поле `existent` установленным в истину (единицу).

Никакие операции над структурой данных не должны приводить ее в такое
состояние, чтобы после этого добавление одного отображения увеличило
количество отображений более, чем на 1. Иными словами, в структуре данных,
все `existent` элементы массива должны означать отображения из хэш-таблицы. 

> **Вариант А:** Отображения хранятся как последовательность пар
> ключ-значение в массиве `items`, возможно с некоторыми пропусками между ними
> (у пропусков поле `existent` установлено в ложь). Элементы хранятся с начала массива. При
> этом за двумя последовательно идущими элементами, у
> которых `existent` установлен в ложь, остальные элементы тоже имеют
> `existent` установленным в ложь.

> **Вариант B:** Отображения хранятся в хэш-таблице, представленной
> массивом `items`. Используется хэш-функция `hash()`. Используется линейное
> пробирование, то есть для доступа к информации о паре для заданного
> ключа `key` поиск начинается c элемента массива `items` по индексу
> `(hash(key) % capacity)` и идёт последовательным увеличением индекса на
> единицу по модулю `capacity`. Если очередной элемент имеет поле
> `existent` установленным в ложь или пройден полный круг, а элемент
> соответствующий заданному `key` ключу не встречен, то считается, что
> такой ключ не содержится в данном ассоциативном массиве.
> Определение `hash`:

    hash(k) = |k.a * 33 + k.b|

## Операции над отображениями (файл map.h)

Исходный код заголовочного файла: [map.h](map.h).

Функция `initializeMap()` создаёт пустой ассоциативный массив с
заданным числом максимально хранимых элементов `size`, выделяя под него
динамическую память. На вход функции должен подаваться указатель на
переменную-структуру, функция должна проинициализировать эту структуру.
В случае неуспеха, функция должна вернуть ненулевое число, иначе
функция должна вернуть 0.
Сигнатура функции:

    int initializeMap(Map *map, int size);

Функция `finalizeMap()` освобождает динамическую память, используемую для ассоциативного массива `map`. На вход функции должен подаваться указатель на 
область памяти, проинициализированную функцией `initializeMap()`.
Сигнатура функции:

    void finalizeMap(Map *map);

Функция `addElement()` добавляет в заданный ассоциативный массив `map`
отображение заданного ключа `key` на заданное значение `value` и возвращает истину
(единицу), если в нём было место для этого отображения. Если в ассоциативном массиве
было недостаточно места, функция возвращает ложь (ноль). Функция не меняет
переданные ключ и значение. Функция не добавляет и не удаляет
другие отображения, кроме отображения по заданному ключу, если оно было.
Функция имеет право изменять структуру ассоциативного
массива, если это не отражается на содержащихся в нём парах. Ничего
другого функция не делает.
Сигнатура функции:

    int addElement(Map *map, Key *key, Value *value);

Функция `removeElement()` удаляет сохранённое в ассоциативном массиве `map`
значение по заданному ключу `key` (если оно там было). Функция не удаляет
другие отображения, кроме отображения по заданному ключу, а также не
добавляет новые отображения. Функция возвращает истину (единицу), если
функция изменила ассоциативный массив, ложь (ноль) в противном случае.
В случае, если значение было удалено и при этом переданный указатель
`value` был отличен от нулевого, функция записывает значение,
содержавшееся для заданного ключа, по данному указателю. Функция имеет
право изменять структуру ассоциативного массива, если это не
отражается на содержащихся в нём парах. Ничего другого функция не
делает.
Сигнатура функции:

    int removeElement(Map *map, Key *key, Value *value);

Функция `getElement()` возвращает по указателю `value` сохранённое в ассоциативном массиве `map`
значение для заданного ключа `key` и возвращает истину (единицу), если
заданный ассоциативный массив имеет отображения для заданного ключа. В
случае, если значение по заданному ключу не содержится в отображении, возвращается
ложь (ноль) и ничего другого не происходит. Функция не меняет ассоциативный массив и
переданный ключ. Ничего другого функция не делает.
Сигнатура функции:

    int getElement(Map *map, Key *key, Value *value);


## Этап 1 - реализация

Реализуйте на языке Си модуль со всеми описанными функциями.
Эта реализация будет в дальнейшем верифицироваться инструментами
`Frama-C`, `AstraVer` (а они не поддерживают некоторые возможности языка Си).

## Этап 2 - анализ кода и тестирование

Найдите и исправьте как можно больше ошибок в исходном коде модуля.
Используйте статические и динамические анализаторы кода, фаззеры,
санитайзеры и др., модульное тестирование, измерение тестового покрытия.
Выбор инструментов остается на ваше усмотрение.
Чем больше ошибок будет исправлено на этом этапе, тем быстрее вы выполните последние этапы задания.

Подготовьте отчет с описанием реализации, выбранных инструментов,
описанием их применения и достигнутых результатов.

## Этап 3 - формальная спецификация

Напишите спецификацию на языке ACSL для данных структур данных
и только для данного вам подмножества функций
(его нужно получить у преподавателя после сдачи предыдущего этапа).

Продемонстририруйте полноту спецификации в
обе стороны (то есть, что любая реализация, удовлетворяющая вашей
формальной спецификации, будет удовлетворять этим требованиям, и наоборот).
Это можно сделать трассировкой (установлением соответствия) частей
требований на части спецификации и в обратную сторону (то есть спецификация
содержит все требования и не утверждает того, что не утверждают требования).

Этап разбивается на два подэтапа:

- формальная спецификация требований к типам данных;

- формальная спецификация требований к функциям.

Требования к типам данных применимы ко всему коду, который использует эти
типы данных. То есть могут быть функции создания, удаления `Map *`, отличные от тех, которые приведены в этом задании. И к полученным `Map` должны быть применимы и правильно работать функции добавления и удаления, приведенные здесь.

Требования к функциям применимы ко всем возможным их реализациям, а не
только к вашей реализации.

## Этап 4 - доказательство safety

Докажите все условия safety, сгенерированные инструментами
Frama-C+AstraVer+Why3, для специфицированных функций. Обнаруженные ошибки
нужно исправить.

## Этап 5 - доказательство behaviors

Докажите все условия behaviors, сгенерированные инструментами
Frama-C+AstraVer+Why3, для специфицированных функций. Обнаруженные ошибки
нужно исправить.

Подготовьте итоговый отчет с описанием проведенных работ, обоснованными
выводами о применяемых техниках и инструментах.
