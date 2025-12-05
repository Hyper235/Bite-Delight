cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
set(MAIN_PROJECT_NAME "oop")
set(MAIN_EXECUTABLE_NAME "${MAIN_PROJECT_NAME}")

project(${MAIN_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# include .cmake-urile din scheletul de proiect
include(cmake/Options.cmake)
include(cmake/CompilerFlags.cmake)
include(cmake/CopyHelper.cmake)

###############################################################################
# external dependencies with FetchContent: SFML 3

include(FetchContent)

set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

set(SFML_WARNINGS_AS_ERRORS OFF)

# NOTE: Also update SFML_VERSION env var in .github/workflows/cmake.yml:33
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        # renovate: datasource=github-tags depName=SFML/SFML versioning=loose
        GIT_TAG        3.0.2
        # renovate: depName=SFML/SFML
        # GIT_TAG        0fa201c969e48ecc253581c5841ce73f44d42f49 # 3.0.2
        GIT_SHALLOW    1  # works only with branches or tags, not with arbitrary commit hashes
)

FetchContent_MakeAvailable(SFML)

###############################################################################
# other external dependencies with find_package

find_package(Threads REQUIRED)

if(APPLE)
    # nothing special here for now
elseif(UNIX)
    find_package(X11)
endif()

###############################################################################
# executable

add_executable(${MAIN_EXECUTABLE_NAME}
        main.cpp
        src/FoodItem.cpp
        src/Player.cpp
        src/Order.cpp
        src/Customer.cpp
        src/Workstation.cpp
        src/BuildStation.cpp
        src/GrillStation.cpp
        src/ServeStation.cpp
        src/OrderStation.cpp
        src/Restaurant.cpp
)

# include-urile TALE (pentru GrillStation.h & co)
target_include_directories(${MAIN_EXECUTABLE_NAME}
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# link SFML + Threads
target_link_libraries(${MAIN_EXECUTABLE_NAME}
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
        Threads::Threads
)

if(APPLE)
    # nimic deocamdată
elseif(UNIX)
    target_link_libraries(${MAIN_EXECUTABLE_NAME} PRIVATE X11)
endif()

###############################################################################
# compiler flags / sanitizers

# NOTE: Add all defined targets (e.g. executables, libraries, etc. )
# NOTE: RUN_SANITIZERS is optional, if it's not present it will default to true
set_compiler_flags(RUN_SANITIZERS TRUE TARGET_NAMES ${MAIN_EXECUTABLE_NAME})
# set_compiler_flags(TARGET_NAMES ${MAIN_EXECUTABLE_NAME} ${FOO} ${BAR})

###############################################################################
# install + copiere resurse

# DESTINATION_DIR is set as "bin" in cmake/Options.cmake:6
install(TARGETS ${MAIN_EXECUTABLE_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

copy_files(FILES tastatura.txt COPY_TO_DESTINATION TARGET_NAME ${MAIN_EXECUTABLE_NAME})
copy_files(DIRECTORY fonts COPY_TO_DESTINATION TARGET_NAME ${MAIN_EXECUTABLE_NAME})
copy_files(DIRECTORY date COPY_TO_DESTINATION TARGET_NAME ${MAIN_EXECUTABLE_NAME})

# pentru Visual Studio (ignored pe MinGW/CLion, dar nu strică)
set_target_properties(${MAIN_EXECUTABLE_NAME} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

