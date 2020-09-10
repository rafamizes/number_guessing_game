APP ?= number_guessing_game
src_dirs := src
build_dir := build

sources := $(shell find $(src_dirs) -name *.cpp -or -name *.c)
objects := $(addsuffix .o,$(basename $(sources)))
deps := $(objects:.o=.d)

inclue_dirs := $(shell find $(src_dirs) -type d)
include_flags := $(addprefix -I,$(inclue_dirs))
CPPFLAGS ?= $(include_flags) -MMD -MP
CXXFLAGS ?= -std=c++17 -Wall

$(APP): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(APP) $(objects) $(LDLIBS)

.PHONY: build_msg clean
build_msg:
	@echo "include_flags: "$(include_flags)
clean:
	$(RM) $(TARGET) $(objects) $(deps)

-include $(deps)

