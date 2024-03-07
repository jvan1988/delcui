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
- Customizable context size. 
- Matches overlapping within the context size given will be combined into one output

## Usage

### Command-line Options

	./d-grep [OPTIONS] PATTERN FILE

Replace OPTIONS, PATTERN, and FILE with your desired parameters.

### Options

- -C N: Print N lines of output context.
- -C  : Print Nothing

## Building

Follow these steps to build ContextGrep:

### Clone the repository:

	git clone https://github.com/your-username/delcui.git
	cd delcui

### Build the executable:

	make

### Run the executable:

	./bin/d-grep -C 2 "your_pattern" your_file.txt
