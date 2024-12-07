Triomino
====================
|cmake| |Coveralls| |Documentation Status|

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
   $ cmake ..  \
      -DBUILD_COVERAGE=1 \
      -DBUILD_HTML_COVERAGE=1 \
      -DUSE_VALGRIND=1 \
      -DRUN_CPPCHECK=1
   $ make

Run test and code coverage
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: shell-session

   $ make test
   $ make coverage
   $ make html-coverage

Check style
~~~~~~~~~~~

.. code:: shell-session

   $ make cclint

Run flaw finder
~~~~~~~~~~~~~~~

.. code:: shell-session

  $ make flawfinder

Build the docs
~~~~~~~~~~~~~~

.. code:: shell-session

   $ make docs


.. |cmake| image:: https://github.com/agueguen-LR/Triomino/actions/workflows/cmake.yml/badge.svg
   :target: https://github.com/agueguen-LR/Triomino/actions
.. |Coveralls| image:: https://coveralls.io/repos/github/agueguen-LR/Triomino/badge.svg?branch=master
   :target: https://coveralls.io/github/agueguen-LR/Triomino?branch=master
.. |Documentation Status| image:: https://readthedocs.org/projects/triomino/badge/?version=latest&style=flat
   :target: http://triomino.readthedocs.io/en/latest/?badge=latest
