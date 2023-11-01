# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google ../Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run tests.cpp ../InputPoll.cpp ../InputPoll.h ../UserCommand.cpp ../UserCommand.h ../UserCommand.h ../Commands.cpp ../Commands.h ../Update.cpp ../Update.h ../Save.cpp ../Save.h ../Load.cpp ../Load.h ../CommandLog.cpp ../CommandLog.h ../SavedLog.cpp ../SavedLog.h ../Logs.cpp ../Logs.h ../CommandLogIterator.cpp ../CommandLogIterator.h ../Clock.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)