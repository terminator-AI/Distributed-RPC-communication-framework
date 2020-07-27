#set(SRC_LIST calluserservice.cpp ../user.pb.cc)

set(SRC_LIST callfriends.cpp ../friend.pb.cc)

add_executable(requestor ${SRC_LIST})

target_link_libraries(requestor mprpc protobuf)