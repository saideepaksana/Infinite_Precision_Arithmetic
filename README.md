# Infinite Precision Arithmetic

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](#)  
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

A header‑only C++ library providing arbitrary‑precision integer and floating‑point arithmetic via simple OOP interfaces. Supports addition, subtraction, multiplication, and division on numbers of virtually unlimited length.

---

## Table of Contents

- [Features](#features)  
- [Getting Started](#getting-started)  
  - [Prerequisites](#prerequisites)  
  - [Installation](#installation)  
- [Usage](#usage)  
  - [Integer Example](#integer-example)  
  - [Float Example](#float-example)  
- [API Reference](#api-reference)  
- [Limitations](#limitations)  
- [Roadmap](#roadmap)  
- [Contributing](#contributing)  
- [License](#license)  

---

## Features

- **Arbitrary‑precision** integers & floats  
- Fully **object‑oriented** design  
- Header‑only public API in `include/infinite_precision.hpp`  
- Simple CLI driver for basic arithmetic  
- Easily extensible (add exponentiation, modulo, etc.)

---

## Getting Started

### Prerequisites

- C++17‑compatible compiler (GCC ≥ 7.0, Clang ≥ 5.0, MSVC ≥ 2017)  
- CMake ≥ 3.10 (optional, if using CMake)  
- Make (if using the provided Makefile)

### Installation

Clone the repository and build:

```bash
git clone https://github.com/yourusername/Infinite_Precision_Arithmetic.git
cd Infinite_Precision_Arithmetic

# Option A: Using CMake
mkdir build && cd build
cmake ..
make infprec-cli

# Option B: Using Makefile
make
