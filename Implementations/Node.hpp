#include <iostream>
#include <stdlib.h>

using namespace std;

class Node{
	public:
		int info;
		Node* link;
		//Included Methods
		// insert -> inserts the element to the end of list
		// insertAtBeginning -> inserts element at the beginning of a list.
		// insertAtPosition -> inserts a element at given position
        

	
	public:
		
		Node(){
			this->info = 0;
			this->link = NULL;
		}

		//void traverse();
		
		void insert(int x){
			Node *p = new Node;
			p->info = x;
			p->link = NULL;
			   
			if(this->link==NULL) this->link = p;
		
			else{
				Node* temp = this->link;
				while(temp->link!=NULL){
					temp = temp->link;
				}
				temp->link = p;
			}
		}

		void insertAtBeginning(int x){
			Node *p = new Node;
			p->info=x;
			p->link = this->link;
			this->link = p;
		}

		void insert(int x,int pos){
			Node *p=new Node;
			p->info=x;
			
			Node *temp=this;
			for(int i=1;i<pos && temp->link!=NULL;i++){
				temp = temp->link;
			}
			p->link=temp->link;
			temp->link = p;
		}

        void deletion(){
            Node* temp = this->link;
            Node* tempBefore;
			while(temp->link != NULL){
				tempBefore = temp;
                temp = temp->link;
                if(temp->link==NULL) tempBefore->link=NULL;
			}
        }

		void deletionAtPosition(int pos){
			Node* temp=this;
			for(int i=1;i<pos;i++){
				temp = temp->link;
			}
			temp->link=temp->link->link;
		}
		
		
		void display(){
			Node* temp = this;
			while(temp->link != NULL){
				temp = temp->link;
				cout<<temp->info<<" ";
			}
			cout<<endl;
		}

        void linkList(Node& n){
            Node* temp = this->link;
			while(temp->link != NULL){
				temp = temp->link;
			}
			temp->link = n.link;
        }

        void deletion(int n){
            Node* temp = this->link;
            Node* tempBefore=this;
			
			while(temp->link != NULL){
				if(temp->info==n){
                    tempBefore->link = (temp->link);
					temp = temp->link;
					continue;
                }
                tempBefore = temp;
                temp = temp->link;
			}
			if(temp->info==n){
                tempBefore->link = (temp->link);
            }  
        }

		int popFirst(){
			int x = this->link->info;
			deletionAtBeginnig();
			return x;
		}

		void deletionAtBeginnig(){
			this->link = this->link->link;
		}

		void reverse(){
			Node* temp = this->link;
			Node* tempBefore=this;
			Node* tempAfter=temp->link;
			temp->link = NULL;
			do{
				tempBefore = temp;
				temp = tempAfter;
				tempAfter = tempAfter->link;
				temp->link = tempBefore;
			}while(tempAfter->link!=NULL);
			tempAfter->link = temp;
			this->link=tempAfter;
		}

		void insertSorted(int x){
			Node *p = new Node;
			p->info=x;
			int pos=1;
			if(this->link==NULL) this->link=p;
			else{
				Node* temp=this->link;
				Node* tempBefore;
				while(temp->link!=NULL && x>=temp->info){
					pos++;
					tempBefore = temp;
					temp = temp->link;
				}
				if(temp->link==NULL && temp->info<=x) pos++;
				insert(x,pos);
			}
		}
        Node* begin(){
            return this->link;
        }

        Node* end(){
            Node* temp=this->link;
            while(temp->link!=NULL){
                temp = temp->link;
            }
            return temp;
        }
};
