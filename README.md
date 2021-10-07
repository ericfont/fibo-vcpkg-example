# Please Feel Free to Fork Me as an Example Template

[.github/workflows/hosted-pure-workflow.yml](.github/workflows/hosted-pure-workflow.yml) uses generic variable names

[CMakeLists.txt](CMakeLists.txt) does the building and zipping cross-platform so almost no platform-specific stuff is needed in the .yml

## Description
Minimal repository using cmake and vcpkg to build & cache library dependencies and upload executable runtime via github actions for win, mac, linux, using a fibonacci example (https://github.com/microsoft/vcpkg/blob/master/docs/examples/manifest-mode-cmake.md) with Luca Cappa's hosted-pure-workflow (https://github.com/lukka/CppBuildTasks-Validation/blob/master/.github/workflows/hosted-pure-workflow.yml) with vcpkg as a submodule.

Generates Fibonnaci sequence up to the maximum that `<cstdint>`'s `uintmax_t` supports, which on 64-bit systems is `fib(92) = 7540113804746346429`.

## Local Build

```
git clone https://github.com/ericfont/fibo-vcpkg-example.git
cd fibo-vcpkg-example
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
```
 
The executable along with any necessary shared runtime libraries the build generated (such as fmt.dll on windows) will be put in `build/runtime/`.

## Online Build
Fork & make a commit to your github, then look in your repo's action folder, and when the run completes it turn from orange to green, then click on its summary and authorized repo users should see (non-publibly)-downloadable zips of the builds for each OS at the bottom. Tagged pushes will also generate a Release which contains publicly-downloadable zips for all OSes.
