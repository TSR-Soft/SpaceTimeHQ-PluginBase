/* SpaceTime Plugin Header
 * Plugin Authors should ALWAYS inherit this class
 *
 */

#ifndef _SPACETIME_PLUGIN_H_
#define _SPACETIME_PLUGIN_H_

/* Includes *
 * Always make sure you get the most updated IPlugin.h & PluginBase.h
 * from the official SpaceTime GitHub. */
#include "IPlugin.h"

/* All plugins should inherit this class */
class STPluginBase {
public:
    /* Constructor */
    STPluginBase();

    /* Called OnRegister *
     * You should fill the data in structure *
     * with appropriate values and make sure to free *
     * the structure again OnDestroy */
    virtual PluginIdentifier *Register() { return (PluginIdentifier*)0; }

    /* Called OnInitialize *
     * Use this function to setup your plugin */
    virtual void Initialize() {}

    /* Called OnDestroy *
     * Cleanup any allocated data and the PluginIdentifier
     * structure you filled earlier */
    virtual void Destroy() {}

    /* Called OnEvent *
     * This function is called on any application or
     * user-event, refer to IPlugin.h to see which events can
     * occur, their ids and their associated data */
    virtual void OnEvent(PluginEventId EventId, PluginEventData EventData) {}
};


#endif // _SPACETIME_PLUGIN_H_
