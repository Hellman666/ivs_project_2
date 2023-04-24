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

- Stažení Qt Open Source:
    - Na stránce [QT Open Source - Download](https://www.qt.io/download-open-source) stažení instalátoru
        - V instalaci zvolit možnosti pro MinGW 64
- Nastavení proměnných v souboru .env.cmake (ukázka v CMakeLists.txt)
- Vytvoření prázdné složky build
1. Možnost:
   - Vytvoření prázdné složky build
   - Ve složce build:
       - `cmake .. -G "Ninja"`
       - `cmake --build .`
2. Možnost:
   - Ve složce src:
     - Spuštění příkazu `make all`

# Spuštění
----------
1. Možnost:
   - Ve složce build:
       - `.\math_test.exe`
2. Možnost:
   - Ve složce src:
     - `make test`

