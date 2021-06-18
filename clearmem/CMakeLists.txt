# CMakeList.txt: проект CMake для clearmem; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (clearmem "clearmem.cpp")
target_link_libraries(clearmem PUBLIC sfml-graphics sfml-window sfml-system)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Fonts/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Fonts/)
add_executable (clearmem_test "clearmem_test.cpp")
target_link_libraries(clearmem_test PUBLIC sfml-graphics sfml-window sfml-system doctest::doctest default)
doctest_discover_tests(clearmem_test)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
