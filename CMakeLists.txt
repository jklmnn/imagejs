cmake_minimum_required(VERSION 2.6)
project(imagejs)

set (VERSION_MAJ 0)
set (VERSION_MIN 7)
set (VERSION_FIX 3)
set (AUTHOR jklmnn)
set (HOMEPAGE https://github.com/jklmnn/imagejs)
set (LICENSE GPLv3)

configure_file (
    "${PROJECT_SOURCE_DIR}/meta.h.in"
    "${PROJECT_BINARY_DIR}/meta.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(imagejs main.c bmp.c pgf.c pnm.c webp.c gif.c)
