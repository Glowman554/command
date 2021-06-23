OBJDIR = lib
BUILDDIR = bin

build:
	@echo "Building command"
	@make -C command

	@echo "Building examples"
	@make -C examples

setup:
	@mkdir $(BUILDDIR)
	@mkdir $(OBJDIR)

clean:
	@rm -r $(BUILDDIR)
	@rm -r $(OBJDIR)
	@mkdir $(BUILDDIR)
	@mkdir $(OBJDIR)

test: build
	$(BUILDDIR)/linux.elf

.PHONY: build