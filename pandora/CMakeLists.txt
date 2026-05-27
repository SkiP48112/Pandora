#
# pandora
#

set(SOURCES
	vendor/stb/stb_image.h
	vendor/stb/stb_image.cpp
	vendor/imgui/imconfig.h
	vendor/imgui/imgui.h
	vendor/imgui/imgui.cpp
	vendor/imgui/imgui_demo.cpp
	vendor/imgui/imgui_draw.cpp
	vendor/imgui/imgui_impl_glfw.h
	vendor/imgui/imgui_impl_glfw.cpp
	vendor/imgui/imgui_impl_opengl3.h
	vendor/imgui/imgui_impl_opengl3.cpp
	vendor/imgui/imgui_impl_opengl3_loader.h
	vendor/imgui/imgui_internal.h
	vendor/imgui/imgui_tables.cpp
	vendor/imgui/imgui_widgets.cpp
	vendor/imgui/imstb_rectpack.h
	vendor/imgui/imstb_textedit.h
	vendor/imgui/imstb_truetype.h
)

add_library(pandora SHARED)

target_sources(pandora PRIVATE ${SOURCES})

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_compile_definitions(pandora PUBLIC GLFW_INCLUDE_NONE)

target_link_libraries(pandora glfw)
target_link_libraries(pandora glad)
target_link_libraries(pandora glm)

target_include_directories(pandora PUBLIC src)
target_include_directories(pandora PUBLIC vendor)