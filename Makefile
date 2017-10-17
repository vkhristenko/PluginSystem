CPPFLAGS=-fPIC -std=c++11
osname := $(shell uname -s)
LIB_EXTENSION = "dylib"
ifeq ($(osname), Linux)
	CPPFLAGS += -ldl
	LIB_EXTENSION = "so"
endif

#PROJECT_DIR=/Users/vk/software/practice/cc/PluginSystem
PROJECT_DIR=$(shell pwd)
INCLUDE_DIR=-I$(PROJECT_DIR)

all: test libplugins.$(LIB_EXTENSION)

test: test.o $(PROJECT_DIR)/PluginManager/src/Manager.o
	g++ $(CPPFLAGS) -o test test.o Manager.o

libplugins.$(LIB_EXTENSION): $(PROJECT_DIR)/TestPlugins/src/Plugin1.o $(PROJECT_DIR)/PluginManager/src/Manager.o
	g++ $(CPPFLAGS) -shared -o libplugins.$(LIB_EXTENSION) Plugin1.o Manager.o

#test: test.cc
#	g++ $(CPPFLAGS) $(INCLUDE_DIR)  $? -o $@

#test: test. $(PROJECT_DIR)/PluginManager/src/Manager.cc
#	g++ $(CPPFLAGS) $(INCLUDE_DIR) $? -o $@

.cc.o:
	g++ $(CPPFLAGS) $(INCLUDE_DIR) -c $<

clean:
	rm test *.o *.$(LIB_EXTENSION)
