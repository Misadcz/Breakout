- Program zacne vystrelem micku, padlo se ovlada pomoci mysi

- po sestreleni vsech bloku hrac vyhraje 
- po vyleteni micku se ubere zivot, hrac ma 3 zivoty
- po vycerpani vsech zivotu hrac prohraje a tim se ukonci hra s textem "PROHRA"
- hrac sbira score za bloky

- soubor position.txt slouzi pro pozice bloku X (od leve strany) a Y (od horni strany)

- pri sestreleni bloku blok zmizi a micek se od neho odrazi

bodovani bloku : 1, 2, 5, 10, 20 a 50



program se spousti pomoci Cmake souboru
ve sloze s projektem napiseme
(cmake .)
nasledne prejit do vytvorene slozky CMakeFiles
nasledni prejit do slozky breakout.dir
a v souboru link.txt prepsat obsah souboru na:
-----
/usr/bin/cc  -fsanitize=address   CMakeFiles/breakout.dir/main.c.o CMakeFiles/breakout.dir/breakout.c.o CMakeFiles/breakout.dir/ttf.c.o CMakeFiles/breakout.dir/brick.c.o  -o breakout  -lSDL2 -lSDL2_image -lSDL2 -lSDL2_ttf -lSDL2 -lSDL2_image -lSDL2_ttf 
-----
nasledne se vratime do terminalu a napiseme
(make)
a pak
(./breakout)

