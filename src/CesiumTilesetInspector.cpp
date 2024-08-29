#include "CesiumTilesetInspector.h"

#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/classes/thread.hpp"
#include "godot_cpp/classes/label.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/variant/callable.hpp"

#include "CesiumTileset.h"

namespace CesiumGodot
{


    CesiumTilesetInspector::CesiumTilesetInspector()
    {
        godot::UtilityFunctions::print("Initializing tileset inspector plugin");
    }

    CesiumTilesetInspector::~CesiumTilesetInspector()
    {
        godot::UtilityFunctions::print("Deinitializing tileset inspector plugin");
    }

    bool CesiumTilesetInspector::_can_handle(godot::Object * object) const
    {
        godot::UtilityFunctions::print(object->get_class());
        return object->is_class("CesiumTileset");
    }

    void memfree_helper(void* ptr)
    {
        godot::Memory::free_static(ptr);
    }

    void CesiumTilesetInspector::_parse_begin( godot::Object *object )
    {
        godot::Label* pLabel = memnew(godot::Label);
        add_custom_control(pLabel);
    }

    void CesiumTilesetInspector::_parse_category( godot::Object *object,
                                                  const godot::String &category )
    {
        godot::UtilityFunctions::print("Parsing category: ", category);

        if (category == "CesiumTileset")
        {
            godot::Button* pAddButton = memnew(godot::Button);
            pAddButton->set_text("Add GLTF");
            pAddButton->set_action_mode(godot::BaseButton::ACTION_MODE_BUTTON_PRESS);
            pAddButton->connect("pressed", callable_mp(godot::Object::cast_to<CesiumTileset>(object), &CesiumTileset::loadGltf), godot::Object::ConnectFlags::CONNECT_DEFERRED);
            add_custom_control(pAddButton);
        }
    }

    void CesiumTilesetInspector::_parse_group( godot::Object *object, const godot::String &group )
    {
        godot::UtilityFunctions::print("Parsing group: ", group);

        if (group == "Cesium/Asset Data")
        {
        }
    }

    void CesiumTilesetInspector::_bind_methods()
    {
    }

    void CesiumTilesetInspector::add_gltf_helper()
    {
    }
}
