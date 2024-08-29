#include "CesiumTilesetPlugin.h"

#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/classes/editor_inspector_plugin.hpp"
#include "godot_cpp/variant/callable.hpp"

#include "CesiumTilesetPlugin.h"

namespace CesiumGodot
{
    CesiumTilesetPlugin::CesiumTilesetPlugin()
    {
        godot::UtilityFunctions::print("CesiumTilesetPlugin initialized.");
    }

    CesiumTilesetPlugin::~CesiumTilesetPlugin()
    {
        godot::UtilityFunctions::print("CesiumTilesetPlugin deinitialized.");
    }

    bool CesiumTilesetPlugin::_has_main_screen() const
    {
        return true;
    }

    godot::String CesiumTilesetPlugin::_get_plugin_name() const
    {
        return m_pluginName;
    }

    void CesiumTilesetPlugin::_enter_tree() 
    {
        godot::UtilityFunctions::print("CesiumTilesetPlugin entered");

        // godot::Ref<godot::Button> button;
        // button.instantiate();

        m_rTilesetInspectorPlugin.instantiate();
        add_inspector_plugin(m_rTilesetInspectorPlugin);
        godot::UtilityFunctions::print("Inspector plugin is valid: ", m_rTilesetInspectorPlugin.is_valid());
    }

    void CesiumTilesetPlugin::_exit_tree()
    {
        godot::UtilityFunctions::print("CesiumTilesetPlugin exited");

        remove_inspector_plugin(m_rTilesetInspectorPlugin);
        m_rTilesetInspectorPlugin.unref();
    }

    void CesiumTilesetPlugin::_bind_methods()
    {
    }

    void CesiumTilesetPlugin::print_helper()
    {
        godot::UtilityFunctions::print("Test button pressed");
    }
}
