
file(GLOB src_files *.h *.cc)
add_executable(examcontroller ${src_files})
target_link_libraries(examcontroller  PRIVATE fmt::fmt)
