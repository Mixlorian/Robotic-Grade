
// El operador ## del preprocesador concatena a su parte izquierda su parte derecha.
// P.e si "C == MyClass" entonces "C##Ptr" (MyClass##Ptr) produce "MyClassPtr".

#define DECLARE_PTR(C) using C##Ptr = C*

