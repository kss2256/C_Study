#pragma once

#include <assert.h>
namespace ks
{
	template <typename T>
	class CStakcNode
	{

	private:

		T					m_Data;
		CStakcNode<T>*		m_Next;


	private:
		CStakcNode()
			: m_Data(0)
			, m_Next(nullptr)
		{}
		~CStakcNode()
		{}

		template <typename T>
		friend class CStack;

	};



	template <typename T>
	class CStack
	{
	private:
		typedef CStakcNode<T>		NODE;
		typedef CStakcNode<T>*		PNODE;

	private:

		PNODE		m_Last;
		int			m_Size;

	public:

		//노드 추가.
		void Push(const T& _data)
		{
			PNODE node = new NODE;

			node->m_Data = _data;

			node->m_Next = m_Last;  //추가된 노드의 Next 부분을 Last 노드로 지정 해둔다.

			m_Last = node;			//추가 된 노드는 Last노드가 된다

			++m_Size;
		}

		//Last노드 Next노드를 Last로 지정하고 이전 Last노드를 삭제 한다.
		void pop()
		{
			if (m_Size == 0)
			{
				assert(false);
			}
			PNODE node = m_Last->m_Next;

			delete m_Last;

			m_Last = node;

			--m_Size;
		}

		// Last노드의 데이터를 꺼내온다.
		T& top()
		{
			if (m_Size == 0)
			{
				assert(false);
			}
			return m_Last->m_Data;
		}
		// Last노드의 데이터를 꺼내온다. const 버전.
		const T& top() const
		{
			if (m_Size == 0)
			{
				assert(false);
			}
			return m_Last->m_Data;
		}
		// 모든 노드를 지우고 Last 노드를 nullptr로 변경
		void clear()
		{
			PNODE Node = m_Last;

			while (Node != nullptr)
			{
				PNODE next = Node->m_Next;
				delete Node;
				Node = next;
			}
			m_Last = nullptr;
			m_Size = 0;
		}


		int size() const
		{
			return m_Size;
		}

		bool empty() const
		{
			return m_Size == 0;
		}




	public:
		CStack()
			: m_Last(nullptr)
			, m_Size(0)
		{

		}
		~CStack()
		{
			PNODE Node = m_Last;

			while (Node != nullptr)
			{
				PNODE next = Node->m_Next;
				delete Node;
				Node = next;
			}
		}

	};

}