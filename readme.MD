
---

## TCP Server Example

This C program demonstrates how to implement a basic TCP server that listens for client connections on a specified port (in this case, port `8989`), accepts them, and handles data transmission.

### Prerequisites

- Basic knowledge of C programming
- Understanding of socket programming
- A C compiler (like GCC)

### How It Works

1. **Create a Socket:**
   The server begins by creating a socket using the `socket()` function.

   ```c
   server_fd = socket(PF_INET, SOCK_STREAM, 0);
   ```

   - `PF_INET`: Specifies the protocol family (IPv4).
   - `SOCK_STREAM`: Specifies the type of socket (TCP).
   - `0`: Default protocol (TCP).

2. **Bind the Socket:**
   The server assigns an IP address and port number to the socket using the `bind()` function.

   ```c
   server.sin_family = AF_INET;
   server.sin_port = htons(PORT);
   server.sin_addr.s_addr = 0;
   bind(server_fd, (struct sockaddr*)&server, sizeof(struct sockaddr));
   ```

   - `AF_INET`: Address family for IPv4.
   - `htons(PORT)`: Converts port number to network byte order.
   - `INADDR_ANY`: Allows the server to accept connections on any of the machine's IP addresses.

3. **Listen for Connections:**
   The server listens for incoming client connections with the `listen()` function.

   ```c
   listen(server_fd, 5);
   ```

   - The second argument (`5`) is the backlog, indicating the maximum length to which the queue of pending connections may grow.

4. **Accept Connections:**
   The server accepts an incoming connection using the `accept()` function.

   ```c
   client_fd = accept(server_fd, (struct sockaddr*)&client, &sin_size);
   ```

   - `client_fd`: New socket descriptor for the accepted connection.
   - `client`: Contains the client's IP address and port number.

5. **Exchange Data:**
   The server sends a "Hello World" message to the client and then waits to receive data.

   ```c
   send(client_fd, "Hello World\n", 14, 0);
   length = recv(client_fd, &buffer, BUFSIZ, 0);
   ```

   - `send()`: Sends data to the client.
   - `recv()`: Receives data from the client.

6. **Handle Multiple Connections:**
   The server runs in an infinite loop to handle multiple connections. After accepting a connection, it processes the received data, and once done, it goes back to listening for new connections.

### Compilation

You can compile the program using GCC:

```bash
gcc -o tcp_server tcp_server.c
```

### Running the Server

After compiling, run the server with:

```bash
./tcp_server
```

The server will start listening on port 8989. You can use a tool like `telnet` to connect to the server and test it:

```bash
telnet 127.0.0.1 8989
```

### Output Example

```bash
listening Port [8989]
Got a connection [127.0.0.1] [55432]
RECV LEN: 14
```

### Notes

- The server is set up to run indefinitely, handling incoming connections one after another.
- The code is set up for educational purposes, and proper error handling or multithreading can be added for production-level code.

---

