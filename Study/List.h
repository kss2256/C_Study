#pragma once
#include <assert.h>


template <typename T>
class ListNode
{

private:

	ListNode<T>* m_PrevNode;
	ListNode<T>* m_NextNode;
	T				m_Data;

private:




private:
	ListNode()
		: m_PrevNode(nullptr)
		, m_NextNode(nullptr)
		, m_Data()
	{

	}

	~ListNode()
	{

	}

	template <typename T>
	friend class LinkedList;
	template <typename T>
	friend class Citerator;

};

template <typename T>
class Citerator
{
	template <typename T>
	friend class LinkedList;

private:

	ListNode<T>* m_Node;



public:
	//bool 타입으로 연산자 오버로딩 이터레이터 끼리 노드가 같은지 확인.
	bool operator == (const Citerator<T>& iter) const
	{
		return m_Node == iter.m_Node;
	}
	//bool 타입으로 연산자 오버로딩 이터레이터 끼리 노드가 다른지 확인.
	bool operator != (const Citerator<T>& iter) const
	{
		return m_Node != iter.m_Node;
	}
	// ++ 전위 연산
	void operator ++ ()
	{
		m_Node = m_Node->m_NextNode;
	}
	// -- 전위 연산
	void operator -- ()
	{
		m_Node = m_Node->m_PrevNode;
	}
	// ++ 후위 연산
	void operator ++ (int)
	{
		m_Node = m_Node->m_NextNode;
	}
	// -- 후위 연산
	void operator -- (int)
	{
		m_Node = m_Node->m_PrevNode;
	}
	// 역참조 오버로딩 *
	T& operator * ()
	{
		return m_Node->m_Data;
	}


public:
	Citerator()
		: m_Node(nullptr)
	{}
	~Citerator()
	{}
};





template <typename T>
class LinkedList
{

public:

	ListNode<T>*	m_Begin;
	ListNode<T>*	m_End;
	int				m_Size;

public:

	//노드의 맨 뒤에 데이터를 추가 한다.
	void Push_Back(const T& _data)
	{
		ListNode<T>* Node = new ListNode<T>;

		Node->m_Data = _data;

		ListNode<T>* PrevNode = m_End->m_PrevNode;

		m_End->m_PrevNode = Node;

		Node->m_NextNode = m_End;

		PrevNode->m_NextNode = Node;

		Node->m_PrevNode = PrevNode;

		m_Size++;

	}
	//노드의 맨 앞에 데이터를 추가 한다.
	void Push_Front(const T& _data)
	{
		ListNode<T>* Node = new ListNode<T>;

		Node->m_Data = _data;

		ListNode<T>* PrevNode = m_Begin->m_NextNode;

		Node->m_PrevNode = m_Begin;

		m_Begin->m_NextNode = Node;

		PrevNode->m_PrevNode = Node;

		Node->m_NextNode = PrevNode;

		m_Size++;

	}

	//iterator가 가지고 있는 노드와 그다음 노드 사이에 새로운 노드를 추가 한다.
	void Insert(const Citerator<T>& iter, const T& _data)
	{
		ListNode<T>* node = new ListNode<T>;
		node->m_Data = _data;

		ListNode<T>* next = iter.m_Node->m_NextNode;

		node->m_NextNode = next;
		next->m_PrevNode = node;

		node->m_PrevNode = iter.m_Node;
		iter.m_Node->m_NextNode = node;

		m_Size++;

	}



	//마지막 노드를 제거 한다.
	void Pop_Back()
	{
		if (m_Size == 0)
			assert(false);


		ListNode<T>* DeleteNode = m_End->m_PrevNode;
		ListNode<T>* temporaryNode = DeleteNode->m_PrevNode;

		temporaryNode->m_NextNode = m_End;
		m_End->m_PrevNode = temporaryNode;

		delete DeleteNode;

		m_Size--;

	}

	//첫번째 노드를 제거한다.
	void Pop_Front()
	{
		if (m_Size == 0)
			assert(false);


		ListNode<T>* DeleteNode = m_Begin->m_NextNode;
		ListNode<T>* temporaryNode = DeleteNode->m_NextNode;

		temporaryNode->m_PrevNode = m_Begin;
		m_Begin->m_NextNode = temporaryNode;

		delete DeleteNode;

		m_Size--;

	}

	//모든 노드 제거하고 처음 상태로 만듬
	void Clear()
	{

		ListNode<T>* DeleteNode = m_Begin->m_NextNode;
		ListNode<T>* Node = DeleteNode->m_NextNode;

		for (int i = 0; i < m_Size; ++i)
		{
			delete DeleteNode;
			DeleteNode = Node;
			Node = Node->m_NextNode;

		}
		m_Size = 0;
		m_Begin->m_NextNode = m_End;
		m_End->m_PrevNode = m_Begin;

		//위에랑 밑에랑 처음엔 헤깔리수도 있음.. 중요 밑에는 안되는 코드로 m_Begin의 넥스트는 지금 널임
		//m_End = m_Begin->m_NextNode;
		//m_Begin = m_End->m_PrevNode;

	}


	// 만약 리스트가 비어있다면 에러를 발생 한다.
	//이 함수는 첫번째 데이터를 반환한다.
	const T& Front()	const
	{
		if (m_Size == 0)
		{
			assert(false);
		}
		return m_Begin->m_NextNode->m_Data;
	}
	//마지막 데이터를 반환한다.
	const T& Back()	const
	{
		if (m_Size == 0)
		{
			assert(false);
		}
		return m_End->m_PrevNode->m_Data;
	}




	int Size() const
	{
		return m_Size;
	}

	//이 함수는 리스트가 비었는지 확인 할수 있는 함수이다.
	bool Empty() const
	{
		return m_Size == 0;
	}

public:

	//이 함수는 첫번째 데이터를 반환한다. 
	Citerator<T> Begin() const
	{
		Citerator<T> iter;
		iter.m_Node = m_Begin->m_NextNode;
		return iter;
	}
	//마지막 데이터를 반환한다.
	Citerator<T> End() const
	{
		Citerator<T> iter;
		iter.m_Node = m_End->m_PrevNode;

		return iter;
	}

	//리턴 타입을 iterator로 하는 이유는 특정 iteraotr 을 받아서 그 iterator가 가지고 있는 
	//노드를 제거할 것이다. 이때 제거한 노드의 다음 노드를 iterator에 담아서 반환 할 것이다.
	Citerator<T> Erase(const Citerator<T>& iter)
	{
		if (iter.m_Node == m_End || iter.m_Node == m_Begin)
		{
			assert(false);
			return End();
		}
		ListNode<T>* prev = iter.m_Node->m_PrevNode;
		ListNode<T>* next = iter.m_Node->m_NextNode;

		prev->m_NextNode = next;
		next->m_PrevNode = prev;

		delete iter.m_Node;
		--m_Size;

		Citerator<T> result;
		result.m_Node = next;
		return result;


	}

	//노드의 데이터값으로 조건 검색해서 그 노드를 지운다. 이때 데이터값이 검색 되지 않다면 End를 반환.
	Citerator<T> Erase(const T& _data)
	{
		iterator iter, iterEnd = End();

		for (iter = Begin(); iter < iterEnd; ++iter)
		{
			if (*iter == _data)
				return Erase(iter);
		}

		return End();

	}


	//제거할 노드의 시작과 끝을 정해주고 시작부터 끝까지 전부 삭제 해주는 함수.
	Citerator<T> Erase(const Citerator<T>& start, const Citerator<T>& end)
	{

		if (start.m_Node == m_End || start.m_Node == m_Begin ||
			end.m_Node == m_End || end.m_Node == m_Begin)
		{
			assert(false);
			return End();
		}

		Citerator<T> iter = Begin();
		Citerator<T> iterEnd = End();

		bool Cheak = false;

		//iterator 를 처음부터 끝까지 돌면서 start, end 중 먼저 만나는게 어떤 노드인지 확인한다.
		//end 를 먼저 만나면start노드와 end 노드를 바꿔준다.
		for (; iter != iterEnd; ++iter)
		{
			if (iter == start)
				break;

			else if (iter == end)
			{
				Cheak = true;
				break;
			}
		}

		Citerator<T> iterStart = start;
		iterEnd = end;

		//End가 먼저 발경 된 경우 이므로 start와 end를 바꿔준다.
		if (Cheak)
		{
			iterStart = end;
			iterEnd = start;
		}

		//for문 버전
		ListNode<T>* Prev = iterStart.m_Node->m_PrevNode;
		ListNode<T>* Next = iterEnd.m_Node->m_NextNode;
		ListNode<T>* Node = iterStart.m_Node;
		for (; iterStart.m_Node < Next; ++iterStart.m_Node)
		{
			ListNode<T>* NextNode = Node->m_NextNode;

			delete Node;
			Node = NextNode;
			--m_Size;
		}

		////while 문 버전
		//ListNode<T>* Prev = iterStart.m_Node->m_PrevNode;
		//ListNode<T>* Next = iterEnd.m_Node->m_NextNode;
		//ListNode<T>* Node = iterStart.m_Node;
		//while (Node != Next)
		//{
		//	ListNode<T>* NodeNext = Node->m_NextNode;

		//	delete Node;

		//	Node = NodeNext;
		//	--m_Size;
		//}

		Prev->m_NextNode = Next;
		Next->m_PrevNode = Prev;

		iter.m_Node = Next;




		return iter;
	}

	//각 노드의 데이터 순서를 정렬 해주는 함수 (오름 차순)
	//인자로 함수 포인터를 넘겨 받아서 값을 교체해야 할지를 결정해주게 한다.
	//함수 포인터로 하는 이유는 리스트가 template 이기때문에 T타입이라 어떤 타입인지 알수 없기 때문에
	//값을 직접 비교 할수 없는 상황이라고 하더라도 사용자가 함수를 구성하여 값을 비교 할 수 있게 
	//제작 하는 기능을 만들어주기 위해서 이다.
	void Sort(bool(*Func)(const T&, const T&))
	{
		Citerator<T> IterOut, IterOutEnd;
		Citerator<T> IterIn, IterInEnd;

		IterInEnd = End();

		IterOutEnd = End();
		--IterOutEnd;


		for (IterOut = Begin(); IterOut != IterOutEnd; ++IterOut)
		{
			IterIn = IterOut;
			++IterIn;

			for (; IterIn != IterInEnd; ++IterIn)
			{
				if (Func(*IterOut, *IterIn))
				{
					T Temp = *IterOut;
					*IterOut = *IterIn;
					*IterIn = Temp;
				}
			}

		}



	}


public:

	LinkedList()
		: m_Begin(nullptr)
		, m_End(nullptr)
	{
		m_Begin = new ListNode<T>;
		m_End = new ListNode<T>;



		m_Begin->m_NextNode = m_End;
		m_End->m_PrevNode = m_Begin;
		m_Size = 0;
	}

	~LinkedList()
	{

		ListNode<T>* Node = m_Begin;
		ListNode<T>* DeleteNode = Node->m_NextNode;

		//for 문 버전 메모리 해제
		//for (int i = 0; i < m_Size + 1; ++i)
		//{							
		//		delete Node;
		//		Node = DeleteNode;
		//		DeleteNode = DeleteNode->m_NextNode;		
		//}
		//
		//delete Node;

		//while 문 버전 메모리 해제
		while (Node != nullptr)
		{
			ListNode<T>* DelNode = Node->m_NextNode;
			delete Node;
			Node = DelNode;
		}

	}

public:
	typedef Citerator<T> iterator;

};