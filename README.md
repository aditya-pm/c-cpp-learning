# C / C++ Learning

This repository documents my learning journey in **C and C++**, with a focus on understanding core language concepts, memory behavior, and correct, idiomatic usage through small, focused examples.

This repository is **not** intended for competitive programming or daily Data Structures & Algorithms practice. DSA-focused work is maintained in a separate repository.


## Repository Structure

```
c-cpp-learning/
├── concepts/
│   ├── common/   # Concepts shared between C and C++
│   ├── c/        # C-specific concepts
│   └── cpp/      # C++-specific concepts
│
└── libraries/
    ├── c/        # Standard C libraries and usage
    └── cpp/      # C++ standard library (STL) and related utilities

```



## Concepts

The `concepts/` directory focuses on *how the language and the underlying machine behave*.

* `common/` contains fundamentals applicable to both C and C++, such as memory layout, pointers, and stack vs heap behavior.
* `c/` contains concepts specific to the C language, including manual memory management and low-level constructs.
* `cpp/` contains concepts specific to C++, such as object lifetime, RAII, copy and move semantics, and language abstractions.

Each file is designed to demonstrate **one concept clearly and in isolation**.

---

## Libraries

The `libraries/` directory explores the correct and idiomatic usage of commonly used libraries.

* `c/` focuses on standard C libraries (`stdio`, `stdlib`, `string`, etc.).
* `cpp/` focuses on the C++ standard library (STL) and related utilities.

Examples in this directory are intentionally small and focused on behavior and usage rather than full applications.



## Scope and Intent

* Learn C and C++ fundamentals in depth
* Develop a strong understanding of memory, performance, and language behavior
* Keep examples minimal, focused, and educational

This repository intentionally does **not** include:

* Data Structures & Algorithms problem solutions
* Competitive programming code



## Disclaimer

This repository is intended for learning and experimentation. Some examples may intentionally demonstrate incorrect usage or undefined behavior for educational purposes.
