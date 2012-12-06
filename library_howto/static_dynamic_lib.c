/*
 * Static and Dynamic libraries.
 *
 * Static libraries are simple archives which hold bunch of C object files (.o)
 * The linker will search and use the appropriate object file while compiling.
 *
 * The extension of this archive file (Static library) is ".a" instead of ".o".
 *
 * To create an archive library or static library.
 *
 * $ ar cr testlib.a test1.o test2.o
 *
 * To link the library while compiling use, -Itest
 *
 * $ gcc -o app -L. -ltest app.o  
 *
 * This method will cause problem since the
 * reference to the f() only happen inside app.o, and after that linker
 * doesn't seen any library to search for that symbol.
 *
 * So it's better to put the library linking statements at the end of the 
 * command. Like bellow.
 *
 * $ gcc -o app app.o -L. -ltest 
 *
 * In the current diractory you should have "libtest.a" static library to 
 * linking this application together.
 *
 *
 *
 * Dynamic linked library or Shared library
 *
 * Shared libraries are similar to the static libraries like a collection of 
 * object files, but while creating the executatble it wont include the codes
 * of library in it, instead it only include a reference to the shared library.
 *
 * So the same shared library can be referenced by different executables and
 * system only keep one copy of the shared library on the memory(Postion
 * Independent Code) and other executables use them when every required via
 * the reference build in it.
 *
 * To create shared library we have to comile the source file with -fPIC
 * option.
 *
 * $ gcc -c -fPIC test.c
 *
 * After creating object files we can compine them together with gcc command
 * itself.
 *
 * $ gcc -shared -fPIC -o libtest.so test.o, ...
 *
 * To link the shared library and creating executable is done by this way
 *
 * $ gcc -o app app.o -L. -ltest
 *
 * If the given module path has .so or .a library it will pick .so by default
 * other wise it will stop searching once it get either of the library from
 * the given directory and then from system paths.
 *
 * The executable doesn't hold the full path to the shared library, only the
 * library name. By default when the program run it search for the library from
 * the system paths(/lib and /usr/lib), which is defined by LD_LIBRARY_PATH. 
 *
 * Use "-Wl,-rpath" Option to link the shared library from custom path. Or you
 * can use the LD_LIBRARY_PATH variable to set the full path like PATH
 * variable. The linker will search there first.
 *
 * $ gcc -o app app.o -L. -ltest -Wl,-rpath,`pwd`
 * 
 * Check for our shared library got loaded properly or not.
 * $ ldd app 
 *
 */
