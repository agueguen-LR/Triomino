import os

output_dir = os.getenv("DOXYGEN_OUTPUT_DIR")

if not output_dir:
    os.environ["DOXYGEN_OUTPUT_DIR"] = os.getenv("PWD") + "/doxygen"

os.system("cd ..; doxygen")

# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Triomino'
copyright = '2024, Adrien Gueguen'
author = 'Adrien Gueguen'
release = '1.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'alabaster'
html_static_path = ['_static']
