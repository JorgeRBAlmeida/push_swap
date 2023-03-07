NAME = ../push_swap

NBRS_TO_SORT:=	3 5 100 500

RM	=	rm -f

all:		compile args $(NBRS_TO_SORT)

compile:
			cd .. && $(MAKE)

args:
			bash arguments.sh

$(NBRS_TO_SORT):	
		@./sorting.sh $@

.PHONY: $(NBRS_TO_SORT)
