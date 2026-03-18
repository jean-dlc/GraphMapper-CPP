QT += widgets

TARGET = Projet
TEMPLATE = app

# Dis à Qt de chercher les .hpp aussi dans le dossier src
INCLUDEPATH += src

# SOURCES : Ajout de src/MapSolver.cpp
SOURCES += src/main.cpp \
           src/window.cpp \
           src/render_area.cpp \
           src/map.cpp \
           src/Case.cpp \
           src/ivec2.cpp \
           src/MapSolver.cpp

# HEADERS : Ajout de src/MapSolver.hpp
HEADERS += src/window.hpp \
           src/render_area.hpp \
           src/map.hpp \
           src/Case.hpp \
           src/ivec2.hpp \
           src/MapSolver.hpp