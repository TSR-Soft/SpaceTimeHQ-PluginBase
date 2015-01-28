/* SpaceTime Plugin Interface
 * This class defines the shared interface of a plugin
 * This is needed by plugin-developers.
 *
 */

#ifndef _PLUGIN_INTERFACE_H_
#define _PLUGIN_INTERFACE_H_

/* Includes */
typedef int PluginId;
typedef int PluginEventId;
typedef void* PluginEventData;

/* The Plugin Identifier Structure */
struct PluginIdentifier
{
    /* Author */
    char *Author;

    /* Version (Major & Minor & Revision) */
    int VersionMajor;
    int VersionMinor;
    int Revision;

    /* Name */
    char *Name;
};

/* C Api */
extern "C" {
    /* Return number of plugins in this module */
    int GetPluginCount();

    /* Called to register the nth plugin of this module.
     * A user-data pointer is expected in return (may be null). */
    PluginIdentifier *RegisterPlugin(PluginId Id);

    /* Called to initialize the nth plugin of this module */
    void InitializePlugin(PluginId Id);

    /* Called when plugin is getting destroyed */
    void DestroyPlugin(PluginId Id);

    /* Program Events */

    /* Occurs when the program signal any event *
     * The data in EventData is defined in the structure header. */
    void OnEvent(PluginId Id,
                 PluginEventId EventId,
                 PluginEventData EventData);
}

#endif
