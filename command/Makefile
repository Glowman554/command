OBJDIR = ../lib
BUILDDIR = ../bin

OUTPUT = libcommand.a

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CPPSRC = $(call rwildcard,./,*.c)
OBJS = $(patsubst %.c, $(OBJDIR)/%_$(OUTPUT).o, $(CPPSRC))


CFLAGS = -mno-red-zone -ffreestanding -fpic -g -Iinclude
LDFLAGS = -r

CC = gcc
LD = ld
AR = ar

$(OUTPUT): $(OBJS)
	@echo LD $^
	@$(LD) $(LDFLAGS) -o $(BUILDDIR)/$@.o $^
	@echo AR $(BUILDDIR)/$@.o
	@$(AR) rcs $(BUILDDIR)/$@ $(BUILDDIR)/$@.o

$(OBJDIR)/%_$(OUTPUT).o: %.c
	@echo "CC $^ -> $@"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: build