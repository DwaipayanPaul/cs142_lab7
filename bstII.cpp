// binary tree

#include<iostream>
using namespace std;

//node class

class node{
	public:
		int data;
		node * left;
		node* right;
		node* parent;
		
		//constructor
		node(int val){
			data=val;
			left=NULL;
			right=NULL;
			parent=NULL;
		}
		
		
};

class Bist{
	public:
		node* root;
	
		
		Bist(){
			root=NULL;
			
		}
		
		void insert(int value){
			insertHelper(root,value);
		}
		void insertHelper(node* curr, int value){
			// case if curr is nULL
			if(curr==NULL){
				curr=new node(value);
				if(root==NULL){
					root=curr;
					
				}
				return;
			}
			//else compare the curr data wth value
			else if(curr->data>value){
				//curr=curr->left;
				if(curr->left==NULL){
				  	curr->left=new node(value);
					curr->left->parent=curr;				
			}
				else
					insertHelper(curr->left,value);
			}
			else{
				//curr=curr->right;
				if(curr->right==NULL){
					
					curr->right=new node(value);
					curr->right->parent=curr;
				}
				else
				insertHelper(curr->right,value);
			}
				
			}
			
			node* search(int value){
			return search2(root, value);
		}
			node* search2(node* curr,int value){
				
			if(curr==NULL || curr->data==value) return curr;
			else if(value<curr->data) return search(value);
			else return search(value);
		}		
			
			
			
			//find minimum
			node * find_min(node * t){
				
				//invalid
				if(t==NULL){
					
					cout<<"INVALID !!"<<endl;
					return NULL;
				}
				while(t->left != NULL){
					t = t->left;
				}
				return t;
			}
			
    	void replace_with_parent(node *curr, node * temp){
		
		
			node * par=curr->parent;
			if(par->left==curr){
				par->left=temp;
				temp->parent=par;
				delete curr;
			}
			else {
				par->right=temp;
				temp->parent=par;
				delete curr;
		}
	}
		
		//delete
		void deletenode(int value){
			node * d=search(value);
			deletenode2(d);
			
			
		}
			void deletenode2(node * del){
			
			//if no son
			if ((del->left==NULL) && (del->right==NULL)){
				node * par=del->parent;
				if(par->left== del){
					par->left=NULL;
					delete del;
				}
				else{
					par->right=NULL;
					delete del;
				}
			
			}
		//	replace_with_parent(d,NULL);
			//replace with null
		//	}
			//if one son//
			//if(left exists
			else if(del->left==NULL || del->right ==NULL){
				if(del->left != NULL){
					replace_with_parent(del,del->left );
				//	delete d;	
				}
				else{
					replace_with_parent(del,del->right);
				//	delete d;	
				}
			}
			else{
				node * f=find_min(del->right);
				del->data= f->data;
				deletenode2(f);
			}
			//value replace crr with curr->left
			//delete temp//
			//for both kids
		}	
			
			
			
			//display
			
			void display(){
				display2(root);
			}
		void display2(node* curr){
			if(curr==NULL)
			return;
			display2(curr->left);
			cout<<curr->data<<",";
			display2(curr->right);			
			}
		
		// search
	

		
	
	  //  height(){	}
};

// main function

int main(){
	Bist l;
	l.insert(10);
	l.insert(6);
	l.insert(13);
	l.insert(7);
	l.insert(8);
	l.display();
	l.deletenode(13);
	l.display();
	
	
}



