#include "PluginManager/include/Manager.h"

Manager* Manager::m_instance = nullptr;

Manager& Manager::get() {
    if (m_instance == nullptr)
        m_instance = new Manager();

    return *m_instance;
}
