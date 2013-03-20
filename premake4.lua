solution "lab2.c"
configurations { "Debug", "Release" }

project "lab2"
kind "ConsoleApp"
language "C"
files { "**.h", "**.c" }

configuration "Debug"
defines { "DEBUG" }
flags { "ExtraWarnings", "Symbols" }

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }