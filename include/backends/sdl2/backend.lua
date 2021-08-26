table.insert(backends_names, "SDL2/gfx")

backends_configs["SDL2/gfx"] = {
    packages = {"libsdl", "libsdl_image", "libsdl_gfx"},
    dirname = "sdl2",
    extra = function() --[[ Nothing to do ]] end
}
