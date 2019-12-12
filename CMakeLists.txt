cmake_minimum_required(VERSION 3.15)
project(CProgramming_MyBuilding)
set(CMAKE_CXX_STANDARD )
add_executable(CProgramming_MyBuilding
        source_files/cycle.c
        header_files/cycle.h
        source_files/file.c
        header_files/file.h
        source_files/gotoyx.c
        header_files/gotoyx.h
        header_files/land.h
        source_files/main.c
        source_files/minigame.c
        header_files/minigame.h
        source_files/money.c
        header_files/money.h
        source_files/player.c
        header_files/player.h
        source_files/random.c
        header_files/random.h
        source_files/resident.c
        header_files/resident.h
        source_files/show.c
        header_files/show.h
        source_files/land.c

        source_files/intro_1.c
        header_files/intro_1.h
        source_files/ending.c
        header_files/ending.h
        source_files/ending_file.c
        header_files/ending_file.h
        source_files/func.c
        header_files/func.h
        header_files/release.h
        source_files/release.c

        minigame/minigamegotoyx.c
        minigame/minigamegotoyx.h
        minigame/class.h
        minigame/maingame.c
        minigame/maingame.h
        minigame/class.c
        )

target_link_libraries(CProgramming_MyBuilding winmm.lib)