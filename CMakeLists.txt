cmake_minimum_required(VERSION 3.27)
project(code_tester)

set(CMAKE_CXX_STANDARD 14)

add_executable(code_tester
        .idea/.gitignore
        .idea/code_tester.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        main.cpp)
