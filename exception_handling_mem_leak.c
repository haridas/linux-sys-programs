#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

/* WRITE MEMORY LEAK PROOF PROGRAMS ON C */

/* C doesn't have the try/catch or exception handling methods. Instead it
 * won't crash the call to low level systems or the system calls won't crash
 * it return status code if succeed/faild. The calling function has to handle
 * the return codes and make sure that we are not letting the systems calls
 * got sufficent protuction around to check the return value of all the 
 * system calls.
 */

/* One example method, that opens a file and try to check for all the 
 * error codes and make sure that it won't fail the application program.
 *
 * If we are exiting the program the unclosed fds and other buffer allocations
 * will get deallocated by the OS, but if we are creating files or other
 * resources which need to be cleaned off by ourself.
 */

char* read_from_file(const char* filename, size_t length)
{
    char* buffer;
    int fd;
    ssize_t bytes_read;

    /* Allocate the buffer. */
    buffer = (char*) malloc(length);
    if(buffer == NULL)
        /* malloc return null point if it faild to 
         * allocate memory */
        return NULL;

    /* Open the file */
    fd = open(filename, O_RDONLY);

    if(fd == -1)
    {
        /* open faild. Deallocate buffer allocated. */
        free(buffer);
        return NULL;
    }

    /* Read the data. */
    bytes_read = read(fd, buffer, length);

    if(bytes_read != length){
        /* Read operation faild. Deallocate buffer and
         * close fd before returning. */
        free(buffer);
        close(fd);
    }

    /* Everything's fine. Close the fd and return buffer. */
    close(fd);
    return buffer;
}


