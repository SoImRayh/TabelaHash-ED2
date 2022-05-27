cmake_minimum_required(VERSION 3.22)
project(trabalho_EDll C)

set(CMAKE_C_STANDARD 11)

include_directories(Atividade05)

add_executable(trabalho_EDll
        Atividade05/main.c
        Atividade05/TabelaHash.c
        Atividade05/TabelaHash.h)
