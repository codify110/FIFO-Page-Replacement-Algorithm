# Least Recently Used Page Replacement Algorithm
## Page Fault:
A page fault happens when a running program accesses a memory page that is mapped into the virtual address space, but not loaded in physical memory.Since actual physical memory is much smaller than virtual memory, page faults happen. In case of page fault, Operating System might have to replace one of the existing pages with the newly needed page. Different page replacement algorithms suggest different ways to decide which page to replace. The target for all algorithms is to reduce the number of page faults.

## Least Recently Used Page Replacement Algorithm Example : 
Consider the page reference string 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 with 4 page frames.Find number of page faults.
Initially all slots are empty, so when 7 0 1 2 are allocated to the empty slots —> 4 Page faults
0 is already their so —> 0 Page fault.
when 3 came it will take the place of 7 because it is least recently used —>1 Page fault
0 is already in memory so —> 0 Page fault.
4 will takes place of 1 —> 1 Page Fault
Now for the further page reference string —> 0 Page fault because they are already available in the memory.
## Output: 
![Least Recently Used Algorithm](https://user-images.githubusercontent.com/69696459/126542339-68971098-c019-4337-a98e-6478f065bdea.PNG)
