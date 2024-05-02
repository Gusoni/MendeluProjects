cmake_minimum_required(VERSION 3.16)

project(Cpp_Group_Project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appCpp_Group_Project
    main.cpp
)

qt_add_qml_module(appCpp_Group_Project
    URI Cpp_Group_Project
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES gameengine.h gameengine.cpp
    SOURCES world.h world.cpp
    SOURCES location.h location.cpp
    SOURCES player.h player.cpp
    SOURCES npc.h npc.cpp
    SOURCES monster.h monster.cpp
    SOURCES inventory.h inventory.cpp
    SOURCES weapon.h weapon.cpp
    SOURCES armor.h armor.cpp
    SOURCES potion.h potion.cpp
    SOURCES quest.h quest.cpp
    SOURCES obstacle.h obstacle.cpp
    QML_FILES Menu.qml
    QML_FILES MenuButton.qml
    QML_FILES Location.qml
    QML_FILES Tile.qml
    SOURCES
    SOURCES gameobject.h
    RESOURCES images/armor.png images/grass.png images/homescreen.png images/monster.png images/npc.png images/player.png images/weapon.png images/wall.png images/potion.png images/slot.png
    QML_FILES PlayerStats.qml
    RESOURCES images/heart.png
    QML_FILES StatsRow.qml
    QML_FILES
    QML_FILES Inventory.qml
    QML_FILES Slot.qml
    QML_FILES FightWindow.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCpp_Group_Project PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCpp_Group_Project
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCpp_Group_Project
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCpp_Group_Project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
