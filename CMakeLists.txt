cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include necessary CMake modules

include(cmake/Options.cmake)

###############################################################################

# External dependencies with FetchContent

include(FetchContent)

set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

# din cauza SFML
set(WARNINGS_AS_ERRORS OFF)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.1  # Use the version tag you want (e.g., 2.6.1)
        GIT_SHALLOW    1
)

# Fetch and make SFML available
FetchContent_MakeAvailable(SFML)

###############################################################################

find_package(Threads REQUIRED)
if(APPLE)
elseif(UNIX)
    find_package(X11)
endif()

###############################################################################
# Your project's source files
add_executable(${PROJECT_NAME}
        generated/src/Helper.cpp
        env_fixes.h
        src/core/Game.cpp
        src/core/Game.h
        src/core/pch.cpp
        src/core/main.cpp
        src/entities/Entity.cpp
        src/entities/Player.cpp
        src/entities/Enemy.cpp
        src/entities/Goomba.cpp
        src/entities/Koopa.cpp
        src/entities/Koopa.h
        src/core/Exceptions.h
        src/core/Button.cpp
        src/core/Button.h
        src/core/Menu.cpp
        src/core/Menu.h
        src/core/ResourceManager.cpp
        src/core/ResourceManager.h
        src/entities/Health.h
)

include(cmake/CompilerFlags.cmake)
# Precompile header
#set(SFML_STATIC_LIBRARIES TRUE)
target_precompile_headers(${PROJECT_NAME} PRIVATE src/core/pch.h)
#add_compile_options(-Wno-overloaded-virtual)



# Link SFML libraries to your project
target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        Threads::Threads
)
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_BINARY_DIR}/lib)

# Include SFML headers (via FetchContent)
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_SOURCE_DIR}/include)

# Additional include directories for your project

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE generated/include)
target_include_directories(${PROJECT_NAME} PRIVATE
        src/core
        src/entities
        src/assets
        src/assets/audio
        src/assets/textures
        src/assets/backround
        src/assets/font
)
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})



if(APPLE)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE X11)
endif()

###############################################################################

# Copy binaries to "bin" folder; these are uploaded as artifacts on each release
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

if (WIN32 AND SFML_BUILD_AUDIO)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SFML_SOURCE_DIR}/extlibs/bin/x64/openal32.dll
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()


include(cmake/CopyHelper.cmake)
copy_files(FILES tastatura.txt)
# copy_files(FILES tastatura.txt config.json DIRECTORY images sounds)
# copy_files(DIRECTORY images sounds)
