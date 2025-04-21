# Cesium for Godot

**Development on this specific project is currently paused.** Battle Road, Inc. has received an official Cesium Ecosystem Grant to develop a Cesium plugin for Godot. Given their expertise and the official support for their effort, we are awaiting the results of their work.

For more details see the Cessium official blog post: [Cesium Ecosystem Grant Supports Development of Cesium Plugin for Godot](https://cesium.com/blog/2024/09/26/cesium-plugin-for-godot/).

It is likely that if Battle Road successfully delivers their plugin, this project will be discontinued.

We recommend following the progress of the Battle Road project for the most up-to-date developments on Cesium integration for Godot.

## Contribution Guidelines

To use this locally on your machine, you will need the following:

- **[CMake](https://cmake.org/)** v3.22+
- C++ Compiler with at least **C++17** support (any recent compiler)
- (optional) **[ccache](https://ccache.dev/)** for faster rebuilds
- (optional) **[clang-format](https://clang.llvm.org/docs/ClangFormat.html)** for linting and automatic code formatting (CI uses clang-format version 15)

### Build & Install

Here's an example of how to build & install a release version (use the terminal to run the following commands in the parent directory of this repo):

#### Not MSVC

```sh
$ cmake -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./install
$ cmake --build ./build --parallel
$ cmake --install ./build
```

#### MSVC

```sh
$ cmake -B ./build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./install
$ cmake --build ./build --config Release
$ cmake --install ./build
```

This tells CMake to use `Visual Studio 2022`. There is a list of Visual Studio generators [on the CMake site](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#visual-studio-generators) - pick the one you are using.

### Cmake Options

This template defines the following additional CMake options:

| Option                                                                   | Description                                      | Default                                                                                                 |
| ------------------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------------------------------------------------- |
| `CCACHE_PROGRAM`                                                         | Path to `ccache` for faster rebuilds             | This is automatically set **ON** if `ccache` is found. If you do not want to use it, set this to "".    |
| `CLANG_FORMAT_PROGRAM`                                                   | Path to `clang-format` for code formatting.      | This is automatically set **ON** if `clang-format` is on. If you do not want to use it, set this to "". |
| `${PROJECT_NAME_UPPERCASE}_WARN_EVERYTHING` (e.g. FOO_WARN_EVERYTHING)   | Turns on all warnings. (Not available for MSVC.) | **OFF** (too noisy, but can be useful sometimes)                                                        |
| `${PROJECT_NAME_UPPERCASE}_WARNING_AS_ERROR` (e.g. FOO_WARNING_AS_ERROR) | Turns warnings into errors.                      | **ON**                                                                                                  |

## Credits

- GDExtension [template](https://github.com/asmaloney/GDExtensionTemplate) for CMake 

