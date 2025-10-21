cmake_minimum_required(VERSION 3.21)
project(0xVault LANGUAGES CXX)

# ===================================
# 🪟 Slint UI setup
# ===================================
find_package(Slint REQUIRED)

add_executable(0xVault src/main.cpp)
slint_target_sources(0xVault ui/app-window.slint)
target_link_libraries(0xVault PRIVATE Slint::Slint)

# ===================================
# 🔐 Link libsodium (static or dynamic)
# ===================================

# Adjust these if your folder layout differs
set(LIBSODIUM_INCLUDE_DIR "C:/lib/libsodium/include")
set(LIBSODIUM_LIB_DIR "C:/lib/libsodium/x64/Release/v143/static")

target_include_directories(0xVault PRIVATE ${LIBSODIUM_INCLUDE_DIR})
target_link_directories(0xVault PRIVATE ${LIBSODIUM_LIB_DIR})
target_link_libraries(0xVault PRIVATE libsodium.lib)


# ===================================
# 📦 Include nlohmann/json (header-only)
# ===================================
# Header-only — no linking required
set(NLOHMANN_JSON_INCLUDE "C:/lib/nlohmann/include")
target_include_directories(0xVault PRIVATE ${NLOHMANN_JSON_INCLUDE})

# ===================================
# 🪟 Optional: Copy required DLLs
# ===================================
if (WIN32)
  add_custom_command(TARGET 0xVault POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:0xVault> $<TARGET_FILE_DIR:0xVault>
    COMMAND_EXPAND_LISTS)
endif()


# ===================================
# ⚙️ Compiler options (optional but recommended)
# ===================================
target_compile_features(0xVault PRIVATE cxx_std_20)
set_target_properties(0xVault PROPERTIES
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)









# ===================================
# Run instructions
# ===================================
# cmake -B build -DCMAKE_PREFIX_PATH="C:\lib\Slint-cpp 1.13.1"
# cmake --build build --config Release


# for live preview

# cmake -B build -DCMAKE_BUILD_TYPE=Release -DSLINT_FEATURE_LIVE_PREVIEW=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX="C:/lib/Slint-cpp-1.13.1"
# cmake --build build --config Release
# cmake --install build
# $env:SLINT_LIVE_PREVIEW = 1
# .\build\Release\0xVault.exe


