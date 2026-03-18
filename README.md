# 🧱 C HTTP Server

A simple HTTP server built from scratch in C using low-level socket programming.

## 🚀 Features

- Handles basic HTTP requests
- Supports simple routing:
  - `/` → Home
  - `/sobre` → About page
- Returns plain text responses
- Built using POSIX sockets (`socket`, `bind`, `listen`, `accept`)
- Minimal and easy to understand

## 🛠️ How to Run

### 1. Compile

```bash
gcc server.c -o server
````

### 2. Run

```bash
./server
```

### 3. Open in browser

```
http://localhost:8080
```

---

## 📡 Available Routes

| Route    | Method | Description |
| -------- | ------ | ----------- |
| `/`      | GET    | Home page   |
| `/sobre` | GET    | About page  |

---

## 🧠 How It Works

This server:

1. Creates a socket using TCP
2. Binds it to port `8080`
3. Listens for incoming connections
4. Accepts client requests
5. Reads raw HTTP requests
6. Parses routes using simple string matching
7. Sends HTTP responses manually

---

## 📌 Example Request

```http
GET / HTTP/1.1
Host: localhost:8080
```

## 📌 Example Response

```http
HTTP/1.1 200 OK
Content-Type: text/plain

Página inicial
```

---

## ⚠️ Limitations

* No concurrency (handles one client at a time)
* Basic request parsing (`strstr`)
* No support for POST/PUT yet
* No file serving
* Not production-ready

---

## 🎯 Future Improvements

* [ ] JSON responses
* [ ] Better HTTP parsing
* [ ] Support for POST requests
* [ ] Multithreading
* [ ] Static file serving
* [ ] Routing system

---

## 📚 Learning Goals

This project was built to understand:

* How HTTP works under the hood
* Socket programming in C
* Client-server communication
* Manual request/response handling

---

## 🧑‍💻 Author

Igor Oliveira
