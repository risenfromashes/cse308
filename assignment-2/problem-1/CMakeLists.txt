
file(GLOB src_files *.h *.cc)
add_executable(abcserver ${src_files})
target_link_libraries(abcserver PRIVATE fmt::fmt)
