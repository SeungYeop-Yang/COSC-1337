add_library(mylib STATIC lib.cpp)
#add_library(mylib SHARED lib.cpp)

target_include_directories(mylib
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})

#PRIVATE
#PUBLIC
#INTERFACE
