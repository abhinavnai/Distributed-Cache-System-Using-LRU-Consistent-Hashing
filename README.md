<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Distributed Cache System</title>

<style>
body{
    font-family: Arial, Helvetica, sans-serif;
    margin:40px;
    background:#f5f7fa;
    color:#333;
}

h1,h2,h3{
    color:#1a4d8f;
}

.container{
    max-width:900px;
    margin:auto;
    background:white;
    padding:40px;
    border-radius:10px;
    box-shadow:0 4px 10px rgba(0,0,0,0.1);
}

ul{
    line-height:1.8;
}

.section{
    margin-top:30px;
}

.code{
    background:#272822;
    color:#f8f8f2;
    padding:15px;
    border-radius:6px;
    font-family:monospace;
}

.footer{
    margin-top:40px;
    font-size:14px;
    color:gray;
}
</style>

</head>

<body>

<div class="container">

<h1>Distributed Cache System Using LRU & Consistent Hashing</h1>

<p>
This project implements a <b>distributed caching system</b> inspired by large-scale
web infrastructure. The system uses a <b>hash-based key-value store</b>, an
<b>LRU (Least Recently Used) eviction policy</b> for efficient memory usage,
and <b>consistent hashing</b> to distribute data across multiple cache nodes.
</p>

<p>
The goal is to simulate how modern distributed caching solutions such as
large-scale in-memory caching layers operate in real production systems.
</p>

<hr>

<div class="section">

<h2>System Architecture</h2>

<p>The system contains three major components:</p>

<ul>
<li><b>LRU Cache Engine</b> – Handles eviction and memory management</li>
<li><b>Hash Table</b> – Provides fast key-value lookup</li>
<li><b>Consistent Hashing Ring</b> – Distributes keys across cache nodes</li>
</ul>

</div>

<div class="section">

<h2>Learning Outcomes</h2>

<ul>
<li>Deep understanding of hashing techniques</li>
<li>Implementation of LRU cache using HashMap + Doubly Linked List</li>
<li>Understanding consistent hashing algorithm</li>
<li>Handling collisions and load balancing</li>
<li>Knowledge of distributed systems concepts</li>
<li>Time and space complexity optimization</li>
</ul>

</div>

<div class="section">

<h2>Project Features</h2>

<ul>
<li>LRU cache eviction mechanism</li>
<li>Hash table based key-value storage</li>
<li>Consistent hashing ring for server distribution</li>
<li>Simulation of multiple cache servers</li>
<li>Cache miss detection</li>
<li>Automatic eviction policies</li>
<li>Performance benchmarking tools</li>
<li>Optional concurrency support</li>
<li>Command Line Interface (CLI) for testing</li>
</ul>

</div>

<div class="section">

<h2>Execution Workflow</h2>

<ol>
<li>Initialize cache servers</li>
<li>Create consistent hashing ring</li>
<li>Insert key-value pairs</li>
<li>Hash keys to determine responsible server</li>
<li>Store keys inside LRU cache of that server</li>
<li>Handle cache hits and misses</li>
<li>Evict least recently used items when capacity is exceeded</li>
</ol>

</div>

<div class="section">

<h2>Core Algorithms Used</h2>

<h3>1. LRU Cache</h3>
<p>
Implemented using a combination of:
</p>

<ul>
<li>HashMap for O(1) lookup</li>
<li>Doubly Linked List for maintaining usage order</li>
</ul>

<h3>2. Consistent Hashing</h3>

<p>
Consistent hashing distributes keys across servers in a circular hash space
called a <b>hash ring</b>. When servers join or leave the system, only a small
subset of keys need to be redistributed.
</p>

</div>

<div class="section">

<h2>Performance Considerations</h2>

<ul>
<li>Hash lookup complexity: <b>O(1)</b> average</li>
<li>LRU operations: <b>O(1)</b></li>
<li>Key distribution: balanced across nodes</li>
<li>Efficient memory utilization through eviction</li>
</ul>

</div>

<div class="section">

<h2>Real World Applications</h2>

<ul>
<li>Web application caching systems</li>
<li>Content Delivery Networks (CDN)</li>
<li>Cloud-based distributed systems</li>
<li>Database query caching</li>
<li>Microservices architecture caching layers</li>
</ul>

</div>

<div class="section">

<h2>Future Improvements</h2>

<ul>
<li>Add multi-threading support</li>
<li>Implement fault tolerance</li>
<li>Network-based node communication</li>
<li>Monitoring and metrics dashboard</li>
<li>Persistence layer for cache recovery</li>
</ul>

</div>

<div class="footer">
<p>Distributed Systems Project | LRU Cache + Consistent Hashing</p>
</div>

</div>

</body>
</html>
