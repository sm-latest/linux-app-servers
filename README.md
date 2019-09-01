# linux-app-servers
Testing linux application performance

## Typical Client Server interaction diagram
![](https://www.ibm.com/support/knowledgecenter/SSLTBW_2.2.0/com.ibm.zos.v2r2.hali001/lbhl0001.gif)

## Socket system calls
- ```socket()``` creates a new socket.
- ```bind()``` binds a socket to an address
- ```listen()``` - allows a stream socket to accept incoming connections from other sockets
- ```accept()``` - accepts a connection froma peer application on a listening stream socket
- ```connect()``` - establishes a connection with another socket

## Types of Servers
1. Iterative Server - handles the client request and the work within the same call. It does not scale for high number of  client requests and also for long running transactions. <b>Deals with one client request at a time.</b>

## General tips
1. in Linux the default for the queue length, which determines the number of clients that can wait until their request is accepted is a parameter of the listen() system call. While a large number can be specified, most operating systems will silently truncate this number to some internal limit. On Linux by default, this number is 128 and you can change this number by writing a new limit into ''' /proc/sys/net/core/somaxconn. '''

![](https://www.ibm.com/support/knowledgecenter/SSLTBW_2.2.0/com.ibm.zos.v2r2.hali001/khcl2002.gif)

### Resources
1. [Linux Application Performance](https://unixism.net/2019/04/linux-applications-performance-introduction/)
2. [Lets build a web server](https://ruslanspivak.com/lsbaws-part1/)
3. [Hackernews feedback](https://news.ycombinator.com/item?id=20081488#20088463)
