![Platformer Logo](Content/Logo/Platformer_large_logo.png?raw=true)
# Platformer
Description

> Version **v0.0.0-a.0**

## Screenshots
_Screenshots coming soon..._

## Roadmap
- [ ] TBD

## Documentation
_Documentation links, files or short paragraphs._
### Technician installation guide
This projects is only set for Windows at the moment
#### Prerequisites
- MinGW64
- C++ 11 or above
- SFML

To install MinGW I recommand using MSYS2 you can easily find it on the internet.

Once you got MSYS2, choose and open the MinGW64 terminal and type these
commands :
> pacman -S mingw-w64-x86_64-gcc

> pacman -S mingw-w64-x86_64-gdb

> pacman -S mingw-w64-x86_64-make

You can verify if your compiler, debugger and make are installed by typing these
commands :
> g++ --version

> gdb --version

> make --version

#### Installation
- git clone the projet in a safe directory
- create a /lib/SFML/ folder and copy-paste the lib/ folder content from your
SFML installation
- create a /include/SFML/ folder and copy paste the include/SFML/ folder content
from your SFML installation
- don't forget to add the bin/ folder of your SFML installation in the
environnement variables' PATH
### Developper preparation guide
Not much things to know here.

To build the project go in the project root folder in a terminal and type :
> make

To clean the build folder type :
> make clean

To execute the project type :
> ./build/game.exe

I personnaly use VS Code with my own project structure even if I try to use some
standards to make compatibility easier but you can use the IDE you want as long
as you know what you are doing.

## Developpers
> [Kydo](https://github.com/ErnestErgonomique) (Project Leader)
