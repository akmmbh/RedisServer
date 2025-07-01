RedisServer
A custom database server implementation inspired by Redis, built from scratch to understand the fundamentals of database systems and network programming.
 Project Overview
This project aims to create a lightweight, in-memory database server with Redis-like functionality. The server uses binary trees for efficient data storage and retrieval, providing fast key-value operations.
 Current Status
Work in Progress - This project is actively under development.
 Completed Features

Server Connection: Basic TCP server implementation that can accept and handle client connections
Binary Tree Implementation: Core data structure for storing and organizing key-value pairs
Network Layer: Foundation for client-server communication

 Currently Working On

Command parsing and execution engine
Basic Redis-compatible commands (GET, SET, DEL)
Connection management and client session handling
Error handling and response formatting

 Architecture
The server is built with the following components:

Network Layer: Handles TCP connections and manages client sessions
Command Parser: Processes incoming Redis-protocol commands
Storage Engine: Binary tree-based storage for efficient data operations
Response Handler: Formats and sends responses back to clients

 Planned Features

 Core Redis commands (GET, SET, DEL, EXISTS)
 Data type support (strings, lists, sets, hashes)
 Persistence mechanisms
 Configuration management
 Connection pooling
 Basic clustering support
 Memory management and garbage collection
 Logging and monitoring

