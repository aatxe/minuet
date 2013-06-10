# minuet #
minuet is a simple, lightweight utility library for C. It provides a small collection of things that might be useful for development along the way. In particular, it features a set of testing and debugging macros derived from [Zed Shaw](https://inculcate.me/school/instructors/1/)'s [dbg.h](http://c.learncodethehardway.org/book/ex20.html) and [minunit.h](http://c.learncodethehardway.org/book/ex30.html). It also features some other small utilities that I thought I might need in other places.

## Why minuet? ##
I decided to set up minuet in a way that makes it as natural as humanly possible to use directly within an application. As such, I came to the conclusion that the best way to do so would be by using [git submodules](https://www.kernel.org/pub/software/scm/git/docs/git-submodule.html). All you need to do is use `git submodule add -b master git://github.com/aaronweiss74/minuet.git src/minuet`. After that, you may wish to edit the update mode in .gitmodules to behave how you want. 

## Acknowledgements ##
* [Peter Atashian](https://github.com/retep998) for his help with [git submodules](https://www.kernel.org/pub/software/scm/git/docs/git-submodule.html).
* [Zed Shaw](https://inculcate.me/school/instructors/1/) for his work on [dbg.h](http://c.learncodethehardway.org/book/ex20.html) and [minunit.h](http://c.learncodethehardway.org/book/ex30.html).
* [Jera Design](http://www.jera.com/) for the original [minunit.h](http://www.jera.com/techinfo/jtns/jtn002.html).

## Licensing ##
pkgnx is licensed under the MIT License. The full license text can be found in LICENSE.md for your convenience.