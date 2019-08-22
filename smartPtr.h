template<class T>
struct Delete
{
    void operator()(T* ptr)
    {
	delete ptr;
    }
};

template<class T,class D = Delete<T>>
class smart_ptr
{
public:
    smart_ptr(T* ptr){count = new int(1);_ptr = ptr;}
    smart_ptr(T* ptr,D d){_d(d);count = new int(1);_ptr = ptr;}
    ~smart_ptr()
    {
	if(--(*count)==0)
	{
	    _d(_ptr);
	    delete(count);
	    _ptr = nullptr;
	    count = nullptr;
	}
    }
    smart_ptr(const smart_ptr<T,D>& temp,D d):_d(d)
    {
	_ptr = temp._ptr;
	count = temp.count;
	(*count)++;
    }
    const smart_ptr<T,D> & operator=(const smart_ptr<T,D>& temp)
    {
	if(_ptr != temp._ptr)
	{
	    if(--(*count) == 0)
	    {
	    	_d(_ptr);delete(count);
	    }
	    _ptr = temp._ptr;
	    count = temp.count;
	    (*count)++;
	}
	return *this;
    }
    T& operator*(){return *_ptr;}
    T* operator->(){return _ptr;}
private:
    int *count;
    T *_ptr;
    D _d;
};

template<class T>
struct ListNode
{
      T _data;
      smart_ptr<ListNode<T>> _next;
      smart_ptr<ListNode<T>> _prev;

      ListNode(T data)
           :_data(data)
           , _next(NULL)
           , _prev(NULL)
      {}
};
