# --------------------------------------------------------------------------
# VERBOSE Compile Information 

ifdef VERBOSE
        VERBOSE = true
        VERBOSE_ECHO = @ echo
        VERBOSE_SHOW =
        QUIET_ECHO = @ echo > /dev/null
else
        VERBOSE = false
        VERBOSE_ECHO = @ echo > /dev/null
        VERBOSE_SHOW = @
        QUIET_ECHO = @ echo
endif

# --------------------------------------------------------------------------
# BUILD directory

BUILD := build

# --------------------------------------------------------------------------
# These CFLAGS assume a GNU compiler.  For other compilers, write a script
# which converts these arguments into their equivalent for that particular
# compiler.
CC = g++ #Need define CC to use with scan-build(it works by substituting CC)
CFLAGS = -std=c99
CFLAGS += -g
CFLAGS += -W -Wall

# --------------------------------------------------------------------------
# Default targets are everything

.PHONY: all
all: test

# --------------------------------------------------------------------------
# Compile target patterns
$(BUILD)/obj/%.o: src/%.c
	$(QUIET_ECHO) $@: Compiling object
	@ mkdir -p $(dir $(BUILD)/dep/$<)
	@ $(CC) $(CFLAGS) -M -MG -MQ $@ -DCOMPILINGDEPENDENCIES \
        -o $(BUILD)/dep/$(<:%.c=%.d) -c $<
	@ mkdir -p $(dir $@)
	$(VERBOSE_SHOW) $(CC) $(CFLAGS) -o $@ -c $<

# --------------------------------------------------------------------------
# test targets

.PHONY: test
test: $(BUILD)/bin/test
TEST_OBJS = $(BUILD)/obj/arr.o \
			   $(BUILD)/obj/dcl.o \
			   $(BUILD)/obj/exp.o \
			   $(BUILD)/obj/mem.o \
			   $(BUILD)/obj/msc.o \
			   $(BUILD)/obj/main.o

$(BUILD)/bin/test: $(TEST_OBJS)
	$(QUIET_ECHO) $@: Building executable
	@ mkdir -p $(dir $@)
	$(VERBOSE_SHOW) gcc -o $@ $^ 

# --------------------------------------------------------------------------
# Clean target

.PHONY: clean
clean:
	$(QUIET_ECHO) $(BUILD): Cleaning
	$(VERBOSE_SHOW) rm -rf $(BUILD)
