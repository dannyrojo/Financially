cmake_minimum_required(VERSION 3.5)

project(Financially)

#Find the Qt6 package
find_package(Qt6 COMPONENTS Widgets Core REQUIRED)

# Add your source files to the project
set(SOURCES
    main.cpp
)
add_executable(Financially ${SOURCES})

#Link against the Qt6 libraries
target_link_libraries(Financially PRIVATE Qt6::Widgets Qt6::Core)

