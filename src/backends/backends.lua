backend_packages   = {}             -- Packages to require
backend_dirname    = "."            -- The directory in src/backends and include/backends
backend_additional = function() end -- Additional steps to perform

option("fejix_backend_option")
    set_showmenu(true)
    set_description("Fejix backend")

    -- The following argument list may be extended in the future
    set_values({
        "SDL2/gfx"
    })
    set_default("SDL2/gfx")
option_end()

-- Some backend_ variables can be redefined in the following config checks

if is_config("backend", "SDL2/gfx") then
    backend_packages = {"libsdl", "libsdl_image", "libsdl_gfx"}
    backend_dirname = "sdl2"
end

-- More checks may be added in the future


-- Call in the global scope
-- Requires all packages needed for the selected backend
function add_backend_requires()
    for i, package in ipairs(backend_packages) do
        add_requires(package)
    end
end

-- Call in a target scope
function add_backend()
    add_options("fejix_backend_option")

    add_files("src/backends/"..backend_dirname.."/*.c")
    add_includedirs("include/backends/"..backend_dirname)

    backend_additional()

    for i, package in ipairs(backend_packages) do
        add_packages(package)
    end
end