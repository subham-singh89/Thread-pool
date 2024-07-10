# ThreadPool Example

This project demonstrates a simple thread pool implementation in C++ using `std::thread`, `std::mutex`, `std::condition_variable`, and `std::future`.

## Features

- **ThreadPool**: Manages a fixed number of threads and distributes tasks asynchronously.
- **Task Enqueueing**: Supports enqueueing tasks with arguments and returning results using `std::future`.
- **Thread Safety**: Ensures thread safety using mutexes and condition variables.
- **Shutdown Mechanism**: Gracefully shuts down the thread pool when tasks are completed.

## Usage

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/YOUR_USERNAME/ThreadPoolExample.git
   cd ThreadPoolExample

    Build the Project:

    Ensure you have CMake installed. Then, build the project:

    bash

cmake .
make

Run the Example:

Execute the compiled executable to see the thread pool in action:

bash

    ./ThreadPoolExample

    Customization:

    Modify main.cpp to change the number of threads in the pool or the tasks being executed.

Requirements

    C++ compiler with C++17 or higher support
    CMake (version 3.8 or newer)

Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
