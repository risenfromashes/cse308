
file(GLOB src_files *.h *.cc)
add_executable(composite ${src_files})
target_link_libraries(composite PRIVATE fmt::fmt)
