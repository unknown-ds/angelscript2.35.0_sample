#include	"stdafx.h"
#include "./script_func.h"
#include "./script_mgr.h"

using namespace std;


//==========================================================================
//--------------------------------------------------------------------------
// 配列の展開
template<typename T>
vector<T> ExpansionScriptArray(
	CScriptArray*	_pArray
	)
{
	int _Size = _pArray->GetSize();
	vector<T> _Ret(_Size);
	
	for(int _Lp=0; _Lp<_Size; _Lp++) {
		T _Val = *(T*)_pArray->At(_Lp);
		
		_Ret[_Lp] = _Val;
	}
	
	return(_Ret);
}

//--------------------------------------------------------------------------
// 2次元配列の展開
template<typename T>
vector<vector<T>> ExpansionScriptArray2(
	CScriptArray*	_pArray
	)
{
	vector<vector<T>> _Ret;
	
	for(int _Lp0=0;_Lp0<(int)_pArray->GetSize();_Lp0++){
		// 配列内配列の展開
		CScriptArray* _pArray1 = (CScriptArray*)_pArray->At(_Lp0);
		
		vector<T> _Tmp = ExpansionScriptArray<T>(_pArray1);
		_Ret.emplace_back(_Tmp);
	}
	
	return(_Ret);
}

//==========================================================================
//--------------------------------------------------------------------------
// 値のキャスト
template<typename T>
T CastParam(void* _pPtr)
{
	return(*reinterpret_cast<T*>(_pPtr));
}

//--------------------------------------------------------------------------
// 引数２つ表示
template<typename T>
void PrintParam2(string &_Fmt, void* _pRef1, void* _pRef2, int _TypeId2)
{
	switch(_TypeId2){
	case asETypeIdFlags::asTYPEID_BOOL: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<bool>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_INT8: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<char>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_INT16: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<short>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_INT32: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<int>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_INT64: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<long long>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_UINT8: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<unsigned char>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_UINT16: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<unsigned short>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_UINT32: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<unsigned int>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_UINT64: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<unsigned long long>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<float>(_pRef2)); }break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	printf(_Fmt.c_str(), CastParam<T>(_pRef1), CastParam<double>(_pRef2)); }break;
	}
}


//--------------------------------------------------------------------------
// 引数３つ表示
template<typename T1, typename T2>
void PrintParam3a(string &_Fmt, void* _pRef1, void* _pRef2, void* _pRef3, int _TypeId3)
{
	switch(_TypeId3){
	case asETypeIdFlags::asTYPEID_BOOL: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<bool>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_INT8: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<int8>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_INT16: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<int16>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_INT32: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<int32>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_INT64: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<int64>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_UINT8: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<uint8>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_UINT16: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<uint16>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_UINT32: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<uint32>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_UINT64: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<uint64>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<float>(_pRef3)); }break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<double>(_pRef3)); }break;
	}
}

template<typename T1>
void PrintParam3(string &_Fmt, void* _pRef1, void* _pRef2, int _TypeId2, void* _pRef3, int _TypeId3)
{
	switch(_TypeId2){
	case asETypeIdFlags::asTYPEID_BOOL: {	PrintParam3a<T1, bool>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_INT8: {	PrintParam3a<T1, int8>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_INT16: {	PrintParam3a<T1, int16>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_INT32: {	PrintParam3a<T1, int32>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_INT64: {	PrintParam3a<T1, int64>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_UINT8: {	PrintParam3a<T1, uint8>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_UINT16: {	PrintParam3a<T1, uint16>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3); }break;
	case asETypeIdFlags::asTYPEID_UINT32: {	PrintParam3a<T1, uint32>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3); }break;
	case asETypeIdFlags::asTYPEID_UINT64: {	PrintParam3a<T1, uint64>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3); }break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	PrintParam3a<T1, float>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3);	 }break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	PrintParam3a<T1, double>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3); }break;
	}
}


//--------------------------------------------------------------------------
// 引数４つ表示用
template<typename T1, typename T2, typename T3>
void PrintParam4b(string &_Fmt, void* _pRef1, void* _pRef2, void* _pRef3, void* _pRef4, int _TypeId4)
{
	switch(_TypeId4){
	case asETypeIdFlags::asTYPEID_BOOL: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<bool>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_INT8: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<int8>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_INT16: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<int16>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_INT32: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<int32>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_INT64: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<int64>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_UINT8: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<uint8>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_UINT16: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<uint16>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_UINT32: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<uint32>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_UINT64: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<uint64>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<float>(_pRef4)); }break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	printf(_Fmt.c_str(), CastParam<T1>(_pRef1), CastParam<T2>(_pRef2), CastParam<T3>(_pRef3), CastParam<double>(_pRef4)); }break;
	}
}

template<typename T1, typename T2>
void PrintParam4a(string &_Fmt, void* _pRef1, void* _pRef2, void* _pRef3, int _TypeId3, void* _pRef4, int _TypeId4)
{
	switch(_TypeId3){
	case asETypeIdFlags::asTYPEID_BOOL: {	PrintParam4b<T1, T2, bool>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4);	 }break;
	case asETypeIdFlags::asTYPEID_INT8: {	PrintParam4b<T1, T2, int8>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4);	 }break;
	case asETypeIdFlags::asTYPEID_INT16: {	PrintParam4b<T1, T2, int16>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_INT32: {	PrintParam4b<T1, T2, int32>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_INT64: {	PrintParam4b<T1, T2, int64>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_UINT8: {	PrintParam4b<T1, T2, uint8>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4);	 }break;
	case asETypeIdFlags::asTYPEID_UINT16: {	PrintParam4b<T1, T2, uint16>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_UINT32: {	PrintParam4b<T1, T2, uint32>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_UINT64: {	PrintParam4b<T1, T2, uint64>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	PrintParam4b<T1, T2, float>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	PrintParam4b<T1, T2, double>(_Fmt, _pRef1, _pRef2, _pRef3, _pRef4, _TypeId4); }break;
	}
}

template<typename T1>
void PrintParam4(string &_Fmt, void* _pRef1, void* _pRef2, int _TypeId2, void* _pRef3, int _TypeId3, void* _pRef4, int _TypeId4)
{
	switch(_TypeId2){
	case asETypeIdFlags::asTYPEID_BOOL: {	PrintParam4a<T1, bool>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4);	 }break;
	case asETypeIdFlags::asTYPEID_INT8: {	PrintParam4a<T1, int8>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4);	 }break;
	case asETypeIdFlags::asTYPEID_INT16: {	PrintParam4a<T1, int16>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_INT32: {	PrintParam4a<T1, int32>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_INT64: {	PrintParam4a<T1, int64>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_UINT8: {	PrintParam4a<T1, uint8>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4);	 }break;
	case asETypeIdFlags::asTYPEID_UINT16: {	PrintParam4a<T1, uint16>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_UINT32: {	PrintParam4a<T1, uint32>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_UINT64: {	PrintParam4a<T1, uint64>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	PrintParam4a<T1, float>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	PrintParam4a<T1, double>(_Fmt, _pRef1, _pRef2, _pRef3, _TypeId3, _pRef4, _TypeId4); }break;
	}
}


//--------------------------------------------------------------------------
// printf関数(Native)
void asPrintf0(string &msg)
{
	printf("%s", msg.c_str());
}

// printf関数(Generic)
void asPrintf0Generic(
	asIScriptGeneric *pGen
	)
{
	string* _pInput = static_cast<string*>(pGen->GetArgObject(0));

	asPrintf0(*_pInput);
}

//--------------------------------------------------------------------------
// printf関数(Native)
void asPrintf1(
	string& _Fmt,
	void*	_pRef,
	int		_TypeId
	)
{
	switch (_TypeId) {
	case asETypeIdFlags::asTYPEID_BOOL: {	printf(_Fmt.c_str(), CastParam<bool>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_INT8: {	printf(_Fmt.c_str(), CastParam<int8>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_INT16: {	printf(_Fmt.c_str(), CastParam<int16>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_INT32: {	printf(_Fmt.c_str(), CastParam<int32>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_INT64: {	printf(_Fmt.c_str(), CastParam<int64>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_UINT8: {	printf(_Fmt.c_str(), CastParam<uint8>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_UINT16: {	printf(_Fmt.c_str(), CastParam<uint16>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_UINT32: {	printf(_Fmt.c_str(), CastParam<uint32>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_UINT64: {	printf(_Fmt.c_str(), CastParam<uint64>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	printf(_Fmt.c_str(), CastParam<float>(_pRef));	}break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	printf(_Fmt.c_str(), CastParam<double>(_pRef));	}break;
	// string型登録時の返り値 RegisterObjectType()
	case (asETypeIdFlags::asTYPEID_APPOBJECT + 0x0c): {
		printf(_Fmt.c_str(), (CastParam<string>(_pRef)).c_str());
	}break;
	default: { printf(_Fmt.c_str()); }break;
	}

}

// printf関数(Generic)
void asPrintf1Generic(
	asIScriptGeneric *pGen
)
{
	string& _Fmt = *static_cast<string*>(pGen->GetArgObject(0));
	int _Prm1TypeId = pGen->GetArgTypeId(1);
	void* _pPrm1Ptr = pGen->GetArgAddress(1);
	
	asPrintf1(_Fmt, _pPrm1Ptr, _Prm1TypeId);
}


//--------------------------------------------------------------------------
// printf関数(Native)
void asPrintf2(
	string&	_Fmt,
	void*	_pRef1,	int	_TypeId1,
	void*	_pRef2,	int	_TypeId2
	)
{

	switch (_TypeId1) {
	case asETypeIdFlags::asTYPEID_BOOL: {	PrintParam2<bool>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_INT8: {	PrintParam2<int8>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_INT16: {	PrintParam2<int16>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_INT32: {	PrintParam2<int32>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_INT64: {	PrintParam2<int64>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_UINT8: {	PrintParam2<uint8>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_UINT16: {	PrintParam2<uint16>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_UINT32: {	PrintParam2<uint32>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_UINT64: {	PrintParam2<uint64>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	PrintParam2<float>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	PrintParam2<double>(_Fmt, _pRef1, _pRef2, _TypeId2);	}break;
	default: { printf(_Fmt.c_str()); }break;
	}

}

// printf関数(Generic)
void asPrintf2Generic(
	asIScriptGeneric *pGen
)
{
	string& _Fmt = *static_cast<string*>(pGen->GetArgObject(0));
	void*	_pRef1		= pGen->GetArgAddress(1);
	int		_TypeId1	= pGen->GetArgTypeId(1);
	void*	_pRef2		= pGen->GetArgAddress(2);
	int		_TypeId2	= pGen->GetArgTypeId(2);
	
	asPrintf2(_Fmt, _pRef1, _TypeId1, _pRef2, _TypeId2);
}


//--------------------------------------------------------------------------
// printf関数(Native)
void asPrintf3(
	string&	_Fmt,
	void*	_pRef1,	int	_TypeId1,
	void*	_pRef2,	int	_TypeId2,
	void*	_pRef3,	int	_TypeId3
	)
{
	switch (_TypeId1) {
	case asETypeIdFlags::asTYPEID_BOOL: {	PrintParam3<bool>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_INT8: {	PrintParam3<int8>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_INT16: {	PrintParam3<int16>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_INT32: {	PrintParam3<int32>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_INT64: {	PrintParam3<int64>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_UINT8: {	PrintParam3<uint8>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_UINT16: {	PrintParam3<uint16>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_UINT32: {	PrintParam3<uint32>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_UINT64: {	PrintParam3<uint64>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	PrintParam3<float>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	PrintParam3<double>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3);	}break;
	default: { printf(_Fmt.c_str()); }break;
	}
	
}

// printf関数(Generic)
void asPrintf3Generic(
	asIScriptGeneric *pGen
)
{
	string& _Fmt = *static_cast<string*>(pGen->GetArgObject(0));
	void*	_pRef1		= pGen->GetArgAddress(1);
	int		_TypeId1	= pGen->GetArgTypeId(1);
	void*	_pRef2		= pGen->GetArgAddress(2);
	int		_TypeId2	= pGen->GetArgTypeId(2);
	void*	_pRef3		= pGen->GetArgAddress(3);
	int		_TypeId3	= pGen->GetArgTypeId(3);
	
	asPrintf3(_Fmt, _pRef1, _TypeId1, _pRef2, _TypeId2, _pRef3, _TypeId3);
}


//--------------------------------------------------------------------------
// printf関数(Native)
void asPrintf4(
	string&	_Fmt,
	void*	_pRef1,	int	_TypeId1,
	void*	_pRef2,	int	_TypeId2,
	void*	_pRef3,	int	_TypeId3,
	void*	_pRef4,	int	_TypeId4
	)
{
	switch (_TypeId1) {
	case asETypeIdFlags::asTYPEID_BOOL: {	PrintParam4<bool>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_INT8: {	PrintParam4<int8>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_INT16: {	PrintParam4<int16>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_INT32: {	PrintParam4<int32>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_INT64: {	PrintParam4<int64>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_UINT8: {	PrintParam4<uint8>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_UINT16: {	PrintParam4<uint16>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_UINT32: {	PrintParam4<uint32>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_UINT64: {	PrintParam4<uint64>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_FLOAT: {	PrintParam4<float>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	case asETypeIdFlags::asTYPEID_DOUBLE: {	PrintParam4<double>(_Fmt, _pRef1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);	}break;
	default: { printf(_Fmt.c_str()); }break;
	}
	
}

// printf関数(Generic)
void asPrintf4Generic(
	asIScriptGeneric *pGen
)
{
	string& _Fmt = *static_cast<string*>(pGen->GetArgObject(0));
	void*	_pRef1		= pGen->GetArgAddress(1);
	int		_TypeId1	= pGen->GetArgTypeId(1);
	void*	_pRef2		= pGen->GetArgAddress(2);
	int		_TypeId2	= pGen->GetArgTypeId(2);
	void*	_pRef3		= pGen->GetArgAddress(3);
	int		_TypeId3	= pGen->GetArgTypeId(3);
	void*	_pRef4		= pGen->GetArgAddress(4);
	int		_TypeId4	= pGen->GetArgTypeId(4);
	
	
	asPrintf4(_Fmt, _pRef1, _TypeId1, _pRef2, _TypeId2, _pRef3, _TypeId3, _pRef4, _TypeId4);
}



//---------------------------------------------------------------------------
// スクリプトにバインドするテスト関数１
float testBindFunc1(
	float _Lhs,			// 引数１
	float _Rhs			// 引数２
	)
{
	//printf("execute %s.\n",__FUNCTION__);
	return (_Lhs + _Rhs);
}


// Generic
void testBindFunc1Generic(
	asIScriptGeneric *pGen
	)
{
	//printf("execute %s.\n", __FUNCTION__);

	float _Lhs = *reinterpret_cast<float*>(pGen->GetAddressOfArg(0));
	float _Rhs = *reinterpret_cast<float*>(pGen->GetAddressOfArg(1));

	pGen->SetReturnFloat(testBindFunc1(_Lhs, _Rhs));
}

//-------------------------------------------------------------------------
// スクリプトにバインドするテスト関数２
int testBindFunc2(
	void*	_pIntArray,		// 配列ポインタ
	int		_Param			// int型引数
	)
{
	CScriptArray* _pArray = (CScriptArray*)_pIntArray;

	int _Sum = 0;
	// 配列を展開して加算
	for (int _Lp = 0; _Lp < (int)_pArray->GetSize(); _Lp++) {
		_Sum += *((int*)_pArray->At(_Lp));
	}
	_Sum *= _Param;

	return(_Sum);
}

// Generic
void testBindFunc2Generic(
	asIScriptGeneric *pGen
	)
{
	void* _pIntArray = pGen->GetArgObject(0);
	int _Param = *reinterpret_cast<int*>(pGen->GetAddressOfArg(1));

	pGen->SetReturnDWord(testBindFunc2(_pIntArray, _Param));
}


//--------------------------------------------------------------------------
constexpr int myhash(char const *s){ return( *s ? *s + 7*myhash(s + 1) : 0 ); }

// スクリプトにバインドするテスト関数３
string testBindFunc3(
	string _Input			// string型引数
	)
{
	
	switch(myhash(_Input.c_str())){		// defaultを使う場合ハッシュ値の衝突に注意
	case myhash("0"):{	return("Zero");	}break;
	case myhash("1"):{	return("One");	}break;
	case myhash("2"):{	return("Two");	}break;
	case myhash("3"):{	return("Three");	}break;
	default:{}
	}
	
	return("???");
}

// Generic
void testBindFunc3Generic(
	asIScriptGeneric *pGen
	)
{
	string* _pInput = static_cast<string*>(pGen->GetArgObject(0));

	pGen->SetReturnObject(&testBindFunc3(*_pInput));
}


//==========================================================================
//==========================================================================
// 内積計算
constexpr float mathVec3DotProduct(const CVector3& _Vec1, const CVector3& _Vec2 ){
	return(_Vec1.x * _Vec2.x + _Vec1.y * _Vec2.y + _Vec1.z * _Vec2.z);
}

//--------------------------------------------------------------------------
// コンストラクタ(Native)
static void Construct1CVector3(
	CVector3*			thisPointer
	)
{
	new(thisPointer) CVector3();
}

// コンストラクタ(Native)
static void Construct2CVector3(
	float				_xx,
	float				_yy,
	float				_zz,
	CVector3*			thisPointer
	)
{
	new(thisPointer) CVector3(_xx, _yy, _zz);
}

// コピーコンストラクタ(Native)
static void CopyConstructCVector3(
	const CVector3&		other,
	CVector3*			thisPointer
	)
{
	new(thisPointer) CVector3(other);
}

// デストラクタ(Native)
static void DestructCVector3(
	CVector3*	thisPointer
	)
{
	thisPointer->~CVector3();
}

// 内積(Native)
float CVector3::DotProduct(
	const CVector3& _Vec		// 対象ベクトル
	) const
{
	return( mathVec3DotProduct(*this, _Vec) );
}


//--------------------------------------------------------------------------
// コンストラクタ(Generic)
static void Construct1CVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	new (_pGen->GetObject()) CVector3();
}

// コンストラクタ(Generic)
static void Construct2CVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	float	_xx = *static_cast<float*>(_pGen->GetAddressOfArg(0));
	float	_yy = *static_cast<float*>(_pGen->GetAddressOfArg(1));
	float	_zz = *static_cast<float*>(_pGen->GetAddressOfArg(2));
	
	new (_pGen->GetObject()) CVector3(_xx, _yy, _zz);
}

// コピーコンストラクタ(Generic)
static void CopyConstructCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* ptr = static_cast<CVector3*>(_pGen->GetArgObject(0));
	new (_pGen->GetObject()) CVector3(*ptr);
}

// デストラクタ(Generic)
static void DestructCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* ptr = static_cast<CVector3*>(_pGen->GetObject());
	ptr->~CVector3();
}

// 初期化(Generic)
static void SetVectorCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	float	_xx = *static_cast<float*>(_pGen->GetAddressOfArg(0));
	float	_yy = *static_cast<float*>(_pGen->GetAddressOfArg(1));
	float	_zz = *static_cast<float*>(_pGen->GetAddressOfArg(2));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	_Self->SetVector(_xx, _yy, _zz);
}

// 代入演算子(=)(Generic)
static void AssignCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	*_Self = *_Other;
	_pGen->SetReturnAddress(_Self);
}

// 代入演算子(+=)(Generic)
static void AddAssignCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	*_Self += *_Other;
	_pGen->SetReturnAddress(_Self);
}

// 代入演算子(-=)(Generic)
static void SubAssignCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	*_Self -= *_Other;
	_pGen->SetReturnAddress(_Self);
}

// 代入演算子(*=)(Generic)
static void MulAssignCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	*_Self *= *_Other;
	_pGen->SetReturnAddress(_Self);
}

// 代入演算子(/=)(Generic)
static void DivAssignCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	*_Self /= *_Other;
	_pGen->SetReturnAddress(_Self);
}

// 2項演算子(+)(Generic)
static void AddCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	CVector3 _Ret = CVector3(_Self->x+_Other->x, _Self->y+_Other->y, _Self->z+_Other->z);
	
	_pGen->SetReturnObject(&_Ret);
}

// 2項演算子(-)(Generic)
static void SubCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	CVector3 _Ret = CVector3(_Self->x-_Other->x, _Self->y-_Other->y, _Self->z-_Other->z);
	
	_pGen->SetReturnObject(&_Ret);
}

// 2項演算子(*)(Generic)
static void MulCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	float _Rate = *static_cast<float*>(_pGen->GetAddressOfArg(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	CVector3 _Ret = CVector3(_Self->x*_Rate, _Self->y*_Rate, _Self->z*_Rate);
	
	_pGen->SetReturnObject(&_Ret);
}

// 2項演算子(/)(Generic)
static void DivCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	float _Rate = *static_cast<float*>(_pGen->GetAddressOfArg(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	CVector3 _Ret = CVector3(_Self->x/_Rate, _Self->y/_Rate, _Self->z/_Rate);
	
	_pGen->SetReturnObject(&_Ret);
}

// 比較演算子(==)(Generic)
static void EqualsCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Other = static_cast<CVector3*>(_pGen->GetArgObject(0));
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	bool _Ret = ( (_Self->x==_Other->x)&&(_Self->y==_Other->y)&&(_Self->z==_Other->z) );
	
	_pGen->SetReturnByte(_Ret);
}

// 正規化(Generic)
static void NormalizeCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());

	_Self->Normalize();

	_pGen->SetReturnAddress(_Self);
}

// 長さ取得(Generic)
static void LengthCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	
	float _Len = _Self->Length();

	_pGen->SetReturnFloat(_Len);
}


// 内積(Generic)
static void DotProductCVector3Generic(
	asIScriptGeneric *_pGen
	)
{
	CVector3* _Self = static_cast<CVector3*>(_pGen->GetObject());
	CVector3* _Vec = static_cast<CVector3*>(_pGen->GetArgObject(0));
	
	_pGen->SetReturnFloat( mathVec3DotProduct(*_Self, *_Vec) );
}

//==========================================================================
//--------------------------------------------------------------------------
// Vector型の登録
void RegistClass_CVector3(asIScriptEngine* _pEngine)
{
	int _Result = 0;


	// オブジェクトタイプの登録
	_Result = _pEngine->RegisterObjectType("CVector3", sizeof(CVector3), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CDAK | asOBJ_APP_CLASS_ALLFLOATS); assert(_Result >= 0);


	if (strstr(asGetLibraryOptions(), "AS_MAX_PORTABILITY"))
	{
		//-----------
		// Generic
		//-----------
		// オペレータの登録
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(Construct1CVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_CONSTRUCT, "void f(const float, const float, const float)", asFUNCTION(Construct2CVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_CONSTRUCT, "void f(const CVector3 &in)", asFUNCTION(CopyConstructCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		// メソッドの登録
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opAssign(const CVector3 &in)", asFUNCTION(AssignCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opAddAssign(const CVector3 &in)", asFUNCTION(AddAssignCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opSubAssign(const CVector3 &in)", asFUNCTION(SubAssignCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opMulAssign(const CVector3 &in)", asFUNCTION(MulAssignCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opDivAssign(const CVector3 &in)", asFUNCTION(DivAssignCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opAdd(const CVector3 &in) const", asFUNCTION(AddCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opSub(const CVector3 &in) const", asFUNCTION(SubCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opMul(float) const", asFUNCTION(MulCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opDiv(float) const", asFUNCTION(DivCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "bool opEquals(const CVector3 &in) const", asFUNCTION(EqualsCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& SetVector(const float, const float, const float)", asFUNCTION(SetVectorCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& Normalize()", asFUNCTION(NormalizeCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "float Length()", asFUNCTION(LengthCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "float DotProduct(const CVector3 &in)", asFUNCTION(DotProductCVector3Generic), asCALL_GENERIC); assert(_Result >= 0);
	}
	else
	{
		//-----------
		// Native
		//-----------
		// オペレータの登録
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(Construct1CVector3), asCALL_CDECL_OBJLAST); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_CONSTRUCT, "void f(const float, const float, const float)", asFUNCTION(Construct2CVector3), asCALL_CDECL_OBJLAST); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_CONSTRUCT, "void f(const CVector3 &in)", asFUNCTION(CopyConstructCVector3), asCALL_CDECL_OBJLAST); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectBehaviour("CVector3", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCVector3), asCALL_CDECL_OBJLAST); assert(_Result >= 0);
		// メソッドの登録
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opAssign(const CVector3 &in)", asMETHODPR(CVector3, operator =, (const CVector3&), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opAddAssign(const CVector3 &in)", asMETHODPR(CVector3, operator+=, (const CVector3&), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opSubAssign(const CVector3 &in)", asMETHODPR(CVector3, operator-=, (const CVector3&), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opMulAssign(const CVector3 &in)", asMETHODPR(CVector3, operator*=, (const CVector3&), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& opDivAssign(const CVector3 &in)", asMETHODPR(CVector3, operator/=, (const CVector3&), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opAdd(const CVector3 &in) const", asMETHODPR(CVector3, operator+, (const CVector3&) const, CVector3), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opSub(const CVector3 &in) const", asMETHODPR(CVector3, operator-, (const CVector3&) const, CVector3), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opMul(float) const", asMETHODPR(CVector3, operator*, (float) const, CVector3), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3 opDiv(float) const", asMETHODPR(CVector3, operator/, (float) const, CVector3), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "bool opEquals(const CVector3 &in) const", asMETHODPR(CVector3, operator==, (const CVector3&) const, bool), asCALL_THISCALL); assert(_Result >= 0);
		
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& SetVector(const float, const float, const float)", asMETHODPR(CVector3, SetVector, (float, float, float), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "CVector3& Normalize()", asMETHODPR(CVector3, Normalize, (), CVector3&), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "float Length()", asMETHODPR(CVector3, Length, () const, float), asCALL_THISCALL); assert(_Result >= 0);
		_Result = _pEngine->RegisterObjectMethod("CVector3", "float DotProduct(const CVector3 &in)", asMETHODPR(CVector3, DotProduct, (const CVector3&) const, float), asCALL_THISCALL); assert(_Result >= 0);
	}

	// オブジェクトプロパティの登録
	_Result = _pEngine->RegisterObjectProperty("CVector3", "float x",	asOFFSET(CVector3, x));		assert(_Result >= 0);
	_Result = _pEngine->RegisterObjectProperty("CVector3", "float y",	asOFFSET(CVector3, y));		assert(_Result >= 0);
	_Result = _pEngine->RegisterObjectProperty("CVector3", "float z",	asOFFSET(CVector3, z));		assert(_Result >= 0);

}
