-- This file processes other backends and selects the current backend options

-- For `backend.lua` files in subdirectories of `include/backends`
backends_names   = {} -- Only strings should be added here
backends_configs = {} -- Name -> configuration table(packages, dirname, extra)
--[[
    The members of the description table will be assigned to the variables
    below if the backend is selected
]]

backend_packages = {}  -- Packages to require
backend_dirname  = "." -- The directory in `src/backends` and `include/backends`
backend_extra    = function() end -- Extra steps to perform in the target scope

includes "sdl2/backend.lua"

option "fejix_backend"
    set_showmenu(true)
    set_description "Fejix backend"

    set_values(backends_names)
    set_default(backends_names[1])
option_end()

-- Find what backend is currently selected
for name, config in pairs(backends_configs) do
    -- If the name matches
    if is_config("fejix_backend", name) then
        -- Assign the backend's config to the global config
        backend_packages = config["packages"]
        backend_dirname  = config["dirname"]
        backend_extra    = config["extra"]
    end
end

-- Call in the global scope in `xmake.lua`
-- Requires all packages needed for the selected backend
function add_backend_requires()
    add_requires(backend_packages)
end

-- Call in a target scope in `xmake.lua`
function add_backend()
    add_options "fejix_backend"

    add_files("src/backends/"..backend_dirname.."/*.c")
    add_includedirs("include/backends/"..backend_dirname)

    backend_extra()

    add_packages(backend_packages)
end