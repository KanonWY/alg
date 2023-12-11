
file(GLOB MY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

set(EXEC_NAME_LIST "")
foreach(FILE_PATH ${MY_FILES})
    get_filename_component(FILE_NAME ${FILE_PATH} NAME_WE)
    list(APPEND EXEC_NAME_LIST ${FILE_NAME})
endforeach()


foreach(demo_name ${EXEC_NAME_LIST})
    add_executable(${demo_name} src/${demo_name}.cpp)
endforeach()
