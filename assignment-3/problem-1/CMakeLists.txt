
file(GLOB src_files *.h *.cc)
add_executable(amongus ${src_files})
target_link_libraries(amongus PRIVATE fmt::fmt)
