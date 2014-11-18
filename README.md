imagejs
=======

Small tool to package javascript into a valid image file.  
Currently supported are gif and bmp.

Usage:

Run 'make' to compile and then run 'imagejs option jsfile.js'
The outcoming image file will be named like the input file + the image ending..
Options are currently bmp, gif, webp, pnm and pgf.

If you add -l as flag you your image is written to the file so that you can open it and view your code as a line of pixels.  
This is currently only supported for bmp files.

Example:

`$ ./imagejs bmp code.js -l`  
will return a file named code.js.bmp that is viewable.

Code can now be embedded into existing gif files by using the flag `-i` with a gif file as argument.  
Example:  
`$ ./imagejs gif code.js -i giffile.gif`

This is currently available for gif, bmp, webp, where webp is still beta.

For more information and to view an example image visit [jklmnn.de](http://jklmnn.de/imagejs/).  

Supported output files are: gif, bmp, webp, pnm, pgf  

Background:
-----------

This tool allows you to create a picture file that is able to run javascript code.
A file like this is able to extend XSS vulnerabilities. For example, if you are able to put a script tag on a website but cant run the script because it only runs scripts from this website, you can just upload e.g. a profile picture containing the code you want to run.
The idea came from [Ajin Abraham](http://iamajin.blogspot.in/2014/11/when-gifs-serve-javascript.html) and i put it in c code and also added the ability to do the same thing also with bitmap files.
