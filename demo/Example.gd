extends Example

func _ready():
	test_cesium()
	print(GDCesium.godot_cpp_version())
	print(GDCesium.version());
