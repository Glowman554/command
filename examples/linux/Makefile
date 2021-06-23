OBJDIR = ../../lib
BUILDDIR = ../../bin

OUTPUT = linux.elf

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CPPSRC = $(call rwildcard,./,*.c)
OBJS = $(patsubst %.c, $(OBJDIR)/%_$(OUTPUT).o, $(CPPSRC))


CFLAGS = -mno-red-zone -ffreestanding -fpic -g -Iinclude -I../../command/include
LDFLAGS = -fpic $(BUILDDIR)/libcommand.a

CC = gcc
LD = gcc
AR = ar

$(OUTPUT): $(OBJS)
	@echo LD $^
	@$(LD) $(LDFLAGS) -o $(BUILDDIR)/$@ $^

$(OBJDIR)/%_$(OUTPUT).o: %.c
	@echo "CC $^ -> $@"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: build