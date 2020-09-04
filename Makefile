appname := guessing_game
CXX=g++
INCLUDES = -Isrc/secret -Isrc/guess -Isrc/diff -Isrc/attempts -Isrc/farewell
CXXFLAGS=-std=c++17 -Wall $(INCLUDES)

srcfiles := $(shell find -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): build_msg $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

.PHONY: clean build_msg
build_msg:
	@echo "Build Guessing Number"
clean:
	$(RM) $(objects)

include .depend
# main.o: main.cpp factories.hpp
# 	g++ $(CPPFLAGS) -c main.cpp
# factories.o: factories.cpp factories.hpp 
# 	g++ $(CPPFLAGS) -c factories.cpp

