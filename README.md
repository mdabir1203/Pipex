# Get_Next_Line_42
This project is about programming a function that returns a line read from a file descriptor


A Good Guide regarding the concept is given by @Raspurrin Life gets easier:xD!![42Guides](https://github.com/Raspurrin/42Guides/blob/main/get_next_line/get_next_line.md)

I used a different implementation idea with Intrusive Linked List. Although it is not required but it helped me learn how to implement linked list.
(Its not about showing off though -->> Just was fedup with the previous implementation where I had timeouts  _-_

## **A small visual of the concept:** ##

<img width="1891" alt="image" src="https://user-images.githubusercontent.com/66947064/183244165-8375f657-5c85-4c64-98e2-47e206932e70.png">

## Intrusive Link List: 

<img width="770" alt="image" src="https://user-images.githubusercontent.com/66947064/183244206-088c95b7-cccd-4488-ac0b-54adceb879b1.png">

## Advantages of Array Approach in this case :

<img width="734" alt="image" src="https://user-images.githubusercontent.com/66947064/183244646-b5e47b3f-01c0-4cea-9ad6-37642b9e6f7f.png">

 For more detailed idea.. Look into this: [Data Structure the lord](https://www.data-structures-in-practice.com/intrusive-linked-lists/)
 
 
 
 One more thing : This is also faster. Have to do a benchmark test though. If anybody knows that please do and let me know ? 


##Things/tools/resources I used while doing this : 

- **Debugging ( Use lldb or usual gdb)**
    Resource Link: A great resource from a fellow 42 Student from another campus(this gem was found in the slack 42 Channel. Its a gem of resources and         peer learning. Use it wisely :
    
   [Debug Me !!](https://sebastienwae.github.io/debugging-42/) `

- **Intutive sense about Memory Allocation** (still learning) - Malloc or Calloc -->> 
    [Stackoverflow !!](https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc)

- Static Variables and Allocating large memory to it .. :xD (You get Timeout( !!! )  -->:xD)
    _<details><summary> **Why allocating large memory in the stack with static variable not worth it ?** </summary><p>  
 _If you are allocating a big chunk of memory as a static variable inside a function, that memory will be allocated to your software until you exit from it.  It is completely valid to do so if you are actively using that memory, like get_next_line. But if you are not using the memory you allocated, then your software will misuse the resources. I know that Mac will recognises this misuse and simply swap your memory usage to the hard drive, which causes your software to slow down._                       ----- @Ali, Fellow Peer from 42 Wolfsburg  
 </p>
</details>

-->> Last but not least : Learn from Evaluations -- <<<<

   
