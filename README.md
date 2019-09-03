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

2. Use lsof command to find which process is listening on a particular port
``` lsof -i :8000``` or ```netstat -ltnp```

![](https://www.ibm.com/support/knowledgecenter/SSLTBW_2.2.0/com.ibm.zos.v2r2.hali001/khcl2002.gif)

3.  Use Apapche http2-toolkit for http development. Use ab tool to benchmark your server
``` ab -n 20 -c 100 http://localhost:8000```

### Resources
1. [Linux Application Performance](https://unixism.net/2019/04/linux-applications-performance-introduction/)
2. [Lets build a web server](https://ruslanspivak.com/lsbaws-part1/)
3. [Hackernews feedback](https://news.ycombinator.com/item?id=20081488#20088463)
4. [The Linux Programming Interface](https://github.com/storypku/tlpi)
5. [Guide to linkers](http://www.lurklurk.org/linkers/linkers.html)
6. [Http Toolkit](https://httptoolkit.tech/)
7. [HTTP made easy](https://www.jmarshall.com/easy/http/)
8. [Learning Rust, implementing a web server](http://julien.gunnm.org/rust/2017/11/18/learning-rust-in-practice-webserver-in-rust/)
9. [Learn Go with tests - http server](https://github.com/quii/learn-go-with-tests)
