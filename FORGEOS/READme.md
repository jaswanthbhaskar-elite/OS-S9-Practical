# Asynchronous File Processing Server

## 📌 Project Overview

The Asynchronous File Processing Server is an Operating Systems project developed in C to demonstrate asynchronous I/O, concurrency, synchronization, and efficient file processing.

The system is designed to handle multiple client requests concurrently without blocking the server during file input/output operations. It maintains request and completion queues and monitors server performance using throughput and request latency.

---

## 🎯 Objectives

- Handle multiple client connections concurrently.
- Process file read and write operations asynchronously.
- Maintain request and completion queues.
- Synchronize access to shared request data.
- Record request and completion times.
- Measure throughput and request latency.
- Demonstrate important Operating System I/O and synchronization concepts.

---

## ⚙️ Key Features

- Multi-client support
- Asynchronous file processing
- File READ and WRITE operations
- Request queue management
- Completion queue management
- Thread synchronization
- Performance monitoring
- Request latency measurement
- Server throughput calculation

---

## 🧠 Operating System Concepts

This project demonstrates:

- Asynchronous I/O
- Multithreading
- Concurrency
- Mutual Exclusion
- Producer-Consumer Problem
- Thread Synchronization
- File I/O
- Socket Communication
- Queue Management
- Performance Measurement

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C | Core implementation |
| Linux / Ubuntu | Development and execution environment |
| GCC | Compilation |
| POSIX Libraries | Threads, synchronization and asynchronous I/O |
| TCP/IP Sockets | Client-server communication |
| Linux File I/O APIs | File reading and writing |

---

## 🏗️ System Architecture

```text
              ┌───────────────┐
              │    Clients    │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │  TCP Server   │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │ Request Queue │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │ Asynchronous  │
              │  I/O Handler  │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │ Completion    │
              │    Queue      │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │    Clients    │
              └───────────────┘