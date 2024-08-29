#pragma once

 #include "godot_cpp/classes/editor_inspector_plugin.hpp"

 #include <memory>

 namespace godot
 {
    class Label;
    class Button;
 } // namespace godot
 

namespace CesiumGodot
{
    /// @brief Godot editor inspector plugin for cesium tileset node
    class CesiumTilesetInspector : public godot::EditorInspectorPlugin
    {
        GDCLASS( CesiumTilesetInspector, godot::EditorInspectorPlugin )

    public:
        CesiumTilesetInspector();
        ~CesiumTilesetInspector();

        bool _can_handle(godot::Object* object) const override;
        void _parse_begin(godot::Object* object) override;
        void _parse_category(godot::Object* object, const godot::String& category) override;
        void _parse_group(godot::Object* object, const godot::String& group) override;

        static void _bind_methods();

    private:
        void add_gltf_helper();

        // std::shared_ptr<godot::Label> m_pLabel;
        godot::Label* m_pLabel;
        godot::Button* m_pAddGlftButton;
    };
}