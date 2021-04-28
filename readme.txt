CSCI 2270 - Final project
- Troy Husted
- Amelia Krause 
- Ananya Tandel

Our minigit project, due to using filesystem, will only compile with c++17. Feel free to copy/paste the following commmand
into your terminal to compile the minigit. (This can be run using a basic ./a.out command)

    g++ -std=c++17 driver.cpp miniGit.cpp

Upon startup, you will be prompted to initialize a new repository. To answer this, just input a simply 'y' or 'n' (caps not required) 
and press enter. Due to the fact this is a 'trivial' question to the user, an answer of no will also initialize a new repository.

You wll then be prompted with a menu that will continuously run until the number 5 has been inputted by the user. Option 1 allows
the user to add a file to the current commit singly linked list. After each add, a visual display of the SLL will be displayed to 
the user to ensure the file has been added, and to keep track of what is already in the list (duplicate files cannot be added).

Option 2 allows the user to remove files from the singly linked list. Fairly straight forward - if the file exisits in the SLL
it will end up being removed, displaying a visual of the SLL once more after the removal. If the file does not exists, the terminal
will let you know and return you back to the menu.

Option 3 allows the user to commit their changes to the created repository "minigit". This will traverse the SLL at the current commit
in its entirety, and will do the follwing.
    - First checks if the current file version exists in the minigit    
        - If no -> Copies the current file into the minigit with the respective file version (starts as version 0)
        - If yes -> Checks if the current file version matches the existing file version
            - If no -> Copy a new file over with an incremented file version
            - If yes -> Do nothing (files match)
    - Then creates a new doubly linked list node (a new commit number/node)
        - Once the new doubly node has been created, we set the starterNode (head of doubly LL)->next to the new doublyNode and
        perform a deep copy of the previous singly linked list to the new doubly node singly linked list.

Option 4 allows the user to checkout a previous version of files within the commit's respective singly linked list. In doing so,
if the user inputs a valid commit number, we will traverse to the respective doubly node that corresponds to that commit.
    - We will then traverse the singly linked list at that respective doubly node
        - Copy the respective fileVersion data to the current working diretory (this overwrites the current working directory files)

Option 5 will quit the program, and upon quitting the program will close the minigit directory including all files inside.

Notes:
    Input verification has not been added (Please be careful about all of your inputs)
    

