# Формальная верификация Си программ

## О курсе

Формальная верификация — это процесс
доказательства того, что некоторая
программа выполняет все требования,
записанные в ее формальной
спецификации. В результате освоения
этого курса слушатель сможет
записывать требования к Си-программам
на языке формальной спецификации ACSL
и верифицировать Си-программы
небольшого и среднего размера
методами дедуктивной (или, по-другому,
аналитической) верификации при помощи
инструментов AstraVer, Why3 и ряда
современных солверов (Alt-Ergo, CVC4,
Z3).

## План курса

Курс состоит из цикла лекций,
семинаров, практикума и экзамена.
Далее приведена программа лекций
и учебные материалы к лекциям.

1. Блок-схемы, определение частичной
   и полной корректности
   [(слайды)](slides/basics/basics.pdf)
   [(упражнения)](exercises/x1.md)

1. Метод индуктивных утверждений
   [(слайды)](slides/floyd_partial/floyd_partial.pdf)
   [(упражнения)](exercises/x2.md)

1. Метод фундированных множеств
   [(слайды)](slides/floyd_term/floyd_term.pdf)
   [(упражнения)](exercises/x3.md)

1. Дедуктивная верификация программ
   из нескольких блок-схем, рекурсия

1. Эффективное использование SMT-солверов

1. Методы дополнительной спецификации
   кода для эффективной дедуктивной
   верификации при помощи SMT-солверов

1. Модель памяти component-as-array 

1. Разделение на регионы памяти и
   другие методы повышения эффективности
   дедуктивной верификации программ,
   оперирующих с памятью

1. Спецификация функции на языке Си
   на языке ACSL
   [(слайды)](slides/intro_acsl/intro_acsl.pdf)
   [(упражнения)](exercises/x4.md)

1. Модель памяти инструмента AstraVer
   [(слайды)](slides/memory_acsl/memory_acsl.pdf)
   [(упражнения)](exercises/x5.md)

1. Спецификация и верификация программы
   на языке Си из нескольких функций
   [(слайды)](slides/modules_acsl/modules_acsl.pdf)

1. Auto-active verification
   [(слайды)](slides/proof_methods/proof_methods.pdf)


Практикум включает самостоятельные
задания по следующим блокам:


1. Дедуктивная верификация: 
   одиночные блок-схемы, переменные
   только целочисленные

2. Дедуктивная верификация:
   более сложные типы данных, более
   сложные блок-схемы
 
3. Дедуктивная верификация:
   программы с памятью

4. Реализация и формальная спецификация
   реалистичного примера на языке Си

5. Дедуктивная верификация
   реалистичного примера на языке Си


У заданий есть сроки выполнения и требования к
оформлению. Условия заданий и сервер сдачи
[находятся по этой ссылке](https://ejudge.cs.msu.ru/ej/client?contest_id=156).


## Оценивание

Оценка выставляется на основе оценки
за практиум и оценки за экзамен.
Оценка за практикум выставляется
на основе суммы баллов за задания.

Баллы за практикум:

Задание   | Оценка
--------- | -----------
Задание 1 | 0-10 баллов
Задание 2 | 0-20 баллов
Задание 3 | 0-20 баллов
Задание 4 | 0-20 баллов
Задание 5 | 0-30 баллов


После дедлайна задание не принимается.


Оценка за практикум:


Сумма баллов | Оценка
------------ | ------
80-100       | 5
60-79        | 4
40-59        | 3
0-39         | 2


Итоговая оценка:


Оценка    | Практикум 5 | Практикум 4 | Практикум 3 | Практикум 2
--------- | ----------- | ----------- | ----------- | -----------
Экзамен 5 |      5      |      5      |      4      |       3
Экзамен 4 |      5      |      4      |      4      |       3
Экзамен 3 |      4      |      3      |      3      |       3
Экзамен 2 |      3      |      2      |      2      |       2



## Литература

1. [Корныхин Е., Петренко А., Хорошилов А. (2020) Дедуктивная верификация блок-схем](floyd_book/Deductive-Verification-2020.pdf)
1. [Bobot, F., Filliâtre, J., Marché, C. et al. (2015) Let’s verify this with Why3. In: International Journal on Software Tools Technology Transfer 17, 709–727.](https://link.springer.com/article/10.1007/s10009-014-0314-5)
1. [ACSL: ANSI/ISO C Specification Language](https://frama-c.com/download/acsl.pdf)
1. [Claude Marché, Yannick Moy (2018) The Jessie pluginfor Deductive Verification in Frama-C.](http://krakatoa.lri.fr/jessie.pdf)
1. [Hubert T., Marche C. (2007) Separation analysis for deductive verification. In: Heap Analysis and Verification (HAV'07). Braga, Portugal : March, 2007, p.81-93.](https://www.lri.fr/~marche/hubert07hav.pdf)
1. [Mandrykin, M.U., Khoroshilov, A.V. (2015) High-level memory model with low-level pointer cast support for Jessie intermediate language. In: Programming and Computer Software, 41, 197–207.](https://link.springer.com/article/10.1134%2FS0361768815040040)
1. [Grigoriy Volkov, Mikhail Mandrykin, Denis Efremov (2018) Lemma Functions for Frama-C: C Programs as Proofs. In: 2018 Ivannikov ISPRAS Open Conference](https://arxiv.org/abs/1811.05879)
1. [Blanchard A., Loulergue F., Kosmatov N. (2019) Towards Full Proof Automation in Frama-C Using Auto-active Verification. In: Badger J., Rozier K. (eds) NASA Formal Methods. NFM 2019. Lecture Notes in Computer Science, vol 11460. Springer, Cham](https://allan-blanchard.fr/publis/blk_nfm_2019.pdf)
1. [Becker N., Müller P., Summers A.J. (2019) The Axiom Profiler: Understanding and Debugging SMT Quantifier Instantiations. In: Vojnar T., Zhang L. (eds) Tools and Algorithms for the Construction and Analysis of Systems. TACAS 2019. Lecture Notes in Computer Science, vol 11427. Springer, Cham](https://link.springer.com/chapter/10.1007/978-3-030-17462-0_6)

## Старый Практикум

* [Инструкция по установке инструментов Frama-C, Why3, AstraVer](https://forge.ispras.ru/projects/astraver/wiki)
* [Домашние задания](hw/statement.md)
* [Практическое задание](project/statement.md)
