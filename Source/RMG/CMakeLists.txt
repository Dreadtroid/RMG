#
# Rosalie's Mupen GUI CMakeLists.txt
#
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Gui Widgets Core REQUIRED)

if (UPDATER)
find_package(Qt5 COMPONENTS Network REQUIRED)
add_definitions(-DUPDATER)
endif(UPDATER)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

configure_file(Config.hpp.in Config.hpp)

set(RMG_SOURCES
    UserInterface/MainWindow.cpp
    UserInterface/Widget/RomBrowserWidget.cpp
    UserInterface/Widget/OGLWidget.cpp
    UserInterface/Widget/KeybindButton.cpp
    UserInterface/Dialog/SettingsDialog.cpp
    UserInterface/Dialog/SettingsDialog.ui
    UserInterface/Dialog/SettingsDialog.qrc
    UserInterface/Dialog/CheatsDialog.cpp
    UserInterface/Dialog/CheatsDialog.ui
    UserInterface/Dialog/AddCheatDialog.cpp
    UserInterface/Dialog/AddCheatDialog.ui
    UserInterface/Dialog/ChooseCheatOptionDialog.cpp
    UserInterface/Dialog/ChooseCheatOptionDialog.ui
    UserInterface/Dialog/RomInfoDialog.cpp
    UserInterface/Dialog/RomInfoDialog.ui
    UserInterface/Dialog/AboutDialog.cpp
    UserInterface/Dialog/AboutDialog.ui
    UserInterface/NoFocusDelegate.cpp
    UserInterface/EventFilter.cpp
    UserInterface/UIResources.rc
    UserInterface/UIResources.qrc
    Thread/RomSearcherThread.cpp
    Thread/EmulationThread.cpp
    Utilities/QtKeyToSdl2Key.cpp
    Callbacks.cpp
    VidExt.cpp
    main.cpp
)

if (UPDATER)
list(APPEND RMG_SOURCES
    UserInterface/Dialog/UpdateDialog.cpp
    UserInterface/Dialog/UpdateDialog.ui
    UserInterface/Dialog/DownloadUpdateDialog.cpp
    UserInterface/Dialog/DownloadUpdateDialog.ui
    UserInterface/Dialog/InstallUpdateDialog.cpp
    UserInterface/Dialog/InstallUpdateDialog.ui
)
endif(UPDATER)

if (CMAKE_BUILD_TYPE MATCHES Release)
    add_executable(RMG WIN32 ${RMG_SOURCES})
else()
    add_executable(RMG ${RMG_SOURCES})
endif()

target_link_libraries(RMG 
    RMG-Core
    ${SDL2_LIBRARIES}
)

target_include_directories(RMG PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(RMG Qt5::Gui Qt5::Widgets)

if (UPDATER)
target_link_libraries(RMG Qt5::Network)
endif(UPDATER)

