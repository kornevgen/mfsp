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

## Лекции и семинары

1. Блок-схемы, определение частичной
   и полной корректности
   [(слайды)](slides/basics/basics.pdf)
   [(упражнения)](exercises/x1.md)

2. Метод индуктивных утверждений
   [(слайды)](slides/floyd_partial/floyd_partial.pdf)
   [(упражнения)](exercises/x2.md)

3. Метод фундированных множеств
   [(слайды)](slides/floyd_term/floyd_term.pdf)
   [(упражнения)](exercises/x3.md)

4. Методы Флойда для блок-схем
   с вызовами других блок-схем, рекурсия
   [(слайды)](slides/floyd_calls/floyd_calls.pdf)
   [(упражнения)](exercises/x4.md)

5. Триггеры
   [(слайды)](slides/smt_triggers/smt_triggers.pdf)
   [(упражнения)](exercises/x5.md)

6. Леммы, ghost-блок-схемы,
   auto-active verification
   [(слайды)](slides/smt_lemmas/smt_lemmas.pdf)
   [(упражнения)](exercises/x6.md)

7. WhyML, автоматизация построения
   условий верификации
   [(слайды)](slides/smt_why3ml/smt_why3ml.pdf)
   [(упражнения)](exercises/x7.md)

8. Добавление новых типов и функций.
   [(слайды)](slides/smt_unintfn/smt_unintfn.pdf)
   [(упражнения)](exercises/x8.md)

9. Моделирование массивов
   [(слайды)](slides/jc_array/jc_array.pdf)
   [(упражнения)](exercises/x9.md)

10. Моделирование памяти Си-программы
   [(слайды)](slides/jc_memmodel/jc_memmodel.pdf)
   [(упражнения)](exercises/xA.md)

11. Фрейм функции. Язык спецификации ACSL
   [(слайды)](slides/acsl/acsl.pdf)
   [(упражнения)](exercises/xB.md)

12. Инструмент AstraVer: модель памяти,
   статическое разрешение синонимии указателей
   [(слайды)](slides/astraver1/astraver1.pdf)
   [(упражнения)](exercises/xC.md)

13. Моделирование Java-программ
   [(слайды)](slides/java/java.pdf)

14. Инструмент AstraVer: приведение типов
   указателей, noembed, итоги
   [(слайды)](slides/astraver2/astraver2.pdf)


## Практикум

В практикуме 5 заданий. В каждом обычно 3 подзадания.
У заданий есть дедлайны. После дедлайна решения
по заданию не принимаются. Плагиат приводит к обнулению
баллов за задание.

Задания 1-3 -- это упражнения к лекциям.
Задания 4-5 -- это реализация на языке Си,
формальная спецификация и формальная верификация
реалистичного примера кода.

[Инструкция по установке инструментов для практикума](https://forge.ispras.ru/projects/astraver/wiki)
[Инструкция по установке солвера CVC4 1.7 (автор - Анастасия Богатенкова)](cvc4.md)

Условие               | Дедлайн
--------------------- | -----------
[Задание 1](hw/b1.md) |   10 марта
[Задание 2](hw/b2.md) |   10 апреля
[Задание 3](hw/b3.md) |   10 мая
[Задание 4](hw/b4.md) |   10 мая
[Задание 5](hw/b5.md) |   31 мая

## Оценивание

Итоговая оценка выставляется на основе оценки
за семестр и оценки за экзамен.
Оценка за семестр выставляется
на основе суммы баллов за задания практикума
и за задания контрольных работ.

Баллы за практикум:

Задание   | Оценка
--------- | -----------
Задание 1 | 0-10 баллов
Задание 2 | 0-10 баллов
Задание 3 | 0-10 баллов
Задание 4 | 0-10 баллов
Задание 5 | 0-20 баллов

Каждая контрольная работа
оценивается до 20 баллов.

Оценка за семестр:

Сумма баллов | Оценка
------------ | ------
80-100       | 5
60-79        | 4
40-59        | 3
0-39         | 2


Итоговая оценка:


Оценка    | Семестр 5 | Семестр 4 | Семестр 3 | Семестр 2
--------- | --------- | --------- | --------- | ---------
Экзамен 5 |      5    |      5    |      4    |       3
Экзамен 4 |      5    |      4    |      4    |       3
Экзамен 3 |      4    |      3    |      3    |       3
Экзамен 2 |      3    |      2    |      2    |       2



## Литература

1. [Корныхин Е., Петренко А., Хорошилов А. (2020) Дедуктивная верификация блок-схем](floyd_book/Deductive-Verification-2020.pdf)
1. [Bobot, F., Filliâtre, J., Marché, C. et al. (2015) Let’s verify this with Why3. In: International Journal on Software Tools Technology Transfer 17, 709–727.](https://link.springer.com/article/10.1007/s10009-014-0314-5)
1. [Why3 Documentation, версия 0.88.2](https://web.archive.org/web/20171208230848/http://why3.lri.fr/manual.pdf)
1. [ACSL: ANSI/ISO C Specification Language](https://frama-c.com/download/acsl.pdf)
1. [Claude Marché, Yannick Moy (2018) The Jessie pluginfor Deductive Verification in Frama-C.](http://krakatoa.lri.fr/jessie.pdf)
1. [Hubert T., Marche C. (2007) Separation analysis for deductive verification. In: Heap Analysis and Verification (HAV'07). Braga, Portugal : March, 2007, p.81-93.](https://www.lri.fr/~marche/hubert07hav.pdf)
1. [Mandrykin, M.U., Khoroshilov, A.V. (2015) High-level memory model with low-level pointer cast support for Jessie intermediate language. In: Programming and Computer Software, 41, 197–207.](https://link.springer.com/article/10.1134%2FS0361768815040040)
1. [Grigoriy Volkov, Mikhail Mandrykin, Denis Efremov (2018) Lemma Functions for Frama-C: C Programs as Proofs. In: 2018 Ivannikov ISPRAS Open Conference](https://arxiv.org/abs/1811.05879)
1. [Blanchard A., Loulergue F., Kosmatov N. (2019) Towards Full Proof Automation in Frama-C Using Auto-active Verification. In: Badger J., Rozier K. (eds) NASA Formal Methods. NFM 2019. Lecture Notes in Computer Science, vol 11460. Springer, Cham](https://allan-blanchard.fr/publis/blk_nfm_2019.pdf)
1. [Becker N., Müller P., Summers A.J. (2019) The Axiom Profiler: Understanding and Debugging SMT Quantifier Instantiations. In: Vojnar T., Zhang L. (eds) Tools and Algorithms for the Construction and Analysis of Systems. TACAS 2019. Lecture Notes in Computer Science, vol 11427. Springer, Cham](https://link.springer.com/chapter/10.1007/978-3-030-17462-0_6)
