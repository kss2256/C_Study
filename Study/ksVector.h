#pragma once


namespace ks
{
	template <typename T, int SIZE = 4>
	class Vector
	{


	private:
		
		T*			mData;
		int			mSize;
		int			mCapacity;

	public:

		T& operator[] (int _data)
		{
			return mData[_data];
		}


	public:

		
		void push_Back(T _data)
		{

			if (mSize >= mCapacity)
			{
				Relocation();
			}		
			mData[mSize++] = _data;
		}

	public:

		int size() { return mSize; }
		bool empty() { return mSize == 0; }


		void Relocation()
		{
			T* type = new T[mCapacity * 2];
			for (size_t i = 0; i < mSize; i++)
			{
				type[i] = mData[i];
			}
			delete[] mData;
			mData = type;
			mCapacity *= 2;			
		}

	public:

		Vector()
		{
			mSize = 0;
			mCapacity = SIZE;

			mData = new T[mCapacity];

		}
		~Vector()
		{
			delete[] mData;
		}

	};

}