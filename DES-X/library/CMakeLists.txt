cmake_minimum_required(VERSION 3.4)

project(Library)

set(SOURCE_FILES
		src/Key.cpp
		src/Misc.cpp
		src/Block.cpp
		src/Des.cpp
		src/Des_algorithms.cpp
		src/FileIO.cpp
		src/CarriageControl.cpp
		)
		
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

#==== SEKCJA TESTÓW ====

# find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

# include_directories(
# 		${CMAKE_CURRENT_SOURCE_DIR}/include/model
# 		${Boost_INCLUDE_DIRS}
# )


# set(SOURCE_TEST_CLIENT_FILES
# 		tests/master.cpp
# 		tests/KeyTest.cpp
# 		tests/SboxTest.cpp	
# )

# add_executable(KeyTest ${SOURCE_TEST_CLIENT_FILES})

# target_link_libraries(
# 		KeyTest
# 		Library
# 		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
# )

# enable_testing()

# add_test(TestLib1 KeyTest
# 		--report_level=detailed
# 		--log_level=all
# 		--color_output=yes
# 		)

# # add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
# #         ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
# # 		WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
		
# add_executable(SboxTest ${SOURCE_TEST_CLIENT_FILES})

# target_link_libraries(
# 		SboxTest
# 		Library
# 		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
# )

# enable_testing()

# add_test(TestLib1 SboxTest
# 		--report_level=detailed
# 		--log_level=all
# 		--color_output=yes
# 		)

# add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
# 		${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
# 		WORKING_DIRECTORY ${CMAKE_BINARY_DIR})