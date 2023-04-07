# Prostředí
-----------
Windows 64bit

# Autoři
--------
tým Lorem Ipsum
- xborek12 Dominik Borek
- xhrubo01 Ondrej Hrubos
- xjestr04 Radek Jestrabik
- xkento00 Samuel Kentos 

# Licence
---------
Tento program je poskytovan pod licenci GNU. Muzete jej redistribuovat a/nebo upravovat
podle podminek GNU General Public License, jak je publikovana Free Software Foundation,
at uz verze 3 teto licence, nebo jakékoli pozdější verze.

Podivejte se na General Public License GNU pro vice informaci na adrese https://www.gnu.org/copyleft/gpl.html.

# Build
-------

- stažení MSYS2 a potřebných nástrojů
    - na stránce [MSYS2](https://www.msys2.org/) stažení instalátoru
    - v MSYS2/MSYS2 MINGW64 konzoli spusťte následující příkazy:
        - pacman -S mingw-w64-x86_64-toolchain
        - pacman -S mingw-w64-x86_64-cmake
        - pacman -S mingw-w64-x86_64-make
- Vytvoření prázdné složky build
- Ve složce build:
    - cmake .. -G "MinGW Makefiles"
    - cmake --build .

# Spuštění
----------
- Ve složce build:
    - math_test.exe
