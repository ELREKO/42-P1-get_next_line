# read()

## Desription 
From the file indicated by the file descriptor fd, the read() function reads the specified amount of bytes cnt of input into the memory area indicated by buf. A successful read() updates the access time for the file. The read() function is also defined inside the <unistd.h> header file.

## Declaration 
```
    size_t read (int fd, void* buf, size_t cnt);
```

## Parameter
- fd: file descriptor of the file from which data is to be read
- buf: buffer to read data from
- cnt: length of the buffer

## Return
- return Number of bytes read on success
- return 0 on reaching the end of file
- return -1 on error
- return -1 on signal interrupt

## special 
- **buf** needs to point to a valid memory location with a length not smaller than the specified size because of overflow.

- **fd** should be a valid file descriptor returned from open() to perform the read operation because if fd is NULL then the read should generate an error.

- **cnt** is the requested number of bytes read, while the return value is the actual number of bytes read. Also, some times read system call should read fewer bytes than cnt.