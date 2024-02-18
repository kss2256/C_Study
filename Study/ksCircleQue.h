#pragma once

#include <assert.h>

namespace ks
{

	template <typename T, int SIZE = 100>
	class CircleQueue
	{
	private:

		T			m_Queue[SIZE];
		int			m_Size;
		int			m_Head;
		int			m_Tail;


	public:
		// 데이터 추가 
		void push(const T& _data)
		{

			m_Queue[m_Head] = _data;

			m_Head = (m_Head + 1) & SIZE;

			++m_Size;
		}
		//데이터 제거
		void pop()
		{
			if (m_Size == 0)
			{
				assert(false);
			}

			m_Tail = (m_Tail + 1) % SIZE;

			--m_Size;
		}



		T& front()
		{
			if (m_Size == 0)
			{
				assert(false);
			}

			return m_Queue[m_Tail];
		}

		const T& front() const
		{
			if (m_Size == 0)
			{
				assert(false);
			}

			return m_Queue[m_Tail];
		}


		void clear()
		{
			m_Size = 0;
			m_Head = 0;
			m_Tail = 0;
		}

	public:


		int size() const
		{
			return m_Size;
		}

		bool empty() const
		{
			return m_Size == 0;
		}

		bool full() const
		{
			return m_Size == SIZE;
		}

	public:
		CircleQueue()
			: m_Queue{}
		{
			m_Size = 0;
			m_Head = 0;
			m_Tail = 0;
		}
		~CircleQueue()
		{}


	};

}