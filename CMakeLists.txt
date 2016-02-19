cmake_minimum_required(VERSION 2.6)
project(Tutorial)

add_definitions(-Wall -Werror -pedantic)

include_directories(src/Doctor src/Patient src/Registration src/Shared)

file(GLOB DOC_SOURCE_FILES . src/Doctor/*.c src/Shared/*.c src/Doctor/*.h src/Shared/*.h) 
file(GLOB PAT_SOURCE_FILES . src/Patient/*.c src/Shared/*.c src/Patient/*.h src/Shared/*.h) 
file(GLOB REG_SOURCE_FILES . src/Registration/*.c src/Shared/*.c src/Registration/*.h src/Shared/*.h) 


set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

add_executable(Doctor ${DOC_SOURCE_FILES})
add_executable(Registration ${REG_SOURCE_FILES})
add_executable(Patient ${PAT_SOURCE_FILES})
