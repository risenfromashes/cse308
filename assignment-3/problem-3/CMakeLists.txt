
file(GLOB src_files *.h *.cc)
add_executable(vending_machine ${src_files})
target_link_libraries(vending_machine PRIVATE fmt::fmt)
