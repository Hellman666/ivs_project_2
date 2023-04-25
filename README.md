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

# Prerekvizity
--------------
- Powershell
- Doxygen
    - Pro vygenerování programátorské dokumentace
- Instalace Qt Open Source:
    - Na stránce [QT Open Source - Download](https://www.qt.io/download-open-source) stažení instalátoru
        - V instalaci zvolit možnosti pro MinGW 64
    - Přidání "*Cesta_ke_QT*\\*Vase_verze*\mingw_64\bin" do PATH
- Instalace Inno Setup
    - Na stránce [Inno Setup Download](https://jrsoftware.org/isdl.php) stažení instalátoru (innosetup-6.2.2.exe)
    - Přidat Inno Setup program (ISCC.exe) do PATH
- stažení MSYS2 a potřebných nástrojů
    - na stránce [MSYS2](https://www.msys2.org/) stažení instalátoru
    - v MSYS2/MSYS2 MINGW64 konzoli spusťte následující příkazy:
        - pacman -S mingw-w64-x86_64-toolchain
        - pacman -S mingw-w64-x86_64-cmake
        - přidání "*Cesta_k_msys64*\mingw64\bin" do PATH
- Instalace Make (2 možnosti):
    - Na stránce [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm)
        - Přidání cesty k make do PATH
    - Nebo pacman -S mingw-w64-x86_64-make
        - Stáhne mingw32-make.exe (je potřeba vytvořit symbolický link pomocí příkazu mklink make mingw32-make.exe)
- V Makefile na řádku 11 nastavení proměnné na cestu k programu windeployqt.exe (součást QT)
- Nastavení proměnných v souboru .env.cmake (ukázka v CMakeLists.txt)

(Tento build setup byl otestován na čisté instalaci Windows 10)

# Build
-------
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

