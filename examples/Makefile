OBJDIR = ../lib
BUILDDIR = ../bin

build:
	@echo "Building linux"
	@make -C linux

setup:
	@mkdir $(BUILDDIR)
	@mkdir $(OBJDIR)

clean:
	@rm -r $(BUILDDIR)
	@rm -r $(OBJDIR)
	@mkdir $(BUILDDIR)
	@mkdir $(OBJDIR)

.PHONY: build