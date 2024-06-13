#include <iostream>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float GPA;
};

class StudentRecordSystem {
public:
    Student *students;
    int capacity;
    int size;

public:
    // Constructor
    StudentRecordSystem(int maxCapacity) {
        capacity = maxCapacity;
        students = new Student[capacity];
        size = 0;
    }

    // Destructor
    ~StudentRecordSystem() {
        delete[] students;
    }

    // Enqueue a new student record
    void enqueue(Student newStudent) {
        if (size >= capacity) {
            cout << "Record system is full. Cannot add more students." << endl;
            return;
        }
        students[size++] = newStudent;
        cout << "Student added successfully." << endl;
    }

    // Dequeue a student record
    void dequeue() {
        if (size == 0) {
            cout << "No students in the record." << endl;
            return;
        }
        cout << "Dequeued student:" << endl;
        cout << "Name: " << students[0].name << endl;
        cout << "Roll Number: " << students[0].rollNumber << endl;
        cout << "GPA: " << students[0].GPA << endl;
        // Shift elements to the left to remove the dequeued student
        for (int i = 0; i < size - 1; ++i) {
            students[i] = students[i + 1];
        }
        size--;
    }

    // Peek at the front student record
    void peek() {
        if (size == 0) {
            cout << "No students in the record." << endl;
            return;
        }
        cout << "Front student record:" << endl;
        cout << "Name: " << students[0].name << endl;
        cout << "Roll Number: " << students[0].rollNumber << endl;
        cout << "GPA: " << students[0].GPA << endl;
    }

    // Print all student records
    void print() {
        if (size == 0) {
            cout << "No students in the record." << endl;
            return;
        }
        cout << "Printing all student records:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Student " << i + 1 << ":" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "GPA: " << students[i].GPA << endl << endl;
        }
    }

    // Bubble sort on student records by GPA
    void bubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (students[j].GPA > students[j + 1].GPA) {
                    // Swap students
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        cout << "Student records sorted by GPA using Bubble Sort." << endl;
    }

    // Insertion sort on student records by GPA
    void insertionSort() {
        for (int i = 1; i < size; ++i) {
            Student key = students[i];
            int j = i - 1;
            while (j >= 0 && students[j].GPA > key.GPA) {
                students[j + 1] = students[j];
                j = j - 1;
            }
            students[j + 1] = key;
        }
        cout << "Student records sorted by GPA using Insertion Sort." << endl;
    }

    // Selection sort on student records by GPA
    void selectionSort() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (students[j].GPA < students[minIndex].GPA) {
                    minIndex = j;
                }
            }
            // Swap students
            Student temp = students[minIndex];
            students[minIndex] = students[i];
            students[i] = temp;
        }
        cout << "Student records sorted by GPA using Selection Sort." << endl;
    }

    // Quick sort on student records by GPA
    void quickSort(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);
            quickSort(low, pivotIndex - 1);
            quickSort(pivotIndex + 1, high);
        }
        cout << "Student records sorted by GPA using Quick Sort." << endl;
    }

private:
    int partition(int low, int high) {
        float pivot = students[high].GPA;
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) {
            if (students[j].GPA < pivot) {
                ++i;
                // Swap students
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
        // Swap students
        Student temp = students[i + 1];
        students[i + 1] = students[high];
        students[high] = temp;
        return i + 1;
    }
};

int main() {
    StudentRecordSystem recordSystem(3);
    int choice;

    do {
        cout << "\nStudent Record Management System" << endl;
        cout << "1. Enqueue Student Record" << endl;
        cout << "2. Dequeue Student Record" << endl;
        cout << "3. Peek at Front Student Record" << endl;
        cout << "4. Print All Student Records" << endl;
        cout << "5. Sort Student Records by GPA (Bubble Sort)" << endl;
        cout << "6. Sort Student Records by GPA (Insertion Sort)" << endl;
        cout << "7. Sort Student Records by GPA (Selection Sort)" << endl;
        cout << "8. Sort Student Records by GPA (Quick Sort)" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent;
                cout << "Enter student name: ";
                cin >> newStudent.name;
                cout << "Enter student roll number: ";
                cin >> newStudent.rollNumber;
                cout << "Enter student GPA: ";
                cin >> newStudent.GPA;
                recordSystem.enqueue(newStudent);
                break;
            }
            case 2:
                recordSystem.dequeue();
                break;
            case 3:
                recordSystem.peek();
                break;
            case 4:
                recordSystem.print();
                break;
            case 5:
                recordSystem.bubbleSort();
                break;
            case 6:
                recordSystem.insertionSort();
                break;
            case 7:
                recordSystem.selectionSort();
                break;
            case 8:
                recordSystem.quickSort(0, recordSystem.size - 1);
                break;
            case 9:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}


