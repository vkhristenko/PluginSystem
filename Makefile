CPPFLAGS=-fPIC -std=c++11
osname := $(shell uname -s)
ifeq ($(osname), Linux)
	CPPFLAGS += -ldl
endif

#PROJECT_DIR=/Users/vk/software/practice/cc/PluginSystem
PROJECT_DIR=$(shell pwd)
INCLUDE_DIR=-I$(PROJECT_DIR)

all: test libplugins.dylib

test: test.o $(PROJECT_DIR)/PluginManager/src/Manager.o
	g++ $(CPPFLAGS) -o test test.o Manager.o

libplugins.dylib: $(PROJECT_DIR)/TestPlugins/src/Plugin1.o $(PROJECT_DIR)/PluginManager/src/Manager.o
	g++ $(CPPFLAGS) -shared -o libplugins.dylib Plugin1.o Manager.o

#test: test.cc
#	g++ $(CPPFLAGS) $(INCLUDE_DIR)  $? -o $@

#test: test. $(PROJECT_DIR)/PluginManager/src/Manager.cc
#	g++ $(CPPFLAGS) $(INCLUDE_DIR) $? -o $@

.cc.o:
	g++ $(CPPFLAGS) $(INCLUDE_DIR) -c $<

clean:
	rm test *.o *.dylib
