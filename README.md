imagejs
=======

Small tool to package javascript into a valid image file.  
Currently supported are gif and bmp.

Usage:

Run 'make' to compile and then run 'imagejs option jsfile.js'
The outcoming image file will be named like the input file + the image ending..
Options are currently bmp and gif.

Example:

`$ ./imagejs gif code.js`  
will return a file named code.js.gif

You can download compiled binaries at [jklmnn.de](http://jklmnn.de/index.php?nav=projects&site=imagejs).  

Background:
-----------

This tool allows you to create a picture file that is able to run javascript code.
A file like this is able to extend XSS vulnerabilities. For example, if you are able to put a script tag on a website but cant run the script because it only runs scripts from this website, you can just upload e.g. a profile picture containing the code you want to run.
The idea came from [Ajin Abraham](http://iamajin.blogspot.in/2014/11/when-gifs-serve-javascript.html) and i put it in c code and also added the ability to do the same thing also with bitmap files.
