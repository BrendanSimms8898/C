$(dst)/%: %.c
	gcc $< -o $@