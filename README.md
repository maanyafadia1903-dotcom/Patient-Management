# Priority-Based Hospital Management System

A high-performance C++ implementation of a Hospital Patient Management System utilizing specialized Data Structures and Algorithms[cite: 5]. This system efficiently manages patient admissions, bed allocations, and waiting room transitions using a custom **Linked List** and **Merge Sort** architecture[cite: 5].

---

## 🏥 Key Features

*   **Smart Admission System**: Automatically manages a fixed bed capacity (5 beds) and seamlessly redirects overflow patients to a priority-based waiting room[cite: 5].
*   **Dual-Tier Management**: Maintains separate data structures for currently admitted patients and those in the waiting room queue[cite: 5].
*   **Priority Sorting**: Implements an optimized **Merge Sort** algorithm ($O(n \log n)$ complexity) to organize patients based on medical urgency (priority levels)[cite: 5].
*   **Patient Lifecycle Workflow**: 
    *   **Admission**: Records patient ID, name, age, and priority[cite: 5].
    *   **Attendance/Discharge**: When a doctor attends to a patient, they are discharged, and the first person in the waiting room is automatically moved to the vacated bed[cite: 5].
    *   **Search**: Real-time lookup for patients across both admitted and waiting lists[cite: 5].

---

## 💻 Technical Implementation

The project is built using Object-Oriented Programming (OOP) principles in C++[cite: 5]:

*   **`Node` Structure**: A custom structure storing patient data and pointers for linked list navigation[cite: 5].
*   **`LinkedList` Class**: Encapsulates the core logic, including:
    *   `mergeSortLogic()`: Recursive sorting for linked lists[cite: 5].
    *   `attend_patient()`: Logic for discharging and queue-to-bed migration[cite: 5].
    *   `add_patients()`: Capacity-aware admission logic[cite: 5].

---

## 📂 Project Structure

```text
└── hospital_management.cpp    # Main source code containing Node and LinkedList definitions
```

---

## 🚀 Getting Started

### Prerequisites
*   A C++ compiler (GCC, Clang, or MSVC).

### Compilation and Execution
To compile the system, run the following command in your terminal:

```bash
g++ hospital_management.cpp -o hospital_system
```

To run the application:

```bash
./hospital_system
```

---

## 📊 Sample Workflow Execution

The current `main()` function demonstrates the following automated workflow[cite: 5]:
1.  **Admits 5 Patients**: Fills the hospital to capacity[cite: 5].
2.  **Queue Management**: Sends a 6th patient (Shivam) to the waiting room[cite: 5].
3.  **Sort Logic**: Reorganizes all patients based on their medical priority[cite: 5].
4.  **Resource Reallocation**: Discharges a patient and automatically pulls the next patient from the queue into the available bed[cite: 5].
