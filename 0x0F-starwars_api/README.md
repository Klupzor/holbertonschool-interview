0x0F. Star Wars API
===================

Info
---------

### Install Node 10

```
$ curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
$ sudo apt-get install -y nodejs

```

### Install semi-standard

```
$ sudo npm install semistandard --global

```

### Install `request` module and use it

```
$ sudo npm install request --global
$ export NODE_PATH=/usr/lib/node_modules

```

* * * * *

Task
-----

#### Star Wars Characters

Write a script that prints all characters of a Star Wars movie:

-   The first positional argument passed is the Movie ID - example: `3` = "Return of the Jedi"
-   Display one character name per line **in the same order as the "characters" list in the `/films/` endpoint**
-   You must use the [Star wars API](https://swapi-api.hbtn.io/ "Star wars API")
-   You must use the `request` module

```
alexa@ubuntu:~/0x0F$ ./0-starwars_characters.js 3
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
alexa@ubuntu:~/0x0F$

```