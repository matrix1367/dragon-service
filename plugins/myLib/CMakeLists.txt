cmake_minimum_required (VERSION 2.8.11)
project (Dragon-myLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/.)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(${PROJECT_BINARY_DIR})


 #SET (CMAKE_C_STANDARD_LIBRARIES_INIT "kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib shlwapi.lib Gdi32.lib ")

add_library (${PROJECT_NAME}  SHARED 
			src/MyLib.cpp
			myLib.rc
			main.cpp
)
			
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
include (GenerateExportHeader)
GENERATE_EXPORT_HEADER( ${PROJECT_NAME}
             BASE_NAME ${PROJECT_NAME}
             EXPORT_MACRO_NAME ${PROJECT_NAME}_EXPORT
             EXPORT_FILE_NAME ${PROJECT_NAME}_Export.h
             STATIC_DEFINE ${PROJECT_NAME}_BUILT_AS_STATIC
)

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC shlwapi.lib)

install(TARGETS ${PROJECT_NAME} DESTINATION ${BUILD_DEBUG_DIR})
install(FILES
 ${PROJECT_NAME}_Export.h
 ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_Export.h DESTINATION ${PROJECT_BINARY_DIR}
)