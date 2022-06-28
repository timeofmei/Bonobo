include_directories(include)

add_subdirectory(lexer)
add_subdirectory(token)
add_subdirectory(repl)
add_subdirectory(tests)

add_executable(Bonobo01 main.cpp)

target_link_libraries(Bonobo01 token)
target_link_libraries(Bonobo01 lexer)
target_link_libraries(Bonobo01 repl)