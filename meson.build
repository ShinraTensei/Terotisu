project('Terotisu', 'cpp')

inc_dir = include_directories('src/include')
sdl2_dep = dependency('sdl2')
sdl2_img = dependency('SDL2_image')

executable('Terotisu', 'src/main.cpp', 'src/Game.cpp', 'src/Tile.cpp', include_directories : inc_dir, dependencies : [sdl2_dep ,sdl2_img])
