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

## Anlysing Booking Trends
Analysing Booking Trends over time is important fro optimizing operations and to devise marketing stratergies. RedBus invloves many buses. It includes anlysing increase in bookings during holidays,weekends etc and decrease in bookings during mid week. This requires extensive data and analysis.

Fenwick Trees can store and efficiently query the number of bookings over different periods.Represent each day or time slot as an entry in the Fenwick Tree. Each index can hold the cumulative number of bookings.When a booking is made, update the tree to increment the booking count for the specific day.The total number of bookings over any range of days can be queried. This can help identify peak booking periods and trends.


## Dynamic Pricing
Dynamic pricing adjusts ticket prices based on demand to maximize revenue and manage seat utilization.Price can be adjusted dynamically based on the booking trends which can be analysed used Fenwick Trees.

The RedBus in real time implemented a Pricing Algorithm using Machine Learning Algorithms and pattern finding algorithms.The engine combines multiple signals from the market, both on the demand and supply side, to compute pricing suggestions on a real time basis. The price suggestions tries to achieve the goal of improving the operator's average revenue per seat.

## Fraud Detection


## Seat Availibity Management
RedBus application requires efficient managing and checking the seat availability across many buses. Fenwick Trees can be effectively utilized for this functionality. 
Integrating Fenwick Trees into RedBus's ticket booking system for seat availability management improves efficiency and customer satisfaction. It supports real-time updates and queries, ensuring that users can quickly find and book available seats across multiple buses and routes.
As same company bus can be used for many routes on different dates, combination of bus-route-date can represented as an entry in Fenwick Tree.

Initialise the Fenwick Tree with total number of seates available. When a booking is made for a bus on particular route and date the corresponding seat count can be descreased and if booking is cancelled the seat count can be increased representing the available seats.  
This quickly retrives the total number of available seats for a specific route over range of dates. This helps the application to dynamically adjust seat availability.

## Efficient Ticket Booking
Challenge : During peak time thousands of requests to book ticket may be received. These must be handled to improve customer experience and reduce overbooking.

Organizing and processing booking requests in an orderly and efficient manner by using queues and concurrency control algorithms. By using queues, the system can handle multiple booking requests in real-time, ensuring that each request is processed fairly and in the order it was received. This is particularly important during peak times when the system might receive thousands of simultaneous requests. The requests can be handled based on first come first serve (FIFO) queues or based on Priority queues.

Concurrency control uses techniques including locking, optimistic and pessimistic concurrency control, and database transactions to preserve data integrity during concurrent bookings. In order to maintain system stability and user satisfaction, this avoids disputes and guarantees that every booking transaction is performed precisely and thoroughly, either completing completely or not at all.

## Sort buses based on preferences

Merge Sort for Efficient Sorting
Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array. In the context of RedBus, Merge Sort can be used to sort bus search results based on various criteria such as relevance, travel time, and fare.

For instance, when a user searches for buses, the initial set may or may not be sorted. By applying Merge Sort, the application can sort these results in a way that optimizes for the user's needs. For example, buses can first be sorted by fare to identify the cheapest options, then by travel time to find the fastest routes, and finally by relevance, which could be determined by factors like the number of stops or departure times that match the user's preferences.

## Ranked Search Results
To implement ranked search results in an application like RedBus, a combination of Merge Sort and a Weighted Ranking Algorithm can be highly effective. This approach ensures that search results are not only sorted efficiently but also prioritized according to user preferences and historical data. 

After the search results are sorted, a Weighted Ranking Algorithm can used to rank them in order of user preference and historical data. Weights are assigned by this algorithm to several elements that affect the user's decision-making process. User-specific preferences (including preferred departure times or bus operators) and special offers may be among these criteria, as well as user reviews, past on-time performance, and historical performance.

The Weighted Ranking Algorithm calculates a composite score for each bus option by multiplying each factor by its corresponding weight and summing the results. The weights can be dynamically adjusted based on the importance of each factor to the user. For example, if a user frequently prefers buses with shorter travel times, the weight for travel time will be higher. Similarly, if the user values lower fares, the weight for fare will be increased.

## Live Monitoring of the bus 

Everyday about 150 K customers travel with a ticket bought on redBus in about 40 K bus trips. We collect real time GPS data from the buses and provide value added services to our customers along with basic tracking of the bus.

For keeping track of the buses data structure called a quadtree can be used. Imagine a map divided into squares, starting with the entire area RedBus covers. The quadtree keeps track of these squares. If a square has too many buses (say, more than 100), it gets divided into four smaller squares. This keeps happening until each square has a manageable number of buses. This way, RedBus can quickly find buses in any area.
![Image Description](/assets/9af53b8a-0a5e-4688-a968-44d5d9ed5951)

Buses with GPS tell the RedBus server where they are all the time. The server updates its map (the quadtree) with these new locations. The map figures out which square (leaf node) each bus belongs to based on its GPS signal. This keeps the map up-to-date with where all the buses are.

The quadtree structure allows for efficient updates and queries, handling frequent GPS updates from buses and real-time queries from users seamlessly. The dynamic partitioning of the quadtree ensures that densely populated areas, where bus activity is high, are represented with smaller, more granular regions. In contrast, sparsely populated areas have larger regions. This adaptability ensures efficient management of bus data across different densities, maintaining performance and accuracy.

[reference](https://medium.com/@joudwawad/school-bus-tracker-system-architecture-6dd3307e3860)

##### The real RedBus Application uses following process:
Data loading: The data is collected from multiple systems and keep them ready for consumption in real time during the trip. These data points include Vehicle information, Trip schedules, Vehicle assignment schedules and Passenger information. We also have manual process for geo-coding boarding points.
Data processing: In these process we run algorithms on historical data and produce output to be used in real time tracking and reporting. Some of the output of these algorithms are
- Boarding point sequence
- Graph for the bus paths
- ETA model
- GTFS (Google transit feed specification)

There are multiple reports for tracking accuracy of the ETA, coverage of Boarding point detection and customer experience during the journey.
Real time tracking: In this system we consume data from the above two systems and merge it with the real time GPS feed coming from the GPS vendor integrations. The result is a set of value added services like;
- Live bus location tracking on mobile web and app
- ETA for boarding and dropping points
- Contextual notifications to passengers through SMS, push notification and automated calls
- Booking window extension for delayed services
- Feed for real time settlement of delay insurances
- 
[reference](https://medium.com/redbus-in/redbus-bus-tracking-system-6134aa6b9160)

## Bus Fleet Management
Applying the knapsack problem to fleet management in RedBus and similar services allows for strategic decision-making that optimizes resource utilization, reduces operational costs, and enhances service efficiency. This approach not only improves financial outcomes but also contributes to a more reliable and customer-centric transportation service.The knapsack problem, known for its ability to optimize resource allocation under constraints, can be applied effectively to manage bus fleets with diverse capacities and operational costs.


