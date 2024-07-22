#include <iostream>
using namespace std;




class DoublyNode {
public:
	int deger;
	DoublyNode* ptrNext;
	DoublyNode* ptrPrev;

	DoublyNode(int deger) {
		this->deger = deger;
		ptrNext = NULL;
		ptrPrev = NULL;
	}
};


class DoublyLinkedList {

private:
	DoublyNode* ptrHead;
	DoublyNode* ptrTail;
	int lengthDLL;

public:
	DoublyLinkedList(int deger) {
		DoublyNode* node = new DoublyNode(deger);
		ptrHead = node;
		ptrTail = node;
		lengthDLL = 1;
	}
	~DoublyLinkedList() {
		cout << "destructor çaðrýldý" << endl;
		DoublyNode* ptrTmp = ptrHead; 
		while (ptrHead) { 
			ptrHead = ptrHead->ptrNext; 
			delete ptrTmp; 
			ptrTmp = ptrHead; 
		}
	}

	void printAll() {
		DoublyNode* ptrTmp = ptrHead;
		cout << "DoublyLinkedList düðümleri: ";
		while (ptrTmp != NULL) {
			if (ptrTmp->ptrNext != NULL) {
				cout << ptrTmp->deger << ", ";
			}
			else {
				cout << ptrTmp->deger;
			}

			ptrTmp = ptrTmp->ptrNext;
		}
		cout << endl;
	}

	void printHead() {
		if (ptrHead != NULL) cout << "Head: " << ptrHead->deger << endl;
	}
	void printTail() {
		if (ptrTail != NULL) cout << "Tail: " << ptrTail->deger << endl;
	}
	void getlengthLL() {
		cout << "Length of DoublyLinkedList: " << this->lengthDLL << endl;
	}

	void appendList(int deger) {
		DoublyNode* node = new DoublyNode(deger);

		if (lengthDLL == 0) {
			ptrHead = node;
			ptrTail = node; 
		}
		else {
			ptrTail->ptrNext = node; 
			node->ptrPrev = ptrTail;
			ptrTail = node;
		}
		lengthDLL++;
	}

	void deleteLastNode() {
		if (lengthDLL == 0) return;
		

		if(lengthDLL != 1){

			DoublyNode* temp = ptrTail;
			ptrTail = ptrTail->ptrPrev;
			ptrTail->ptrNext = NULL;

			delete temp;
			

		}else if(lengthDLL == 1){
			
			ptrHead = NULL;
			ptrTail = NULL; 

		}

		lengthDLL--;

	}

	void addFirst(int deger) {
		DoublyNode* node = new DoublyNode(deger);

		if (lengthDLL == 0) { 
			ptrHead = node; 
			ptrTail = node; 
		}
		else {
			node->ptrNext = ptrHead;
			ptrHead->ptrPrev = node; 
			ptrHead = node;  
		}
		lengthDLL++;
	}


	void deleteFirstNode() {
		if (lengthDLL == 0) return;

		DoublyNode* temp = ptrHead;
		if (lengthDLL == 1) {
			ptrHead = NULL;
			ptrTail = NULL;
		}
		else {
			ptrHead = ptrHead->ptrNext;
			ptrHead->ptrPrev = NULL;
		}
		delete temp;
		lengthDLL--;
	}

	DoublyNode* getNode(int index) {
		if (index < 0 || index >= lengthDLL) return NULL;//index yoksa null atar.

		DoublyNode* temp;
		if(index<=lengthDLL/2){
			temp = ptrHead;
			for (int i = 0; i < index; i++) {
				temp = temp->ptrNext;//düðüme index verdik. index deðerini girince o düðümün deðeri bize dönecek.
			}
			return temp;
		}
		else {
			temp = ptrTail; 
			for (int i = lengthDLL-1; i >index ; i--) { 
				temp = temp->ptrPrev;//düðüme index verdik. index deðerini girince o düðümün deðeri bize dönecek.
			}
			return temp;
		}
		
		
	}


	bool setNode(int index, int newValue) {
		DoublyNode* temp = getNode(index);
		if (temp != NULL) { temp->deger = newValue; return true; }

		return false;

	}

	bool insertNode(int index, int value) {
		if (index<0 || index>lengthDLL) {
			return false;
		}
		else if (index == 0) {
			addFirst(value);
			return true;
		}
		else if (index == lengthDLL) {
			appendList(value);
			return true;
		}
		else {
			DoublyNode* newNode = new DoublyNode(value);
			DoublyNode* leftOfNode = getNode(index - 1);
			DoublyNode* rightOfNode = getNode(index);
			
			newNode->ptrNext = rightOfNode;
			newNode->ptrPrev = leftOfNode;
			leftOfNode->ptrNext = newNode;
			rightOfNode->ptrPrev = newNode;

			lengthDLL++;  
			return true; 
		}
	}


	void deleteAnyNode(int index) {
		if (index >= 0 && index < lengthDLL) {
			if (index == 0) {
				deleteFirstNode();
			}
			else if (index == lengthDLL - 1) {
				deleteLastNode();
			}
			else {
				DoublyNode* ptrDel = getNode(index);
				
				ptrDel->ptrNext->ptrPrev = ptrDel->ptrPrev;
				ptrDel->ptrPrev->ptrNext = ptrDel->ptrNext;

				delete ptrDel;

				lengthDLL--;

			}
		}
		else {
			cout << "Index deðeri kapasite dýþý." << endl;
		}
	}

};


int main() {
	setlocale(LC_ALL, "Turkish");
	DoublyLinkedList* dList1 = new DoublyLinkedList(51); 
	

	dList1->getlengthLL(); 
	dList1->printHead(); 
	dList1->printTail();  
	dList1->printAll(); 
	dList1->appendList(48);  
	dList1->appendList(19);  
	dList1->appendList(4);  
	dList1->appendList(23); 
	dList1->appendList(5143);
	dList1->appendList(3);
	dList1->appendList(454);
	dList1->appendList(45422);
	dList1->appendList(233);
	dList1->printAll();  
	dList1->deleteLastNode(); 
	dList1->printAll(); 
	dList1->addFirst(87);
	dList1->printAll();  
	dList1->deleteFirstNode();  
	dList1->printAll(); 

	cout << dList1->getNode(5)->deger << endl;
	
	dList1->setNode(2, 144);
	dList1->printAll(); 

	dList1->insertNode(4, 8157); 
	dList1->printAll(); 

	dList1->deleteAnyNode(7);
	dList1->printAll();

	cout << endl;
	delete dList1;  
}