file(GLOB src_files *.h *.cc)
add_executable(carfactory ${src_files})
target_link_libraries(carfactory PRIVATE fmt::fmt)

