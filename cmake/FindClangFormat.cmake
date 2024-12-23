find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)
mark_as_advanced(CLANG_FORMAT_EXECUTABLE)

function(enable_clang_format)
    if(CLANG_FORMAT_EXECUTABLE)
        add_custom_target(clang-format
                COMMAND
                ${CLANG_FORMAT_EXECUTABLE}
                -i
                -style=file
                "${CMAKE_SOURCE_DIR}/src/numeric/*.c"
                "${CMAKE_SOURCE_DIR}/src/numeric/*.h"
                "${CMAKE_SOURCE_DIR}/test/numeric/*.c"
                COMMENT "Format sources."
        )
    endif(CLANG_FORMAT_EXECUTABLE)
endfunction(enable_clang_format)