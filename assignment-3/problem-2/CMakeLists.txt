
file(GLOB src_files *.h *.cc)
add_executable(cafe ${src_files})
target_link_libraries(cafe  PRIVATE fmt::fmt)
