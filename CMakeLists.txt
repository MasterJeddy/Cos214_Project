cmake_minimum_required(VERSION 3.27)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project main.cpp InputPoll.cpp InputPoll.h UserCommand.cpp UserCommand.h UserCommand.h Commands.cpp Commands.h Update.cpp Update.h Save.cpp Save.h Load.cpp Load.h CommandLog.cpp CommandLog.h SavedLog.cpp SavedLog.h Logs.cpp Logs.h CommandLogIterator.cpp CommandLogIterator.h)
add_subdirectory(GTest)
