# C - Binary Trees

## Function Prototypes

All function prototypes used to compile are included in the header file:

-typedef struct binary_tree_s binary_tree_t;

-typedef struct binary_tree_s bst_t;

-typedef struct binary_tree_s avl_t;

-typedef struct binary_tree_s heap_t;

-void binary_tree_print(const binary_tree_t *);

-binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

-binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

-binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

-void binary_tree_delete(binary_tree_t *tree);

-int binary_tree_is_leaf(const binary_tree_t *node);

-int binary_tree_is_root(const binary_tree_t *node);

-void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

-void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));-

-void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

-size_t binary_tree_height(const binary_tree_t *tree);

-size_t binary_tree_depth(const binary_tree_t *tree);

-size_t binary_tree_size(const binary_tree_t *tree);

-size_t binary_tree_leaves(const binary_tree_t *tree);

-size_t binary_tree_nodes(const binary_tree_t *tree);

-int binary_tree_balance(const binary_tree_t *tree);

-int binary_tree_is_full(const binary_tree_t *tree);

-int binary_tree_is_perfect(const binary_tree_t *tree);

-binary_tree_t *binary_tree_sibling(binary_tree_t *node);

-binary_tree_t *binary_tree_uncle(binary_tree_t *node);


## Tasks
### 0. New node
Write a function that creates a binary tree node

-Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`

- Where parent is a pointer to the parent node of the node to create
- And value is the value to put in the new node
- When created, a node does not have any child
- Your function must return a pointer to the new node, or `NULL` on failure

```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node

alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
```

### 1. Insert left

Write a function that inserts a node as the left-child of another node

- Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`
- Where parent is a pointer to the node to insert the left-child in
- And value is the value to store in the new node
- Your function must return a pointer to the created node, or `NULL` on failure or if parent is NULL
- If parent already has a left-child, the new node must take its place, and the old - left-child must be set as the left-child of the new node.
```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left

alex@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)                                            
```
### 2. Insert right

Write a function that inserts a node as the right-child of another node

- Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`
- Where parent is a pointer to the node to insert the right-child in
- And value is the value to store in the new node
- Your function must return a pointer to the created node, or `NULL` on failure or if parent is NULL
- If parent already has a right-child, the new node must take its place, and the - - old right-child must be set as the right-child of the new node.
```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right

alex@/tmp/binary_trees$ ./2-right 
  .--(098)--.
(012)     (402)

  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
```
### 3. Delete

Write a function that deletes an entire binary tree

- Prototype: `void binary_tree_delete(binary_tree_t *tree);`
- Where tree is a pointer to the root node of the tree to delete
- If tree is` NULL`, do nothing
```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
alex@/tmp/binary_trees$ valgrind ./3-del

==13264== Memcheck, a memory error detector
==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==13264== Command: ./3-del
==13264== 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
==13264== 
==13264== HEAP SUMMARY:
==13264==     in use at exit: 0 bytes in 0 blocks
==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
==13264== 
==13264== All heap blocks were freed -- no leaks are possible
==13264== 
==13264== For counts of detected and suppressed errors, rerun with: -v
==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### 4. Is leaf
Write a function that checks if a node is a leaf

- Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`
- Where node is a pointer to the node to check
- Your function must return 1 if node is a leaf, otherwise 0
- If `node`is `NULL`, return `0`

```
 gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf

alex@/tmp/binary_trees$ ./4-leaf 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a leaf: 0
Is 128 a leaf: 0
Is 402 a leaf: 1


```


 ### 5. Is root

Write a function that checks if a given node is a root

- Prototype: `int binary_tree_is_root(const binary_tree_t *node);`
- Where node is a pointer to the node to check
- Your function must return 1 if node is a root, otherwise 0
- If `node` is `NULL`, return `0`


```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root

alex@/tmp/binary_trees$ ./5-root 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a root: 1
Is 128 a root: 0
Is 402 a root: 0

```

 ### 6. Pre-order traversal

Write a function that goes through a binary tree using pre-order traversal

- Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`
- Where tree is a pointer to the root node of the tree to traverse
- And func is a pointer to a function to call for each node. The value in the node - must be passed as a parameter to this function.
- If tree or func is `NULL`, do nothing

```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre

alex@/tmp/binary_trees$ ./6-pre
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
6
56
402
256
512
```

### 7. In-order traversal

Write a function that goes through a binary tree using in-order traversal

- Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`
- Where tree is a pointer to the root node of the tree to traverse
- And func is a pointer to a function to call for each node. The value in the node - must be passed as a parameter to this function.
- If tree or func is `NULL`, do nothing

```
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in

alex@/tmp/binary_trees$ ./7-in
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
12
56
98
256
402
512
```

###8. Post-order traversal

Write a function that goes through a binary tree using post-order traversal

- Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
- Where tree is a pointer to the root node of the tree to traverse
- And func is a pointer to a function to call for each node. The value in the node - must be passed as a parameter to this function.
- If tree or func is `NULL`, do nothing

```

gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post

alex@/tmp/binary_trees$ ./8-post
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
56
12
256
512
402
98

```

## Contributing

Pull requests are welcome. For major changes, please open an issue first

to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Authors and acknowledgment

## Glorisabel Rivera Rodriguez (<glorisabel200@gmail.com>) , github [link]
(https://github.com/glorisabelriv/holbertonschool-low_level_programming/tree/main/doubly_linked_lists)
