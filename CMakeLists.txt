cmake_minimum_required(VERSION 3.13)
project(klases)


set(CMAKE_CXX_STANDARD 14)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")


add_executable(klases main.cpp galvininkas.h kontrole.cpp Komandos-X.cpp Proza.cpp Generacija.cpp NumerisVienasStrategija.cpp NumerisDuStrategija.cpp Viktor.h Viktoro_iteratorius.h  )

