# Process Scheduling Simulator - README

## Overview

This project is a **Process Scheduling Simulator** that implements two scheduling algorithms: **FIFO (First In, First Out)** and **Round Robin (RR)**. The program manages processes using linked lists, calculates scheduling metrics like turnaround time and waiting time, and visualizes process scheduling with Gantt charts.

---

## Features

1. **FIFO Scheduling**:
   - Processes are scheduled in the order of their arrival.
   - Calculates average turnaround and waiting times.
   - Displays a Gantt chart of process execution.

2. **Round Robin Scheduling**:
   - Processes are executed in a cyclic order based on a time quantum.
   - Supports dynamic quantum allocation and visual representation of the Gantt chart.
   - Calculates average turnaround and waiting times.

3. **Dynamic Process Management**:
   - Allows user input for processes and their attributes (arrival time, execution time).
   - Utilizes linked lists for dynamic management of processes.

---

## How to Run

1. Compile the code using a C compiler (e.g., `gcc`):
   ```bash
   gcc -o process_scheduler process_scheduler.c
   ```

2. Execute the compiled program:
   ```bash
   ./process_scheduler
   ```

3. Follow the on-screen prompts to:
   - Choose a scheduling algorithm.
   - Input the number of processes and their respective attributes.
   - View the results, including scheduling metrics and Gantt charts.

---

## Input Format

- **Process Attributes**:
  - **PID**: Process ID (auto-assigned).
  - **Arrival Time**: Time at which the process arrives.
  - **Execution Time**: Time required for the process to complete execution.

- **Quantum (for RR)**: Time slice allocated to each process in Round Robin scheduling.

---

## Output

1. **Process Table**:
   Displays the list of processes with their attributes: PID, arrival time, and execution time.

2. **Scheduling Metrics**:
   - **Turnaround Time (TAT)**: Total time from arrival to completion.
   - **Waiting Time (WT)**: Time spent waiting in the ready queue.

3. **Gantt Chart**:
   Visual representation of process execution.

---

## Functions Breakdown

### Core Functions
1. **Process Initialization**:
   - `process* init()` initializes a new process.
   - `process* Saisie_process()` collects user input for process attributes.

2. **Scheduling Algorithms**:
   - `FIFO_process(process* p)`: Implements FIFO scheduling.
   - `RR_process(process* p)`: Implements Round Robin scheduling with dynamic quantum adjustment.

3. **Metrics Calculation**:
   - Computes average TAT and WT for both algorithms.

4. **Visualization**:
   - `diag_grantt(process* p)`: Generates the Gantt chart.

### Utilities
- `tri_process(process* p)`: Sorts processes by arrival time.
- `copy_process(process* p)`: Creates a copy of the process list for Round Robin execution.
- `cleanup_processes(process* p)`: Frees memory allocated to the process list.
- `get_positive_int(const char* prompt)`: Ensures valid integer input from the user.

---

## Example Usage

### FIFO Example:
1. Select **1** from the main menu.
2. Enter process details (e.g., 3 processes with arrival times 0, 2, and 4, and execution times 5, 3, and 6).
3. View scheduling metrics and the Gantt chart.

### Round Robin Example:
1. Select **2** or **3** from the main menu.
2. Enter process details and a time quantum (e.g., 3 processes with a quantum of 2).
3. View scheduling metrics and the Gantt chart.

---

## Author

**Rahma Khlifi**

This program was developed as an educational tool for understanding process scheduling in operating systems.

---

## Notes

- The code includes error handling for invalid inputs.
- Gantt chart display and process visualization rely on console-based representations.
- Ensure the program is run in a terminal that supports ANSI escape codes for color output. 

---

## License

This project is open-source and free to use for educational purposes.