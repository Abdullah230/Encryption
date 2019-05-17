#include <iostream>
#include <fstream>
using namespace std;


//This makes a link list of characters
class charnode{
public:
	charnode *head, *n, *temp, *next;
	char data;
	//Simple insert function
	void insert(char data){
		if (head == NULL){
			n = new charnode;
			n->data = data;
			n->next = NULL;
			head = n;
			temp = head;
		}
		else if(head != NULL){
			n = new charnode;
			temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = n;
			n->data = data;
			n->next = NULL;
		}
	}
	//This gives the list size
	int listsize(){
		int i = 0;
		temp = head;
		while (temp->next != NULL){
			i++;
			temp = temp->next;
		}
		i++;
		return i;
	}
	//This prints the link list
	void printlinklist(){
		temp = head;
		while (temp->next != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
	//This deletes a node
	void deletenode(char data){
		temp = head;
		while (temp->next != NULL){
			if (head->data == data){
				head = head->next;
				delete temp;
				temp = head;
				break;
			}
			else if (temp->next->data == data){
				n = temp->next;
				temp->next = n->next;
				temp = head;
				delete n;
				break;
			}
			temp = temp->next;
		}
	}

	
};
//All of this is the same as above.
class intNode{
public:
	intNode *head, *n, *temp;
	int data;
	intNode *next;

	void insert(int data){
		if (head == NULL){
			n = new intNode;
			n->data = data;
			n->next = NULL;
			head = n;
			temp = head;
		}
		else if(head != NULL){
			n = new intNode;
			temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = n;
			n->data = data;
			n->next = NULL;
		}

	}

	int linklistsize(){
		int i = 0;
		temp = head;
		while (temp->next != NULL){
			i++;
			temp = temp->next;
		}
		i++;
		return i;
	}
	
	void printlinklist(){
		temp = head;
		while (temp->next != NULL){
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}

	void deletenode(int data){
		temp = head;
		while (temp->next != NULL){
			if (head->data == data){
				head = head->next;
				delete temp;
				temp = head;
				break;
			}
			else if (temp->next->data == data){
				n = temp->next;
				temp->next = n->next;
				temp = head;
				delete n;
				break;
			}
			temp = temp->next;
		}
	}
};


class Encrypter{
public:
	void takeinput(charnode *characternode){ //We pass an object link list to the function in which we want to take the input.
		cout << "Please enter the password: ";
		char temporary;
		//We can not use cin for this purpose, getchar takes only one character and that is what we need.
		temporary = getchar();
		while (temporary != 10){ // 10 is the enter key.
			characternode->insert(temporary);
			temporary = getchar();
		}
		cin.clear();
	
	}
	//This is for testing purposes and will not be included in the final program.
	//This can be used to confirm if we are taking the right input.
	void printchar(charnode *characternode){
			characternode->printlinklist();
		}


	//Makes a linked list which has the ascii values of all the characters which were entered


	void keymaker1(intNode *key1, charnode *characternode){  
		characternode->temp = characternode->head;
		int a;
		charnode *d, *f;
		d = characternode->temp; //We put d equal to temp because characternode->temp->next creates access violations
		while (d->next != NULL){
			a = d->data; //The value is automatically converted into it's ascii value because a is an int.
			key1->insert(a);
			d = d->next;
		}
		key1->insert(d->data); //For last node
	}
	//Again only for testing purposes;
	void keymaker1print(intNode *keymaker1){
		keymaker1->printlinklist();
	}
	
	
	// The following function segments ascii values into single digits and stores them in a seperate linklist for easy access


	void keysegmenter(intNode *key1, intNode *segementedkey){
		intNode *t;
		key1->temp = key1->head;
		t = key1->temp;
		int a, b;
		while (t->next != NULL){
			a = t->data;
			if (a / 100 == 0){ //For 2 digit numbers
				b = a / 10;
				segementedkey->insert(b);
				b = a % 10;
				segementedkey->insert(b);
			}
			else if (a / 100 != 0){ //For 3 digit numbers
				b = a / 100;
				segementedkey->insert(b);
				b = (a / 10) % 10;
				segementedkey->insert(b);
				b = a % 10;
				segementedkey->insert(b);
			}
			t = t->next;
		}
		//For last node, same as above
		a = t->data;
			if (a / 100 == 0){
				b = a / 10;
				segementedkey->insert(b);
				b = a % 10;
				segementedkey->insert(b);
			}
			else if (a / 100 != 0){
				b = a / 100;
				segementedkey->insert(b);
				b = (a / 10) % 10;
				segementedkey->insert(b);
				b = a % 10;
				segementedkey->insert(b);		
	}

	}
	//For testing segmented key;
	void segkeyprint(intNode *segkeytoprint){
		segkeytoprint->printlinklist();
	}
	
	void finalkeymaker(intNode *finalkey, intNode *key2){ //This makes the final key that we need to encrypt the text file, converts a single digit into two;
		key2->temp = key2->head;
		intNode *t;
		t = key2->temp;
		while (t->next != NULL){
			if (t->data == 0){
				finalkey->insert(1);
				finalkey->insert(1);
			}
			else if(t->data == 1){
				finalkey->insert(1);
				finalkey->insert(2);
			}
			else if(t->data == 2){
				finalkey->insert(1);
				finalkey->insert(3);
			}
			else if(t->data == 3){
				finalkey->insert(1);
				finalkey->insert(4);
			}
			else if(t->data == 4){
				finalkey->insert(2);
				finalkey->insert(1);
			}
			else if(t->data == 5){
				finalkey->insert(2);
				finalkey->insert(2);
			}
			else if(t->data == 6){
				finalkey->insert(2);
				finalkey->insert(3);
			}
			else if(t->data == 7){
				finalkey->insert(2);
				finalkey->insert(4);
			}
			else if(t->data == 8){
				finalkey->insert(3);
				finalkey->insert(1);
			}
			else if(t->data == 9){
				finalkey->insert(3);
				finalkey->insert(2);
			}
			t = t->next;

		}
		//For the last Node;
		if (t->data == 0){
				finalkey->insert(1);
				finalkey->insert(1);
			}
			else if(t->data == 1){
				finalkey->insert(1);
				finalkey->insert(2);
			}
			else if(t->data == 2){
				finalkey->insert(1);
				finalkey->insert(3);
			}
			else if(t->data == 3){
				finalkey->insert(1);
				finalkey->insert(4);
			}
			else if(t->data == 4){
				finalkey->insert(2);
				finalkey->insert(1);
			}
			else if(t->data == 5){
				finalkey->insert(2);
				finalkey->insert(2);
			}
			else if(t->data == 6){
				finalkey->insert(2);
				finalkey->insert(3);
			}
			else if(t->data == 7){
				finalkey->insert(2);
				finalkey->insert(4);
			}
			else if(t->data == 8){
				finalkey->insert(3);
				finalkey->insert(1);
			}
			else if(t->data == 9){
				finalkey->insert(3);
				finalkey->insert(2);
			}
	}
	//For testing purposes
	void finalkeyprinter(intNode *fkey){
		fkey->printlinklist();
	}
	//Encrypts the file according to the key;
	void filechanger(intNode *finalkey){
		char ch;
		fstream in("file.txt", fstream::in); //Takes the file
		fstream out("encrypt.txt", fstream::out);//Crates a file to write a program;
		int ch1;
		finalkey->temp = finalkey->head;
		intNode *t;
		t = finalkey->temp;
		while(in >> noskipws >> ch){ //This reads every character. The "noskipws" means do not skip white spaces, means that is reads spaces and tabs too;
		if (ch == '\n'){ //Replaces endline character with space;
			ch = ' ';
		}
		ch1 = ch;
		ch1 += t->data; //Increments the ascii value according to the key
		ch = ch1;
		out << ch;
		if (t->next == NULL){
			t = finalkey->head;
		}

		else t = t->next;
		
		}

	}
	//Decrypts the file according to the key;
	//This does the same thing, the only difference is that this decrements the ascii value according to the key.
	void filechanger1(intNode *finalkey){
		char ch;
		fstream in("encrypt.txt", fstream::in);
		fstream out("decrypt.txt", fstream::out);
		int ch1;
		finalkey->temp = finalkey->head;
		intNode *t;
		t = finalkey->temp;
		while(in >> noskipws >> ch){
		if (ch == '\n'){
			ch = ' ';
		}
		ch1 = ch;
		ch1 -= t->data;
		ch = ch1;
		out << ch;
		if (t->next == NULL){
			t = finalkey->head;
		}

		else t = t->next;
		
		}

	}
};
/*
Uncomment 
//s.filechanger(&finalkey);
to encrypt file.


Uncomment
//s.filechanger1(&finalkey);
to decrypt file.


Create a .txt document named file which will have the text that you want to encrypt;
Without this file the program will not work;
*/
void main(){
	Encrypter s;
	intNode key1;
	intNode key2;
	intNode finalkey;
	charnode wordnode;
	wordnode.head = NULL;
	key1.head = NULL;
	key2.head = NULL;
	finalkey.head = NULL;
	s.takeinput(&wordnode);
	//s.printchar(&wordnode);
	s.keymaker1(&key1, &wordnode);
	//s.keymaker1print(&key1);
	s.keysegmenter(&key1, &key2);
	//s.segkeyprint(&key2);
	s.finalkeymaker(&finalkey, &key2);
	//s.finalkeyprinter(&finalkey);
	//s.filechanger(&finalkey);
	//s.filechanger1(&finalkey);
	
	system("PAUSE");
}
