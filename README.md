# forca

###### O projeto é apenas uma abstração simples do jogo forca, onde deve-se tentar adivinhar a palavra letra a letra.

para compilar o projeto, você deve instalar o compilador gcc, mas caso esteja utilizando algum sistema UNIX, ele já vem instalado por padrão.

para executar o programa:

``` bash
 gcc forca.c -o "nome a ser dado"
 
 gcc forca.c -o forca
```

para utilizar o programa basta utilizar o executável e um arquivo de texto que contenha palavras:

``` bash
./nome-dado arquivo-de-palavras.txt
./forca /usr/share/dict/brazilian
```

o programa é encerrado quando o número 0 (zero) é inserido ou quando a palavra é completada. 
