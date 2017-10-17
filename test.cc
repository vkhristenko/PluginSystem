
#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

#include "PluginManager/include/Manager.h"

typedef void (*func)();

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;

    char* cwd = std::getenv("PWD");

#ifdef __APPLE__
    std::string libName = "libplugins.dylib";
    std::string symbName = "doSomething";
#elif __linux__
    std::string libName = std::string(cwd) + std::string("/") + 
        std::string("libplugins.so");
    std::string symbName = "doSomething";
#endif
    std::cout << "libName = " << libName << " symbName = " << symbName << std::endl;

    void *handle = dlopen(libName.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    std::cout << "plain address = " << dlsym(handle, symbName.c_str()) << std::endl;
    func fff = (func)dlsym(handle, symbName.c_str());
    std::cout << "address of the func = " << fff << std::endl;
    fff();

    Manager::get()->printPlugins();
    std::cout << "number of plugins = " << Manager::get()->m_plugins.size() << std::endl;
    std::cout << "address of the manager in main = " << Manager::get() << std::endl;
}
