project(Final)

#add_definitions(-DTESTCODE)

file(GLOB SOURCES "./*.cpp")

add_library(test STATIC test.c)
add_executable(FinalProject2 ${SOURCES})

#install(TARGETS FinalProject2 SOURCES Source.cpp)