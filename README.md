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



# Introduction
<div align="center">
  <img src="https://github.com/chaitra-mk/aps-portfolio/assets/105005252/525d188a-384d-4cc9-8047-1098eec1744e" alt="Image" width="550" height="450">
</div>

RedBus is a online bus ticket booking platform, connecting various cities across the globe with just a click of a button. With its mobile app downloaded by over 7.5 million loyal customers, redBus has become the largest community of bus travelers in the world. Initially launched in India, Redbus has since expanded its services to Singapore, Malaysia, Indonesia, Colombia, and Peru as of 2014. Boasting the most extensive network of bus operators, routes, and registered users, Redbus plays an important role in connecting cities, enhancing co-living, and positively influencing local economies and public services. Its user-friendly, robust, and scalable reservation and management system is widely used by both passengers and bus operators. This application has played a significant role in public transportation. It provides functionalities such as a route planner, online reservation system accessible to multiple bus companies, and a taxi-sharing service. There are hundreds of API Providers integrated with redBus.

# Objectives

- Apply data structures and algorithms to the real-world operations of RedBus.
- Identify business cases and propose various algorithms to implement these cases.
- Highlight challenges and market benefits for each case, where possible.
- Provide sample code for the algorithms identified for different cases.





# Business Cases
## Search Boarding Location and Destination Location

Challenges : Redbus is a very large platform. In most of India, this app is utilised for ticket reservations. As a result, a large number locations need to be effectively saved and retrieved.
Market Benefits :  Enhances user experience by quickly and accurately find source and destination locations.

### Trie Data Structure 

A Trie is a tree-based data structure designed for storing dynamic strings, offering efficient insertion and deletion methods. It supports fast searches, making it ideal for applications like Redbus, which operates across India and manages many locations. Efficient data storage and retrieval are crucial for such platforms. Tries are particularly useful for storing source and destination places, as well as for implementing auto-completion functionality.

Each node in a Trie node structure has character data, child nodes (for characters that come after it), and a flag to indicate the end of a word. Insertion is the process of adding each city name  to the Trie by iterating through the Trie based on each character in the word, adding new nodes as necessary, and marking the word's end when adding the last character. In order to provide autocomplete capability, the subtree rooted at the prefix node is traversed in the Trie depending on the input prefix, collecting all words (city names) that match the prefix.
<div align="center">
  <img src="https://github.com/chaitra-mk/aps-portfolio/assets/105005252/cc8ce47c-1bc0-41e8-99c2-34d3b4392829" alt="Image" width="400" height="450">
</div>


To manage multiple boarding or destination locations within cities, hash maps can be used. By implementing a hash map where city names act as keys and hold lists containing the locations as their values, this structure enables rapid access to boarding or destination locations associated with each city. Such an approach optimizes the retrieval and organization of location data, enhancing the application's efficiency and user experience.

Time Complexity : For insertion,deletion.searching is O(n) where n is the length of the string
Auxillary Space : For Insertin, Deletion O(n) and for Searching O(1)  
[Link for the code](https://github.com/chaitra-mk/aps-portfolio/blob/main/Trie.cpp)

## Optimize Routes
RedBus's implementation must consider variables like traffic conditions, passenger demand, operational constraints etc., can be considered.

Market Benefits : Helps minimize travel times, reduce fuel consumption, and improve overall service reliability.
Challenge : Find shortest route from source to destination considering traffic and other constraints.

In RedBus, each bus stop can be represented as a node in a graph, where edges between nodes represent roads or routes connecting these stops. Each edge has an associated weight, typically representing travel time, distance, or other relevant metrics like traffic conditions.
To find the shortest distanace between node Dijkstra's algorithm can be used where the shortest distance from the given node to all other nodes are calculated by constructing spanning tree.

The A* algorithm, on the other hand, offers an efficient alternative.
In A* algorithm The cost function g(n) represent the distance to reach a specific bus stop from the starting point. This cost is updated dynamically as the algorithm explores different paths.
The heuristic function h(n) estimates the distance from any given bus stop to the destination. This estimation guides the algorithm towards the most promising paths, reducing unnecessary exploration and improving efficiency.A* combines g(n) and h(n) to determine the priority of nodes in the open list. The total cost function f(n)=g(n)+h(n) ensures that nodes with lower estimated costs to reach the goal are explored first, leading to faster convergence towards the optimal route.A priority queue is used in the A* algorithm to manage nodes based on their total cost function, ensuring that nodes with lower total costs are explored first, which helps in efficiently finding the shortest path from a start node to a goal node in applications such as route optimization for RedBus.
Once the goal node is reached, reconstruct the optimal path by tracing back from the goal node to the start node using the recorded parent pointers or paths.

[Code for Dijkstra's Algorithm](https://github.com/Nerdylicious/DijkstraShortestPath/blob/master/DijkstraShortestPath.cpp)

Time Complexity of A* Algorithm depends on heuristics. For priority queue O((E + V)log(V) where E: Number of Edges and V: Number of Vertices

## Analysing Booking Trends

Challenges : Analyzing booking trends requires handling and processing large volumes of data efficiently. Also, it requires managing data consistency and integrity across different periods and time slots.
Market Benefits : Identifying peak booking periods helps optimize bus schedules and resource allocation. Analysis also helps to boost sales during low-demand periods.
Analysing Booking Trends over time is important for optimizing operations and to devise marketing stratergies. RedBus invloves many buses. It includes anlysing increase in bookings during holidays,weekends etc and decrease in bookings during mid week. This requires extensive data and analysis.

<img src="https://github.com/chaitra-mk/aps-portfolio/assets/105005252/45a70709-77d7-49a9-9dc7-7843f0803f6f" alt="Image" width="550" height="450">

Fenwick Trees can store and efficiently query the number of bookings over different periods.Represent each day or time slot as an entry in the Fenwick Tree. Each index can hold the cumulative number of bookings.When a booking is made, update the tree to increment the booking count for the specific day.The total number of bookings over any range of days can be queried. This can help identify peak booking periods and trends.

Time Complexity : nlogn

Here is the simple [code](https://github.com/chaitra-mk/aps-portfolio/blob/main/FenwickTree.cpp) of Fenwick Tree

## Dynamic Pricing
Challenge : Balancing price adjustments to avoid customer dissatisfaction while maximizing revenue.
Market Benefits :Helps to maximize revenue by adjusting prices based on real-time demand and supply.
Dynamic pricing adjusts ticket prices based on demand to maximize revenue and manage seat utilization.Price can be adjusted dynamically based on the booking trends which can be analysed used Fenwick Trees.

The RedBus in real time implemented a Pricing Algorithm using Machine Learning Algorithms and pattern finding algorithms.The engine combines multiple signals from the market, both on the demand and supply side, to compute pricing suggestions on a real time basis. The price suggestions tries to achieve the goal of improving the operator's average revenue per seat.

Here is the simple [code](https://github.com/chaitra-mk/aps-portfolio/blob/main/FenwickTree.cpp) of Fenwick Tree
Time Complexity : nlogn

## Fraud Detection
Challenge : Identifying potential frauds real time. 
Market Benefits : Enhances security and trust, improves operational efficiency and reduces financial risks associated with fraudulent activities.
Identification is based on a whole lot of data that is being generated by the various systems in terms of logs.
Graph Theory can be applied to detect fraudulent activities such as multiple bookings or unusual payment patterns. Machine Learning Models can be to classify transactions as fraudulent or legitimate.
In RedBus application Amazon Athena is used to run queries against the raw data and a run-time graph generation and evaluation engine is built to recognize frauds and block the same.

Graph theory offers an effective approach to identify fraudulent activities, such as detecting multiple bookings or unusual payment patterns. In addition, transactions can be classified as valid or fraudulent using machine learning algorithms.

Amazon Athena is utilised in the RedBus application to run queries against raw data directly. A runtime engine has been created to create and assess graphs dynamically, allowing for quick identification of fraudulent activity and quick risk mitigation.

## Seat Availibity Management
RedBus application requires efficient managing and checking the seat availability across many buses. Segment Trees can be effectively utilized for this functionality. 
Integrating Segment Tree into RedBus's ticket booking system for seat availability management improves efficiency and customer satisfaction. It supports real-time updates and queries, ensuring that users can quickly find and book available seats across multiple buses and routes.
As same company bus can be used for many routes on different dates, combination of bus-route-date can represented as an entry in Fenwick Tree.

Initialise the Tree with total number of seates available. When a booking is made for a bus on particular route and date the corresponding seat count can be descreased and if booking is cancelled the seat count can be increased representing the available seats.  
This quickly retrives the total number of available seats for a specific route over range of dates. This helps the application to dynamically adjust seat availability.

Time Complexity : nlogn

[Code for Segment Tree](https://github.com/chaitra-mk/aps-portfolio/blob/main/SegmentTree.cpp)

## Efficient Ticket Booking
Challenge : During peak time thousands of requests to book ticket may be received. These must be handled to improve customer experience and reduce overbooking.

Market Benefits : It helps to optimize seat utilization, hence increase efficiency.

Organizing and processing booking requests in an orderly and efficient manner by using queues and concurrency control algorithms. By using queues, the system can handle multiple booking requests in real-time, ensuring that each request is processed fairly and in the order it was received. This is particularly important during peak times when the system might receive thousands of simultaneous requests. The requests can be handled based on first come first serve (FIFO) queues or based on Priority queues.

![image](https://github.com/chaitra-mk/aps-portfolio/assets/105005252/2ee8987a-5b9a-4a59-9f06-5fe4368e6bea)


Time Complexity of queue data structure : Insertion and Deletion takes O(1) time and searching takes O(n) time.

Concurrency control uses techniques including locking, optimistic and pessimistic concurrency control, and database transactions to preserve data integrity during concurrent bookings. In order to maintain system stability and user satisfaction, this avoids disputes and guarantees that every booking transaction is performed precisely and thoroughly, either completing completely or not at all.

[Simple Implemetation od Queues](https://github.com/amitbansal7/Data-Structures-and-Algorithms/blob/master/5.Queue/PriorityQueue.c)

## Sort buses based on preferences
Challenge : Handling many sorting criteria like fare, travel time, and relevance efficiently to meet varying user preferences and requirements.
Market Benefits : Improves user experience.
Merge Sort for Efficient Sorting
Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array. In the context of RedBus, Merge Sort can be used to sort bus search results based on various criteria such as relevance, travel time, and fare.

For instance, when a user searches for buses, the initial set may or may not be sorted. By applying Merge Sort, the application can sort these results in a way that optimizes for the user's needs. For example, buses can first be sorted by fare to identify the cheapest options, then by travel time to find the fastest routes, and finally by relevance, which could be determined by factors like the number of stops or departure times that match the user's preferences.

Time Complexity : nlogn

[Code for Merge sort](https://github.com/chaitra-mk/aps-portfolio/blob/main/MergeSort.cpp)

Max-heap and Min-heap can also be used. The buses can be stored in max-heap where they can be  sorted based on reviews.

## Ranked Search Results
To implement ranked search results in an application like RedBus, a combination of Merge Sort and a Weighted Ranking Algorithm can be highly effective. This approach ensures that search results are not only sorted efficiently but also prioritized according to user preferences and historical data. 

After the search results are sorted, a Weighted Ranking Algorithm can used to rank them in order of user preference and historical data. Weights are assigned by this algorithm to several elements that affect the user's decision-making process. User-specific preferences (including preferred departure times or bus operators) and special offers may be among these criteria, as well as user reviews, past on-time performance, and historical performance.

The Weighted Ranking Algorithm calculates a composite score for each bus option by multiplying each factor by its corresponding weight and summing the results. The weights can be dynamically adjusted based on the importance of each factor to the user. For example, if a user frequently prefers buses with shorter travel times, the weight for travel time will be higher. Similarly, if the user values lower fares, the weight for fare will be increased.

## Live Monitoring of the bus 

Challenge : Monitering the bus in real time may experience delays, connectivity issues etc.
Market Benefits : Improves passenger experience and safety by providing real-time bus locations and updates. 
Everyday about 150 K customers travel with a ticket bought on redBus in about 40 K bus trips. We collect real time GPS data from the buses and provide value added services to our customers along with basic tracking of the bus.

For keeping track of the buses data structure called a quadtree can be used [[3]](https://medium.com/@joudwawad/school-bus-tracker-system-architecture-6dd3307e3860) . Imagine a map divided into squares, starting with the entire area RedBus covers. The quadtree keeps track of these squares. If a square has too many buses (say, more than 100), it gets divided into four smaller squares. This keeps happening until each square has a manageable number of buses. This way, RedBus can quickly find buses in any area.
![Screenshot 2024-07-07 195853](https://github.com/chaitra-mk/aps-portfolio/assets/105005252/ac1566f3-2cf6-4605-b7cf-ec8e1b10ced1)


Buses with GPS tell the RedBus server where they are all the time. The server updates its map (the quadtree) with these new locations. The map figures out which square (leaf node) each bus belongs to based on its GPS signal. This keeps the map up-to-date with where all the buses are.

The quadtree structure allows for efficient updates and queries, handling frequent GPS updates from buses and real-time queries from users seamlessly. The dynamic partitioning of the quadtree ensures that densely populated areas, where bus activity is high, are represented with smaller, more granular regions. In contrast, sparsely populated areas have larger regions. This adaptability ensures efficient management of bus data across different densities, maintaining performance and accuracy.

[Link to the simple implemetation of QuadTree](https://github.com/m-byte918/QuadTree-Cpp)

[reference](https://medium.com/@joudwawad/school-bus-tracker-system-architecture-6dd3307e3860)

#### The real RedBus Application uses following process:
The below is the process for live tracking [[1]](https://medium.com/redbus-in/user-generated-reviews-classification-and-tagging-from-redbus-e62b5a5e6951)

Data loading: The data is collected from multiple systems and keep them ready for consumption in real time during the trip. These data points include Vehicle information, Trip schedules, Vehicle assignment schedules and Passenger information. We also have manual process for geo-coding boarding points.
Data processing: In these process we run algorithms on historical data and produce output to be used in real time tracking and reporting. Some of the output of these algorithms are
- Boarding point sequence
- Graph for the bus paths

There are multiple reports for tracking accuracy of the ETA, coverage of Boarding point detection and customer experience during the journey.
Real time tracking: In this system we consume data from the above two systems and merge it with the real time GPS feed coming from the GPS vendor integrations. The result is a set of value added services like;
- Live bus location tracking on mobile web and app
- ETA for boarding and dropping points
- Contextual notifications to passengers through SMS, push notification and automated calls


## Bus Fleet Management
Challenge :  The challenge lies in determining the optimal mix of bus types (e.g., small, medium, large) to assign to different routes and schedules. 
Market Benefits : This optimization aims to maximize profitability by minimizing operational costs while meeting passenger demand and service quality standards.

RedBus fleet management can maximise resource utilisation, cut costs, and improve service efficiency by implementing the knapsack problem. Effective management of bus fleets with varying capacities and operating costs can be achieved through the application of the knapsack problem, which is recognised for its capacity to optimise resource allocation under limitations.Bus fleets typically consist of buses with varying capacities, operational costs, and specific capabilities suited for different routes or times of the day.

![Knapsack_problem_dynamic_programming](https://github.com/chaitra-mk/aps-portfolio/assets/105005252/8d996c53-3890-4965-94f3-20dffb05c120)

Here is the [code](https://github.com/lowkimberly/knapsack/blob/main/knapsack1.cpp)


## Managing Customer Data

Challenges : As data grows in large volumes, scalability issues must be handled while maintaining performance and reliability.
### Hash Tables
A hash table may be used to store a customer's session data for easy access and updates once they log in. This is very helpful for saving preferences, session data, and other temporary information. Using unique identifiers like user IDs or email addresses, hash tables can be utilised to quickly retrieve customer information.

### B and B+ Trees
<div style="display: flex; justify-content: center;">
  <div style="flex: 1; text-align: center;">
    <img src="https://github.com/chaitra-mk/aps-portfolio/assets/105005252/a162b4d7-02aa-4b79-bcda-4e48d5e95868" alt="B Tree" style="max-width: 100%; height: auto;">
    <p style="margin-top: 10px;">B Tree</p>
  </div>
  <div style="flex: 1; text-align: center;">
    <img src="https://github.com/chaitra-mk/aps-portfolio/assets/105005252/04d3e6c7-7d71-4fe5-88f7-d9b051df07bc" alt="B+ Tree" style="max-width: 100%; height: auto;">
    <p style="margin-top: 10px;">B+ Tree</p>
  </div>
</div>



B trees can be used to store and arrange customer data, including booking histories, preferences, and transaction records, after a user logs in. B-trees are effective for storing and retrieving data based on identifiers like customer IDs or booking numbers because each node can have numerous keys and pointers. This structure is appropriate for real-time applications where data access speed is critical since it guarantees that all searches, insertions, and deletions have logarithmic time complexity.

Where range queries are common, such as retrieving bookings within a given period range or ranking customers based on transaction amounts, B+ trees can be used to manage customer related data. RedBus can utilize B+ trees to manage and retrieve booking information, with operations such as searching for bookings by date, customer ID, route etc.

[Code for B Tree](https://github.com/chaitra-mk/aps-portfolio/blob/main/B_Tree.cpp)

[Code for B+ Tree](https://github.com/sayef/bplus-tree/blob/master/BPlusTree.cpp)


## Conclusion

Implementing advanced data structures and algorithms within the RedBus platform enhances its efficiency, scalability, and user experience. Utilizing Trie data structures for efficient location search, Dijkstra's and A* algorithms for route optimization, Fenwick Trees for booking trend analysis, and Segment Trees for seat availability management ensures robust and responsive service. Dynamic pricing models, backed by real-time data, maximize revenue while maintaining customer satisfaction. Additionally, graph theory and machine learning for fraud detection, along with quadtree structures for live bus monitoring, significantly improve operational security and passenger experience. By integrating these technologies, RedBus not only optimizes its operations but also sets a high standard in the online bus ticket booking industry, ultimately leading to increased market competitiveness and customer trust.


## References 
[1] RedBus. (n.d.). User-generated reviews classification and tagging from RedBus. Medium. [Online]. Available: [https://medium.com/redbus-in/user-generated-reviews-classification-and-tagging-from-redbus-e62b5a5e6951
](https://medium.com/redbus-in/user-generated-reviews-classification-and-tagging-from-redbus-e62b5a5e6951
)

[2] RedBus. (n.d.). RedBus bus tracking system. Medium. [Online]. Available: [https://medium.com/redbus-in/redbus-bus-tracking-system-6134aa6b9160](https://medium.com/redbus-in/redbus-bus-tracking-system-6134aa6b9160)

[3] Joud Wawad. (n.d.). School bus tracker system architecture. Medium. [Online]. Available: [https://medium.com/@joudwawad/school-bus-tracker-system-architecture-6dd3307e3860](https://medium.com/@joudwawad/school-bus-tracker-system-architecture-6dd3307e3860)

[4] GeeksforGeeks. (n.d.). Trie | Insert and Search. Retrieved July 8, 2024, from [https://www.geeksforgeeks.org/trie-insert-and-search/](https://www.geeksforgeeks.org/trie-insert-and-search/)

[5] RedBus Engineering. (2020). RedBus Tracking: What’s Under the Hood? Medium. Retrieved July 8, 2024, from [https://medium.com/redbus-in/redbus-tracking-whats-under-the-hood-9ca99aa6b8ee](https://medium.com/redbus-in/redbus-tracking-whats-under-the-hood-9ca99aa6b8ee)

[6] GeeksforGeeks. (n.d.). Merge Sort Algorithm. Retrieved July 8, 2024, from [https://www.geeksforgeeks.org/merge-sort/](https://www.geeksforgeeks.org/merge-sort/)



