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

1. Блок-схемы, определение частичной и полной корректности
1. Метод индуктивных утверждений
1. Метод фундированных множеств
1. Спецификация функции на языке Си на языке ACSL
1. Модель памяти инструмента AstraVer
1. Спецификация и верификация программы на языке Си из нескольких функций
1. Auto-active verification
1. Другие формальные методы разработки программ

## Литература

1. [Корныхин Е., Петренко А., Хорошилов А. (2020) Дедуктивная верификация блок-схем](floyd_book/Deductive-Verification-2020.pdf)
1. [Bobot, F., Filliâtre, J., Marché, C. et al. (2015) Let’s verify this with Why3. In: International Journal on Software Tools Technology Transfer 17, 709–727.](https://link.springer.com/article/10.1007/s10009-014-0314-5)
1. [ACSL: ANSI/ISO C Specification Language](https://frama-c.com/download/acsl.pdf)
1. [Claude Marché, Yannick Moy (2018) The Jessie pluginfor Deductive Verification in Frama-C.](http://krakatoa.lri.fr/jessie.pdf)
1. [Hubert T., Marche C. (2007) Separation analysis for deductive verification. In: Heap Analysis and Verification (HAV'07). Braga, Portugal : March, 2007, p.81-93.](https://www.lri.fr/~marche/hubert07hav.pdf)
1. [Mandrykin, M.U., Khoroshilov, A.V. (2015) High-level memory model with low-level pointer cast support for Jessie intermediate language. In: Programming and Computer Software, 41, 197–207.](https://link.springer.com/article/10.1134%2FS0361768815040040)
1. [Grigoriy Volkov, Mikhail Mandrykin, Denis Efremov (2018) Lemma Functions for Frama-C: C Programs as Proofs. In: 2018 Ivannikov ISPRAS Open Conference](https://arxiv.org/abs/1811.05879)
1. [Blanchard A., Loulergue F., Kosmatov N. (2019) Towards Full Proof Automation in Frama-C Using Auto-active Verification. In: Badger J., Rozier K. (eds) NASA Formal Methods. NFM 2019. Lecture Notes in Computer Science, vol 11460. Springer, Cham](https://allan-blanchard.fr/publis/blk_nfm_2019.pdf)

## Практикум

* [Инструкция по установке инструментов Frama-C, Why3, AstraVer](https://forge.ispras.ru/projects/astraver/wiki)
* [Домашние задания](hw/statement.md)
* [Практическое задание](project/statement.md)
