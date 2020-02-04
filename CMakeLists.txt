CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

PROJECT(Pocon)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(Include)

# Find the librarys here
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/Library)

ADD_EXECUTABLE(Pocon Main.cpp
        Source/ReaderFile.cpp
        Source/ReaderFile.hpp
        Source/Pocon.cpp
        Source/Pocon.hpp
        Source/IInterfaceGraphic.hpp
        Source/CommandLine.cpp
        Source/CommandLine.hpp
        Source/Exception.hpp
        Source/FileNotFoundException.hpp
        Source/Keyboard/Keyboard.cpp
        Source/Keyboard/Keyboard.hpp
        Source/Keyboard/KeyCode.hpp
        Source/Xml.cpp
        Source/Xml.hpp
        Source/WriterFile.cpp
        Source/WriterFile.hpp)

# Load and link the library Ana for manage XML files
TARGET_LINK_LIBRARIES(Pocon Ana)