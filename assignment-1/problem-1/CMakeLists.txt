
file(GLOB src_files *.h *.cc)
add_executable(pcbuilder ${src_files})
target_link_libraries(pcbuilder PRIVATE fmt::fmt)
