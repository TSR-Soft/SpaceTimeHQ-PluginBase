/* SpaceTime Plugin Header
 * Plugin Authors should ALWAYS inherit this class
 *
 */

/* Includes */
#include "PluginBase.h"
#include <vector>

/* The local plugin manager, this enables us to have multiple plugins
 * in each module */
static std::vector<STPluginBase*> _LocalPlugins;


/* Constructor */
STPluginBase::STPluginBase() {
    _LocalPlugins.push_back(this);
}

/* These functions makes sure to redirect events from main application */
extern "C" {
    int GetPluginCount() {
        return static_cast<int>(_LocalPlugins.size());
    }

    PluginIdentifier *RegisterPlugin(PluginId Id) {
        STPluginBase *plugin = _LocalPlugins[Id];
        return plugin->Register();
    }

    void InitializePlugin(PluginId Id) {
        STPluginBase *plugin = _LocalPlugins[Id];
        plugin->Initialize();
    }

    /* Called when plugin is getting destroyed */
    void DestroyPlugin(PluginId Id) {
	STPluginBase *plugin = _LocalPlugins[Id];
        plugin->Destroy();
    }

    void OnEvent(PluginId Id, PluginEventId EventId, PluginEventData EventData) {
        STPluginBase *plugin = _LocalPlugins[Id];
        plugin->OnEvent(EventId, EventData);
    }
}
