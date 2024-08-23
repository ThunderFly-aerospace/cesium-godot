#pragma once
// SPDX-License-Identifier: Unlicense

#include "godot_cpp/classes/object.hpp"

namespace godot
{
    class ClassDB;
};

class GDCesium : public godot::Object
{
    GDCLASS( GDCesium, godot::Object )

public:
    static godot::String version();
    static godot::String godotCPPVersion();

private:
    static void _bind_methods();
};
