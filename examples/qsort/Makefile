step1:
	frama-c -av qsort_4.c

step2:
	frama-c -av qsort_5_1.c

step3:
	frama-c -av qsort_5_1.c permut_min_theorems.h -av-file-name qsort_5_1_proof

step4:
	frama-c -av qsort_5_2.c permut_min_theorems.h -av-file-name qsort_5_2

step5:
	frama-c -av qsort_7.c permut_min_theorems.h -av-file-name qsort_7

step6:
	frama-c -av qsort_9.c permut_min_theorems.h -av-file-name qsort_9

step7:
	frama-c -av part_10.c permut_min_theorems.h -av-file-name part_10

