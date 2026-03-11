# 📡 minitalk

`minitalk` is a **client-server communication program written in C**.
It demonstrates **inter-process communication (IPC)** using Unix signals.

The client sends a message to the server **bit by bit**, and the server reconstructs the message and prints it to the terminal.

---

# ✨ Features

* Client-server architecture
* Communication using **UNIX signals**
* Bit-by-bit message transmission
* Message decoding on the server
* Uses custom **libft** functions
* Simple and lightweight communication protocol

---

# ⚙️ How It Works

1. The **server** starts and prints its **PID**.
2. The **client** takes:

   * the server PID
   * the message to send
3. The client converts each character into **binary**.
4. Each bit is sent to the server using signals:

| Signal    | Meaning    |
| --------- | ---------- |
| `SIGUSR1` | Binary `0` |
| `SIGUSR2` | Binary `1` |

5. The server receives the signals and reconstructs the characters to display the message. ([Medium][1])

---

# 📂 Project Structure

```
minitalk
│
├── client.c        # Sends messages to the server
├── server.c        # Receives and prints messages
├── minitalk.h      # Header file
│
├── libft           # Custom C library
│
├── client.o
├── server.o
└── Makefile
```

---

# ⚙️ Compilation

Compile the project with:

```bash
make
```

This will generate two executables:

```
server
client
```

---

# 🚀 Usage

### Start the server

```bash
./server
```

The server will display its **PID**.

Example:

```
Server PID: 12345
```

---

### Send a message from the client

```bash
./client <PID> "Hello World"
```

Example:

```bash
./client 12345 "Hello from minitalk!"
```

The server will display the received message.

---

# 🎯 Learning Goals

This project helps practice:

* Unix signals
* inter-process communication (IPC)
* bit manipulation
* signal handling
* client-server architecture
* low-level C programming

---

# 🛠️ Technologies

* C
* Unix signals (`SIGUSR1`, `SIGUSR2`)
* Makefile
* Custom `libft`

---

Created by ~Diana Kolarova

