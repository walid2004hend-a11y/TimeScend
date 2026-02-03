cmake_minimum_required(VERSION 3.20)
project(TimeScend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(timescend_core
    core/ActionDispatcher.cpp
    core/Engine.cpp
    core/EventBus.cpp
    core/ModeController.cpp
    core/StateManager.cpp
)

target_include_directories(timescend_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(timescend_scheduler
    scheduler/PolicyCompiler.cpp
    scheduler/RuleEngine.cpp
    scheduler/TimeEngine.cpp
    scheduler/TriggerSystem.cpp
)

target_include_directories(timescend_scheduler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_scheduler PUBLIC timescend_core)

add_library(timescend_system
    system/PowerManager.cpp
    system/ProcessKiller.cpp
    system/ProcessMonitor.cpp
    system/StartupManager.cpp
    system/WindowController.cpp
)

target_include_directories(timescend_system PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_system PUBLIC timescend_core)

add_library(timescend_security
    security/AntiDebug.cpp
    security/AntiKill.cpp
    security/IntegrityGuard.cpp
    security/PermissionGuard.cpp
    security/ServiceProtector.cpp
)

target_include_directories(timescend_security PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_security PUBLIC timescend_core)

add_library(timescend_service
    service/IPCServer.cpp
    service/ServiceMain.cpp
    service/Watchdog.cpp
)

target_include_directories(timescend_service PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_service PUBLIC timescend_core timescend_security)

add_library(timescend_persistence
    persistence/BackupManager.cpp
    persistence/Database.cpp
    persistence/MigrationManager.cpp
)

target_include_directories(timescend_persistence PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_persistence PUBLIC timescend_core)

add_library(timescend_analytics
    analytics/ReportGenerator.cpp
    analytics/ScoreCalculator.cpp
    analytics/UsageTracker.cpp
)

target_include_directories(timescend_analytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_analytics PUBLIC timescend_core)

add_library(timescend_ui
    ui/Client.cpp
)

target_include_directories(timescend_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_ui PUBLIC timescend_core)

add_library(timescend_installer
    installer/Installer.cpp
)

target_include_directories(timescend_installer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(timescend_installer PUBLIC timescend_core)

add_library(timescend_config
    config/Config.cpp
)

target_include_directories(timescend_config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(TimeScend
    main/main.cpp
)

target_link_libraries(TimeScend
    PRIVATE
        timescend_core
        timescend_scheduler
        timescend_system
        timescend_security
        timescend_service
        timescend_persistence
        timescend_analytics
        timescend_ui
        timescend_installer
        timescend_config
)
