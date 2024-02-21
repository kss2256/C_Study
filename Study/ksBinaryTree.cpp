#pragma once

namespace ks
{

	template <typename T>
	class Node 
	{
	private:



	public:
		Node()
		{

		}
		~Node()
		{

		}

		template <typename T>
		friend class BinaryTree;

		

	};

	template <typename T>
	class BinaryTree
	{
		typedef Node<T>			NODE;
		typedef Node<T>*		PNODE;

	private:

		PNODE		mRootNode;




	public:

		BinaryTree()
		{

		}
		~BinaryTree()
		{

		}
	};




}