APP ?= number_guessing_game
# the path of the source files.
src := number_guessing_game
# the path of the output build directory — the place where the intermediate
# outputs of the compiler are put into.
build := build
# the path of the generated binaries — executable files.
bin := bin
# the path of the application executable.
app := $(bin)/$(APP)

# Searches for .cpp and .c files.
# If there are assembly files, just add "-or -name *.s" 
sources := $(shell find $(src) -name *.cpp -or -name *.c)
objects := $(sources:%=$(build)/%.o)
deps := $(objects:.o=.d)

# Searches for .cpp.o and .c.o files WITHOUT the main function.
# According to the project convention, only files whose name end with
# '.main.cpp' or '.test.cpp' can have main function.
objs_without_main_func := $(filter-out %.main.cpp.o %.test.cpp.o,$(objects))
# the objects that make up the application executable.
app_objs := $(filter %$(APP).cpp.o,$(objects)) $(objs_without_main_func)
deps := $(objects:.o=.d)

MKDIR_P ?= mkdir -p
CXX ?= g++
LIB ?= -lpthread -static-libasan -static-libubsan -static-liblsan
# Warning Options
# Wpedantic: issue all the warnings demanded by strict ISO C and ISO C++.
warnings := -Wall -Wextra -Wpedantic -Wsuggest-override -Wconversion \
-Wsign-conversion -Wuseless-cast -Wshadow -Wvla -Wnull-dereference -Wswitch-enum \
-Wduplicated-cond -Wduplicated-branches -Wimplicit-fallthrough

# Sanitizers improve application security — good to use in debug mode. Make sure
# to specify -fsanitize=undefined,address to BOTH the compile and the link line.
sanitizers := -fsanitize=address,undefined,leak

debug :=  -fno-omit-frame-pointer -fvar-tracking-assignments -rdynamic
override CPPFLAGS += -I. -MMD -D_GLIBCXX_DEBUG
# -D_GLIBCXX_DEBUG => switches out the std lib with a safe one that does bounds
#  checking on everything (even overloaded [] operators)

# it is important to use at least optimization level -O1 because it appears that
# some errors are not detected without optimization. If a stack trace is not
# needed, -g and -fno-omit-frame-pointer can be skipped.
override CXXFLAGS += -std=c++17 -g -O1 $(warnings) $(sanitizers) $(debug)

.PHONY: all

# Application's executable rule.
# 
# Notice that both the compilation and linking steps require the contents of the
# sanitizers variable.
$(app): build_msg $(objects)
	@$(RM) $@
	$(CXX) $(objects) -o $@ $(sanitizers) $(LIB) $(LDFLAGS)
	@ls -lh $@

# C++ sources to objects
$(build)/%.cpp.o: %.cpp 
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Make OBJS depend on CPP/C/CXX/LD flags 
$(objects): $(build)/flags.txt

# Makes bin directory
$(bin):
	$(MKDIR_P) $@

.PHONY: build_msg clean flags
build_msg:
	@echo "Building "$(APP)
clean:
	$(RM) -r $(build)

# Creates a new flags.txt file when flags change; make will detect this change
# and force a rebuild of all the sources
$(build)/flags.txt: flags
	$(MKDIR_P) $(dir $@)
	$(Q){                                  \
		TMP=`mktemp`;                          \
		echo 'CPPFLAGS: $(CPPFLAGS)' >> $$TMP; \
		echo 'CFLAGS:   $(CFLAGS)'   >> $$TMP; \
		echo 'CXXFLAGS: $(CXXFLAGS)' >> $$TMP; \
		echo 'LDFLAGS:  $(LDFLAGS)'  >> $$TMP; \
		cmp -s $$TMP $@ || mv -f $$TMP $@;     \
		}
# Avoids inclusion of the dependencies when cleaning.
ifneq ($(MAKECMDGOALS),clean)
  -include $(deps)
endif
