#include "CesiumTileset.h"

#include "godot_cpp/classes/gltf_document.hpp"
#include "godot_cpp/classes/gltf_state.hpp"
#include "godot_cpp/classes/file_access.hpp"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/gltf_document_extension_convert_importer_mesh.hpp"

#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/classes/dir_access.hpp"

#include "godot_cpp/variant/utility_functions.hpp"

namespace CesiumGodot
{
    void _recursive_change_owner(godot::Node* node, godot::Node* owner)
    {
        godot::Callable chown_callable = callable_mp_static(_recursive_change_owner);
        node->get_children().map(chown_callable.bind(owner));
    }

    CesiumTileset::CesiumTileset()
    {
        m_assetId = -1;
        m_gltfNode = nullptr;
    }

    CesiumTileset::~CesiumTileset()
    {
    }

    godot::String CesiumTileset::getAccessToken() const
    {
        return m_accessToken;
    }

    void CesiumTileset::setAccessToken( const godot::String &inToken )
    {

        m_accessToken = inToken;
    }

    
    int32_t CesiumTileset::getAssetId() const
    {
        return m_assetId;
    }

    void CesiumTileset::setAssetId( int32_t id )
    {
        m_assetId = id;
    }

    void CesiumTileset::loadGltfPath(const godot::String& gltfPath)
    {
        godot::UtilityFunctions::print("Loading GLTF model: ", gltfPath);

        if (!godot::FileAccess::file_exists(gltfPath))
        {
            godot::UtilityFunctions::print("File ", gltfPath, " does not exist");
            return;
        }

        if (m_gltfNode != nullptr)
        {
            if (get_children().has(m_gltfNode)) remove_child(m_gltfNode);
            memdelete(m_gltfNode);
        }

        godot::GLTFDocument* gltfDoc = memnew(godot::GLTFDocument);

        // Register convert extension. Apparently needed for correct editor runtime mesh import
        godot::Ref<godot::GLTFDocumentExtensionConvertImporterMesh> gltfConvertExt;
        gltfConvertExt.instantiate();
        gltfDoc->register_gltf_document_extension(gltfConvertExt);

        godot::Ref<godot::GLTFState> gltfState;
        gltfState.instantiate();
        gltfState->set_handle_binary_image(godot::GLTFState::HANDLE_BINARY_EMBED_AS_UNCOMPRESSED);

        godot::Error err = gltfDoc->append_from_file(gltfPath, gltfState, 0,  "base_path?");
        godot::UtilityFunctions::print("Load result: ", err);

        m_gltfNode = gltfDoc->generate_scene(gltfState);
        add_child(m_gltfNode);
        _recursive_change_owner(m_gltfNode, get_owner());
        
        memdelete(gltfDoc);
    }

    void CesiumTileset::loadGltf()
    {
        const godot::String& path = m_accessToken;
        loadGltfPath(path);
    }

    void CesiumTileset::_bind_methods()
    {
        godot::ClassDB::bind_method( godot::D_METHOD("set_access_token"), &CesiumTileset::setAccessToken );
        godot::ClassDB::bind_method( godot::D_METHOD("get_access_token"), &CesiumTileset::getAccessToken );
        godot::ClassDB::bind_method( godot::D_METHOD("set_asset_id"), &CesiumTileset::setAssetId ); 
        godot::ClassDB::bind_method( godot::D_METHOD("get_asset_id"), &CesiumTileset::getAssetId ); 
        godot::ClassDB::bind_method( godot::D_METHOD("load_gltf"), &CesiumTileset::loadGltf );

        ADD_GROUP("Cesium", "cesium_");
        ADD_SUBGROUP("Asset Data", "cesium_assetData_");

        ADD_PROPERTY( godot::PropertyInfo( godot::Variant::STRING, "cesium_assetData_access_token" ),
                         "set_access_token", "get_access_token");
        ADD_PROPERTY( godot::PropertyInfo( godot::Variant::INT, "cesium_assetData_asset_id" ),
                         "set_asset_id", "get_asset_id");

    }
}