$(dst)/%: %.c
	gcc $< -o $@
