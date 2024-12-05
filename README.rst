Triomino
====================

School project for 2nd year at university, the goal is to implement many functionalities of the game 'Triominoes' based on the starting blocs we developped during lessons and the final test.
The starting point for this project was the correction of the final test. These 'starting point' files have our teacher's, Christophe Demko, name and copyright at the top, and will most likely stay as they are.

Progress
--------

Step two, documentation and cclint, has completed.

Installation
------------

.. code:: shell-session

   $ sudo apt install cmake gcc lcov cppcheck python-pip valgrind flawfinder doxygen
   $ git clone https://github.com/agueguen-LR/Triomino.git
   $ pip install -r Triomino/docs/requirements.txt

Usage
-----

Compilation
~~~~~~~~~~~

.. code:: shell-session

   $ mkdir build
   $ cd build
   $ cmake ../Triomino \
       -DUSE_VALGRIND=1 \
   $ make

Run test
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: shell-session

   $ make test

Check style
~~~~~~~~~~~

.. code:: shell-session

   $ make cclint

Build the docs
~~~~~~~~~~~~~~

.. code:: shell-session

   $ make docs
