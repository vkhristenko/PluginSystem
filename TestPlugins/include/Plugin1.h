#ifndef TestPlugins_Plugin1_h
#define TestPlugins_Plugin1_h

#include <iostream>

#include "PluginManager/include/Manager.h"

class Plugin1 : public Manager::PluginBase {
public:
    Plugin1() {
        std::cout << "Hello World from Plugin" << std::endl;
    };
    Plugin1(std::string const& name) : Manager::PluginBase(name) {
        std::cout << "Hello World from plugin: " << name << std::endl;
        Manager::get().registerPlugin(this, name);
    }

    inline int get() const { return m_value; }
    inline void set(int x) { m_value = x; }

private:
    int m_value;
};

static const Plugin1 plugin1(std::string("Plugin1"));
static const Plugin1 plugin2(std::string("Plugin2"));

extern "C" {
    void doSomething() { std::cout << "Hello World\n" << std::endl;}
}

#endif
