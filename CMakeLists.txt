cmake_minimum_required(VERSION 3.8)
project(QtTetrix)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED Widgets)

set(SOURCE_FILES src/main.cpp src/main.cpp
        src/tetrixwindow.cpp src/tetrixwindow.h
        src/tetrixboard.cpp src/tetrixboard.h
        src/tetrixpiece.cpp src/tetrixpiece.h
        src/userdialog.cpp src/userdialog.h
        src/usermanager.cpp src/usermanager.h src/userinfo.cpp src/userinfo.h)
add_executable(QtTetrix ${SOURCE_FILES})

target_link_libraries(QtTetrix Qt5::Widgets)