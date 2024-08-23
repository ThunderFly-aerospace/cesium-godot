# SPDX-License-Identifier: Unlicense

file(GLOB_RECURSE gdcesium_src CONFIGURE_DEPENDS 
        "*.h"
        "*.cpp")

target_sources( ${PROJECT_NAME}
    PRIVATE
        # Example.h
        # Example.cpp
        # GDExtensionTemplate.h
        # GDExtensionTemplate.cpp
        # RegisterExtension.cpp
        ${gdcesium_src}
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
