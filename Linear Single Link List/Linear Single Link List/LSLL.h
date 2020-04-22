#ifndef LSLL_H
#define LSLL_H
#include"Node.h"

template<typename T>
class LSLL
{
public:
	Node<T>*head;
	bool isPresent(T val)
	{
		Node<T>*p = head;
		while (p != nullptr)
		{
			if (p->info == val)
			{
				return true;
			}
			p = p->next;
		}
		return false;
	}
	bool isValidMandN(int M, int N)
	{
		Node<T>*p = head;
		int count = 0;
		while (p != nullptr)
		{
			count = count + 1;
			p = p->next;
		}
		if (count < M || count < N)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void swapNodes(Node<T>*M , Node<T>*N ) //Private Function to swap on basis of address
	{
		if (head == nullptr || head->next == nullptr || M==N)
		{
			return;
		}
		Node<T>*Ppre = nullptr, *Qpre = nullptr;
		Node<T>*p = head;
		Node<T>*q = head;
		while (p!=M || q!=N)
		{
			if (p!= M)
			{
				Ppre = p;
				p = p->next;
			}
			if (q!= N)
			{
				Qpre = q;
				q = q->next;
			}
		}
		Node<T>*temp = p->next;
		Node<T>*temp2 = q->next;
		(Ppre == nullptr) ? (head = q) : (Ppre->next = q);
		(p->next != q) ? (q->next = temp) : (q->next = Qpre);
		Qpre->next = p;
		p->next = temp2;
	}

	Node<T>*middle()   //private function to return middle node in O(N)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		Node<T>*p = head;
		Node<T>*q = head->next;
		while (q != nullptr)
		{
			q = q->next;
			if (q != nullptr)
			{
				q = q->next;
				p = p->next;
			}
			else
			{
				return p;
			}
		}
		return p;
	}

	void seperate() //private function to seperate white and black in O(N)
	{
		if (head == nullptr)
		{
			return;
		}
		LSLL<T>black;
		Node<T>*b;
		LSLL<T>white;
		Node<T>*w;
		Node<T>*p = head;
		while (p != nullptr)
		{
			if (p->info == 0)
			{
				if (black.head != nullptr)
				{
					b->next = p;
					p = p->next;
					b = b->next;
					b->next = nullptr;
				}
				else
				{
					black.head = p;
					p = p->next;
					b = black.head;
					b->next = nullptr;
				}
			}
			else if (p->info == 1)
			{
				if (white.head != nullptr)
				{
					w->next = p;
					p = p->next;
					w = w->next;
					w->next = nullptr;
				}
				else
				{
					white.head = p;
					p = p->next;
					w = white.head;
					w->next = nullptr;
				}
			}
		}
		head = black.head;
		if (head == nullptr)
		{
			head = white.head;
		}
		else
		{
			p = head;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = white.head;
		}
		black.head = nullptr;
		white.head = nullptr;
	}

	int countNodes()   //private function to count number of nodes
	{
		if (head == nullptr)
		{
			return 0;
		}
		int count = 0;
		Node<T>*p = head;
		while (p != nullptr)
		{
			count = count + 1;
			p = p->next;
		}
		return count;
	}

public:
	LSLL()
	{
		head = nullptr;
	}
	~LSLL()
	{
		while (head != nullptr)
		{
			removeAtHead();
		}
	}
	
	LSLL<T>(const LSLL<T>&ref)
	{
		if (ref.head == nullptr)
		{
			head = nullptr;
			return;
		}
		head = new Node<T>(ref.head->info);
		Node<T>*p = head;
		Node<T>*q = ref.head;
		while (q->next != nullptr)
		{
			p->next= new Node<T>(q->next->info);
			p = p->next;
			q = q->next;
		}
	}

	void removeLesserNodes()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}
		reverseList();
		Node<T>*p = head->next;
		Node<T>*pre = head;
		int max = head->info;
		while (p != nullptr)
		{
			if (p->info < max)
			{
				pre->next = p->next;
				delete p;
				p = pre->next;
			}
			else
			{
				max = p->info;
				pre = p;
				p = p->next;
			}
		}
		reverseList();
	}

	void lessThanGreaterThanArrange()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		bool less = true;
		while (p->next != nullptr)
		{
			if (less)
			{
				if (p->info > p->next->info)
				{
					swapNodes(p, p->next);
				}
				else
				{
					p = p->next;
				}
			}
			else
			{
				if (p->info < p->next->info)
				{
					swapNodes(p, p->next);
				}
				else
				{
					p = p->next;
				}
			}
			less = !less;
		}
	}

	void reArrange()
	{
		if (head == nullptr || head->next==nullptr || head->next->next==nullptr)
		{
			return;
		}

		Node<T>*pre = nullptr;  //Reverse The Second Half
		Node<T>*revStart = middle();
		Node<T>*mid = revStart->next;
		Node<T>*p = mid;
		while (p->next != nullptr)
		{
			revStart->next = p->next;
			p->next = pre;
			pre = p;
			p = revStart->next;
		}
		p->next = pre;
		
		p = head;    
		mid = middle();
		revStart = mid->next;
		while (revStart != nullptr && p!=mid)
		{
			Node<T>*temp = revStart->next;
			revStart->next = p->next;
			p->next = revStart;
			p = revStart->next;
			revStart = temp;
			mid->next = temp;
		}
	}

	T findMiddlePoint()   //private function to return middle node in O(N)
	{
		if (head == nullptr)
		{
			exit(0);
		}
		Node<T>*p = head;
		Node<T>*q = head->next;
		while (q != nullptr)
		{
			q = q->next;
			if (q != nullptr)
			{
				q = q->next;
				p = p->next;
			}
			else
			{
				return p->info;
			}
		}
		return p->info;
	}


	LSLL<T>doUnion(LSLL<T>&list2)
	{
		LSLL<T>result;
		Node<T>*p = this->head;
		while (p != nullptr)
		{
			result.insertAtHead(p->info);
			p = p->next;
		}
		p = list2.head;
		while (p != nullptr)
		{
			if (!isPresent(p->info))
			{
				result.insertAtHead(p->info);
			}
			p = p->next;
		}
		return result;
	}

	int isEqual(LSLL<T>&list2)
	{
		Node<T>*p = head;
		Node<T>*q = list2.head;
		while (p != nullptr)
		{
			if (!list2.isPresent(p->info))
			{
				return false;
			}
			p = p->next;
			q = q->next;
		}
		if (q == nullptr)
		{
			return true;
	    }
		else
		{
			return false;
		}
	}

	LSLL<T> createClone()
	{
		return *this;
	}

	void delAlternate()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		while (p->next != nullptr)
		{
			Node<T>*temp = p->next;
			p->next = p->next->next;
			delete temp;
			p = p->next;
		}	
	}
	
	int findMajorityColor()
	{
		LSLL<int>black;
		LSLL<int>white;
		Node<T>*p = head;
		while (p != nullptr)
		{
			if (p->info == "black")
			{
				black.insertAtHead(0);
			}
			else
			{
				white.insertAtHead(1);
			}
			p = p->next;
		}
		Node<int>*ptrBlack = black.head;
		Node<int>*ptrWhite = white.head;
		while (ptrBlack != nullptr && ptrWhite != nullptr)
		{
			ptrBlack = ptrBlack->next;
			ptrWhite = ptrWhite->next;
		}
		if (ptrBlack == nullptr && ptrWhite == nullptr)
		{
			return 2;
		}
		else if (ptrBlack != nullptr)
		{
			return 0;
		}
		else
		{
			return 1;
		}
		//seperate();
		//LSLL<T>black;
		//LSLL<T>white;
		//Node<T>*blackLast=nullptr;
		//Node<T>*p = head;
		//bool foundWhite = false;
		//while (p != nullptr && !foundWhite)
		//{
		//	if (p->info==1)
		//	{
		//		foundWhite = true;
		//		white.head = p;
		//	}
		//	else
		//	{
		//		blackLast = p;
		//		p = p->next;
		//	}
		//}
		//blackLast->next = nullptr;
		//black.display();
		//cout << "\n";
		//white.display();
		//Node<T>*ptrBlack = black.head;
		//Node<T>*ptrWhite = white.head;
		//while (ptrBlack != nullptr && ptrWhite != nullptr)
		//{
		//	ptrBlack = ptrBlack->next;
		//	ptrWhite = ptrWhite->next;
		//}
		//if (ptrBlack == nullptr && ptrWhite==nullptr)
		//{
		//	return 2;
		//}
		//else if (ptrBlack == nullptr)
		//{
		//	return 1;
		//}
		//else
		//{
		//	return 0;
		//}
		///*if (middle()->info == "black")
		//{
		//	return "black";
		//}
		//else
		//{
		//	return "white";
		//}*/
	}

	bool isJoining(LSLL<T>&list2)
	{
		if (head == nullptr || list2.head == nullptr)
		{
			return false;
		}
		Node<T>*p=head;
		Node<T>*q=list2.head;
		int count1 = countNodes();
		int count2 = list2.countNodes();
		int diff = abs(count1 - count2),temp=0;
		while (temp != diff)
		{
			(count1 >= count2) ? (p = p->next) : (q = q->next);
			temp = temp + 1;
		}
		while (p != nullptr && q != nullptr && q != p)
		{
			p = p->next;
			q = q->next;
	    }
		if (p == q && p!=nullptr && q!=nullptr)
		{
			return true;
	    }
		else
		{
			return false;
		}
	}

	int joiningPoint(LSLL<T>&list2)
	{
		if (head == nullptr || list2.head == nullptr)
		{
			exit(0);
		}
		Node<T>*p = head;
		Node<T>*q = list2.head;
		int count1 = countNodes();
		int count2 = list2.countNodes();
		int diff = abs(count1 - count2), temp = 0;
		while (temp != diff)
		{
			(count1 >= count2) ? (p = p->next) : (q = q->next);
			temp = temp + 1;
		}
		while (p != nullptr && q != nullptr && q != p)
		{
			p = p->next;
			q = q->next;
		}
		if (p == q && p != nullptr && q != nullptr)
		{
			return p->info;
		}
		else
		{
			exit(0);
		}
	}

	bool isCyclic()
	{
		if (head == nullptr)
		{
			return false;
		}
		if (head->next == nullptr)
		{
			return false;
		}
		Node<T>*p = head;
		Node<T>*q = head->next;
		while (p != nullptr && q != nullptr && q->next!=nullptr)
		{
			q = q->next->next;
			p = p->next;
			if (p == q)
			{
				return true;
			}
		}
		return false;
	}

	void splitList(LSLL<T>&list1, LSLL<T>&list2)
	{
		/*if (this->head == nullptr)
		{
			return;
		}
		int countTotal = 0,countList1=0,countList2=0;
		Node<T>*p = head;
		while (p != nullptr)
		{
			countTotal = countTotal + 1;
			p = p->next;
		}
		countList1 = ceil(countTotal / 2.0);
		countList2 = countTotal - countList1;
		list1.head=new Node<T>(head->info);
		removeAtHead();
		Node<T>*q = list1.head;
		for (int i = 1; i < countList1; i++)
		{
			q->next = new Node<T>(head->info);
			removeAtHead();
			q = q->next;
		}
		if (countList2 != 0)
		{
			list2.head = new Node<T>(head->info);
			removeAtHead();
			q = list2.head;
			for (int i = 1; i < countList2; i++)
			{
				q->next = new Node<T>(head->info);
				removeAtHead();
				q = q->next;
			}
		}*/
		if (head == nullptr)
		{
			return;
		}
		list1.head = head;
		Node<T>*p = middle();
		list2.head = p->next;
		p->next = nullptr;
		head = nullptr;
		
	}

	void removeDuplicates()
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		while (p != nullptr)
		{
			Node<T>*q = p->next;
			Node<T>*pre = p;
			while (q != nullptr)
			{
				if (q->info == p->info)
				{
					Node<T>*temp = q->next;
					delete q;
					pre->next = temp;
					q = pre->next;
				}
				else 
				{
					pre = q;
					q = q->next;
				}
			}
			p = p->next;
		}
	}

	LSLL<T> mergeSortedLists(LSLL<T>&list2)
	{
		LSLL<T>sorted;
		if ((list2.head == nullptr && this->head == nullptr) || (list2.head == nullptr && this->head != nullptr))
		{
			return *this;
		}
		else if (list2.head != nullptr && this->head == nullptr)
		{
			return list2;
		}
		Node<T>*p = head;
		Node<T>*q = list2.head;
		(p->info <= q->info) ? (sorted.head = new Node<T>(p->info)) : sorted.head = new Node<T>(q->info);
		(p->info <= q->info) ? (p = p->next) : (q = q->next);
		Node<T>*r = sorted.head;
		while (p != nullptr && q != nullptr)
		{
			(p->info <= q->info) ? (r->next = new Node<T>(p->info)) : r->next = new Node<T>(q->info);
			(p->info <= q->info) ? (p = p->next) : q = q->next;
			r = r->next;
		}
		if (p == nullptr)
		{
			while (q != nullptr)
			{
				r->next = new Node<T>(q->info);
				r = r->next;
				q = q->next;
			}
		}
		else
		{
			while (p != nullptr)
			{
				r->next = new Node<T>(p->info);
				r = r->next;
				p = p->next;
			}
		}
		return sorted;
	}

	void reversePrint()
	{
		reverseList();
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		Node<T>*pre = nullptr;
		while (p->next != nullptr)
		{
			cout << head->info << " ";
			head = p->next;
			p->next = pre;
			pre = p;
			p = head;
		}
		cout << head->info;
		p->next = pre;
	}

	void reverseList()
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		Node<T>*pre = nullptr;
		while (p->next!= nullptr)
		{
			head = p->next;
			p->next = pre;
			pre = p;
			p = head;
		}
		p->next = pre;
	}

	void swapMN(int M, int N)
	{
		if (!isValidMandN(M,N) || head==nullptr || head->next==nullptr || M==N)
		{
			return;
		}
		if (M > N)
		{
			swap(M, N);
		}
		Node<T>*p = head,*q=head;
		Node<T>*Ppre = nullptr,*Qpre=nullptr;
		int count1 = 1,count2=1;
		while (count1 != M || count2 != N)
		{
			if (count1 != M)
			{
				count1 = count1 + 1;
				Ppre = p;
				p = p->next;
			}
			if (count2 != N)
			{
				count2 = count2 + 1;
				Qpre = q;
				q = q->next;
		    }
		}
		Node<T>*temp = p->next;
		(Ppre == nullptr) ? (head = q) : (Ppre->next = q);
		Qpre->next = p;
		p->next = q->next;
		(N - M != 1) ? (q->next = temp) : (q->next = Qpre);
	}

	/*void sortList()  //Sort base on data
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		while (p != nullptr)
		{
			Node<T>*min = p;
			Node<T>*q = p->next;
			while (q!=nullptr)
			{
				if (q->info < min->info)
				{
					min = q;
				}
				q = q->next;
			}
			T temp = min->info;
			min->info = p->info;
			p->info = temp;
			p = p->next;
		}
	}*/

	void sortList()    //Sort base on address
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		while (p != nullptr)
		{
			Node<T>*min = p;
			Node<T>*q = p->next;
			while (q != nullptr)
			{
				if (q->info < min->info)
				{
					min = q;
				}
				q = q->next;
			}
			Node<T>*temp = p;
			p = p->next;
			swapNodes(temp, min);
		}
	}

	void insertAtHead(T val)
	{
		Node<T>*temp = new Node<T>(val);
		temp->next = head;
		head = temp;
	}
	
	void insertAtTail(T val)
	{
		if (head == nullptr)
		{
			head = new Node<T>(val);
			return;
		}
		Node<T>*p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Node<T>(val);
	}
	
	void insertAfter(T key, T val)
	{
		Node<T>*p = head;
		while (p!=nullptr)
		{
			if (p->info == key)
			{
				Node<T>*temp = new Node<T>(val);
				temp->next = p->next;
				p->next = temp;
				break;
			}
			p = p->next;
		}
	}
	void insertBefore(T key, T val)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		Node<T>*p = head;
		Node<T>*pre;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				Node<T>*temp = new Node<T>(val);
				temp->next = p;
				pre->next = temp;
				break;
			}
			pre = p;
			p = p->next;
		}
	}
	
	void removeAtHead()
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*temp = head->next;
		delete head;
		head = temp;
	}
	
	void removeAtTail()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node<T>*p = head;
		while (p->next->next!=nullptr)
		{
			p = p->next;
		}
		delete p->next;
		p->next = nullptr;
	}
	
	void removeAfter(T key)
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>*p = head;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				if (p->next != nullptr)
				{
					Node<T>*temp = p->next->next;
					delete p->next;
					p->next = temp;
					break;
				}
				else
				{
					return;
				}
			}
			p = p->next;
		}
	}
	void removeBefore(T key)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next==nullptr)
		{
			return;
		}
		if (head->next->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>*pre = head;
		Node<T>*p = head->next->next;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				delete pre->next;
				pre->next = p;
				break;
			}
			p = p->next;
			pre = pre->next;
		}

	}
	
	void remove(T key)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->info == key)
		{
			removeAtHead();
			return;
	    }
		Node<T>*p = head->next;
		Node<T>*pre=head;
		while (p != nullptr)
		{
			if (p->info == key)
			{
				Node<T>*temp = p->next;
				delete pre->next;
				pre->next = temp;
				break;
			}
			pre = p;
			p = p->next;
		}
	}
	
	void display()
	{
		Node<T>*temp = head;
		while (temp != nullptr)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
	}
};

#endif
