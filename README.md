# Data Structures Lab Programs in C

This repository contains 15 standalone C programs for the Data Structures lab list.

## Program list

| No. | File | Topic |
|---|---|---|
| 1 | `01_singly_linked_list.c` | Singly linked list: insert, delete, search, display |
| 2 | `02_doubly_linked_list.c` | Doubly linked list: insert, delete, forward/backward display |
| 3 | `03_circular_linked_list.c` | Circular singly linked list: insert, delete, display |
| 4 | `04_stack_array_and_linked_list.c` | Stack using array and linked list |
| 5 | `05_infix_postfix_and_evaluation.c` | Infix-to-postfix conversion and postfix evaluation |
| 6 | `06_queue_array_and_linked_list.c` | Queue using array and linked list |
| 7 | `07_circular_queue_and_priority_queue.c` | Circular queue and priority queue |
| 8 | `08_deque_circular_array.c` | Deque using circular array |
| 9 | `09_hashing_collision_resolution.c` | Linear probing, quadratic probing, separate chaining |
| 10 | `10_bst_insert_delete_search.c` | BST insertion, deletion, search |
| 11 | `11_bst_fixed_data_traversal_search.c` | BST fixed data, recursive traversals, search |
| 12 | `12_bst_nonrecursive_traversals.c` | BST fixed data, non-recursive inorder/preorder/postorder |
| 13 | `13_graph_bfs_dfs.c` | Graph adjacency matrix, BFS, DFS |
| 14 | `14_floyd_warshall_all_pairs_shortest_path.c` | Floyd–Warshall all-pairs shortest paths |
| 15 | `15_dijkstra_single_source_shortest_path.c` | Dijkstra shortest path from a source |

## Compile and run

Install GCC or another C compiler. Open a terminal in this folder and run:

```bash
gcc 01_singly_linked_list.c -o program
./program
```

On Windows, run `program.exe` after compiling:

```bash
gcc 01_singly_linked_list.c -o program.exe
program.exe
```

Replace the filename with the program you want to run. Each file has its own `main()` function, so compile **one file at a time**. Do not compile all 15 files into a single executable.

## Notes

- These are menu-driven educational implementations; enter values in the format requested by each program.
- Graph programs use vertices numbered from `1` to `N` in prompts and output.
- For program 14, enter `10000000` for an absent edge (`INF`) and `0` on the diagonal.
- For program 15, Dijkstra's algorithm requires non-negative edge weights. Enter `10000000` for an absent edge and `0` on the diagonal.
- Program 5 evaluates single-digit numbers and uppercase variables. For multi-digit operands, extend the tokenizer to parse complete numbers.
- Program 9 uses a fixed hash table size of 11. The same inserted key is added to all three collision-resolution demonstrations.

## Suggested GitHub repository name

`data-structures-lab-c`

## Suggested GitHub description

`Menu-driven C implementations of linked lists, stacks, queues, hashing, BSTs, graph traversal, and shortest-path algorithms.`
