set_xmakever "2.5.0"
set_project "Fejix"
set_version "0.0.0"

includes "include/backends/backends.lua"

add_backend_requires()


target "fejix"
    set_kind "static"

    add_files "src/*.c"
    add_includedirs "include"
    
    add_backend()


target "fejix_test"

    set_kind "binary"

    add_files "src/test.c"
    add_includedirs "include"

    add_deps "fejix"
