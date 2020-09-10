APP ?= number_guessing_game
src_dirs := src
build_dir := build
bin_dir := bin

# Searches for cpp, c and assembly files.
# In case there are assembly files, just add "-or -name *.s" 
sources := $(shell find $(src_dirs) -name *.cpp -or -name *.c)
objects := $(sources:%=$(build_dir)/%.o)
deps := $(objects:.o=.d)

inclue_dirs := $(shell find $(src_dirs) -type d)
include_flags := $(addprefix -I,$(inclue_dirs))
CPPFLAGS ?= $(include_flags) -MMD -MP
CXXFLAGS ?= -std=c++17 -Wall
MKDIR_P ?= mkdir -p

# Application's executable rule.
$(bin_dir)/$(APP): build_msg $(objects)
	$(CXX) $(objects) -o $@ $(LDFLAGS)

# C++ sources
$(build_dir)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# C sources
# $(build_dir)/%.c.o: %.c
# 	$(MKDIR_P) $(dir $@)
# 	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Assembly 
# $(build_dir)/%.s.o: %.s
# 	$(MKDIR_P) $(dir $@)
# 	$(AS) $(ASFLAGS) -c $< -o $@

# Instructs make to remove all *.d files after compilation
.INTERMEDIATE: $(deps)

.PHONY: build_msg clean
build_msg:
	@echo "Building "$(APP)
clean:
	$(RM) -r $(build_dir)

-include $(deps)

