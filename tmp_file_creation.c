#include<stdlib.h>
#include<unistd.h>


/* Temporary file handler (file descriptor). The write_temp_file function use
 * this to save the file descriptor.
 */

typedef int temp_file_handle;


/* This function create a temp file and write the content send to it, also
 * make sure that the temp file gets removed from the disk when the file
 * descriptor of that file got closed or program exit somehow.
 */
temp_file_handle write_temp_file(char* buffer, size_t length)
{
    /* Create the temp filename, XXXXXX will generate a random number so that
     * no two same file will be created. */
    char temp_filename[] = "tmp/tmp_file.XXXXXX";
    int fd = mkstemp(temp_filename);

    /* Unlink the filename so that it will be get removed from the disk once
     * we close the file descriptor or program exit some how.
     */
    unlink(temp_filename);

    /* write number of bytes to the file first. */
    write(fd, &length, sizeof(length));

    /* write data itself. */
    write(fd, buffer, length);

    return fd;
}

char* read_temp_file(temp_file_handle temp_file, size_t* length)
{
    char* buffer;

    int fd = temp_file;

    /* Rewind the file pointer to the beginning of the file. */
    lseek(fd, 0, SEEK_SET);

    /* Read the size of the data in the temporary file. */
    read(fd, length, sizeof(*length));

    /* Allocate the buffer */
    buffer = (char*)malloc(*length);
    read(fd, buffer, *length);

    /* close the file descriptor which will cause the temporary file to go
     * away from disk, since the fd was unlinked already. */
    close(fd);

    return buffer;
}

int main(int argc, char**argv)
{
    printf("testing");

}
