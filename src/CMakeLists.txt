# SPDX-License-Identifier: Unlicense

file(GLOB_RECURSE gdcesium_src CONFIGURE_DEPENDS 
        "*.h"
        "*.cpp")

target_sources( ${PROJECT_NAME}
    PRIVATE
        # ${gdcesium_src}
        Example.h
        Example.cpp
        GDCesium.h
        GDCesium.cpp
        RegisterExtension.cpp
        GodotAssetAccessor.h
        GodotAssetAccessor.cpp
        GodotTaskProcessor.h
        GodotTaskProcessor.cpp
        CesiumTileset.h
        CesiumTileset.cpp
        CesiumTilesetPlugin.h
        CesiumTilesetPlugin.cpp
        CesiumTilesetInspector.h
        CesiumTilesetInspector.cpp
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
