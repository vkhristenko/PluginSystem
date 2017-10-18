#PROJECT_DIR=/Users/vk/software/practice/cc/PluginSystem
PROJECT_DIR=$(shell pwd)

CXXFLAGS=-fPIC -std=c++11 -I$(PROJECT_DIR)
LDFLAGS=-rdynamic

osname := $(shell uname -s)
LIB_EXTENSION = dylib
ifeq ($(osname), Linux)
	LDFLAGS += -ldl
	LIB_EXTENSION = so
endif

all: test libplugins.$(LIB_EXTENSION)

test: test.o $(PROJECT_DIR)/PluginManager/src/Manager.o
	g++ $(CXXFLAGS) $^ $(LDFLAGS) -o $@

libplugins.$(LIB_EXTENSION): $(PROJECT_DIR)/TestPlugins/src/Plugin1.o $(PROJECT_DIR)/PluginManager/src/Manager.o
	g++ $(CXXFLAGS) $^ $(LDFLAGS) -shared -o $@

%.o: %.cc
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm test *.o *.$(LIB_EXTENSION)
