# Here are some topics we've discussed during this quarter

## Version Control Software (git)
Among other things we talked about: 
+ Bitbucket & Github
+ Sourcetree & Github Desktop
We then set up a couple of local repositories. One of them was managed via a Command Line Interface (CLI for short), whereas the other was managed via frontends (e.g., VS2015 and git gui). 

You might also want to check out the following links: 
+ Git tutorial (github)
+ Learn SourceTree with BitBucket Cloud (bitbucket)
+ GitHub Desktop User Guides
+ Hello World in GitHub
+ An Intro to Git and GitHub for Beginners
If you decide that Graphical User Interfaces (GUI's) are not for you, then I highly recommend you bookmark these links: 
+ Git Tutorial (local branching on the cheap). By the very same developers of git.
+ Git FAQ. For specific everyday type of examples. 
+ Pro Git (book). In case you want to be a Git-Fu master. Also available in several downloadable formats:
++ PDF 
++ EPUB
++ MOBI

# Here are some topics we've discussed during this quarter

## Move semantics 

Among specific sub-topics we discussed:

+ lvalues and rvalues (old meaning)
+ The new M diagram:
glvalues [ locator values (lvalues) AND xvalues (x-rated, [e]xperts only, [e]xpiring) ].
rvalues [ xvalues AND prvalues ].
+ How *moving* (e.g., stealing resources) prevents unnecessary copies.
+ Why a working move constructor also provides move assignment functionality if the assignment operator is a construct-and-swap one.


## Generic algorithms, lambda functions, binders and adapters 

Here we focused mostly on examples of how to use these tools. However, we also dug deep into the way binders can be implemented via a combination of functors, and template functions.

The 10c-genericAlg-LambdaFun is now deprecated [will no longer be maintained]. If you want to get a better idea of the way things were presented during lecture you should look instead at the handouts and examples in the following three repositories

+ 10c-generic-algorithms 
+ 10c-lambda-functions 
+ 10c-binders-and-adapters

## Iterators 

Among specific sub-topics we discussed:

+ Types: input, output, forward, bidirectional, and random access.
+ Their operations (dereferencing, increment, decrement, operator[],as well as overloads of several 'arithmetic' operators (e.g., +, +=, -, -=, <, <=, ==, !=, etc.).
+ The advantages of passing a range [first,last) over passing a container.
+ The 10c-iterators contains some theory, as well as examples and an implementation of a bidirectional iterator for our very own Pic10C::list<ItemType> class. 

## Smart pointers 

Among specific sub-topics we discussed:

+ shared_ptr<ItemType>
+ weak_ptr<ItemType>
+ unique_ptr<ItemType>
We also 'home-cooked' our own SmartPtr class with the purpose of understanding how reference counting works. It turned out that our class had a few advantages over the standard smart pointers listed above. On the negative side, our implementation is not nearly as strong as any of the standard smart pointers. In the 10c-smart-pointers repository, you can find exmaples of how to use these classes, as well as problems that arise (e.g., the cycle problem) if one does not use these classes carefully. 

## Memory management 

Among specific sub-topics we discussed:

Examples of memory mismanagement
Slicing and leaks via inheritance.
Safe programming practices.
The Memory Management Repository contains additional documentation that you might find helpful. 

C++ STL containers 

Among specific sub-topics we discussed:

Categories: sequential, adaptors, associative, etc. 
Complexity in running times for "typical" operations associated to every container.
Details about their implementation. E.g: based on other containers, based on self-balancing binary search trees, etc.
The STL containers repository contains a brief summary of some of the things we mentioned during lecture. 

Introduction to Qt. 

Some of the notions that were introduced are:

The RAII idiom.
Signals, Slots and the way they communicate [via their parameters]. 
Functions "being sent" as parameters to other functions.
The repositories Qt-via-CLI, Qt-connections, as well as Qt-dots might come in handy at some point; be sure to check them out. 
The series of examples in the Qt-via-CLI repository are lifted mostly taken from a pdf textbook found online (Google search: qt pdf book). You might want to read through the first chapter, especially if you want to be able to use Xcode and/or Visual Studio instead of Qt Creator. 

Templates 

Among specific sub-topics we discussed:

Template functions are "smart". The parameter types are deduced from the function call.
Template classes are "dumb". The template types need to be explicitly specified in the object instatiation.
Default parameter values, and default template paramater values.
Setting policy: templates + function objects and/or function pointers.
The repository 10c-templates contains examples that you might find helpful. Those same examples can be found in this [deprecated] repository, but you have to navigate through commits to access them. 

Inheritance and polymorphism

Among specific sub-topics we discussed:
Syntax declaration and keywords (i.e., public, protected, and private).
Base and Derived classes.
Multiple inheritance.
Virtual member functions.
Abstract classes.
In the future I hope to have a pdf handout with some additional remarks. In the meantime you are encouraged to browse through the repository 10c-review-inheritance.

Also, a quick google search (inheritance polymorphism c++) should provide additional examples and/or explanations about these topics.


Function pointers 

Among specific sub-topics we discussed:

Function names storing memory addresses (i.e., a function name doubles as a pointer).
Declaration of function pointers.
Use of function pointers to "pass a function to another function".
Setting policy via function pointers. 
There is a topic we did not discuss, but we will come back to it at some point, maybe after we cover templates. 
Appending parenthesis to primitive types, classes, variables and objects functors.
The repositories 10c-review-function-pointers, as well as 10c-function-pointers [deprecated] might come in handy at some point. Be sure to check them out. 

Version Control Software (git)
Among other things we talked about: 
Bitbucket & Github
Sourcetree & Github Desktop
We then set up a couple of local repositories. One of them was managed via a Command Line Interface (CLI for short), whereas the other was managed via frontends (e.g., VS2015 and git gui). 

You might also want to check out the following links: 
Git tutorial (github)
Learn SourceTree with BitBucket Cloud (bitbucket)
GitHub Desktop User Guides
Hello World in GitHub
An Intro to Git and GitHub for Beginners
If you decide that Graphical User Interfaces (GUI's) are not for you, then I highly recommend you bookmark these links: 
Git Tutorial (local branching on the cheap). By the very same developers of git.
Git FAQ. For specific everyday type of examples. 
Pro Git (book). In case you want to be a Git-Fu master. Also available in several downloadable formats:
PDF
EPUB
MOBI
