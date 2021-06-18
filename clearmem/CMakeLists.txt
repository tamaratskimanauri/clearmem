# CMakeList.txt: проект CMake для clearmem; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (clearmem "clearmem.cpp" "clearmem.h")
target_link_libraries(clearmem PUBLIC sfml-graphics sfml-window sfml-system)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Fonts/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Fonts/)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
