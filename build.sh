#!/usr/bin/bash

export CMAKE_EXPORT_COMPILE_COMMANDS=1

cmake -B Build

cmake --build Build
