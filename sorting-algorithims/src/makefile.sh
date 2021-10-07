$(dst)/sorting: Sorting.c
	gcc -o $@ Sorting.c

$(dst)/%: %.c
	gcc $< -o $@
