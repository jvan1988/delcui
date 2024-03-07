# ContextGrep

ContextGrep is a command-line utility that searches for a specified pattern in a text file and prints the lines containing the pattern along with contextual lines.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Building](#building)

## Introduction

ContextGrep is a tool designed to provide additional context around matches when searching for a pattern in a text file. It can be useful for quickly identifying the context in which a particular pattern appears in a file.

## Features

- Search for a specified pattern in a text file.
- Print lines containing the pattern along with contextual lines.
- Customizable context size. Matches overlapping within the context size will have their section merged in with the previous section

## Usage

### Command-line Options

	./ContextGrep [OPTIONS] PATTERN FILE

Replace OPTIONS, PATTERN, and FILE with your desired parameters.

### Options

- -C, --context N: Print N lines of output context.

## Building

Follow these steps to build ContextGrep:

###Clone the repository:

	git clone https://github.com/your-username/ContextGrep.git
	cd ContextGrep

###Build the executable:

	make

###Run the executable:

	./bin/ContextGrep -C 2 "your_pattern" your_file.txt
