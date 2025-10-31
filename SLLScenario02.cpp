
// Question 1: You are tasked to implement the reading list feature for an online book platform. 
// Users can add books they plan to read, remove books they finished or no longer want, and search 
// for books in their list.

// •	Implement a Singly Linked List where each node stores a book's ID and title.
// •	Write functions to:

// •	Add a book at the head of the list (addBookAtHead).
// •	Add a book at the tail of the list (addBookAtTail).
// •	Remove a book by its ID (removeBookById).
// •	Search for a book by ID (searchBookById) and return the book’s title or indicate not found.
// •	Print the entire reading list in order (printReadingList).


#include <iostream>
#include <string>
using namespace std;
struct Node{
    public:
       int id;
       string title;
       Node* next;

       // constructor
       Node(int id, string title){
           this -> id = id;
           this -> title = title;
           this -> next = NULL;

       }
           // destructor

           ~Node(){
           cout << "Memory is freed for node with ID: " << id 
             << " and title: " << title << endl;
            next = NULL;
           }
};



class Book{
    private:
       Node* head;
       Node* tail;

    public:
      Book(){
        head=NULL;
        tail=NULL;
      }   



// ---------------------------------------------------------------------------------------------------------------


      // Add Book At The Head
      void addBookAtHead(int id, string title){
         Node* newNode = new Node(id,title);

           if(head==NULL){
            Node* temp = new Node(id,title);
            head=temp;
            tail=temp;
            return;
           }

          
           newNode -> next = head;
           head=newNode;
      }


    //   ----------------------------------------------------------------------------------------------------------

       // Add Book At The Tail
        void addBookAtTail(int id, string title){
        Node* newNode = new Node(id, title);
        if(head == NULL){
            Node* temp=new Node(id,title);
              head=temp;
              tail=temp;
              return;
        }

        tail -> next = newNode;
        tail = newNode;

      }


// -----------------------------------------------------------------------------------------------------------------

      // Remove Book By Id
      void removeBookById(int id){

        // empty List 

          if(head == NULL){
            cout<<" Reading List is empty " << endl;
            return;
          }

          // Delete from head

           Node*temp=head;
          if(head -> id == id){
            head=head->next;
            temp -> next = NULL;
            delete temp;
            if(head==NULL){
                tail=NULL;
            }
            cout<<"Book with id "<< id <<"removed "<< endl;
            return;
          }

         // Case 3: Delete middle or last node

         Node* prev = head;
         Node* curr = head -> next;

         while(curr != NULL && curr->id != id){
             prev=curr;
             curr=curr->next;
         }

         if(curr == NULL){
            cout << "Book with ID " << id << " not found." << endl;
            return;
         }

         prev -> next = curr -> next;

         // if last node was deleted, update tail

         if( curr == tail){
            tail = prev;
         }
         delete curr;

         cout << "Book with ID " << id << " removed successfully." << endl;


      }

// ----------------------------------------------------------------------------------------------------------------

      // Search Book By Id
      string searchById(int key){
        Node* temp = head;
        while(temp != NULL){
            if(temp -> id == key){
                return temp->title;
            }
            temp = temp -> next;
        }
        return "Not Found";
      }

// ---------------------------------------------------------------------------------------------------------------

      // Print List
      void printReadingList(){
         Node* temp = head;
         while(temp != NULL){
            cout<< temp -> id <<"-"<< temp -> title<<endl;
            temp = temp -> next;
         }
         cout<<endl;
      }


    

};

// -----------------------------------------------------------------------------------------------------------------

int main(){
    Book book;
    // book.addBookAtHead(1, "A");
    // book.addBookAtHead(2, "B");
    // book.addBookAtHead(3, "C");
    
    // book.printReadingList();


    book.addBookAtTail(1, "A");
    book.addBookAtTail(2, "B");
    book.addBookAtTail(3, "C");
    book.addBookAtTail(4,"D");
    book.printReadingList();


    int key = 3;
string result = book.searchById(key);
if (result != "Not Found") {
    cout << "Book found with ID " << key << ": " << result << endl;
} else {
    cout << "Book not found with ID " << key << endl;
}


    // book.printReadingList();  


    // book.removeBookById(2);
    // book.printReadingList();

    book.removeBookById(3);
    book.printReadingList();

    return 0;
}