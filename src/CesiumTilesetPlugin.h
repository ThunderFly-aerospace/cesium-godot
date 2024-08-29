#pragma once

#include "godot_cpp/classes/editor_plugin.hpp"

#include "CesiumTilesetInspector.h"

namespace CesiumGodot
{
    /// @brief Godot editor plugin for cesium
    class CesiumTilesetPlugin : public godot::EditorPlugin
    {
        GDCLASS( CesiumTilesetPlugin, godot::EditorPlugin )

    public:
        CesiumTilesetPlugin();
        ~CesiumTilesetPlugin();

        bool _has_main_screen() const override;
        godot::String _get_plugin_name() const override;

        void _enter_tree() override;
        void _exit_tree() override;


    protected:
        static void _bind_methods();

    private:
        godot::String m_pluginName = "Cesium Ion";
        godot::Ref<CesiumTilesetInspector> m_rTilesetInspectorPlugin;

        void print_helper();
    };
}
