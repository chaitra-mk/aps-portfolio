# APS Case Study on RedBus Application

# RedBus Portfolio
<dl>
<dt>Course Name</dt>
<dd>Algorithmic Problem Solving</dd>
<dt>Course Code</dt>
<dd>23ECSE309</dd>
<dt>Name</dt>
<dd>Chaitra Kulkarni</dd>
<dt>University</dt>
<dd>KLE Technological University, Hubballi-31</dd>
</dl>

* * *

> A step towards applying dsa to the functionalities of instagram
>
> 

#### Note:
This page hosts:

1. Introduction
3. Why Portfolio
4. Objectives
5. Design
6. Challenges
7. To-Do



* * *

#  Business Cases
## Search Boarding Location and Destination Location

Challenges : Redbus is a very large platform. In most of India, this app is utilised for ticket reservations. As a result, a large number locations need to be effectively saved and retrieved.

### Trie Data Structure 

A Trie is a tree-based data structure designed for storing dynamic strings, offering efficient insertion and deletion methods. It supports fast searches, making it ideal for applications like Redbus, which operates across India and manages many locations. Efficient data storage and retrieval are crucial for such platforms. Tries are particularly useful for storing source and destination places, as well as for implementing auto-completion functionality.

Each node in a Trie node structure has character data, child nodes (for characters that come after it), and a flag to indicate the end of a word. Insertion is the process of adding each city name  to the Trie by iterating through the Trie based on each character in the word, adding new nodes as necessary, and marking the word's end when adding the last character. In order to provide autocomplete capability, the subtree rooted at the prefix node is traversed in the Trie depending on the input prefix, collecting all words (city names) that match the prefix.

To manage multiple boarding or destination locations within cities, hash maps can be used. By implementing a hash map where city names act as keys and hold lists containing the locations as their values, this structure enables rapid access to boarding or destination locations associated with each city. Such an approach optimizes the retrieval and organization of location data, enhancing the application's efficiency and user experience.


## Route Optimisation
RedBus's implementation of A* enables dynamic route optimisation in real-time. Variables like traffic conditions, passenger demand, operational constraints etc., can be considered. By efficiently determining the shortest paths between bus stops, A* helps minimize travel times, reduce fuel consumption, and improve overall service reliability.

In RedBus, each bus stop can be represented as a node in a graph, where edges between nodes represent roads or routes connecting these stops. Each edge has an associated weight, typically representing travel time, distance, or other relevant metrics like traffic conditions. The cost function g(n) represent the distance to reach a specific bus stop from the starting point. This cost is updated dynamically as the algorithm explores different paths.
The heuristic function h(n) estimates the distance from any given bus stop to the destination. This estimation guides the algorithm towards the most promising paths, reducing unnecessary exploration and improving efficiency.A* combines g(n) and h(n) to determine the priority of nodes in the open list. The total cost function f(n)=g(n)+h(n) ensures that nodes with lower estimated costs to reach the goal are explored first, leading to faster convergence towards the optimal route.A priority queue is used in the A* algorithm to manage nodes based on their total cost function, ensuring that nodes with lower total costs are explored first, which helps in efficiently finding the shortest path from a start node to a goal node in applications such as route optimization for RedBus.
Once the goal node is reached, reconstruct the optimal path by tracing back from the goal node to the start node using the recorded parent pointers or paths.


## Seat Availibity Management
RedBus application requires efficient managing and checking the seat availability across many buses. Fenwick Trees can be effectively utilized for this functionality. 
Integrating Fenwick Trees into RedBus's ticket booking system for seat availability management improves efficiency and customer satisfaction. It supports real-time updates and queries, ensuring that users can quickly find and book available seats across multiple buses and routes.
As same company bus can be used for many routes on different dates, combination of bus-route-date can represented as an entry in Fenwick Tree.
Initialise the Fenwick Tree with total number of seates available.
When a booking is made for a bus on particular route and date the corresponding seat count can be descreased and if booking is cancelled the seat count can be increased representing the available seats.  
This quickly retrives the total number of available seats for a specific route over range of dates. This helps the application to dynamically adjust seat availability.

### Anlysing Booking Trends
Analysing Booking Trends over time is important fro optimizing operations and to devise marketing stratergies. 
RedBus invloves many buses. It includes anlysing increase in bookings during holidays,weekends etc and decrease in bookings during mid week. This requires extensive data and analysis.

Fenwick Trees can store and efficiently query the number of bookings over different periods.
Represent each day or time slot as an entry in the Fenwick Tree. Each index can hold the cumulative number of bookings.When a booking is made, update the tree to increment the booking count for the specific day.The total number of bookings over any range of days can be queried. This can help identify peak booking periods and trends.


## Dynamic Pricing
Dynamic pricing adjusts ticket prices based on demand to maximize revenue and manage seat utilization.
Price can be adjusted dynamically based on the booking trends which can be analysed used Fenwick Trees.
The RedBus in real time implemented a Pricing Algorithm using Machine Learning Algorithms and pattern finding algorithms.The engine combines multiple signals from the market, both on the demand and supply side, to compute pricing suggestions on a real time basis. The price suggestions tries to achieve the goal of improving the operator's average revenue per seat.

##


