macro(catch_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    target_link_libraries(${TESTNAME} token)
    target_link_libraries(${TESTNAME} lexer)
endmacro()

catch_add_test(test test.cpp)