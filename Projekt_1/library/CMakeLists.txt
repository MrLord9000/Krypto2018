cmake_minimum_required(VERSION 3.4)

project(Library)

set(SOURCE_FILES
		src/fileInput.cpp
		src/algorithmDES.cpp
		)
		
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

#==== SEKCJA TESTÓW ====

# find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

# include_directories(
		# ${CMAKE_CURRENT_SOURCE_DIR}/include/model
		# ${Boost_INCLUDE_DIRS}
# )


# set(SOURCE_TEST_CLIENT_FILES
		# tests/master.cpp
		# tests/ClientTest.cpp	
# )

# add_executable(TestClient ${SOURCE_TEST_CLIENT_FILES})

# target_link_libraries(
		# TestClient
		# Library
		# ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
# )

# enable_testing()

# add_test(TestLib1 TestClient
		# --report_level=detailed
		# --log_level=all
		# --color_output=yes
		# )

# add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        # ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        # WORKING_DIRECTORY ${CMAKE_BINARY_DIR})