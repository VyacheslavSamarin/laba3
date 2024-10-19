cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Вячеслав Самарин" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "vyacheslav_samarin@bk.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабораторная работа номер 3, вариант 33" CACHE STRING "")

project(figure_program VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Устанавливаем флаги компиляции
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wcast-align -Wconversion -Wsign-conversion -Wfloat-equal -Wpedantic -Werror -pedantic -O2")
endif()

# Добавляем исходные файлы
set(SOURCES
    src/Figure.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/main.cpp
)

# Добавляем заголовочные файлы
set(HEADERS
    include/Figure.h
    include/Triangle.h
    include/Square.h
    include/Rectangle.h
)

# Добавляем исполняемый файл
add_executable(figure_program ${SOURCES} ${HEADERS})

# Указываем директорию для заголовочных файлов
target_include_directories(figure_program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Добавляем поддиректорию для тестов, если она существует
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/googletest")
    add_subdirectory(
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
        "googletest"
    )

    set(
        TEST_SOURCES
        test/test_lab.cpp
    )

    # Исключаем main.cpp из тестов
    list(REMOVE_ITEM SOURCES src/main.cpp)

    add_executable(
        lab_1_tests
        ${TEST_SOURCES}
        ${SOURCES}  # Добавляем все исходные файлы, кроме main.cpp
    )

    target_include_directories(
        lab_1_tests PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    )

    target_link_libraries(
        lab_1_tests
        gtest 
        gtest_main
    )

    enable_testing()

    add_test(NAME ProjectTests COMMAND lab_1_tests)

    if (MSVC)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

        target_compile_options(
            lab_1_tests PRIVATE
            /W4
        )
    else ()
        target_compile_options(
            lab_1_tests PRIVATE
            -Wall
            -Wextra
            -Wshadow
            -Wcast-align
            -Wconversion
            -Wsign-conversion
            -Wfloat-equal
            -Wpedantic
            -Werror
            -pedantic
            -O2
        )
    endif()
endif()