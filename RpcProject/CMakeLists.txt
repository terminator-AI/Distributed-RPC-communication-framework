cmake_minimum_required(VERSION 3.0)
project(mprpc)

#可执行文件输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#库文件输出位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_BUILD_TYPE "Debug")

#头文件
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)

#链接库
link_libraries(${PROJECT_SOURCE_DIR}/lib)

#cmake子目录
add_subdirectory(src)
add_subdirectory(example)