#ifndef ___ooCollectionsSS_H___ // {
#define ___ooCollectionsSS_H___

#ifndef  CO_STORAGE_SPECIFIER // {
#if defined(_MSC_VER) && defined(_DLL) // {
#define CO_STORAGE_SPECIFIER    __declspec(dllimport)
#ifdef _DEBUG
/* Dynamic debug link */
#pragma comment(lib, "oocod.lib")
#else
/* Dynamic non-debug link */
#pragma comment(lib, "ooco.lib")
#endif
#else
// }{
#define CO_STORAGE_SPECIFIER
#endif // }
#endif // }


#endif // ___ooCollectionsSS_H___ }

