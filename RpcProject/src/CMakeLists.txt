aux_source_directory(. SRC_LISTS)

add_library(mprpc ${SRC_LISTS})

target_link_libraries(mprpc muduo_net muduo_base  pthread zookeeper_mt)