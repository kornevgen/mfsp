# this makefile was automatically generated; do not edit 

TIMEOUT ?= 10

WHYLIB ?= /home/kornevgen/.opam/4.07.1/lib/astraver

USERWHYTHREEOPT=

JESSIE3CONF ?= $(WHYLIB)/why3/why3.conf

why3ml: qsort_5_1.mlw
	 why3 $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

why3ide: qsort_5_1.mlw
	 why3 ide $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

why3replay: qsort_5_1.mlw
	 why3 replay $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

why3autoreplay: qsort_5_1.mlw
	 why3 replay -q -f --obsolete-only $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

why3typecheck: qsort_5_1.mlw
	 why3 prove --type-only $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

why3prove: qsort_5_1.mlw
	 why3 prove $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

why3sprove: qsort_5_1.mlw
	 why3 sprove -S 'Auto level 1' $(USERWHYTHREEOPT) --extra-config $(JESSIE3CONF) $<

