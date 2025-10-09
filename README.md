# CPU Scheduling Algorithms Simulator (with Gantt Chart Visualization) #

### **Project Overview**

This project simulates and visualizes **CPU Scheduling Algorithms** — fundamental concepts in Operating Systems that determine the order in which processes are executed.
It supports major scheduling algorithms including:

* **FCFS (First Come First Serve)**
* **SJF (Shortest Job First)**
* **Round Robin (RR)**
* **Priority Scheduling**

A **Gantt Chart** is also generated in the console for each algorithm, providing a clear visualization of how CPU time is distributed among processes.

---

## **Concepts Covered**

| Algorithm               | Type           | Description                                              |
| ----------------------- | -------------- | -------------------------------------------------------- |
| **FCFS**                | Non-preemptive | Executes processes in the order they arrive.             |
| **SJF**                 | Non-preemptive | Executes the process with the shortest burst time first. |
| **Round Robin**         | Preemptive     | Allocates equal time slices (quantum) cyclically.        |
| **Priority Scheduling** | Both           | Executes the highest-priority process first.             |

---

##  **Features**

Supports multiple scheduling algorithms
Displays **Process Table** (Arrival, Burst, Waiting, Turnaround times)
Generates a **Gantt Chart** in text format
Calculates:

* Average Waiting Time
* Average Turnaround Time
  Simple **Menu-based interface** for interaction

---

## **How to Run**

### 1. **Clone this repository**

```bash
git clone https://github.com/yourusername/CPU-Scheduling-Simulator.git
cd CPU-Scheduling-Simulator
```

### 2. **Compile the code**

```bash
gcc cpu_scheduling.c -o cpu_scheduling
```

### 3. **Run the executable**

```bash
./cpu_scheduling
```

---

## **Sample Output**

### Example (FCFS Algorithm)

```
Enter number of processes: 3
Enter Arrival Time and Burst Time:
P1: 0 5
P2: 1 3
P3: 2 8

Gantt Chart:
| P1 | P2 | P3 |
0    5    8   16

Process Table:
------------------------------------------------
Process | AT | BT | WT | TAT
P1      | 0  | 5  | 0  | 5
P2      | 1  | 3  | 4  | 7
P3      | 2  | 8  | 6  | 14
------------------------------------------------
Average Waiting Time: 3.33
Average Turnaround Time: 8.66
```

---

## **Gantt Chart Visualization Example**

```
| P1 | P2 | P3 |
0    5    8   16
```

You can visually interpret:

* Each bar represents a process being executed.
* The timeline shows start and completion times.

---

## **Learning Objectives**

* Understand the working of CPU Scheduling algorithms.
* Analyze CPU utilization and process performance.
* Visualize CPU scheduling using Gantt Charts.
* Develop strong OS fundamentals using C programming.

---

## **Code Structure**

```
CPU-Scheduling-Simulator/
│
├── cpu_scheduling.c      # Main simulation file
├── README.md             # Project documentation
```

## **References**

* Operating System Concepts – Silberschatz, Galvin, Gagne

* Modern Operating Systems – Andrew S. Tanenbaum

* TutorialsPoint / GeeksforGeeks – CPU Scheduling Algorithms

