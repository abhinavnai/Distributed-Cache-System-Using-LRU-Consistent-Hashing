# Distributed Cache System Using LRU & Consistent Hashing

This project implements a **distributed caching system** inspired by large-scale web infrastructure. The system uses a **hash-based key-value store**, an **LRU (Least Recently Used) eviction policy** for efficient memory usage, and **consistent hashing** to distribute data across multiple cache nodes.

The goal is to simulate how modern distributed caching solutions such as large-scale **in-memory caching layers** operate in real production systems.

---

## System Architecture

The system contains three major components:

- **LRU Cache Engine** – Handles eviction and memory management  
- **Hash Table** – Provides fast key-value lookup  
- **Consistent Hashing Ring** – Distributes keys across cache nodes  

---

## Learning Outcomes

This project helps develop a deeper understanding of:

- Deep understanding of hashing techniques  
- Implementation of **LRU cache using HashMap + Doubly Linked List**  
- Understanding the **consistent hashing algorithm**  
- Handling collisions and load balancing  
- Knowledge of **distributed systems concepts**  
- Time and space complexity optimization  

---

## Project Features

- LRU cache eviction mechanism  
- Hash table based key-value storage  
- Consistent hashing ring for server distribution  
- Simulation of multiple cache servers  
- Cache miss detection  
- Automatic eviction policies  
- Performance benchmarking tools  
- Optional concurrency support  
- Command Line Interface (CLI) for testing  

---

## Execution Workflow

1. Initialize cache servers  
2. Create consistent hashing ring  
3. Insert key-value pairs  
4. Hash keys to determine responsible server  
5. Store keys inside LRU cache of that server  
6. Handle cache hits and misses  
7. Evict least recently used items when capacity is exceeded  

---

## Core Algorithms Used

### 1. LRU Cache

Implemented using a combination of:

- **HashMap** for `O(1)` lookup  
- **Doubly Linked List** for maintaining usage order  

---

### 2. Consistent Hashing

Consistent hashing distributes keys across servers in a circular hash space called a **hash ring**.

When servers **join or leave the system**, only a **small subset of keys** need to be redistributed.

---

## Performance Considerations

| Operation | Complexity |
|----------|------------|
| Hash lookup | O(1) average |
| LRU operations | O(1) |
| Key distribution | Balanced across nodes |

Efficient memory utilization is achieved through **automatic eviction**.

---

## Real World Applications

- Web application caching systems  
- Content Delivery Networks (CDN)  
- Cloud-based distributed systems  
- Database query caching  
- Microservices architecture caching layers  

---

## Future Improvements

- Add multi-threading support  
- Implement fault tolerance  
- Network-based node communication  
- Monitoring and metrics dashboard  
- Persistence layer for cache recovery  

---

### Distributed Systems Project  
**LRU Cache + Consistent Hashing**
