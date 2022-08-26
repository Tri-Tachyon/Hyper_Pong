add_library(
        lib_hyper_pong STATIC
        items/abstractitem.hpp
        items/verticalracket.hpp
        items/verticalracket.cpp
        items/ball.hpp
        items/ball.cpp
        items/score.cpp items/score.hpp
        config.hpp
        game/ponggame.cpp game/ponggame.hpp
        items/abstractactiveitem.hpp
        items/abstractpassiveitem.hpp
        items/horisontalwall.cpp items/horisontalwall.hpp
        physengine/physengine.cpp physengine/physengine.hpp
        game/abstractgame.hpp)

target_include_directories(lib_hyper_pong PUBLIC ../) #Is this right? todo: