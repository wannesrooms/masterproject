Name: Wannes Rooms

Student Number: s0211140

I've tested the program in MacOS (M1 chip), this should be simular to Linux. 



How to run:

cmake -S . -B build -G Ninja -DCMAKE_PREFIX_PATH="$(brew --prefix)/opt/sfml@2"

cmake --build build

(cd Ghana_Jump && ../build/GhanaJump)
