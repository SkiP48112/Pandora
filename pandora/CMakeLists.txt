#
# pandora
#

set(SOURCES
	src/pandora.h
	src/core/core.h
	src/core/application.h
	src/core/application.cpp
	src/core/entry_point.h
	src/core/log.h
	src/core/log.cpp
	src/events/event.h
	src/events/mouse_event.h
	src/events/key_event.h
	src/events/application_event.h
	src/events/window_event.h
)

add_library(pandora SHARED)

target_sources(pandora PRIVATE ${SOURCES})

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_compile_definitions(pandora PUBLIC  GLFW_INCLUDE_NONE)
target_compile_definitions(pandora PRIVATE PANDORA_BUILD_DLL)

target_link_libraries(pandora glfw)
target_link_libraries(pandora glad)
target_link_libraries(pandora glm)
target_link_libraries(pandora stb_image)
target_link_libraries(pandora spdlog)
target_link_libraries(pandora imgui)

target_include_directories(pandora PUBLIC src)

set(PCH_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/pandora_pch.h")

target_precompile_headers(pandora PRIVATE ${PCH_PATH})
if(MSVC)
    target_compile_options(pandora PRIVATE /FI${PCH_PATH})
endif()
