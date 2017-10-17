#include "PluginManager/include/Manager.h"

//Manager* Manager::m_instance = nullptr;

Manager* Manager::get() {
    static Manager m_instance;
    return &m_instance;
}
