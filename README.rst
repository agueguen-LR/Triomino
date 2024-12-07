Triomino
========
|cmake| |Coveralls| |Documentation Status|

School project for 2nd year at university, the goal is to implement many functionalities of the game 'Triominoes' based on the starting blocs we developed during lessons and the final test.

The starting point for this project was the correction of the final test. These 'starting point' files have our teacher's, Christophe Demko, name and copyright at the top, and will most likely stay as they are.

Progress
--------

Step three, flawfinder, coverage and triomino-generate are done.

Installation
------------

Requirements
~~~~~~~~~~~~

.. code:: shell-session

   $ sudo apt install cmake gcc lcov cppcheck python-pip valgrind flawfinder doxygen
   $ git clone https://github.com/agueguen-LR/Triomino.git
   $ pip install -r Triomino/docs/requirements.txt

Compilation
~~~~~~~~~~~

Create the build directory and compile the project.

.. code:: shell-session

  $ mkdir build
  $ cd build
  $ cmake ..  \
     -DBUILD_COVERAGE=1 \
     -DBUILD_HTML_COVERAGE=1 \
     -DUSE_VALGRIND=1 \
     -DRUN_CPPCHECK=1
  $ make

Documentation
~~~~~~~~~~~~~

Generate the documentation.

Documentation is generated in the build/docs directory.

.. code:: shell-session

  $ make docs

Installation
~~~~~~~~~~~~

Install the project.

Add -DCMAKE_INSTALL_PREFIX:"Install_directory" to cmake command if you want to install in a specific directory.

.. code:: shell-session

  $ make install

Review Code
-----------

Run test and code coverage
~~~~~~~~~~~~~~~~~~~~~~~~~~

Run the tests and check the code coverage.

Code coverage is generated in the build/coverage directory.

.. code:: shell-session

   $ make test
   $ make coverage
   $ make html-coverage

Check style
~~~~~~~~~~~

Check the code style is in accord with the clang format.

.. code:: shell-session

   $ make cclint

Run flaw finder
~~~~~~~~~~~~~~~

Check for any security issues in the code.

.. code:: shell-session

  $ make flawfinder

Usage
-----

Generate Triominos
~~~~~~~~~~~~~~~~~~

Run the triomino-generate executable with the file name as argument.

Fails if the file already exists.

Generates all possible combinations of triominos and writes them to the file, named initial.3 here.

.. code:: shell-session

  $ triomino-generate initial.3

Display Triominos
~~~~~~~~~~~~~~~~~

Run the triomino-display executable with the file name as argument.

Prints all the triominos in the file (stored in binary format) into the console.

.. code:: shell-session

  $ triomino-display initial.3


.. |cmake| image:: https://github.com/agueguen-LR/Triomino/actions/workflows/cmake.yml/badge.svg
   :target: https://github.com/agueguen-LR/Triomino/actions
.. |Coveralls| image:: https://coveralls.io/repos/github/agueguen-LR/Triomino/badge.svg?branch=master
   :target: https://coveralls.io/github/agueguen-LR/Triomino?branch=master
.. |Documentation Status| image:: https://readthedocs.org/projects/triomino/badge/?version=latest&style=flat
   :target: http://triomino.readthedocs.io/en/latest/?badge=latest
