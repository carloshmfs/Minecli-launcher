add_rules("plugin.compile_commands.autoupdate", { outputdir = "." })

add_requires("cpr")

target("minecli")
    set_kind("binary")
    add_files("minecli/*.cpp")
    add_packages("cpr")
