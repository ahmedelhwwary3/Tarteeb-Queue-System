#pragma once
#include <string>
#include <stack>

using namespace std;

class clsMyString
{

private:

	stack <string> _Undo;
	stack <string> _Redo;
	string _Value;

public:
	//"",1,2
	void Set(string value)
	{
		_Undo.push(_Value);//""
		_Value = value;//1
	}

	string Get()
	{
		return _Value;
	}

	__declspec(property(get = Get, put = Set)) string Value;


	void Undo()
	{
		//"",1,2
		if (!_Undo.empty())
		{
			//3
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();//2
		}

	}

	void Redo()
	{

		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}


	}
};

