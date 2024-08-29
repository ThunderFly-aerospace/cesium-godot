#pragma once

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/gltf_state.hpp"
#include "godot_cpp/classes/gltf_document.hpp"

#include "Cesium3DTilesSelection/Tileset.h"

#include <memory>


#include "godot_cpp/classes/sphere_mesh.hpp"
#include "godot_cpp/classes/mesh_instance3d.hpp"

namespace CesiumGodot
{
    /// @brief Godot object representing cesium tileset
    class CesiumTileset : public godot::Node3D
    {
        GDCLASS( CesiumTileset, godot::Node3D )

    public:
        CesiumTileset();
        ~CesiumTileset();

        godot::String getAccessToken() const;
        void setAccessToken(const godot::String& inToken);
        int32_t getAssetId() const;
        void setAssetId(int32_t id);

        /// @brief Load glTF model at gltfPath and add it to this node's children
        /// @param gltfPath model path
        void loadGltfPath(const godot::String& gltfPath);
        void loadGltf();

    protected:
        static void _bind_methods();

    private:
        godot::Node* m_gltfNode;

        std::shared_ptr<Cesium3DTilesSelection::Tileset> m_tileset;

        godot::String m_accessToken;
        int32_t m_assetId;
    };
}