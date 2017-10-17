
#include <iostream>
#include <dlfcn.h>

#include "PluginManager/include/Manager.h"

typedef void (*func)();

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;

    auto& m = Manager::get();
    std::cout << "manager address = " << &m << std::endl;

    std::string libName = "libplugins.dylib";
    std::string symbName = "doSomething";
    void *handle = dlopen(libName.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    std::cout << "plain address = " << dlsym(handle, symbName.c_str()) << std::endl;
    func fff = (func)dlsym(handle, symbName.c_str());
    std::cout << "address of the func = " << fff << std::endl;
    fff();

    m.printPlugins();
    std::cout << "number of plugins = " << m.m_plugins.size() << std::endl;
}
