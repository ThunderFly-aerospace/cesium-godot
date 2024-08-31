# Cesium for Godot

Work in progress. Milestones will be added to the project soon.

## Contribution Guidelines

To use this locally on your machine, you will need the following:

- **[CMake](https://cmake.org/)** v3.22+
- C++ Compiler with at least **C++17** support (any recent compiler)
- (optional) **[ccache](https://ccache.dev/)** for faster rebuilds
- (optional) **[clang-format](https://clang.llvm.org/docs/ClangFormat.html)** for linting and automatic code formatting (CI uses clang-format version 15)

### Build instructions

Here's an example of how to build & install a debug version into the demo project:

#### Clone the repository

```sh
$ git clone --recursive https://github.com/ThunderFly-aerospace/cesium-godot.git 
```

#### Build & Install

```sh
$ cmake -B ./build -G"Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX="./demo/addons"
$ cmake --build ./build
$ cmake --install ./build
```

This tells CMake to use `Ninja` generator. There is a list of generators [on the CMake site](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#cmake-generators) - pick the one you are using.

**Note:** Even for multi-config generators you still have to specify `CMAKE_BUILD_TYPE`, because of the way [godot-cpp](https://github.com/godotengine/godot-cpp)'s build process is set up, hence there is not much use for this type of generators now. 

#### Run demo project in Godot Editor

```sh
$ godot -e --path ./demo
```

Additionally, basic VSCode configuration files are provided, including launch configuration to debug the extension and `CMakePresets.json` for easier build system configuration (by default uses `Ninja`).

### Cmake Options

Additional CMake options:

| Option                                                                   | Description                                      | Default                                                                                                 |
| ------------------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------------------------------------------------- |
| `CCACHE_PROGRAM`                                                         | Path to `ccache` for faster rebuilds             | This is automatically set **ON** if `ccache` is found. If you do not want to use it, set this to "".    |
| `CLANG_FORMAT_PROGRAM`                                                   | Path to `clang-format` for code formatting.      | This is automatically set **ON** if `clang-format` is on. If you do not want to use it, set this to "". |
| `GDCESIUM_WARN_EVERYTHING`  | Turns on all warnings. (Not available for MSVC.) | **OFF** (too noisy, but can be useful sometimes)                                                        |
| `GDCESIUM_WARNING_AS_ERROR` | Turns warnings into errors.                      | **ON**                                                                                                  |

## Credits

- GDExtension [template](https://github.com/asmaloney/GDExtensionTemplate) for CMake 

