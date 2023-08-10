$TOOLCHAIN_FILE = Join-Path download openage-dep-x64-windows scripts buildsystems vcpkg.cmake | Resolve-Path
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS='/Zc:__cplusplus /permissive- /EHsc' -DCMAKE_EXE_LINKER_FLAGS='' -DCMAKE_MODULE_LINKER_FLAGS='' -DCMAKE_SHARED_LINKER_FLAGS='' -DCXX_OPTIMIZATION_LEVEL=auto -DCXX_SANITIZE_FATAL=False -DCXX_SANITIZE_MODE=none -DWANT_BACKTRACE=if_available -DWANT_GPERFTOOLS_PROFILER=if_available -DWANT_GPERFTOOLS_TCMALLOC=False -DWANT_INOTIFY=if_available -DWANT_NCURSES=if_available -DWANT_OPENGL=if_available -DWANT_VULKAN=if_available  -A x64 ..
cmake --build . --config RelWithDebInfo -- -nologo -maxCpuCount
cd ..