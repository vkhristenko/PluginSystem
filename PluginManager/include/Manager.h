#ifndef PluginManager_Manager_h
#define PluginManager_Manager_h

#include <iostream>
#include <map>
#include <string>

class Manager {
public:
    Manager() = default;

    static Manager* get();

    class PluginBase {
    public:
        PluginBase() = default;
        PluginBase(std::string const& name) : m_name(name) {}

        std::string getName() const { return m_name; }

    protected:
        std::string m_name = "";
    };

    void registerPlugin(PluginBase* plugin, std::string const& pname) {
        std::cout << "Registering plugin " << pname << std::endl;
        m_plugins[pname] = plugin;
        std::cout << "number of plugins = " << m_plugins.size() << std::endl;
        std::cout << "address of the manager = " << this << std::endl;
    }

    void printPlugins() const {
        for (auto const& kv : m_plugins) 
            std::cout << "name = " << kv.first << "  address of plugin = "
                << kv.second << std::endl;
    }

//private:
//    static Manager* m_instance;

public:
    std::map<std::string, PluginBase*> m_plugins;
};

#endif
