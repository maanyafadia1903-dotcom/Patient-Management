#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;           
    int priority;       
    string name;        
    int age;            
    Node* next;
};

class LinkedList {
    private:
        Node* head;         
        Node* queueHead;    
        Node* queueTail;    
        int bedCount;       

        Node* getMiddle(Node* headNode) {
            if (headNode == NULL || headNode->next == NULL) return headNode;
            Node* slow = headNode;
            Node* fast = headNode->next;
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node* merge(Node* left, Node* right) {
            if (left == NULL) return right;
            if (right == NULL) return left;
            Node* result = NULL;
            if (left->priority <= right->priority) {
                result = left;
                result->next = merge(left->next, right);
            } else {
                result = right;
                result->next = merge(left, right->next);
            }
            return result;
        }

        Node* mergeSortLogic(Node* headNode) {
            if (headNode == NULL || headNode->next == NULL) return headNode;
            Node* middle = getMiddle(headNode);
            Node* nextToMiddle = middle->next;
            middle->next = NULL;
            Node* left = mergeSortLogic(headNode);
            Node* right = mergeSortLogic(nextToMiddle);
            return merge(left, right);
        }

    public:
        LinkedList() {
            head = NULL;
            queueHead = NULL;
            queueTail = NULL;
            bedCount = 0; 
        }

        void add_patients(int patient_id, int priority, string name, int age) {
            if(bedCount < 5) {
                Node *newNode = new Node{patient_id, priority, name, age, NULL};
                if (head == NULL) {
                    head  = newNode;
                } else {
                    Node* curr = head;
                    while(curr->next != NULL) curr = curr->next;
                    curr->next = newNode;
                }
                bedCount++;
                cout << "Admitted " << name << " to a bed." << endl;
            } else {
                cout << "Hospital full! Sending " << name << " to waiting room." << endl;
                add_in_queue(patient_id, priority, name, age);
            }
        }

        void add_in_queue(int patient_id, int priority, string name, int age) {
            Node *newNode = new Node{patient_id, priority, name, age, NULL};
            if (queueHead == NULL) {
                queueHead = queueTail = newNode;
                return;
            }
            queueTail->next = newNode;
            queueTail = newNode;
        }

        void attend_patient() {
            if (head == NULL) {
                cout << "No patients are currently in beds." << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            cout << "\nDoctor attended to: " << temp->name << ". Discharged." << endl;
            delete temp; 
            bedCount--; 

            if (queueHead != NULL) {
                Node* movingNode = queueHead;
                queueHead = queueHead->next; 
                if (queueHead == NULL) queueTail = NULL;
                
                movingNode->next = NULL;
                if (head == NULL) {
                    head = movingNode;
                } else {
                    Node* curr = head;
                    while(curr->next != NULL) curr = curr->next;
                    curr->next = movingNode;
                }
                bedCount++;
                cout << "Moving " << movingNode->name << " from waiting room to bed." << endl;
            }
        }

        void sort_priority() {
            if (head != NULL) head = mergeSortLogic(head);
            if (queueHead != NULL) {
                queueHead = mergeSortLogic(queueHead);
                Node* curr = queueHead;
                while (curr != NULL && curr->next != NULL) curr = curr->next;
                queueTail = curr;
            }
            cout << "\nSystems sorted by priority." << endl;
        }

        void display_patients() {
            cout << "\n--- ADMITTED PATIENTS (" << bedCount << "/5) ---" << endl;
            Node* curr = head;
            while(curr != NULL) {
                cout << "ID: " << curr->data << " | Name: " << curr->name << " | Priority: " << curr->priority << endl;
                curr = curr->next;
            }
            cout << "\n--- WAITING ROOM ---" << endl;
            curr = queueHead;
            while(curr != NULL) {
                cout << "ID: " << curr->data << " | Name: " << curr->name << " | Priority: " << curr->priority << endl;
                curr = curr->next;
            }
        }

        void searching_patients(int patient_id) {
            Node* curr = head;
            while(curr != NULL) {
                if(curr->data == patient_id) {
                    cout << "\nFound in Bed: " << curr->name << endl;
                    return;
                }
                curr = curr->next;
            }
            curr = queueHead;
            while(curr != NULL) {
                if(curr->data == patient_id) {
                    cout << "\nFound in Queue: " << curr->name << endl;
                    return;
                }
                curr = curr->next;
            }
            cout << "\nPatient " << patient_id << " not found." << endl;
        }
};

int main() {
    LinkedList hospital;
    hospital.add_patients(101, 3, "Maanya", 17);
    hospital.add_patients(102, 1, "Preksha", 25);
    hospital.add_patients(103, 2, "Hetal", 51);
    hospital.add_patients(104, 1, "Pankil", 53);
    hospital.add_patients(105, 3, "Priyank", 18);
    hospital.add_patients(106, 3, "Shivam", 19);

    
    hospital.display_patients();
    hospital.sort_priority();
    hospital.display_patients();
    hospital.attend_patient();
    hospital.display_patients();
    
    return 0;
}