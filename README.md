
# Work Report

## Name: <ins> Robin Lee Simpson </ins>

## Features:

- Not Implemented:

<br><br>

- Implemented:
  - insert head function
  - print list function
  - print list backwards function*
  - search list
  - delete node
  - insert before and after
  - copy function
  - clear list function
  - previous node
  - at function
  - Big 3 Three for list
  - Linked List class
  - Stack
  - Queue
  - Airport


<br><br>

- Partly implemented:


<br><br>

- Bugs
  - ~~Print reverse unable to print "|||"~~ fixed 9/1/21 (2:25 PM)
  - ~~2 zero's when copying~~ fixed 8/27/21 (7:07 PM)
  - Copy constructor, assignment operator OR pop function causes issues when trying to create a copy. After creating a copy via copyconst or assignment operator, original cannot be popped and program will not move to the next test

<br><br>

# Reflections:

- Rough start with grasping the nodes
- Creating simulation was made easier by the carwash example
- Took longer than expected due to delays and bugs
- Frustrating yet enjoyable -- I can spend 12 hours bashing my head debugging
- Learned a lot

<br><br>

# Log:
- 8/26 (3:50 PM): Created linked_list_functions.h with insert_head and print_list for node
- 8/26 (3:52 PM): Created linked list class
- 8/26 (7:04 PM): Delete node, search list functions
- 8/26 (9:53 PM): Bug fixes, created insert function
- 8/26 (10:35 PM): Insert Before and After
- 8/27 (2:08 PM): Implemented _at function
- 8/27 (2:19 PM): Added clear list function
- 8/27 (5:23 PM): Copy function added
- 8/27 (7:07 PM): Copy function bug fix
- 8/28 (7:00 PM): Finished list.h - finished destructor, copy constructor, assignment operator, second constructor
- 8/30 (12:25 AM): Added provided stack.h, queue.h, split node.h to separate .h, changed insert head to implement previous
- 8/31 (2:23 PM): Finished linked list functions; Test works for linked list functions; mistakenly created a queue head insert
- 8/31 (2:39 PM): Updated insert head as a doubly linked
- 9/1 (6:42 PM): Updated Stack.h with push, pop, and top. Updated testB
- 9/2 (10:33 AM): Updated Queue.h with push, pop, front, and rear. Updated testB
- 9/2 (12:35 PM): Finished Stack, Finished Queue, Finished Iterator
- 9/3 (6:01 PM): Started Simulation.h
- 9/4 (10:30 AM): Simulation.h functions finished
- 9/5 (3:00 PM): Started on Simulation.cpp
- 9/7 (12:33 PM): Working on Simulate Airport function
- 9/7 (2:19 PM): Finshed first prototype of simulation.cpp
- 9/7 (3:54 PM): Finished Airport (no fuel implementation, no priority)
- 9/7 (5:24 PM): Finished Airport

# **output**
<br/><br/>
# basic_test.cpp output:

![basic](https://i.imgur.com/ByDcXb3.png)
<br/><br/><br/><br/>
# testB.cpp output:

![testB](https://i.imgur.com/fAIciDJ.png)
<br/><br/><br/><br/>

# testB.cpp 100,000 simulation time output:
![100k](https://i.imgur.com/DRayivX.png)

